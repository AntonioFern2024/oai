set(5GMM_MSG_SRC
    RegistrationRequest.c
    RegistrationAccept.c
    FGSIdentityResponse.c
    FGSAuthenticationResponse.c
    FGSNASSecurityModeComplete.c
    RegistrationComplete.c
    FGSUplinkNasTransport.c
    FGSDeregistrationRequestUEOriginating.c
)

add_library(5gmm_msg ${5GMM_MSG_SRC})
