# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcochin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/02 13:54:33 by mcochin           #+#    #+#              #
#    Updated: 2022/08/31 14:17:55 by mcochin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
NAMEB = fractol_bonus

SRCS = src/main.c \
	src/events.c \
	src/fractal.c \
	src/images.c
SRCSB = src_bonus/main_bonus.c \
	src_bonus/events_bonus.c \
	src_bonus/fractal_bonus.c \
	src_bonus/images_bonus.c \
	src_bonus/palette_bonus.c \
	src_bonus/palette2_bonus.c
OBJS = $(SRCS:.c=.o)
OBJSB = $(SRCSB:.c=.o)

LIBFT = libft
LIBFTPATH = libft/libft.a
MLX = minilibx
MLXPATH = minilibx/libmlx.a

CC = gcc
CFLAGS = -O3 -Werror -Wextra -Wall
MLXFLAGS = -Imlx_linux -lXext -lX11 -lm -lz
RM = rm -f
MAKE = make -C

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFTPATH) $(MLXPATH)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFTPATH) $(MLXPATH) $(MLXFLAGS)

bonus : $(OBJSB) $(LIBFTPATH) $(MLXPATH)
	@$(CC) $(CFLAGS) -o $(NAMEB) $(OBJSB) $(LIBFT)/libft.a $(MLX)/libmlx.a $(MLXFLAGS)

$(LIBFTPATH) :
	@$(MAKE) $(LIBFT) --no-print-directory

$(MLXPATH) :
	@$(MAKE) $(MLX) --no-print-directory -s

clean :
	@$(RM) $(OBJS) fractol.so
	@$(RM) $(OBJSB) fractol_bonus.so
	@$(MAKE) $(LIBFT) clean
	@$(MAKE) $(MLX) clean

fclean : clean
	@$(RM) $(NAME)
	@$(RM) $(NAMEB)
	@$(RM) $(LIBFT)/libft.a
	@$(RM) $(MLX)/libmlx.a
	@echo DONE

re : fclean $(NAME)

f : fclean

r : all
	@clear
	@./$(NAME)

.PHONY: all fclean re clean
