add_subdirectory(utils)

configure_file(oai_version.h.in oai_version.h @ONLY)

add_library(instrumentation INTERFACE instrumentation.h)
target_include_directories(instrumentation INTERFACE .)
if (ENABLE_TRACY)
  target_link_libraries(instrumentation INTERFACE Tracy::TracyClient)
endif()
