PRNT = ./ft_printf/ft_print.c ./ft_printf/ft_printf.c
SRCS = server.c
SRCC = client.c

OBJS = $(SRCS:.c=.o)

OBJC = $(SRCC:.c=.o)

RM = rm -f

SERVER = server

CLIENT = client

all : $(SERVER) $(CLIENT)

.c.o:
		gcc -Wall -Werror -Wextra -I ./ -I ./ft_printf -c $< -o $(<:.c=.o)

$(SERVER) :	$(OBJS) $(PRNT)
		gcc -Wall -Werror -Wextra $(OBJS) $(PRNT) -I./ -o $(SERVER)

$(CLIENT) :	$(OBJC) $(PRNT)
		gcc -Wall -Werror -Wextra $(OBJC) $(PRNT) -I./ -o $(CLIENT)

clean :
		$(RM) $(OBJS) $(OBJC)

fclean :	clean
			$(RM) $(SERVER)
			$(RM) $(CLIENT)

re:			fclean all

.PHONY: all clean fclean re