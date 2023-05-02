BIN := main
SOURCES := main.c
HEADERS := main.h

.PHONY: clean

all: $(BIN) 

$(BIN): $(SOURCES)
		gcc $(SOURCES) -o $(BIN)
$(BIN): $(HEADERS)

clean:
		rm -rf $(BIN)