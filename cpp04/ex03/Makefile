NAME = world

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

SRCS =	main.cpp \
		AMateria.cpp \
		Character.cpp \
		Cure.cpp \
		Ice.cpp \
		MateriaSource.cpp \

OBJS = $(SRCS:.cpp=.o)

HEADERS =	AMateria.hpp Character.hpp Cure.hpp Ice.hpp ICharacter.hpp \
			IMateriaSource.hpp MateriaSource.hpp

all: $(NAME) $(OBJS) $(HEADERS)

%.o: %.cpp $(HEADERS)
	$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(OBJS) $(HEADERS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re