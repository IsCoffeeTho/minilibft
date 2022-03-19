# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amenadue <amenadue@student.42adel.org.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 13:09:38 by amenadue          #+#    #+#              #
#    Updated: 2022/03/19 06:32:59 by amenadue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mlft

all: i thankyou


install:
	-@printf "\e[92m>> mini libft header for development\e[0m\n"
	-@printf "\e[92m>> Attempting install for all users "

test:
	-@printf "Compiling test\n"
	-@gcc tester.c -o libfttest.a
	-@printf "Running Test"
	-@./libfttest.a

verbose:
	

i: install

v: verbose

thankyou:
	-@printf "\e[97mThank You for installing ${NAME}\n"
