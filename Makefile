#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysushkov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/21 13:12:45 by ysushkov          #+#    #+#              #
#    Updated: 2018/09/21 13:12:50 by ysushkov         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	:=	menu

SRC		:= menu.c m_loadtexts.c menu_controls.c switch_fields.c

OBJ		:= $(SRC:.c=.o)

SDL		:= $(shell sdl2-config --cflags)

FLAGS	:= -g -Wall -Werror -Wextra

CGFLAGS = `sdl2-config --cflags --libs` -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lm

INCLUDES	=	-I./frameworks/SDL2.framework/Versions/A/Headers \
				-I./frameworks/SDL2_ttf.framework/Versions/A/Headers \
				-I./frameworks/SDL2_image.framework/Versions/A/Headers \
				-I./frameworks/SDL2_mixer.framework/Headers \
				-F./frameworks/

FRAMEWORKS	=	-F./frameworks \
				-rpath ./frameworks \
				-framework OpenGL -framework AppKit -framework OpenCl \
				-framework SDL2 -framework SDL2_ttf -framework SDL2_image \
				-framework SDL2_mixer

all:	$(NAME)

$(NAME): $(OBJ)
			gcc $(FLAGS) -o $(NAME) $(OBJ) $(SDL) $(FRAMEWORKS)

%.o: %.c
			gcc $(FLAGS) -o $@ $(INCLUDES) -c $^

clean:
		rm -f $(OBJ)

fclean:
		rm -rf $(OBJ)
		rm -f $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
