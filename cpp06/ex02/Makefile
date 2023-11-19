NAME = convert

SRC =	main.cpp \
		Base.cpp \
		A.cpp \
		B.cpp \
		C.cpp \

OBJ = ${SRC:.cpp=.o}

CC = c++

RM = rm -rf

FLAGS = -Wall -Wextra -Werror -std=c++98

HEADERS = Base.hpp A.hpp B.hpp C.hpp

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
