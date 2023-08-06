
add_library(uno INTERFACE)
target_include_directories(uno INTERFACE .)
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
