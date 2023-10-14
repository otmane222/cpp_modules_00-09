NAME = fixed

SRC = main.cpp \
	  Fixed.cpp \

OBJS = $(SRC:.cpp=.o)

CC = c++

FLAGS = -Werror -Wextra -Wall -std=c++98

HEADERS = Fixed.hpp

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	$(CC) $(OBJS) $(FLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all