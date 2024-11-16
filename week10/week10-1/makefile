CC = gcc
OBJ = main.o ui.o list.o
EXE = run

all: $(EXE)

.c.o:
	$(CC) -c $*.c

$(EXE): $(OBJ)
	$(CC) -o $@ $(OBJ)

clean:
	rm -rf $(EXE) *.o