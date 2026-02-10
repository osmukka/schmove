CC := clang
CFLAGS := -O3 -I ./include
SRC_FILES := $(wildcard src/*.c)
TEST_FILES := $(wildcard test/*.c)


all:
	echo $(SRC_FILES)

#lib:



