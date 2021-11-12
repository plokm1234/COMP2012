CXX = g++

include default.mk

LIB_DIR = ../lib/macos
EXTRA_CXXFLAGS = -fsanitize=address,undefined

pa2: $(SRC_DIR)/main.cpp $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $(EXTRA_CXXFLAGS) -o $@ $(OBJ_FILES) $< \
	  -L$(LIB_DIR) -limgui-for-imtui -limtui -limtui-ncurses -lncurses -lpthread

run: pa2
	LD_LIBRARY_PATH=$(LIB_DIR):$LD_LIBRARY_PATH \
		./pa2 2>error.log

pa2_sample: $(SRC_DIR)/main.cpp $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $(EXTRA_CXXFLAGS) -o $@ $(OBJ_FILES) $< \
	  -L$(LIB_DIR) -limgui-for-imtui -limtui -limtui-ncurses -lncurses -lpthread

run_sample: pa2_sample
	LD_LIBRARY_PATH=$(LIB_DIR) \
	  TERMINFO=../share/terminfo \
	  TERM=xterm-256color \
		./pa2_sample "brass-sample.log" 2>sample_error.log
clean:
	rm -f *.o pa2

distclean: clean
	rm -f .depend.mk

-include .depend.mk
