NAME=main

#
OBJECTS = $(NAME).o persona.o crupier.o main.o jugador.o ruleta.o

#
CPPFLAGS = -c -g -Wall -ansi -O2

INCLUDES = persona.h crupier.h jugador.h ruleta.h

# Macros predefinidas
#
# $@: nombre del objetivo
# $^: todas las dependencias
# $<: primera dependencia
#

objetivo: $(NAME).exe

#Opciones para NO depurar los asertos
ndebug: CPPFLAGS += -DNDEBUG 
ndebug: objetivo

# Primer objetivo 
$(NAME).exe: $(OBJECTS)
			@echo "Generando " $@
			@g++ $^ -o $@
#
$(NAME).o: $(NAME).cc $(INCLUDES)
			@echo "Compilando " $<
			@g++ $(CPPFLAGS) $<

#
jugador.o: jugador.cc jugador.h 
			@echo "Compilando " $<
			@g++ $(CPPFLAGS) $<

#
persona.o: persona.cc persona.h 
			@echo "Compilando " $<
			@g++ $(CPPFLAGS) $<


#
crupier.o: crupier.cc crupier.h persona.h \

			@echo "Compilando " $<
			@g++ $(CPPFLAGS) $<

#
ruleta.o: ruleta.cc ruleta.h persona.h crupier.h jugador.h \

			@echo "Compilando " $<
			@g++ $(CPPFLAGS) $<
  
# Borrado
.PHONY: clean  
clean:
	@echo "Borrando los ficheros superfluos"
	@rm -f $(OBJECTS) *~ *.exe

