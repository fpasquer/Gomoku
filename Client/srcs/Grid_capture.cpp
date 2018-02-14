/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Grid_capture.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 20:13:50 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/14 20:15:31 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Grid.hpp"

Grid::t_list_way const		Grid::m_list_way[] = {
	{LEFT, &Grid::checkLeft},
	{LEFT_TOP, &Grid::checkLeftTop},
	{TOP, &Grid::checkTop},
	{TOP_RIGHT, &Grid::checkTopRight},
	{RIGHT, &Grid::checkRight},
	{RIGHT_BOTTOM, &Grid::checkRightBottom},
	{BOTTOM, &Grid::checkBottom},
	{BOTTOM_LEFT, &Grid::checkBottomLeft},
	{NONE, NULL}
};

t_way						Grid::checkLeft(Player &player)
{
	char					val;
	unsigned int			y;
	unsigned int			x;
	unsigned int			i;

	y = player.getY();
	x = player.getX();
	val = player.getValue();
	for (i = 0; i < NB_STONE_CAPTURE && x - i - 1 < SIZE_GRID; i++)
		if (m_cell[y][x - i - 1] == val || m_cell[y][x - i - 1] == EMPTY_CELL)
			break ;
	if (i != NB_STONE_CAPTURE || x - i - 1 >= SIZE_GRID || m_cell[y][x - i - 1] != val)
		return (NONE);
	for (i = 0; i < NB_STONE_CAPTURE; i++)
		m_cell[y][x - i - 1] = EMPTY_CELL;
	return (LEFT);
}

t_way						Grid::checkLeftTop(Player &player)
{
	char					val;
	unsigned int			y;
	unsigned int			x;
	unsigned int			i;

	y = player.getY();
	x = player.getX();
	val = player.getValue();
	for (i = 0; i < NB_STONE_CAPTURE && x - i - 1 < SIZE_GRID && y - i - 1 < SIZE_GRID; i++)
		if (m_cell[y - i - 1][x - i - 1] == val || m_cell[y - i - 1][x - i - 1] == EMPTY_CELL)
			break ;
	if (i != NB_STONE_CAPTURE || x - i - 1 >=  SIZE_GRID|| y - i - 1 >= SIZE_GRID || m_cell[y - i - 1][x - i - 1] != val)
		return (NONE);
	for (i = 0; i < NB_STONE_CAPTURE; i++)
		m_cell[y - i - 1][x - i - 1] = EMPTY_CELL;
	return (LEFT_TOP);
}

t_way						Grid::checkTop(Player &player)
{
	char					val;
	unsigned int			y;
	unsigned int			x;
	unsigned int			i;

	y = player.getY();
	x = player.getX();
	val = player.getValue();
	for (i = 0; i < NB_STONE_CAPTURE && y - i - 1 < SIZE_GRID; i++)
		if (m_cell[y - i - 1][x] == val || m_cell[y - i - 1][x] == EMPTY_CELL)
			break ;
	if (i != NB_STONE_CAPTURE || y - i - 1 >= SIZE_GRID || m_cell[y - i - 1][x] != val)
		return (NONE);
	for (i = 0; i < NB_STONE_CAPTURE; i++)
		m_cell[y - i - 1][x] = EMPTY_CELL;
	return (TOP);
}

t_way						Grid::checkTopRight(Player &player)
{
	char					val;
	unsigned int			y;
	unsigned int			x;
	unsigned int			i;

	y = player.getY();
	x = player.getX();
	val = player.getValue();
	for (i = 0; i < NB_STONE_CAPTURE && y - i - 1 < SIZE_GRID && x + i + 1 < SIZE_GRID; i++)
		if (m_cell[y - i - 1][x + i + 1] == val || m_cell[y - i - 1][x + i + 1] == EMPTY_CELL)
			break ;
	if (i != NB_STONE_CAPTURE || y - i - 1 >= SIZE_GRID || x + i + 1 >= SIZE_GRID || m_cell[y - i - 1][x + i + 1] != val)
		return (NONE);
	for (i = 0; i < NB_STONE_CAPTURE; i++)
		m_cell[y - i - 1][x + i + 1] = EMPTY_CELL;
	return (TOP_RIGHT);
}

t_way						Grid::checkRight(Player &player)
{
	char					val;
	unsigned int			y;
	unsigned int			x;
	unsigned int			i;

	y = player.getY();
	x = player.getX();
	val = player.getValue();
	for (i = 0; i < NB_STONE_CAPTURE && x + i + 1 < SIZE_GRID; i++)
		if (m_cell[y][x + i + 1] == val || m_cell[y][x + i + 1] == EMPTY_CELL)
			break ;
	if (i != NB_STONE_CAPTURE || x + i + 1 >= SIZE_GRID || m_cell[y][x + i + 1] != val)
		return (NONE);
	for (i = 0; i < NB_STONE_CAPTURE; i++)
		m_cell[y][x + i + 1] = EMPTY_CELL;
	return (RIGHT);
}

t_way						Grid::checkRightBottom(Player &player)
{
	char					val;
	unsigned int			y;
	unsigned int			x;
	unsigned int			i;

	y = player.getY();
	x = player.getX();
	val = player.getValue();
	for (i = 0; i < NB_STONE_CAPTURE && y + i + 1 < SIZE_GRID && x + i + 1 < SIZE_GRID; i++)
		if (m_cell[y + i + 1][x + i + 1] == val || m_cell[y + i + 1][x + i + 1] == EMPTY_CELL)
			break ;
	if (i != NB_STONE_CAPTURE || x + i + 1 >= SIZE_GRID || y + i + 1 >= SIZE_GRID || m_cell[y + i + 1][x + i + 1] != val)
		return (NONE);
	for (i = 0; i < NB_STONE_CAPTURE; i++)
		m_cell[y + i + 1][x + i + 1] = EMPTY_CELL;
	return (RIGHT_BOTTOM);
}

t_way						Grid::checkBottom(Player &player)
{
	char					val;
	unsigned int			y;
	unsigned int			x;
	unsigned int			i;

	y = player.getY();
	x = player.getX();
	val = player.getValue();
	for (i = 0; i < NB_STONE_CAPTURE && y + i + 1 < SIZE_GRID; i++)
		if (m_cell[y + i + 1][x] == val || m_cell[y + i + 1][x] == EMPTY_CELL)
			break ;
	if (i != NB_STONE_CAPTURE || y + i + 1 >= SIZE_GRID || m_cell[y + i + 1][x] != val)
		return (NONE);
	for (i = 0; i < NB_STONE_CAPTURE; i++)
		m_cell[y + i + 1][x] = EMPTY_CELL;
	return (BOTTOM);
}

t_way						Grid::checkBottomLeft(Player &player)
{
	char					val;
	unsigned int			y;
	unsigned int			x;
	unsigned int			i;

	y = player.getY();
	x = player.getX();
	val = player.getValue();
	for (i = 0; i < NB_STONE_CAPTURE && y + i + 1 < SIZE_GRID && x - i - 1 < SIZE_GRID; i++)
		if (m_cell[y + i + 1][x - i - 1] == val || m_cell[y + i + 1][x - i - 1] == EMPTY_CELL)
			break ;
	if (i != NB_STONE_CAPTURE || y + i + 1 >= SIZE_GRID || x - i - 1 >= SIZE_GRID || m_cell[y + i + 1][x - i - 1] != val)
		return (NONE);
	for (i = 0; i < NB_STONE_CAPTURE; i++)
		m_cell[y + i + 1][x - i - 1] = EMPTY_CELL;
	return (BOTTOM_LEFT);
}

std::string					Grid::captureIa(void) const
{
	return (m_ia.capture());
}

t_way						Grid::checkCaptures(Player &player)
{
	unsigned int			i;
	t_way					way;

	for (way = NONE, i = 0; m_list_way[i].f != NULL; i++)
		if (((*this).*m_list_way[i].f)(player) == m_list_way[i].way)
		{
			player.addCapture();
			way = m_list_way[i].way;
		}
	return (way);
}