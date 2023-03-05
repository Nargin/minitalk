SRC = main.c ./printf/ft_print.c ./printf/ft_printf.c

OBJS = $(SRC:.c=.o)

RM = rm -f

NAME = minitalk

all : $(NAME)

.c.o:
		gcc -Wall -Werror -Wextra -I ./ -I ./printf -c $< -o $(<:.c=.o)

$(NAME) :	$(OBJS)
		gcc -Wall -Werror -Wextra ${OBJS} -I./ -o ${NAME}

clean :
		$(RM) $(OBJS)

fclean :	clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re