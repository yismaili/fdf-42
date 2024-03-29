# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yaskour <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/31 12:01:08 by yaskour           #+#    #+#              #
#    Updated: 2022/01/15 17:44:26 by yaskour          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

framework= -framework OpenGL -framework AppKit -g
NAME=fdf
cc = gcc
flags = -Wall -Wextra -Werror
SRCS = main.c\
	   drow.c\
	   read_maps.c\
	   key.c\

BONUS_SRCS = main_bonus.c\

OBJS =$(SRCS:.c=.o)
INCL= fdf.h

BONUS_OBJS =$(BONUS_SRCS:.c=.o)\
			draw.o\
			read.o\

GNL_SRC = get_next_line.c\
		  get_next_line_utils.c

GNL_OBJS =$(GNL_SRC:.c=.o)
GREY=$'\x1b[30m
GREEN=$'\x1b[32m
YELLOW=$'\x1b[33m
BLUE=$'\x1b[34m
PURPLE=$'\x1b[35m
CYAN=$'\x1b[36m
WHITE=$'\x1b[37m


all:utils $(NAME)

%.a:
	@echo " $(CYAN)MAKE $(YELLOW)$@\n"
	@make -C ./libft
	@mv ./libft/libft.a .

gnl:$(GNL_OBJS)

utils:gnl libft.a

%.o: %.c $(INCL)
	@$(cc) $(flags) $< -I $(INCL) -c
	@echo " $(CYAN)COMPILING $(YELLOW) $^ $(CYAN) to $(YELLOW)$@\n"

$(NAME):$(OBJS) utils
	@echo " \n$(BLUE)---------------------------------------------\n"
	@echo " $(CYAN)LINKING$(YELLOW) $(OBJS) $(GNL_OBJS) libft.a $(CYAN) to $(YELLOW) $(NAME)\n"
	@$(cc) $(flags) $(OBJS) $(GNL_OBJS) -lmlx $(framework) libft.a -o $(NAME)

bonus:$(BONUS_OBJS) utils
	@echo " \n$(BLUE)---------------------------------------------\n"
	@echo " $(GREEN)LINKING$(CYAN) $(BONUS_OBJS) $(GNL_OBJS) libft.a $(GREEN) to $(CYAN) $(NAME)\n"
	@$(cc) $(flags) $(BONUS_OBJS) $(GNL_OBJS) -lmlx  $(framework) libft.a -o $(NAME)

clean:
	@rm -rf *.o
	@rm -rf ./libft/*.o
	@rm -rf ./get_next_line/*.o

fclean:clean
	@rm -rf *.a
	@rm -rf fdf

re:fclean all

.PHONY: all gnl utils bonus clean fclean re
