CC = gcc
CXXFLAGS = -Wall -W -O2
TARGET = Runfile

OBJ = personal.o personal_add.o personal_delete.o personal_load.o personal_modify.o personal_print.o personal_sort.o
SRCS = $(OBJ:.o=.c)
# create out file (target name)
# before make obj
all: $(OBJ)
		$(CC) -o $(TARGET) $(CXXFLAGS) $(OBJ)

# create obj file (func name = obj name)
personal.o: personal.c
		$(CC) -c personal.c

personal_add.o: personal_add.c
		$(CC) -c personal_add.c

personal_delete.o: personal_delete.c
		$(CC) -c personal_delete.c

personal_load.o: personal_load.c
		$(CC) -c personal_load.c

personal_modify.o: personal_modify.c
		$(CC) -c personal_modify.c

personal_print.o: personal_print.c
		$(CC) -c personal_print.c

personal_sort.o: personal_sort.c
		$(CC) -c personal_sort.c

clean:
	rm -r *.o 
	rm -r $(TARGET)