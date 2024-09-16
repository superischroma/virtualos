EXE=vos.exe
OBJS=out/util.o out/log.o
LIBS=-lsdl2

default: $(EXE)

CC=gcc
CFLAGS=-g -Wall -pedantic
LDFLAGS=-g

$(EXE): out/main.o $(OBJS)
	$(CC) $(LDFLAGS) -o $(EXE) $^ $(LIBS)

out/%.o: src/%.c
	if not exist out mkdir out
	$(CC) -o $@ -c $(CFLAGS) $<

clean:
	rd /s /q out
	del /q $(EXE)