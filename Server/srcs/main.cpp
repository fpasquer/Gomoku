/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 18:37:01 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/10 11:53:42 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Gomoku_server.hpp"
#include "../incs/Server.hpp"
#include "../incs/Client.hpp"
#include "../incs/Fork_ia.hpp"
#include "../incs/Fork_lan.hpp"
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
	

	if (argc != 2 || (!((port = atoi(argv[1])) >= MIN_PORT && port < MAX_PORT)))
		usage(argv[0]);
	Server					server(port);
	Client					client;
	//Client					*tmp;

	while (1)
	{
		client.setNewClient(server);
		if (client.getTypeClient() == IA)
			Fork_ia			fork_ia(client);
		// else if (client.getTypeClient() == LAN)
		// {
		// 	if (tmp != NULL)
		// 	{
		// 		Fork_lan	forkLan(*tmp, client);
		// 		delete tmp;
		// 		tmp = NULL;
		// 	}
		// 	else
		// 		tmp = new Client::Client(client);
		// }
		else
			client.sendError();
	}
	return (0);
}