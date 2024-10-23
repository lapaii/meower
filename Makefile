CC	= gcc
RM	= rm -f

default: all

all: build

build:
	$(CC) -o meower src/main.c

clean:
	$(RM) meower
