BIN := main
SOURCES := main.c
HEADERS := main.h

CC := gcc

.PHONY: clean

all: $(BIN) 

$(BIN): $(SOURCES)
		$(CC) $(SOURCES) -o $(BIN)
$(BIN): $(HEADERS)

clean:
		rm -rf $(BIN)