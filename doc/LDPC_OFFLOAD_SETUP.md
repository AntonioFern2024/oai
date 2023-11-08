<table style="border-collapse: collapse; border: none;">
  <tr style="border-collapse: collapse; border: none;">
    <td style="border-collapse: collapse; border: none;">
      <a href="http://www.openairinterface.org/">
         <img src="./images/oai_final_logo.png" alt="" border=3 height=50 width=150>
         </img>
      </a>
    </td>
    <td style="border-collapse: collapse; border: none; vertical-align: center;">
      <b><font size = "5">OAI T1/T2 LDPC offload</font></b>
    </td>
  </tr>
</table>

**Table of Contents**

[[_TOC_]]

This documentation aims to provide a tutorial for AMD Xilinx T2 Telco card integration into OAI and its usage.
## Prerequisites
Offload of the channel decoding was tested with the T2 card in following setup:

**AMD Xilinx T2 card**
 - bitstream image and PMD driver provided by AccelerComm
 - DPDK 20.11.3 with patch from Accelercomm (also tested with DPDK 20.11.7
   version)
 - tested on RHEL7.9, RHEL9.2, Ubuntu 20.04, Ubuntu 22.04


## DPDK setup

 - check the presence of the card on the host
	 - `lspci | grep "Xilinx"`
 - binding of the device with igb_uio driver
	 - `./dpdk-devbind.py -b igb_uio <address of the PCI of the card>`
 - hugepages setup (10 x 1GB hugepages)
	 - `./dpdk-hugepages.py -p 1G --setup 10G`

*Note: Commands to run from dpdk/usertool folder*

## Compilation
Deployment of the OAI is precisely described in the following tutorials.
 - [BUILD](https://gitlab.eurecom.fr/oai/openairinterface5g/-/blob/develop/doc/BUILD.md)
 - [NR_SA_CN5G_gNB_USRP_COTS_UE_Tutorial](https://gitlab.eurecom.fr/oai/openairinterface5g/-/blob/develop/doc/NR_SA_Tutorial_COTS_UE.md)

Shared object file *libldpc_t2.so* is created  during the compilation. This objects is conditionally compiled. Selection of the library to compile is done using *--build-lib ldpc_t2*. Sample command to build OAI with support for LDPC offload to T2 card is:

`./build_oai -P --gNB -w USRP --build-lib "ldpc_t2" --ninja`

*Required DPDK version  has to be installed on the host, prior to the build of OAI*

## nr_ulsim test
Offload of the channel decoding is in nr_ulsim specified by *-o* option followed by the version of the card. Example command for running nr_ulsim with offload to the T2 card:

`./nr_ulsim -n100 -s20 -m20 -r273 -o _t2`


### LDPC encoding/decoding with CPU/GPU
Available LDPC implementations and loading particular libraries is well described in *openair1/PHY/CODING/DOC/LDPCImplementation.md*. Default library for LDPC processing is called `libldpc.so`. Sample command for running nr-softmodem with selected library (in this case we want to replace `libldpc.so` by `libldpc_optim.so` library): 
`./nr-softmodem -O config_file.conf --sa --loader.ldpc.shlibversion _optim`
Available options: 
- --loader.ldpc.shlibversion _optim8seg
- --loader.ldpc.shlibversion _optim
- --loader.ldpc.shlibversion _orig
- --loader.ldpc.shlibversion _cuda
- --loader.ldpc.shlibversion _cl


### LDPC decoding offload to AMD Xilinx T1 and T2 accelerator cards
Library for the LDPC decoder is selected by *--ldpc.shlibversion* option, followed by the version of the card - *_t2*. Sample command for running nr_ulsim with offload to the T2 card:

`./nr-softmodem -O config_file.conf --sa --ldpc.shlibversion _t2`

## Limitations
### AMD Xilinx T1 card
 - offload of the LDPC decoding implemented only for MCS > 9, decoding of the smaller TBs on the T1 card leads to blocking of the card
 - HARQ is not functional with LDPC decoding offload to the T1 card (restricted in the code to avoid blocking of the card)
 - LDPC encoding offload not implemented for the T1 card
 - not supported in current develop branch, please checkout to *2023.w41*
### AMD Xilinx T2 card
 - offload of the LDPC encoding implemented only for MCS > 9, encoding in case of MCS < 9 leads to the blocking of the card, there is still an ongoing work to fix this issue
