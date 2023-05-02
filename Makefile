BIN := main
SOURCES := main.c
HEADERS := main.h
CFLAGS := 
LDFLAGS :=


CC := gcc

.PHONY: clean

all: $(BIN) 

$(BIN): $(SOURCES)
		$(CC) $(SOURCES) -o $(BIN) $(CFLAGS) $(LDFLAGS)
$(BIN): $(HEADERS)

clean:
		rm -rf $(BIN)