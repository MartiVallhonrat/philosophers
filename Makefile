# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/29 12:25:41 by mvallhon          #+#    #+#              #
#    Updated: 2024/05/03 19:24:17 by mvallhon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers

GCC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

LIBFT = libs/libft

SRCS_FILES = main.c \
			 utils.c \
			 parse_args.c \
			 routine.c \
			 setter_utils.c \
			 handle_errors.c \
			 ft_litoa.c \

HEAD = philosophers.h
MAKE = Makefile

SRCS_DIR = srcs/
OBJS_DIR = objs/


OBJS_FILES = $(SRCS_FILES:.c=.o)
DEPS_FILES = $(SRCS_FILES:.c=.d)

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS = $(addprefix $(OBJS_DIR), $(OBJS_FILES))
DEPS = $(addprefix $(OBJS_DIR), $(DEPS_FILES))

all: make_libs $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p objs
	$(GCC) $(CFLAGS) -c -MMD $< -o $@

make_libs: $(OBJS) $(HEAD) $(MAKE)
	@make -C $(LIBFT)

$(NAME): $(OBJS) $(HEAD) $(MAKE)
	$(GCC) $(CFLAGS) $(OBJS) $(LIBFT)/libft.a -o $(NAME)

clean:
	$(RM) $(OBJS) $(DEPS)
	$(RM) -r $(OBJS_DIR)
	@make clean -C $(LIBFT)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)/libft.a

re: fclean all

-include $(DEPS)

.PHONY: clean fclean re all make_libs
