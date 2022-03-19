# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 13:09:38 by amenadue          #+#    #+#              #
#    Updated: 2022/03/19 18:23:37 by amenadue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mlft

all: i thankyou

install:
	-@printf "\e[92m>> mini libft header for development\e[0m\n"
	-@printf "\e[92m>> Attempting install for all users\e[0m\n"

verbose:
	-@print "[mlft] \n"

test:
	-@printf "Compiling test\n"
	-@gcc tester.c -o libfttest.a
	-@printf "Running Test"
	-@./libfttest.a

i: install

v: verbose

t: test

thankyou:
	-@printf "\e[97mThank You for installing ${NAME}\n"
