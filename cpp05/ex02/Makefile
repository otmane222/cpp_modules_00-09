NAME = exception

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

SRCS =	main.cpp \
		Bureaucrat.cpp \
		AForm.cpp \
		ShrubberyCreationForm.cpp \
		RobotomyRequestForm.cpp \
		PresidentialPardonForm.cpp \

OBJS = $(SRCS:.cpp=.o)

HEADERS =	Bureaucrat.hpp AForm.hpp  ShrubberyCreationForm.hpp \
			RobotomyRequestForm.hpp PresidentialPardonForm.hpp

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

.PHONY: clean fclean re