assembler: assembler.o symboltable.o ainstr.o cinstr.o assemblatore.o
	gcc -o assembler assembler.o symboltable.o ainstr.o cinstr.o assemblatore.o

assembler.o: assembler.c assemblatore.h
	gcc -c assembler.c 
	
assemblatore.o: assemblatore.c assemblatore.h ainstr.h cinstr.h 
	gcc -c assemblatore.c
	
cinstr.o: cinstr.c cinstr.h ainstr.h 
	gcc -c cinstr.c	

ainstr.o: ainstr.c ainstr.h 
	gcc -c ainstr.c
	
symboltable.o: symboltable.c symboltable.h
	gcc -c symboltable.c

clean:
	rm *.o assembler
