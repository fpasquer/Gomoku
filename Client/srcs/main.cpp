/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 20:22:18 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/07 09:34:23 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Gomoku_client.hpp"
#include "../incs/Player.hpp"
#include "../incs/Client.hpp"
#include "../incs/Cell.hpp"
#include "../incs/Grid.hpp"
#include "../incs/Key.hpp"
#include "../incs/Window.hpp"
#include <iostream>
#include <signal.h>
#include <exception>

void						usage(std::string str)
{
	std::cerr << str << " <addr> <port>" << std::endl;
	exit(-1);
}

int							main(int argc, char **argv)
{
	int						port;

	if (argc != 3 || (!((port = atoi(argv[2])) >= MIN_PORT && port < MAX_PORT)))
		usage(argv[0]);
	Client					client(argv[1], port);
	Player					player1;
	std::string				key;
	Window					win;
	Grid					grid;

	while (1)
	{
		win.show(grid, player1, key);
		if (Key::getKey(key) == false)
			return (-1);
		if (player1.checkKeySelect(key) == true)
			grid.play(player1, client);
		if (key == KEY_ESC_)
			break ;
	}
	return (0);
}