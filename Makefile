BIN := main
SOURCES := main.c
HEADERS := main.h

$(BIN): $(SOURCES)
		gcc $(SOURCES) -o $(BIN)
$(BIN): $(HEADERS)
