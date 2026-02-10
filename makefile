CC := clang
CFLAGS := -O3 -I./include

BIN_DIR := bin
BUILD_DIR := build
DIRS := bin build

SRC_DIR := src
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(patsubst *.c, $(BUILD_DIR)/%.o, $(SRC_FILES))
LIB_TARGET := $(BIN_DIR)/schmove.a

TESTS_DIR := tests
TESTS_SRC_FILES := $(SRC_FILES) $(wildcard $(TESTS_DIR)/*.c)
TESTS_OBJ_FILES := $(patsubst *.c, $(BUILD_DIR)/%.o, $(TESTS_SRC_FILES))
TESTS_TARGET := $(BIN_DIR)/tests_main

$(DIRS):
	mkdir -p $@

lib: $(LIB_TARGET) | $(DIRS)

$(LIB_TARGET): $(OBJ_FILES)
	ar -rcs $@ $^

tests: $(TESTS_TARGET) | $(DIRS)

$(TESTS_TARGET): $(TESTS_OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@


$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	@rm -rf build bin



