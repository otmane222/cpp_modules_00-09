NAME = phonebook

SRC = main.cpp \
	  phonebook.cpp \
	  contact.cpp \

OBJ = $(SRC:.cpp=.o)

FLAGS = -Werror -Wextra -Wall -std=c++98

HEADERS = phonebook.hpp contact.hpp

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)

.o: .cpp
	c++ $(SRC) $(FLAGS) -o $(NAME)


clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)