
add_library(uno INTERFACE)
target_include_directories(uno INTERFACE src)
target_compile_features(uno INTERFACE cxx_std_17)

add_executable(test_utility test/test_utility.cpp)
target_link_libraries(test_utility PRIVATE uno)
add_test(NAME TestUtility COMMAND test_utility)

add_executable(test_array test/test_array.cpp)
target_link_libraries(test_array PRIVATE uno)
add_test(NAME TestArray COMMAND test_array)

add_executable(test_type_traits test/test_type_traits.cpp)
target_link_libraries(test_type_traits PRIVATE uno)
add_test(NAME TestTypeTraits COMMAND test_type_traits)

add_executable(test_Clock test/test_Clock.cpp)
target_link_libraries(test_Clock PRIVATE uno)
add_test(NAME TestClock COMMAND test_Clock)

add_executable(test_algorithm test/test_algorithm.cpp)
target_link_libraries(test_algorithm PRIVATE uno)
add_test(NAME TestAlgorithm COMMAND test_algorithm)
