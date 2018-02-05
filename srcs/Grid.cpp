/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Grid.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 21:33:00 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/05 21:55:58 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Grid.hpp"

							Grid::Grid(void) : m_border(SIZE_GRID * 4 + 1, '-')
{
	unsigned int			x;
	unsigned int			y;

	for (x = 0; x < SIZE_GRID; x++)
		for (y = 0; y < SIZE_GRID; y++)
			m_cell[x][y] = new Cell(x, y);
}

std::string					Grid::show(void) const
{
	std::string				ret;
	unsigned int			x;
	unsigned int			y;

	ret = m_border + "\n";
	for (x = 0; x < SIZE_GRID; x++)
	{
		for (y = 0; y < SIZE_GRID; y++)
			ret += "| " + m_cell[x][y]->getVal() + " ";
		ret += "|\n" + m_border + "\n";
	}
	return (ret);
}

bool						Grid::play(Player const &player)
{
	return (m_cell[player.getX()][player.getY()]->setVal(player));
}

							Grid::~Grid(void)
{
	unsigned int			x;
	unsigned int			y;

	for (x = 0; x < SIZE_GRID; x++)
		for (y = 0; y < SIZE_GRID; y++)
		{
			delete m_cell[x][y];
			m_cell[x][y] = NULL;
		}
}