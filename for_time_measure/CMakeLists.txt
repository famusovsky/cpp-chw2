add_subdirectory(string_processing)

add_library(for_time_measure_lib
  kmp_advanced.cpp
  kmp_simple.cpp
  naive.cpp
  algorithms.h
)

target_link_libraries(for_time_measure_lib
  string_processing_ftm_lib
)