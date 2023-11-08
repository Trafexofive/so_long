


$(CFLAGS) := -Wall -Wextra -Werror 

$(FILES) := so_long.c
$(OBJ) := $(FILES=.c=.o)
$(NAME) := so_long

all : $(NAME)


%.o: %.c 
	$(CC) $(CFLAGS) -Imlx -c $< -o $@
