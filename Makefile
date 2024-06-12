SRC = src
UTILS = src/utils
BIN = bin
BUILD_DIR = build
DEBUG_DIR = $(BUILD_DIR)/Debug
RELEASE_DIR = $(BUILD_DIR)/Release

DEBUG_EXE = $(BIN)/test
DEBUG_OUT = $(DEBUG_DIR)/test.o
LIB_OUT = $(DEBUG_DIR)/libmenu.o
UTILS_OUT = $(DEBUG_DIR)/utils.o

all: clean Debug

$(DEBUG_EXE):$(DEBUG_OUT) $(UTILS_OUT) $(LIB_OUT)
	cc $(DEBUG_OUT) $(UTILS_OUT) $(LIB_OUT) -o $(DEBUG_EXE)

$(DEBUG_DIR)/%.o:$(SRC)/%.c
	cc -c -o $@ $<

Debug:$(DEBUG_EXE)
	./$(DEBUG_EXE)

Release: $(SRC)/libmenu.c $(SRC)/libmenu.h
	mkdir -p $(RELEASE_DIR)
	cp $(SRC)/libmenu.* $(RELEASE_DIR)

$(UTILS_OUT):$(UTILS)/utils.c
	cc -c -o $@ $<

clean:
	rm -f $(DEBUG_DIR)/*
	mkdir -p $(DEBUG_DIR)
	mkdir -p $(BIN)