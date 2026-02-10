CC := clang
CFLAGS := -O3 -I./include

BIN_DIR := bin
BUILD_DIR := build
DIRS := bin build

SRC_DIR := src
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(SRC_FILES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
LIB_TARGET := $(BIN_DIR)/schmove.a

TESTS_DIR := tests
TESTS_SRC_FILES := $(SRC_FILES) $(wildcard $(TESTS_DIR)/*.c)
TESTS_OBJ_FILES := $(patsubst *.c, $(BUILD_DIR)/%.o, $(TESTS_SRC_FILES))
TESTS_TARGET := $(BIN_DIR)/tests_main

lib: $(LIB_TARGET)

$(LIB_TARGET): $(OBJ_FILES) | bin
	ar -rcs $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | build
	@echo $(OBJ_FILES)
	$(CC) $(CFLAGS) -c $< -o $@

tests: $(TESTS_TARGET)

$(TESTS_TARGET): $(TESTS_OBJ_FILES) | bin
	$(CC) $(CFLAGS) $^ -o $@


.PHONY: clean build bin

clean:
	@rm -rf build bin

build:
	@mkdir -p build
bin:
	@mkdir -p bin



