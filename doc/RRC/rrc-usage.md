This document describes the basic functioning of the 5G RRC layer, describes
the periodic output, and explains the various configuration options that
influence its behavior.

Developer documentation, such as UE connection control flow, reestablishment, or handover, are described in [a separate page](./rrc-dev.md).

[[_TOC_]]

# General

The RRC layer controls the basic connection setup of UEs as well as additional
procedures. It is the fundamental building block of OAI's CU-CP, and interacts
with lower layers (DU, basically MAC and RLC) through F1AP messages, and with
the CU-UP through E1AP messages. More information can be found in the
respective [F1AP page](../F1-design.md) and [E1AP page](../E1AP/E1-design.md).

# Periodic output and interpretation

Similarly to the scheduler, the RRC periodically prints information about
connected UEs and DUs into file `nrRRC_stats.log` in the current working
directory of the executable running the RRC (typically, `nr-softmodem`). The
output has the following structure:

```
[UE1]
[UE2]
[...]
[DU1]
[DU2]
[...]
```

For each UE, it prints:

    TBD

For each DU, it prints:

    TBD

As of now, it does not print information about connected CU-UPs or AMFs.

# Configuration of the RRC

## Split-related options (when running in a CU or CU-CP)

See [F1 documentation](../F1-design.md) for information about the F1 split.
See [E1 documentation](../E1AP/E1-design.md) for information about the E1 split.

## RRC-specific configuration options

### UE-specific options

The following options have an incluence on the operation of the RRC, and
notably configuration of UEs:

In the `gNBs` section of the gNB/CU/CU-CP configuration file:

- `um_on_default_drb` (default: false): use RLC UM instead of RLC AM on default
  bearers
- `enable_sdap` (default: false): enable the use of the SDAP layer. If
  deactivated, a transparent SDAP header is prepended to packets, but no
  further processing is being done.
- `drbs`?
- `plmn`?
- `tac`?

### Neighbor-gNB configuration

    TODO

### RRC Measurement configuration

    TODO
