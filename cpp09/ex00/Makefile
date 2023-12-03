NAME = btc

SRC = 	main.cpp \
		BitcoinExchange.cpp \

OBJS = $(SRC:.cpp=.o)

FLAGS = -Werror -Wextra -Wall -std=c++98

CC = c++

RM = rm -rf

HEADERS = BitcoinExchange.hpp

all: $(NAME) $(OBJS) $(HEADERS)

%.o: %.cpp $(HEADERS)
	$(CC) -c $(FLAGS) $< -o $@

$(NAME): $(OBJS) $(HEADERS)
	$(CC)  $(FLAGS) $(OBJS) -o $(NAME)


clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean