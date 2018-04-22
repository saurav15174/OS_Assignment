all : reader writer initialize

reader : reader.c
	gcc -o reader reader.c

writer: writer.c
	gcc -o writer writer.c
initialize : initialize.c
	gcc -o initialize initialize.c 
clean :
	rm initialize reader writer data.txt
