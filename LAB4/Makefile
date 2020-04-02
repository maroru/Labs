# Matthew Ruiz
# Makefile

APP_TARGET = demo

# directories
SRC_DIR		= src
LIB_DIR		= lib
INC_DIR		= include

# system dependencies
CFLAGS = -I $(INC_DIR)
CFLAGS += -MMD

# check operating system
ifeq ($(OS), Windows_NT)
	EXT = .exe
	RM = del
	CFLAGS += -std=c++11
	CXX = C:\usr\local\mingw32\bin\g++.exe
	PREFIX =
else
	EXT =
	PREFIX = ./
	RM = rm -f
	CXX = g++
	UNAME_S = $(shell uname -s)
	ifeq ($(UNAME_S), Darwin)
		CFLAGS += -std=c++11
	endif
	ifeq ($(UNAME_S), Linux)
		CFLAGS +=
	endif
endif

# file lists
SRC_FILES	= $(wildcard $(SRC_DIR)/*.cpp)
LIB_FILES	= $(wildcard $(LIB_DIR)/*.cpp)
SRC_OBJS	= $(SRC_FILES:.cpp=.o)
LIB_OBJS	= $(LIB_FILES:.cpp=.o)
ALL_OBJS	= $(SRC_OBJS) $(LIB_OBJS)
DEPENDS	= $(ALL_OBJS:.o=.d)

# build targets
.PHONY:
all:	$(APP_TARGET)$(EXT)

$(APP_TARGET)$(EXT):	$(SRC_OBJS) $(LIB_OBJS)
		$(CXX) -o $@ $(LFLAGS) $^

.PHONY:
clean:
		$(RM) $(APP_TARGET)$(EXT)
		$(RM) $(ALL_OBJECTS) $(DEPENDS)

.PHONY:
run:	$(APP_TARGET)
		$(PREFIX)$(APP_TARGET)

# implicit rules
%.o:	%.cpp
		$(CXX) -c $(CFLAGS) $< -o $@

-include $(DEPENDS)
