/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ia_player.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 11:43:03 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/10 11:46:05 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Ia_player.hpp"

void						Ia_player::play
		(char const grid[SIZE_GRID][SIZE_GRID], unsigned int const depth, unsigned int &x, unsigned int &y)
{
	do
	{
		x = depth;
		x = rand() % SIZE_GRID;
		y = rand() % SIZE_GRID;
	}	while (grid[y][x] != EMPTY_CELL);
}
