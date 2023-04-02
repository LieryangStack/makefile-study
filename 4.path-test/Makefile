SRC:= $(wildcard *.c)
SRC+= $(wildcard source/*.c)

OBJ:= $(SRC:.c=.o)

INC:= -I./include

test:$(OBJ)
	$(CC) $^ -o $@
%.o:%.c
	@$(CC) -c $< -o $@ $(INC)

clean:
	rm -rf $(OBJ)
