NAME = tests

SRC =	tests.cpp \
		Account.cpp \

OBJ = $(SRC:.cpp=.o)

FLAGS = -Werror -Wextra -Wall -std=c++98

HEADERS = Account.hpp

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)

.o:
	c++ $(SRC) $(FLAGS) -o $(NAME)


clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)