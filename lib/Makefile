MCU=atmega324pa
PROJECTNAME=library.a
PRJSRC= $(wildcard *.cpp)
# Niveau d'optimization
# Utilisez s (size opt), 1, 2, 3 ou 0 (off)
OPTLEVEL=s
AVRDUDE_PROGRAMMERID=usbasp
#compilateur utilise
CC=avr-gcc
#pour supprimer les fichiers lorsque l'on appel make clean
REMOVE=rm -f

####### Options de compilation #######

# Flags pour le compilateur en C
CFLAGS=-I. -I/usr/include/simavr  -MMD $(INC) -g -mmcu=$(MCU) -O$(OPTLEVEL) \
	-std=c++14 -fpack-struct -fshort-enums             \
	-funsigned-bitfields -funsigned-char    \
	-DF_CPU=8000000UL \
	-Wall                                        
# Flags pour le compilateur en C++
CXXFLAGS=-fno-exceptions     


#Nom des cibles par defaut
TRG=$(PROJECTNAME)

CFILES=$(filter %.c, $(PRJSRC))
# Fichier C++
CPPFILES=$(filter %.cpp, $(PRJSRC))
# Liste de tout les fichiers objet que nous devons creer
OBJDEPS=$(CFILES:.c=.o) \
	$(CPPFILES:.cpp=.o)


.PHONY: all clean 

# Make all permet simplement de compiler le projet
#
all: $(TRG) 

# Implementation de la cible
$(TRG): $(OBJDEPS)
	avr-ar crs $(TRG) $(OBJDEPS)

# Production des fichiers object
# De C a objet
%.o: %.c
	$(CC) $(CFLAGS) -c $<
# De C++ a objet
%.o: %.cpp
	$(CC) $(CFLAGS) $(CXXFLAGS) -c $<

# Verification des dependances (header dependencies)
-include *.d
# Make clean permet d'effacer tout les fichiers generes
# lors de la compilation
clean:
	$(REMOVE) $(TRG) $(OBJDEPS)  *.d

# Pour plus d'information sur les phony target, consulter:
# http://bit.ly/1WBQe61

# De plus, pour mieux comprendre les makefiles et 
# leur fonctionnement, consulter la documentation de GNU Make:
# http://bit.ly/23Vpk8s

# Finalement, ce tutoriel en ligne constitut une bonne 
# introduction au Makefile:
# http://bit.ly/1XvxsN3

#####                    EOF                   #####
