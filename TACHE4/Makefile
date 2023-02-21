CFLAGS = -lc
LDOPTS = -lm
EXECS:= test_eps

all: test_eps images

test_eps: test_eps.o geometrie2d.o robot.o image.o \
	contour.o eps.o
	$(CC) -o $@ $^ $(LDOPTS)

geometrie2d.o: ../TACHE2/geometrie2d.c
	$(CC) -c $^ -o $@

image.o: ../TACHE1/image.c
	$(CC) -c $^ -o $@

robot.o: ../TACHE3/robot.c
	$(CC) -c $^ -o $@

contour.o: ../TACHE3/contour.c
	$(CC) -c $^ -o $@

eps.o: eps.c
	$(CC) -c $^ -o $@

images: chat.eps image_ex_poly.eps coq.eps elephant.eps gymnaste.eps labyrinthe.eps lettreZ.eps map401.eps tete.eps test_eps

%.eps: ../TACHE3/%.pbm
	./test_eps $^ fill > $@

clean:
	rm -f $(IMAGES_EPS) $(EXECS) *.o
	rm -f chat.eps image_ex_poly.eps coq.eps elephant.eps gymnaste.eps labyrinthe.eps lettreZ.eps map401.eps tete.eps
