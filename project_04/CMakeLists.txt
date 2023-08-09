add_executable(test_map
               test/test_map.cpp)
target_compile_features(test_map PRIVATE cxx_std_17)
target_include_directories(test_map PRIVATE .)
target_link_libraries(test_map PRIVATE uno)

add_test(NAME Project_04::TestMap COMMAND test_map)
