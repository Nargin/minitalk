SRCS = server.c ./printf/ft_print.c ./printf/ft_printf.c
SRCC = client.c ./printf/ft_print.c ./printf/ft_printf.c

OBJS = $(SRCS:.c=.o)

OBJC = $(SRCC:.c=.o)

RM = rm -f

SERVER = server

CLIENT = client

all : $(SERVER) $(CLIENT)

.c.o:
		gcc -Wall -Werror -Wextra -I ./ -I ./printf -c $< -o $(<:.c=.o)

$(SERVER) :	$(OBJS)
		gcc -Wall -Werror -Wextra ${OBJS} -I./ -o ${SERVER}

$(SERVER) :	$(OBJC)
		gcc -Wall -Werror -Wextra ${OBJC} -I./ -o ${CLIENT}

clean :
		$(RM) $(OBJS)

fclean :	clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re