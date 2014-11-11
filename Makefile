TARGET       = pointer_chasing
CC           = g++
FLAGS        = -std=c++11
CCFLAGS      = -MMD -flto -Wall -Wextra -march=native
LDFLAGS      = -lm
RELEASEFLAGS = -O3 -fwhole-program -DNDEBUG
DEBUGFLAGS   = -O0 -ggdb3

ifdef DEBUG
    CCFLAGS += $(DEBUGFLAGS)
else
    CCFLAGS += $(RELEASEFLAGS)
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

