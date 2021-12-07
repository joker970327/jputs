CC = gcc

main:main.o puts.o
	@$(CC) $^ -o $@
main.o:main.c
	@$(CC) -c $^ -o $@
puts.o:puts.c
	@$(CC) -c $^ -o $@

.PHONY:clean
clean:
	@rm -f *.o main