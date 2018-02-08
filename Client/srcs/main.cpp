/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 20:22:18 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/08 11:52:52 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Gomoku_client.hpp"
#include "../incs/Player_human.hpp"
#include "../incs/Client.hpp"
#include "../incs/Grid.hpp"
#include "../incs/Key.hpp"
#include "../incs/Window.hpp"
#include <iostream>
#include <signal.h>
#include <exception>

int							main(int argc, char **argv)
{
	int						port;
	Player_human			player1;

	if (argc == 3 && (port = atoi(argv[2])) >= MIN_PORT && port < MAX_PORT)
		player1.set_online(argv[1], port);
	// else
	// 	Player_human			player2;

	std::string				key;
	Grid					grid;
	Window					win;

	while (1)
	{
		win.show(grid, player1, key);
		if (Key::getKey(key) == false)
			return (-1);
		if (player1.checkKeySelect(key) == true)
			grid.play(player1);
		if (key == KEY_ESC_)
			break ;
	}
	return (0);
}