# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ede-sous <ede-sous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/09 01:59:12 by ede-sous          #+#    #+#              #
#    Updated: 2018/02/15 08:02:56 by ede-sous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	Urgatlen_Typer

ifeq (,$(shell command -v SDL2-config 2> /dev/null))
	SDL_EXEC := SDL2-config
else
	SDL_EXEC := sdl2-config
endif

LIBS_SDL	=	`$(SDL_EXEC) --libs` -lSDL2_image -lSDL2_ttf
GCC_FLAGS	=	gcc -Wall -Werror -Wextra

INCLUDES	=	-I./includes `$(SDL_EXEC) --cflags`

DIR_SRCS	=	srcs/
DIR_INIT	=	init/
DIR_KEYS	=	keys_manage/
DIR_OBJS_M	=	objs_manage/
DIR_PARSER	=	parser/

SRCS_INIT	=	main.c \
				x_InitSDL.c \
				x_InitTyper.c
SRCS_KEYS	=	x_KeyCharModifier.c \
				x_ValidKey_Char.c
SRCS_OBJS_M	=	x_AddDelChar.c \
				x_ModifyObject.c \
				x_ObjectPrinter.c
SRCS_PARSER	=	x_readtoi.c

SRCS_FILES	=	$(addprefix $(DIR_INIT), $(SRCS_INIT)) \
				$(addprefix $(DIR_KEYS), $(SRCS_KEYS)) \
				$(addprefix $(DIR_OBJS_M), $(SRCS_OBJS_M)) \
				$(addprefix $(DIR_PARSER), $(SRCS_PARSER))

SRCS		=	$(addprefix $(DIR_SRCS), $(SRCS_FILES))

OBJS		=	$(SRCS:.c=.o)

all : checkup $(NAME)

$(NAME): $(OBJS) $(INC) Makefile
	$(GCC_FLAGS) -o $(NAME) $(OBJS) $(INCLUDES) $(LIBS_SDL)

%.o : %.c
	gcc $(INCLUDES) -c -o $@ $<

checkup:
	@if [ "$(shell command -v brew 2> /dev/null)" = "" ]; then echo "brew is not installed - WARNING"; fi
	@if [ "$(shell command -v $(SDL_EXEC) 2> /dev/null)" = "" ]; then echo "SDL2 is not installed - ABORT" && exit 1; fi


clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re: fclean
	@make

.PHONY: re fclean clean checkup %.o %.c $(NAME) all 
