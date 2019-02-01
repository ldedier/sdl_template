# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/30 13:25:13 by ldedier           #+#    #+#              #
#    Updated: 2018/12/06 16:56:32 by ldedier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= sdl_template

CC      = gcc -g

PWD = $(shell pwd)

DEBUG ?= 0

SRCDIR   = srcs
OBJDIR   = objs
BINDIR   = .
INCLUDESDIR = includes

LIBFTDIR = libft
LIBFT_INCLUDEDIR = includes
LIBFT = $(LIBFTDIR)/libft.a

LIBMATDIR = libmat
LIBMAT_INCLUDEDIR = includes
LIBMAT = $(LIBMATDIR)/libmat.a

OK_COLOR = \x1b[32;01m
EOC = \033[0m

SRCS_NO_PREFIX =	main.c ft_init.c ft_loop.c ft_events.c ft_events_state.c\
					ft_render.c ft_process.c framerate.c

INCLUDES_NO_PREFIX = sdl_template.h

SOURCES = $(addprefix $(SRCDIR)/, $(SRCS_NO_PREFIX))

OBJECTS =	$(addprefix $(OBJDIR)/, $(SRCS_NO_PREFIX:%.c=%.o))

INCLUDES = $(addprefix $(INCLUDESDIR)/, $(INCLUDES_NO_PREFIX))

INC = -I $(INCLUDESDIR) -I $(LIBFTDIR)/$(LIBFT_INCLUDEDIR)\
	  -I $(LIBMATDIR)/$(LIBMAT_INCLUDEDIR) \
	  -I $(FRAMEWORKSDIR)/SDL2

FRAMEWORKSDIR = $(PWD)/frameworks

LFLAGS = -L $(LIBFTDIR) -lft -L $(LIBMATDIR) -lmat\
		 -Wl,-rpath $(FRAMEWORKSDIR)

CFLAGS =	-DPATH=\"$(PWD)\" -Wall -Wextra -Werror -Wno-error=unused-variable\
			-Wno-error=unused-parameter $(INC)\

ifeq ($(DEBUG), 1)
	LFLAGS += -fsanitize=address
	CFLAGS += -DDEBUG
	CC += -g3
endif

SDL2_FRAMEWORKS =	-framework SDL2 -framework SDL2_image \
					-framework SDL2_mixer -framework SDL2_ttf \
					-framework SDL2_net
opti:
	@make all -j8

all:
	@make -C $(LIBFTDIR) all
	@make -C $(LIBMATDIR) all
	@make $(BINDIR)/$(NAME)

debug:
	@make opti DEBUG=1

$(LIBFT):
	@make -C $(LIBFTDIR) all

$(LIBMAT):
	@make -C $(LIBMATDIR) all

$(BINDIR)/$(NAME): $(OBJECTS) $(LIBFT) $(LIBMAT)
	@$(CC) -o $@ $^ -F $(FRAMEWORKSDIR) $(SDL2_FRAMEWORKS) $(CFLAGS) $(LFLAGS)
	@echo "$(OK_COLOR)$(NAME) linked with success !$(EOC)"

$(OBJDIR)/%.o : $(SRCDIR)/%.c $(INCLUDES) 
	@mkdir -p $(OBJDIR)
	$(CC) -c $< -o $@ -F $(FRAMEWORKSDIR) $(CFLAGS)

clean:
	@make clean -C $(LIBMATDIR)
	@make clean -C $(LIBFTDIR)
	@rm -rf $(OBJDIR)

fclean: clean
	@make fclean -C $(LIBMATDIR)
	@make fclean -C $(LIBFTDIR)
	@rm -f $(BINDIR)/$(NAME)

re: fclean opti

.PHONY: all clean fclean re
