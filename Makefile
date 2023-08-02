CPPFLAGS += -I.
CXXFLAGS +=-std=c++17 -Wall -Werror
CC=${CXX}

test/test_transformer : test/test_transformer.o Transformer.o

test/test_transformer.o : State.h Transformer.h utility.h

