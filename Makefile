CC = gcc
gambler-ruin:
	$(CC) -o  DrugTesting main.c
plot:data.dat
	gnuplot script.gp
clean:
	rm -f DrugTesting data.dat results.png