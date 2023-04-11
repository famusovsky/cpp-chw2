add_subdirectory(string_processing)

add_library(for_time_measure_normal_lib
  kmp.cpp
  kmp_advanced.cpp
  kmp_standart.cpp
  naive.cpp
  algorithms.h
)

target_link_libraries(for_time_measure_normal_lib
  string_processing_ftm_n_lib
)