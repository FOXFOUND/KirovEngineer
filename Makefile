all: mainapp.c
	gcc -o mainapp mainapp.c `pkg-config --libs --cflags gtk+-2.0` -lcurl

run:
	./mainapp
	
clean:
	rm -rf mainapp.dSYM mainapp