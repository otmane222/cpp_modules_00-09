NAME = temple

SRC = main.cpp \

OBJ = $(SRC:.cpp=.o)

HEADER = 

CC = c++

RM = rm -rf

FLAGS = -Werror -Wall -Wextra -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(FLAGS) -o $(NAME)

%.c: %.o $(HEADER)
	$(CC) $(FLAGS) -o $< $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
