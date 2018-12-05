# MAKEFILE pour Cours sur les files de messages
#
#

#
# Directories
#
top_dir = .


#
# Object files
#

fich_obj_utlisateur = utilisateur.o hadamard.o

#
# Options for compilation
#

GCCOBJ = gcc -c
GCCLNK = gcc


# Option for debugger
opt = -g -Wall -D_DEBUG_
# opt = -O2 -Wall
#
#
#

#
#-------- Mains ---------------
#

utilisateur : $(fich_obj_utlisateur)
	$(GCCLNK) $(fich_obj_utlisateur) $(opt) -o utilisateur -I ./

utilisateur.o : utilisateur.c
	$(GCCOBJ) $(opt) utilisateur.c -o utilisateur.o -I ./

#
# --- Tests ---
#

#
#-------- Modules -------------
#


hadamard.o : hadamard.c hadamard.h
	$(GCCOBJ) $(opt) hadamard.c -o hadamard.o -I ./

#
#-------- Headers -------------
#

#
#-------- Clean objects -------
#

clean :
	rm -f *.o

#
#-------- All executables -------
#

all :   utilisateur

#
#-------- All tests -------
#

#
#-------- Tags -------
#

tags :
	etags *.c
