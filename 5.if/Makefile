libs_for_gcc:= 
normal_libs:= -lmosquitto

SRC:= $(wildcard *.c)
SRC+= $(wildcard source/*.c)
# SRC += $(shell ls source/*.c)
OBJ:= $(SRC:.c=.o)

INC:= -I./include

test:$(OBJ)
ifeq ($(CC),cc)
		$(CC) $^ -o $@ $(libs_for_gcc)
else
		$(CC) $^ -o $@ $(normal_libs)
endif
%.o:%.c
	$(CC) -c $< -o $@ $(INC)


.PHONY : testif
bar = 
foo = $(OBJ)
testif:
ifdef bar
	@echo yes
else
	@echo no
endif


.PHONY : clean
clean:
	rm -rf $(OBJ)

