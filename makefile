all: 2048

fn:
	gcc -Wall -o 2048 main.c fn.c

mrproper: clean
	rm -rf 2048
