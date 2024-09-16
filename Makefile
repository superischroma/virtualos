EXE=vos.exe
OBJS=out/util.o out/log.o out/vga.o out/terminal.o
LIBS=-lsdl2

default: $(EXE)

CC=gcc
CFLAGS=-g -Wall -pedantic
LDFLAGS=-g

$(EXE): out/main.o $(OBJS)
	$(CC) $(LDFLAGS) -o $(EXE) $^ $(LIBS)

out/%.o: src/%.c
	mkdir -p out
	$(CC) -o $@ -c $(CFLAGS) $<

clean:
	rm -rf out
	rm -f $(EXE)