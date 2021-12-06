main:main.o puts.o
	@gcc $^ -o $@
main.o:main.c
	@gcc -c $^ -o $@
puts.o:puts.c
	@gcc -c $^ -o $@

.PHONY:clean
clean:
	@rm *.o main