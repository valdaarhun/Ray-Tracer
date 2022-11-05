LIB_DIR = ./libs
SRC_DIR = ./src
OBJ_DIR = ./obj

CC=g++
CXXFLAGS=-Wall --std=c++1z -I${LIB_DIR}

SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
DEPS = $(wildcard $(LIB_DIR)/*.hpp)
BIN = tracer

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(DEPS)
	$(CC) $(CXXFLAGS) -c -o $@ $<

$(BIN): $(OBJ)
	$(CC) $(CXXFLAGS) -o $@ $^

.PHONY: clean
clean:
	$(RM) $(BIN) $(OBJ)