CC = g++
CXXFLAGS = -Wall -W -O2
TARGET = Runfile

OBJ = personal.o personal_add.o personal_print.o personal_delete.o personal_search.o personal_load.o personal_modify.o 

# create out file (target name)
# before make obj
all: $(OBJ)
		$(CC) -o $(TARGET) $(CXXFLAGS) $(OBJ)

# create obj file (func name = obj name)
personal.o: personal.cpp
		$(CC) -c personal.cpp

personal_add.o: personal_add.cpp
		$(CC) -c personal_add.cpp

personal_delete.o: personal_delete.cpp
		$(CC) -c personal_delete.cpp

personal_search.o: personal_search.cpp
		$(CC) -c personal_search.cpp

personal_load.o: personal_load.cpp
		$(CC) -c personal_load.cpp

personal_modify.o: personal_modify.cpp
		$(CC) -c personal_modify.cpp

personal_print.o: personal_print.cpp
		$(CC) -c personal_print.cpp

clean:
	rm -r *.o 
	rm -r $(TARGET)