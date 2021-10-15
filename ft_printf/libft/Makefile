# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmustach <nmustach@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/17 16:38:23 by nmustach          #+#    #+#              #
#    Updated: 2021/09/19 16:21:52 by nmustach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

OBJDIR = objs/

SRCS = $(wildcard ft_*.c)

BIN = $(addprefix $(OBJDIR),$(SRCS:.c=.o))

HEAD = ./libft.h

all: $(NAME)

$(NAME):$(BIN)
	@echo 'Link libft'
	@ar rc $(NAME) $(BIN)
	@ranlib $(NAME)

$(OBJDIR)%.o : %.c $(HEAD)
	@mkdir -p $(OBJDIR)
	@gcc -Wall -Wextra -Werror -c $< -o $@
	@echo 'Compile $<'

clean:
	@echo 'Deleting object files...'
	@rm -rf $(OBJDIR)
	@echo 'Done'

fclean:
	@echo 'Deleting object files and libft.a ...'
	@rm -f $(NAME)
	@rm -rf $(OBJDIR)
	@echo 'Done'
	
re: fclean all