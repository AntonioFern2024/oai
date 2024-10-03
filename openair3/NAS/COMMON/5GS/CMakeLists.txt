add_subdirectory(5GMM/MSG)
add_subdirectory(5GSM/MSG)

set(FGS_LIBS
    5gmm_msg
    5gsm_msg
)

add_library(LIB_5GNAS)
target_link_libraries(LIB_5GNAS PUBLIC ${FGS_LIBS})
target_include_directories(LIB_5GNAS PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_DIR})
