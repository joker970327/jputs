CC = gcc
TARGET = main
SRC = $(wildcard ./*c)
# OBJ = main.o puts.o 
# OBJ = $(patsubst %.c, %.o, $(SRC)) 
OBJ = $(SRC:%.c=%.o) 
# FLAGS = -c


$(TARGET): $(OBJ)
	@$(CC) $(OBJ) -o $(TARGET)

%.o: %.c
	@$(CC) -c $< -o $@

.PHONY:clean
clean:
	@rm -f $(OBJ) $(TARGET)