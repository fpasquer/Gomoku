/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 20:22:18 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/08 12:58:38 by fpasquer         ###   ########.fr       */
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
	Player_human			player2;
	Player_human			*ptr;

	if (argc == 3 && (port = atoi(argv[2])) >= MIN_PORT && port < MAX_PORT)
		player1.set_online(argv[1], port);

	std::string				key;
	Grid					grid;
	Window					win;

	ptr = &player1;
	while (1)
	{
		win.show(grid, *ptr, key);
		if (Key::getKey(key) == false)
			return (-1);
		if (ptr->checkKeySelect(key) == true)
		{
			grid.play(*ptr);
			if (player1.isOnline() == false)
				ptr = (ptr == & player1) ? &player2 : &player1;
		}
		if (key == KEY_ESC_)
			break ;
	}
	return (0);
}