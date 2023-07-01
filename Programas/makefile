#Makefile modelo C++ adapitavel para C

#----------------------------Variáveis-------------------------

PROGRAMA=main

all: $(PROGRAMA)

COMPILAR=clang++

MAIN=main.cpp

HEARD=global.hpp


HRD=./hrd

SRC=./src

BIN=./bin

EXEC=$(BIN)/$(PROGRAMA)



#----------------------Texto dos arquivos----------------------

MAIN_TEXT='\#include "../hrd/$(HEARD)"\n\nint main(int argc,char* argv[]){\n\n\treturn 0;\n}'

HEARD_TEXT='\#pragma once\n\n\#include <iostream>\n\nusing std::cout;\nusing std::cin;\nusing std::string;\nusing std::ostream;'

#----------------------------Comandos--------------------------

*.o:*.hpp *.cpp
	$(COMPILAR)  -c  *.cpp 

main:*.o
	$(COMPILAR)  *.o -o $(PROGRAMA)


run: 
	./main

create:
	mkdir bin src hrd rcs;
	echo $(HEARD_TEXT) > $(HEARD);
	mv $(HEARD) $(HRD);
	echo $(MAIN_TEXT) > $(MAIN);
	mv $(MAIN) $(SRC);
	vim $(SRC)/$(MAIN);

clean:
	rm -f $(EXEC)

cleanObj:
	rm -f ./*.o
zip:
	zip -9 -r Prog_`date +'%A_%d_%B_%Y_%H_%M'` *

editar:
	vim ./$(SRC)/$(MAIN)

destroy:
	rm -r *
#-------------------------------------------------------------
