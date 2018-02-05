/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 20:22:18 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/05 23:17:13 by fpasquer         ###   ########.fr       */
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
	Player					player2;
	Grid					grid;

	player1.setX(2);
	player1.setY(3);
	grid.play(player1);
	player2.setX(3);
	player2.setY(3);
	grid.play(player2);
	std::cout << grid.show() << std::endl;
	win.show(grid.show(), grid.show());
	getch();

	// while (1)
	// {
	// 	if (Key::getKey(key) == false)
	// 		return (-1);
	// 	for (int i = 0; key[i] != '\n'; i++)
	// 		std::cout << (int)key[i] << std::endl;
	// 	std::cout << std::endl;
	// 	if (key.compare(KEY_ESC_) == 0)
	// 		break ;
	// }
	return (0);
}