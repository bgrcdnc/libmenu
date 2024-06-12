BUILD_DIR = build
DEBUG_DIR = $(BUILD_DIR)/Debug
RELEASE_DIR = $(BUILD_DIR)/Release

DEBUG_OUT = $(DEBUG_DIR)/outDebug
LIB_OUT = $(DEBUG_DIR)/libmenu.o
UTILS_OUT = $(DEBUG_DIR)/utils.o

all: clean Debug

$(DEBUG_OUT):$(DEBUG_DIR)/main.o $(UTILS_OUT) $(LIB_OUT)
	cc $(DEBUG_DIR)/main.o $(UTILS_OUT) $(LIB_OUT) -o $(DEBUG_OUT)

$(DEBUG_DIR)/%.o:%.c
	mkdir -p $(DEBUG_DIR)
	cc -c -o $@ $<

Debug:$(DEBUG_OUT)
	./$(DEBUG_OUT)

clean:
	rm -rf $(BUILD_DIR)