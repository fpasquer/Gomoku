/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 18:37:01 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/07 21:57:26 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Gomoku_server.hpp"
#include "../incs/Server.hpp"
#include "../incs/Fork_client.hpp"
#include <iostream>
#include <stdlib.h>
#include <signal.h>

void						usage(std::string str)
{
	std::cerr << str << " <port " << MIN_PORT << "<->"<< MAX_PORT << ">"<< std::endl;
	exit(-1);
}

int							main(int argc, char **argv)
{
	int						port;
	Fork_client				client;
	pid_t					pid;

	if (argc != 2 || (!((port = atoi(argv[1])) >= MIN_PORT && port < MAX_PORT)))
		usage(argv[0]);
	Server					server(port);

	while (1)
	{
		client.set_sock_client(server.accept_client());
		client.set_sock_server(server.get_sock_server());
		if ((pid = fork()) == -1)
			return (-1);
		else if (pid == 0)
			client.run_loop();
	}
	return (0);
}