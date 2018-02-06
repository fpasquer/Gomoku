/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 20:22:18 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/06 12:41:07 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Player.hpp"
#include "../incs/Cell.hpp"
#include "../incs/Grid.hpp"
#include "../incs/Key.hpp"
#include "../incs/Window.hpp"
#include <iostream>

int							main(void)
{
	std::string				key = "ABCDEFG";
	Window					win;
	Player					player1;
	Grid					grid;

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