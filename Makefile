# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anhloba <anhloba@student.unit.ua>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/30 16:03:56 by anhloba           #+#    #+#              #
#    Updated: 2018/09/26 13:52:27 by anhloba          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RT

SRC_RT = main.c \
		errors.c \
		inits.c \
		events.c \
		events1.c \
		events2.c \
		oper_vek.c \
		oper_vek1.c \
		oper_vek2.c \
		init_figur.c \
		init_figur_help.c \
		dop_init1.c \
		dop_init2.c \
		color.c \
		color_efects1.c \
		color_efects2.c \
		math_func.c \
		closest.c \
		liting.c \
		tracer.c \
		init_light.c \
		init_light1.c \
		tracer_obj.c \
		tracer_obj1.c \
		get_normal.c \
		get_normal1.c \
		rotation.c \
		parsing.c \
		pars_atoi.c \
		pars_fig.c \
		pars_fig_help.c \
		pars_fig_help_2.c \
		pars_fig_help_3.c \
		pars_fig_help_4.c \
		pars_fig_close.c \
		blur.c \
		torus.c \
		mebius.c \
		quadric.c \
		priveden.c \
		bikvadrat.c \
		resolventa.c \
		texture.c \
		texture1.c \
		texture_help.c \
		texture_fig.c \
		switch_fields.c \
		m_loadtexts.c \
		m_img_read.c \
		m_event_listener.c \
		menu_controls.c

OBJ_D = obj/
OBJECT_RT = $(addprefix $(OBJ_D), $(SRC_RT:.c=.o))

FLAGS = -Wall -Wextra -Werror

INCLUDES_RT = -I ./includes/

INCLUDES_LIBFT = -I ./src/libft/includes

INCLUDES_SDL2 = -I ./src/SDL/SDL2.framework/Headers

INCLUDES_SDL2_IMAGE = -I ./src/SDL/SDL2_image.framework/Headers

INCLUDES_SDL2_MIXER = -I ./src/SDL/SDL2_mixer.framework/Headers

LIBFT = ./src/libft/libft.a

INCLUDES_SDL2_TTF = -I ./src/SDL/SDL2_ttf.framework/Headers

FRAMEWORK_SDL2 = -F ./src/SDL -framework SDL2 \
	-framework SDL2_image \
	-framework SDL2_ttf \
	-framework SDL2_mixer

FRAMEWORK_MLX = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME) : $(OBJECT_RT)
	@ make -C ./src/libft
	@ gcc -o $(NAME) $(FLAGS) $(LIBFT) $(INCLUDES_SDL2) $(INCLUDES_SDL2_IMAGE) -rpath @loader_path/src/SDL $(FRAMEWORK_SDL2) $(OBJECT_RT) $(INCLUDES_SDL2_TTF) $(INCLUDES_SDL2_MIXER)
	@ echo "RT compiled"

$(OBJECT_RT): | $(OBJ_D)

$(OBJ_D):
	mkdir $(OBJ_D)

$(OBJ_D)%.o: %.c includes/rt.h
	@ gcc -g $(FLAGS) -o $@ -c $< $(INCLUDES_RT) $(INCLUDES_SDL2) $(INCLUDES_LIBFT) \
	$(INCLUDES_SDL2_IMAGE) $(INCLUDES_SDL2_TTF) $(INCLUDES_SDL2_MIXER)

$(OBJ_D)%.o: %.c
	@ gcc -g 	$(FLAGS) -o $@ -c $< $(INCLUDES_RT) $(INCLUDES_SDL2) $(INCLUDES_LIBFT) \
	$(INCLUDES_SDL2_IMAGE) $(INCLUDES_SDL2_TTF) $(INCLUDES_SDL2_MIXER)

clean:
	@ make -C ./src/libft clean
	@ /bin/rm -f $(OBJECT_RT)

fclean: clean
	@ make -C ./src/libft fclean
	@ /bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re