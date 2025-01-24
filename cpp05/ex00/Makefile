
NAME			=			Bureaucrat

SRCS			=			Bureaucrat.cpp main.cpp

CC				=			c++

CFLAGS			=			-Wall -Wextra -Werror -std=c++98

RM				=			rm -rf

OBJS			=			$(SRCS:.cpp=.o)

all				:			$(NAME)

$(NAME)			:			$(OBJS)
								$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o				:			%.cpp
								$(CC) $(CFLAGS) -c $< -o $@

clean			:
								$(RM) $(OBJS)

fclean			:			clean
								$(RM) $(NAME)

re				:			fclean all

prog			:			all clean
									clear
											
.PHONY			:			all clean fclean re