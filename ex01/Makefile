# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gprada-t <gprada-t@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/27 10:46:50 by gprada-t          #+#    #+#              #
#    Updated: 2024/07/28 11:39:34 by gprada-t         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FormUpMaggots

SRCS = Bureaucrat.cpp Form.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(OBJS:.o=.d)

CPPNDFLAGS = c++ -std=c++98 -Wall -Wextra -Werror -MMD -MP -fsanitize=address

all: $(NAME)

$(NAME): $(OBJS)
	$(CPPNDFLAGS) $(OBJS) -o $(NAME)

%.o:%.cpp %.hpp
	$(CPPNDFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(DEPS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include: $(DEPS)
