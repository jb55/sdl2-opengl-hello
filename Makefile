NAME ?= sdl2-opengl-hello
BIN ?= $(NAME)
PREFIX ?= /usr/local
CFLAGS = -O2 -ggdb -Iinclude -Ideps -Wall -Wextra -std=c99 \
						-Wno-unused-function \
						-Wno-unused-parameter \
						-Wno-unused-variable \
						-Wno-cast-align \
						-Wno-padded
LDFLAGS = -lSDL2 -lGL

OUT=build
SRC=src

SRC  = $(wildcard src/*.c)
DEPS = $(wildcard deps/*/*.c)

ALL = $(SRC)
ALL += $(DEPS)

OBJS = $(ALL:.c=.o)

all: $(BIN)

%.o: %.c %.h
	$(CC) $(CFLAGS) -fPIC $(DEFS) -c $< -o $@

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(DEFS) $^ $(LDFLAGS) -o $@

install: $(BIN)
	install -d $(PREFIX)/bin
	install $(BIN) $(PREFIX)/bin

clean:
	rm -f $(OUT)/main.o $(OBJS) $(BIN)
