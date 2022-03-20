# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 13:09:38 by amenadue          #+#    #+#              #
#    Updated: 2022/03/20 19:55:21 by amenadue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mlft

all: testandinstall

install:
	-@printf "\e[92m>> mini libft header for development\e[0m\n"
	-@printf "\e[92m>> Attempting to install for all users\e[0m\n"

verbose:
	-@print "[mlft] \n"

i: install

v: verbose