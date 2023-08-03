
add_executable(test_transformer
               test/test_transformer.cpp
               Transformer.cpp)
target_link_libraries(test_transformer PRIVATE uno)
target_include_directories(test_transformer PRIVATE .)
target_compile_features(test_transformer PRIVATE cxx_std_17)

add_test(NAME TestTransformer COMMAND test_transformer)
