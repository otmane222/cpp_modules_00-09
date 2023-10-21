NAME = pointref

SRC = main.cpp \
	  HumanA.cpp \
	  HumanB.cpp \
	  Weapon.cpp \

OBJS = $(SRC:.cpp=.o)

CC = c++

FLAGS = -Werror -Wextra -Wall -std=c++98

HEADERS = Weapon.hpp HumanA.hpp HumanB.hpp

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	$(CC) $(OBJS) $(FLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all