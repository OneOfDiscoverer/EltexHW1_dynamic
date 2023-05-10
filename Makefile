BIN := main
SOURCES := main.c list.c
HEADERS := main.h list.h
CFLAGS := -g
LDFLAGS :=


CC := gcc

.PHONY: clean

all: $(BIN) 

$LD_LIBRARY_PATH=$PWD:$LD_LIBRARY_PATH

$(BIN): $(SOURCES)
		$(CC) $(SOURCES) -o $(BIN) $(CFLAGS) $(LDFLAGS)
$(BIN): $(HEADERS)

clean:
		rm -rf $(BIN)