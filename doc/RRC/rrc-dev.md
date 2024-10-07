This document contains documentation for the 5G RRC layer, destined towards
developers. It explains the basic working of the RRC, and various UE procedure
schemes (connection, reestablishment, handover) including their interworking
with other layers.

User documentanio, such as general configuration options, are described in [a
separate page](./rrc-usagetmd).

[[_TOC_]]

# General

5G RRC is basically an ITTI message queue with associated handlers. It
sequentially reads received ITTI messages and handles them through the function
`rrc_gnb_task()` (constituing the thread entry point function). In this
function, one can see three main groups of messages in a big switch statement:

- NGAP (messages starting with `NGAP_*`)
- F1AP (messages starting with `F1AP_*`)
- E1AP (messages starting with `E1AP_*`)

For each message, a corresponding handler is called. The messages are roughly
named according to the 3GPP specification messages, so it should already be
possible to find the message in the switch based on a message name in the spec.

Note that RRC is inherently single-threaded, and processes messages in a FIFO
order.

# Sequence Diagrams of UE procedures

The following section presents a number of common UE procedures for connection
establishment&control, bearer establishment, etc. The intention is to help
developers find specific functions within RRC in the context of these
procedures. For more information on message handlers at F1 and E1 layers,
please refer to the respective [F1 documentation](../F1AP/F1-design.md) and [E1
documentation](../E1AP/E1-design.md).

For more information on these procedures, please also refer to 3GPP TS 38.401
(NG-RAN Architecture Description) and O-RAN.WG5.C.1-v11 (NR C-plane profile).

A lot of the following diagrams would show an exchange between CU-CP, DU, and
UE, in which the CU-CP forwards an "RRC Message" to the UE via an F1AP DL RRC
Message Transfer through the DU, and correspondingly receives the "RRC Message
Answer", as follows:

```mermaid
sequenceDiagram
  participant ue as UE
  participant du as DU
  participant cucp as CU-CP
  cucp->>du: F1AP DL RRC Msg Transfer (RRC Message)
  du->>ue: RRC Message
  ue->>du: RRC Message Answer
  du->>cucp: F1AP UL RRC Msg Transfer (RRC Message Answer)
```

To better utilize horizontal space, these exchanges have been collapsed as
follows, but should be read as the above exchange:

```mermaid
sequenceDiagram
  participant ue as UE
  participant du as DU
  participant cucp as CU-CP
  cucp->>ue: F1AP DL RRC Msg Transfer (RRC Message)
  ue->>cucp: F1AP UL RRC Msg Transfer (RRC Message Answer)
```

## Initial connection setup/Registration

This sequence diagram shows the principal steps for an initial UE connection.
This can either happen through a _Registration Request_ (e.g., UE connects
"from flight mode"), or a _Service Request_ (i.e., UE connects after leaving
coverage). Both requests are handled similar by the gNB, and basically
distinguish themselves, from the point-of-view of the gNB, by having PDU
sessions in the NGAP Initial Context Setup Request present (Service Request) or
not (Registration Request, with following PDU Session Resource Setup Request
procedure).

```mermaid
sequenceDiagram
  participant ue as UE
  participant du as DU
  participant cucp as CU-CP
  participant cuup as CU-UP
  participant amf as AMF

  ue->>du: Msg1/Preamble
  du->>ue: Msg2/RAR
  ue->>cucp: F1AP Initial UL RRC Msg Tr (RRC Setup Req, in Msg3)
  Note over cucp: rrc_handle_RRCSetupRequest()
  cucp->>ue: F1AP DL RRC Msg Transfer (RRC Setup, in Msg4)
  ue->>cucp: F1AP UL RRC Msg Transfer (RRC Setup Complete)
  Note over cucp: rrc_handle_RRCSetupComplete()
%% TODO: when is RRC connected?
  cucp->>amf: NGAP Initial UE Message (NAS Registration/Service Req)
  Note over amf,ue: NAS Authentication Procedure (see 24.501)
  Note over amf,ue: NAS Security Procedure (see 24.501)
  amf->>cucp: NGAP Initial Context Setup Req
  Note over cucp: rrc_gNB_process_NGAP_INITIAL_CONTEXT_SETUP_REQ()
  Note over cucp: rrc_gNB_generate_SecurityModeCommand()
  cucp->>ue: F1AP DL RRC Msg Transfer (RRC Security Mode Command)
  ue->>cucp: F1AP UL RRC Msg Transfer (RRC Security Mode Complete)
  Note over cucp: rrc_gNB_decode_dcch() (inline)
  opt No UE Capabilities present
    Note over cucp: rrc_gNB_generate_UECapabilityEnquiry()
    cucp->>ue: F1AP DL RRC Msg Transfer (RRC UE Capability Enquiry)
    ue->>cucp: F1AP UL RRC Msg Transfer (RRC UE Capability Information)
    Note over cucp: handle_ueCapabilityInformation()
  end
  opt PDU Sessions in NGAP Initial Context Setup Req present
    Note over cucp: trigger_bearer_setup()
    cucp->>cuup: E1AP Bearer Context Setup Req
    cuup->>cucp: E1AP Bearer Context Setup Resp
    Note over cucp: rrc_gNB_process_e1_bearer_context_setup_resp()
    cucp->>du: F1AP UE Context Setup Req
    du->>cucp: F1AP UE Context Setup Resp
    Note over cucp: rrc_CU_process_ue_context_setup_response()
    Note over cucp: e1_send_bearer_updates()
    cucp->>cuup: E1AP Bearer Context Modification Req
    cucp->>ue: F1AP DL RRC Msg Transfer (RRC Reconfiguration)
    cuup->>cucp: E1AP Bearer Context Modification Resp
    ue->>cucp: F1AP UL RRC Msg Transfer (RRC Reconfiguration Complete)
    Note over cucp: handle_rrcReconfigurationComplete()
  end
  Note over cucp: rrc_gNB_send_NGAP_INITIAL_CONTEXT_SETUP_RESP()
  cucp->>amf: NGAP Initial Context Setup Resp (NAS Registration/Service Complete)
```

Note that if no PDU session is present in the NGAP Initial UE Context Setup
Req, no F1AP UE Context Setup will be observed during this initial phase.

If there is no PDU session set up during NGAP Initial Context Setup Req, the UE
typically requests a PDU session(s) through a NAS procedure, which is basically
the same code paths as the above optional PDU Session setup during an NGAP
Initial Context Setup procedure:

```mermaid
sequenceDiagram
  participant ue as UE
  participant du as DU
  participant cucp as CU-CP
  participant cuup as CU-UP
  participant amf as AMF

  ue->>cucp: F1AP UL RRC Msg Transfer (RRC UL Information Transfer)
  cucp->>amf: NGAP UL NAS Transport (NAS PDU Session Establishment Req)
  amf->>cucp: NGAP PDU Session Resource Setup Req (NAS PDU Session Establishment Accept)
  Note over cucp: rrc_gNB_process_NGAP_PDUSESSION_SETUP_REQ()
    Note over cucp: trigger_bearer_setup()
    cucp->>cuup: E1AP Bearer Context Setup Req
    cuup->>cucp: E1AP Bearer Context Setup Resp
  Note over cucp: rrc_gNB_process_e1_bearer_context_setup_resp()
  cucp->>du: F1AP UE Context Setup Req
  du->>cucp: F1AP UE Context Setup Resp
  Note over cucp: rrc_CU_process_ue_context_setup_response()
    Note over cucp: e1_send_bearer_updates()
    cucp->>cuup: E1AP Bearer Context Modification Req
  cucp->>ue: F1AP DL RRC Msg Transfer (RRC Reconfiguration + NAS PDU Session Establishment Accept)
    cuup->>cucp: E1AP Bearer Context Modification Resp
  ue->>cucp: F1AP UL RRC Msg Transfer (RRC Reconfiguration Complete)
  Note over cucp: handle_rrcReconfigurationComplete()
  Note over cucp: rrc_gNB_send_NGAP_PDUSESSION_SETUP_RESP()
  cucp->>amf: NGAP PDU Session Resource Setup Resp
```

## Reestablishment

    TBD

## Handover

The basic handover (HO) structure is as follows. In order to support various
handover "message passing implementation" (F1AP, NGAP, XnAP), RRC employs
callbacks to signal HO Accept (`ho_req_ack()`), HO Success (`ho_success()`),
and HO Cancel (`ho_cancel()`). These can be used to trigger the corresponding
functionality based on mentioned "message passing implementation".

The following sequence diagram shows the basic functional execution of a
successful handover in the case of an F1 handover. Note the callbacks as
mentioned above:

```mermaid
sequenceDiagram
  participant ue as UE
  participant sdu as source DU
  participant tdu as target DU
  participant cucp as CU-CP
  participant cuup as CU-UP

  Note over ue,sdu: UE active on source DU
  alt HO triggered through A3 event
    ue->>sdu: RRC Measurement Report
    sdu->>cucp: F1AP UL RRC Msg Transfer (RRC Measurement Report)
    Note over cucp: Handover decision (A3 event trigger)
  else Manual Trigger
    Note over cucp: Handover decision (e.g., telnet)
  end
  Note over cucp: nr_rrc_trigger_f1_ho() ("on source CU")
  Note over cucp: nr_initiate_handover() ("on target CU")
  cucp->>tdu: F1AP UE Context Setup Req
  Note over tdu: Create UE context
  tdu->>cucp: F1AP UE Context Setup Resp (incl. CellGroupConfig)
  Note over cucp: rrc_CU_process_ue_context_setup_response() ("on target CU")
    Note over cucp: cuup_notify_reestablishment()
    cucp->>cuup: E1AP Bearer Context Modification Req
  cucp-->>cucp: callback: ho_req_ack()
  Note over cucp: nr_rrc_f1_ho_acknowledge() ("on source CU")
  cucp->>sdu: F1AP Context Modification Req (RRC Reconfiguration)
    cuup->>cucp: E1AP Bearer Context Modification Resp
  sdu->>ue: RRC Reconfiguration
  sdu->>cucp: F1AP Context Modification Resp
  Note over sdu: Stop scheduling UE
  Note over ue: Resync
  ue<<->>tdu: Msg1 + Msg2
  ue->>tdu: RRC Reconfiguration Complete
  tdu->>cucp: F1AP UL RRC Msg Transfer (RRC Reconfiguration Complete)
  Note over cucp: handle_rrcReconfigurationComplete() ("on target CU")
  cucp-->>cucp: callback: ho_success()
  Note over cucp: nr_rrc_f1_ho_complete() ("on source CU")
  cucp->>sdu: F1AP UE Context Release Command
  sdu->>cucp: F1AP UE Context Release Complete
  Note over ue,tdu: UE active on target DU
```

# Structures

TODO:

- explain xid and transactions
- explain `ho_context`
