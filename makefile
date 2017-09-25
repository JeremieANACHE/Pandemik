CFLAGS = -Wall
CLIBS = -lglut -lGL -lGLU -lm -lX11


conway : conway.o moteur.o affichage.o BmpLibSupport.o
	gcc -o conway conway.o moteur.o affichage.o BmpLibSupport.o -Wall -g libisentlib.a $(CLIBS)

conway.o : conway.c conway.h moteur.h affichage.h BmpLibSupport.h
	gcc -c conway.c -Wall -g

moteur.o : moteur.c conway.h moteur.h BmpLibSupport.h
	gcc -c moteur.c -Wall -g

affichage.o : affichage.c conway.h affichage.h BmpLibSupport.h
	gcc -c affichage.c -Wall -g

BmpLibSupport.o:        BmpLibSupport.c BmpLibSupport.h
	gcc $(CFLAGS) -c BmpLibSupport.c



clean:
	rm -f main
	rm -f *.o
