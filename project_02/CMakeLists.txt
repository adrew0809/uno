add_executable(test_transformer
               test/test_transformer.cpp
               Transformer.cpp)
target_compile_features(test_transformer INTERFACE cxx_std_17)
target_link_libraries(test_transformer PRIVATE uno)
target_include_directories(test_transformer PRIVATE .)

add_test(NAME Project_02::TestTransformer COMMAND test_transformer)
