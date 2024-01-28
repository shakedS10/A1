CC = gcc
AR = ar
MAIN = main.c
NUMCLASS = NumClass.h
BASIC_C = basicClassification.o
ADVANCDED_C = advancedClassificationLoop.o
ADVANCDED_C_R = advancedClassificationRecursion.o
FLAGS= -Wall -g

all: makeloops makerecursives makerecursived makelooped makemains makemaindloop makemaindrec

makeloops: libclassloops.a
libclassloops.a: $(ADVANCDED_C) $(BASIC_C)
	$(AR) -rcs libclassloops.a $(ADVANCDED_C) $(BASIC_C)

makerecursives: libclassrec.a
libclassrec.a: $(ADVANCDED_C_R) $(BASIC_C)
	$(AR) -rcs libclassrec.a $(ADVANCDED_C_R) $(BASIC_C)

makerecursived: libclassrec.so
libclassrec.so: $(ADVANCDED_C_R) $(BASIC_C)
	$(CC) -shared -o libclassrec.so $(ADVANCDED_C_R) $(BASIC_C)

makelooped: libclassloops.so
libclassloops.so: $(ADVANCDED_C) $(BASIC_C)
	$(CC) -shared -o libclassloops.so $(ADVANCDED_C) $(BASIC_C)

makemains: $(MAIN) libclassrec.a
	$(CC) $(FLAGS) -o mains $(MAIN) libclassrec.a

makemaindloop: $(MAIN)
	$(CC) $(FLAGS) -o maindloop $(MAIN) ./libclassloops.so

makemaindrec: $(MAIN)
	$(CC) $(FLAGS) -o maindrec $(MAIN) ./libclassrec.so

main.o: $(MAIN) $(NUMCLASS)
	$(CC) $(FLAGS) -c main.c

basicClassification.o: basicClassification.c $(NUMCLASS)
	$(CC) $(FLAGS) -fPIC -c basicClassification.c

advancedClassificationLoop.o: advancedClassificationLoop.c $(NUMCLASS)
	$(CC) $(FLAGS) -fPIC -c advancedClassificationLoop.c

advancedClassificationRecursion.o: advancedClassificationRecursion.c $(NUMCLASS)
	$(CC) $(FLAGS) -fPIC -c advancedClassificationRecursion.c


.PHONY: clean all

clean:
		rm -f *.o *.a *.so mains maindrec maindloop