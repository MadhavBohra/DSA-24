matrix_generator.o : input_files/matrix_generator.c
	gcc -c input_files/matrix_generator.c

task5.o : task5.c
	gcc -c task5.c 

task5_exe : matrix_generator.o task5.o
	gcc -o task5_exe matrix_generator.o task5.o

task5 : task5_exe
	./task5_exe

clean :
	rm -f *.o
