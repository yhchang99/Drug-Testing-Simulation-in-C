CC = gcc
gambler-ruin:
	$(CC) -o  DrugTesting main.c
plot:
	gnuplot -p script.gp
clean:
	rm -f DrugTesting data/data*.dat image/results.jpg