NAME = megaphone

SRC = megaphone.cpp \

OBJ = megaphone.o \

FLAGS = -Werror -Wextra -Wall -std=c++98

all: $(NAME)

$(NAME): $(OBJ)

.o: .cpp
	c++ $(SRC) $(FLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)