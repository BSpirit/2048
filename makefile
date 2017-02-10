all: 2048

fn:
	gcc -Wall -o 2048 fn.c 2048.c

mrproper: clean
	rm -rf 2048
