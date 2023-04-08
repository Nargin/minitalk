SRCS = server.c
SRCC = client.c

OBJS = $(SRCS:.c=.o)

OBJC = $(SRCC:.c=.o)

RM = rm -f

SERVER = server

CLIENT = client

all : $(SERVER) $(CLIENT)

.c.o:
		gcc -Wall -Werror -Wextra -I ./ -c $< -o $(<:.c=.o)

$(SERVER) :	$(OBJS)
		gcc -Wall -Werror -Wextra $(OBJS) -I./ -o $(SERVER)

$(CLIENT) :	$(OBJC)
		gcc -Wall -Werror -Wextra $(OBJC) -I./ -o $(CLIENT)

clean :
		$(RM) $(OBJS) $(OBJC)

fclean :	clean
			$(RM) $(SERVER)
			$(RM) $(CLIENT)

re:			fclean all

.PHONY: all clean fclean re
