TARGET       = pointer_chasing
CC           = g++
FLAGS        = -std=c++11
CCFLAGS      = -MMD -flto -Wall -Wextra -march=native
LDFLAGS      = -lm
DEBUGFLAGS   = -O0 -ggdb3
RELEASEFLAGS = -O3 -fwhole-program -DNDEBUG

ifdef RELEASE
    CCFLAGS += $(RELEASEFLAGS)
else
    CCFLAGS += $(DEBUGFLAGS)
endif

SOURCES = $(wildcard src/*.cpp)
OBJECTS = $(addprefix build/,$(notdir $(SOURCES:.cpp=.o)))

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(FLAGS) $(CCFLAGS) -o $(TARGET) $(OBJECTS) $(LDFLAGS)

build/%.o: src/%.cpp
	$(CC) $(FLAGS) $(CCFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	-@rm $(TARGET) build/* 2>/dev/null || true

