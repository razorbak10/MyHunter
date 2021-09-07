NAME	= my_hunter

CC	= gcc

RM	= rm -f

SRCS	= 	./main_game.c \
	  		./my_hunter.c 
			

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I 
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -l csfml-graphics -l csfml-audio -l csfml-window -l csfml-network -l csfml-system -o $(NAME) 

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
