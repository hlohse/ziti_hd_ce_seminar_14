CC       = gcc
EMCC     = emcc
TARGET   = pointer_chasing
SOURCE   = mem_hierarchy.c
OBJECT   = $(SOURCE:%.c=%.o)
CCFLAGS  = -MMD -flto -Wall -Wextra -march=native
LDFLAGS  = 

OPTFLAGS = -O3 -fwhole-program -DNDEBUG
DEBFLAGS = -O0 -g

ifdef OPT
    CCFLAGS += $(OPTFLAGS)
else
    CCFLAGS += $(DEBFLAGS)
endif

all: c js

c: $(TARGET)

js: $(TARGET).js

$(TARGET): $(OBJECT)
	$(CC) $(CCFLAGS) -o $@ $(OBJECT)

$(TARGET).js: $(SOURCE)
	$(EMCC) $(CCFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	-@rm $(TARGET) $(TARGET).js* *.d *.o 2>/dev/null || true

