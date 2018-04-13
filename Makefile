NAME = eval_expr

SRCS = eval_expr.c print.c

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRCS) -I header.h
	gcc $(FLAGS) *.o -o $(NAME)

clean:
	/bin/rm -f *.o
	
fclean: clean
	/bin/rm $(NAME)
	
re: fclean all
