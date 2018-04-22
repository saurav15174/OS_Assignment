object = ls mkdir cat date rm
all : shell ls date cat mkdir rm
shell : shell.c
	gcc -o shell shell.c
ls : ls.c
	gcc -o ls ls.c
cat : cat.c
	gcc -o cat cat.c
date : date.c
	gcc -o date date.c
rm : rm.c
	gcc -o rm rm.c
mkdir : mkdir.c
	gcc -o mkdir mkdir.c
clean :
	rm mkdir cat ls date rm shell
