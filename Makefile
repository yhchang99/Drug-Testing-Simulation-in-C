CC = gcc
gambler-ruin:
	$(CC) -o  DrugTesting main.c
clean:
	rm -f DrugTesting results.dat