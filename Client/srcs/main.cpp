/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 20:22:18 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/24 14:56:09 by fpasquer         ###   ########.fr       */
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

typedef struct				s_sig_func
{
	int						sig;
	void					(*f)(int);
}							t_sig_func;

Window						win;

void						resize_win(int val)
{
	win.show_resize();
	val = (int)val;
}

void						init_signaux(void)
{
	unsigned int			i;
	t_sig_func const		sig_funcs[] = {
		{SIGWINCH, resize_win},
		{0, NULL}
	};

	for (i = 0; sig_funcs[i].f != NULL; i++)
		if (signal(sig_funcs[i].sig, sig_funcs[i].f) == SIG_ERR)
		{
			std::cout << "Signal error : " << strerror(errno) << std::endl;
			exit(-1);
		}
}

int							main(int argc, char **argv)
{
	int						port;
	Player_human			player1;
	Player_human			player2;
	Player_human			*player;

	if ((argc == 3 || argc == 4) && (port = atoi(argv[2])) >= MIN_PORT && port < MAX_PORT)
		player1.set_online(argv[1], port, argc == 3 ? "" : argv[3]);

	std::string				key = "";
	Grid					grid;
	init_signaux();

	player = &player1;
	while (key != KEY_ESC_)
	{
		if (grid.updateGrid(*player) == false)
			return (win.disconnected());
		win.show(grid, *player, key, (player == &player1) ? player2 : player1);
		if (Key::getKey(key) == false)
			return (-1);
		if (player->checkKeySelect(key) == true && grid.play(*player) == true)
		{
			if (grid.haveWin(*player) == true || grid.checkIaWin(*player) == true)
				break ;
			if (player1.isOnline() == OFFLINE)
				player = (player == &player1) ? &player2 : &player1;
		}
	}
	return (0);
}