# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apergens <apergens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 12:04:58 by svachere          #+#    #+#              #
#    Updated: 2015/01/28 14:01:08 by svachere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = nvcc
CFLAGS = #-Wall -Wextra -Werror -g3
SRCSFILES = main.c \
			fractal.c \
			functions.c \
			hook.c \
			put.c \
			cudafractal.cu
SRCSDIR = srcs/
SRCS = $(addprefix $(SRCSDIR), $(SRCSFILES))
OBJSDIR = objs/
OBJSFILES = $(SRCSFILES:.c=.o)
OBJS = $(addprefix $(OBJSDIR), $(OBJSFILES))
HEADERS = srcs/fractol.h libft/libft.h libft/libftprintf.h
HEADERFLAGS = $(addprefix -I , $(dir $(HEADERS))) -I /opt/X11/include/
LIBS = libft/libft.a
LDFLAGS = -L libft/ -lft -lm -L /usr/X11/lib -lmlx -lXext -lX11

all: $(NAME)

$(NAME): $(OBJSDIR) $(LIBS) $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

$(OBJSDIR):
	mkdir $(OBJSDIR)

$(LIBS):
	$(MAKE) -C $(dir $@)

$(OBJSDIR)%.o: $(SRCSDIR)%.c $(HEADERS)
	$(CC) $(CFLAGS) $(HEADERFLAGS) -c -o $@ $<

clean:
	$(MAKE) -C libft/ $@
	/bin/rm -f $(OBJS)

fclean: clean
	$(MAKE) -C libft/ $@
	/bin/rm -f $(NAME)

re: fclean all

libftinstall:
	mkdir libft
	$(MAKE) libftupdate

libftupdate:
	cp ../libft/* libft
	$(MAKE) -C libft/ prepare

.PHONY: clean fclean re
