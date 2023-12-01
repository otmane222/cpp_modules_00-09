NAME = temple

SRC =	main.cpp \

OBJ = $(SRC:.cpp=.o)

HEADER = Array.hpp

CC = c++

RM = rm -rf

FLAGS = -Werror -Wall -Wextra -std=c++98

all: $(NAME) $(HEADER)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(FLAGS) $(OBJ)  -o $(NAME)

%.c: %.o $(HEADER)
	$(CC) -c $(FLAGS) -o $< $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
