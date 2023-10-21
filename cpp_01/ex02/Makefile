NAME = go

SRC = main.cpp \

OBJS = $(SRC:.cpp=.o)

CC = c++

FLAGS = -Werror -Wextra -Wall -std=c++98


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(FLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all