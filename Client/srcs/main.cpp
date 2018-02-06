/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 20:22:18 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/06 14:23:03 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Player.hpp"
#include "../incs/Cell.hpp"
#include "../incs/Grid.hpp"
#include "../incs/Key.hpp"
#include "../incs/Window.hpp"
#include <iostream>
#include <signal.h>
#include <exception>

int							main(void)
{
	Player					player1, player2;
	std::string				key;
	Window					win;

	Grid					grid;
	grid.play(player2);
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