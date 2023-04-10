cmake_minimum_required(VERSION 3.16)
project(chw2)

add_subdirectory(checker)
add_subdirectory(for_comp_count_measure)
add_subdirectory(for_time_measure)
add_subdirectory(task_execution)

add_executable(main
  main.cpp
)

target_link_libraries(main
  checker_lib
  for_comp_count_measure_normal_lib
  for_comp_count_measure_with_substs_lib
  for_time_measure_normal_lib
  for_time_measure_with_substs_lib
  task_execution_lib
)
