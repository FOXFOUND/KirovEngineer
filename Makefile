all: mainapp.c
	gcc -o mainapp -Wall mainapp.c MainFrame.c `pkg-config --libs --cflags gtk+-2.0` -lcurl

run:
	./mainapp
	
clean:
	rm -rf mainapp.dSYM mainapp