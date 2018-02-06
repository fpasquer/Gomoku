# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/06 20:45:03 by fpasquer          #+#    #+#              #
#    Updated: 2018/02/06 20:48:57 by fpasquer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

All:
	make -C Client Gomoku_client
	make -C Server Gomoku_server

client:
	make -C Client Gomoku_client

server:
	make -C Server Gomoku_server

clean:
	make -C Client clean
	make -C Server clean

fclean: clean
	make -C Client fclean
	make -C Server fclean

re: fclean All