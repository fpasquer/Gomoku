/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 20:22:18 by fpasquer          #+#    #+#             */
/*   Updated: 2018/03/04 16:51:57 by fpasquer         ###   ########.fr       */
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

Window						*get_win(void)
{
	static Window			*win = NULL;
	
	if (win == NULL)
	{
		try
		{
			if ((win = new Window) == NULL)
				throw Error("Error window create");
		}
		catch (std::exception const&e)
		{
			clear();
			printw("%s", e.what());
			getch();
			exit(-1);
		}
	}
	return (win);
}

typedef struct				s_sig_func
{
	int						sig;
	void					(*f)(int);
}							t_sig_func;

void						resize_win(int val)
{
	Window					*win = get_win();

	win->show_resize();
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
	Window					*win = get_win() ;
	init_signaux();

	player = &player1;
	while (key != KEY_ESC_)
	{
		if (grid.updateGrid(*player) == false)
			return (win->disconnected());
		win->show(grid, *player, key, (player == &player1) ? player2 : player1);
		if (Key::getKey(key) == false)
			break ;
		if (player->checkKeySelect(key) == true && grid.play(*player) == true)
		{
			if (grid.checkIaWin(*player) == true)
				break ;
			if (player1.isOnline() == OFFLINE)
				player = (player == &player1) ? &player2 : &player1;
		}
	}
	delete win;
	return (0);
}