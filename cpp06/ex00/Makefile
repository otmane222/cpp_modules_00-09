NAME = convert

SRC =	main.cpp \
		ScalarConverter.cpp 

OBJ = ${SRC:.cpp=.o}

CC = c++

RM = rm -rf

FLAGS = -Wall -Wextra -Werror -std=c++98

HEADERS = 

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CC) -c $(FLAGS)  $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re all clean fclean
