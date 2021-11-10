CFLAGS = -std=c99 -lxcb
main:main.c
	gcc main.c ${CFLAGS} -o main

clean:
	rm -rf main
