add_executable(test_process
               test/test_process.cpp
               process.cpp)
target_compile_features(test_process PRIVATE cxx_std_17)
target_include_directories(test_process PRIVATE .)

add_test(NAME Project_03::TestProcess COMMAND test_process)
