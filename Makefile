BUILD_DIR = build
DEBUG_DIR = $(BUILD_DIR)/Debug
RELEASE_DIR = $(BUILD_DIR)/Release

DEBUG_OUT = $(DEBUG_DIR)/outDebug
LIB_OUT = $(DEBUG_DIR)/libmenu.o
UTILS_OUT = $(DEBUG_DIR)/utils.o
LIB_LINK = $(DEBUG_DIR)/libmenu.a

all: clean lib Debug

$(DEBUG_OUT):$(DEBUG_DIR)/main.o $(UTILS_OUT) $(LIB_LINK)
	cc $(DEBUG_DIR)/main.o $(UTILS_OUT) $(LIB_LINK) -o $(DEBUG_OUT)

$(DEBUG_DIR)/%.o:%.c
	mkdir -p $(DEBUG_DIR)
	cc -c -o $@ $<

Debug:$(DEBUG_OUT)
	./$(DEBUG_OUT)

lib:$(LIB_OUT)
	ar ruv $(LIB_LINK) $(LIB_OUT)
	ranlib $(LIB_LINK)

clean:
	rm -rf $(BUILD_DIR)