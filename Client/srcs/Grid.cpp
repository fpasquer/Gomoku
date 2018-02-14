/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Grid.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 21:33:00 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/14 11:32:26 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Grid.hpp"
#include "../incs/Captures.hpp"

unsigned int				Grid::m_last_x = SIZE_GRID;
unsigned int				Grid::m_last_y = SIZE_GRID;
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

							Grid::Grid(void) : m_time_spend(0.0), m_ia()
{
	unsigned int			x;
	unsigned int			y;

	for (y = 0; y < SIZE_GRID; y++)
		for (x = 0; x < SIZE_GRID; x++)
			m_cell[y][x] = EMPTY_CELL;
}

unsigned int				Grid::getLastY(void) const
{
	return (m_last_y);
}

unsigned int				Grid::getLastX(void) const
{
	return (m_last_x);
}

bool						Grid::getValue(char &val, unsigned int const x, unsigned int const y) const
{
	if (x >= SIZE_GRID || y >= SIZE_GRID)
		return (false);
	val = m_cell[y][x];
	return (true);
}

bool						Grid::play(Player_ia &player)
{
	if (player.getX() < SIZE_GRID && player.getY() < SIZE_GRID && m_cell[player.getY()][player.getX()] == EMPTY_CELL)
	{
		m_last_x = player.getX();
		m_last_y = player.getY();
		m_cell[m_last_y][m_last_x] = player.getValue();
		this->checkCaptures(player);
		return (true);
	}
	return (false);
}

bool						Grid::updateGrid(Player_human &player)
{
	unsigned int			x;
	unsigned int			y;
	char					buff[SIZE_CMD + 1];
	ssize_t					len;

	if (player.enable() == false)
	{
		if (player.isOnline() == ONLINE_LAN)
		{
			len = player.read_from_server(buff, SIZE_CMD);
			buff[len] = '\0';
			if (strcmp(buff, CONNECTED) != 0)
				return (false);
		}
		player.read_from_server(&y, sizeof(y));
		player.read_from_server(&x, sizeof(x));
		m_ia.setY(y);
		m_ia.setX(x);
		this->play(m_ia);
		player.setEnable();
	}
	return (true);
}

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

unsigned int				Grid::countLeft(Player const &player) const
{
	char					val;
	unsigned int			count;
	unsigned int			y;
	unsigned int			x;
	unsigned int			i;

	y = player.getY();
	x = player.getX();
	val = player.getValue();
	for (count = 0, i = 0; x - i - 1 < SIZE_GRID && m_cell[y][x - i - 1] == val; i++)
		count ++;
	return (count);
}

unsigned int				Grid::countRight(Player const &player) const
{
	char					val;
	unsigned int			count;
	unsigned int			y;
	unsigned int			x;
	unsigned int			i;

	y = player.getY();
	x = player.getX();
	val = player.getValue();
	for (count = 0, i = 0; x + i + 1 < SIZE_GRID && m_cell[y][x + i + 1] == val; i++)
		count ++;
	return (count);
}

unsigned int				Grid::countTop(Player const &player) const
{
	char					val;
	unsigned int			count;
	unsigned int			y;
	unsigned int			x;
	unsigned int			i;

	y = player.getY();
	x = player.getX();
	val = player.getValue();
	for (count = 0, i = 0; y - i - 1 < SIZE_GRID && m_cell[y - i - 1][x] == val; i++)
		count ++;
	return (count);
}

unsigned int				Grid::countBottom(Player const &player) const
{
	char					val;
	unsigned int			count;
	unsigned int			y;
	unsigned int			x;
	unsigned int			i;

	y = player.getY();
	x = player.getX();
	val = player.getValue();
	for (count = 0, i = 0; y + i + 1 < SIZE_GRID && m_cell[y + i + 1][x] == val; i++)
		count ++;
	return (count);
}

unsigned int				Grid::countLeftTop(Player const &player) const
{
	char					val;
	unsigned int			count;
	unsigned int			y;
	unsigned int			x;
	unsigned int			i;

	y = player.getY();
	x = player.getX();
	val = player.getValue();
	for (count = 0, i = 0; y - i - 1 < SIZE_GRID && x - i - 1 < SIZE_GRID && m_cell[y - i - 1][x - i - 1] == val; i++)
		count ++;
	return (count);
}

unsigned int				Grid::countRightBottom(Player const &player) const
{
	char					val;
	unsigned int			count;
	unsigned int			y;
	unsigned int			x;
	unsigned int			i;

	y = player.getY();
	x = player.getX();
	val = player.getValue();
	for (count = 0, i = 0; y + i + 1 < SIZE_GRID && x + i + 1 < SIZE_GRID && m_cell[y + i + 1][x + i + 1] == val; i++)
		count ++;
	return (count);
}

unsigned int				Grid::countTopRight(Player const &player) const
{
	char					val;
	unsigned int			count;
	unsigned int			y;
	unsigned int			x;
	unsigned int			i;

	y = player.getY();
	x = player.getX();
	val = player.getValue();
	for (count = 0, i = 0; y - i - 1 < SIZE_GRID && x + i + 1 < SIZE_GRID && m_cell[y - i - 1][x + i + 1] == val; i++)
		count ++;
	return (count);
}

unsigned int				Grid::countBottomLeft(Player const &player) const
{
	char					val;
	unsigned int			count;
	unsigned int			y;
	unsigned int			x;
	unsigned int			i;

	y = player.getY();
	x = player.getX();
	val = player.getValue();
	for (count = 0, i = 0; y + i + 1 < SIZE_GRID && x - i - 1 < SIZE_GRID && m_cell[y + i + 1][x - i - 1] == val; i++)
		count ++;
	return (count);
}

unsigned int				Grid::getLineNbStone(Player const &player) const
{
	return (this->countLeft(player) + this->countRight(player) + 1);
}

unsigned int				Grid::getColNbStone(Player const &player) const
{
	return (this->countTop(player) + this->countBottom(player) + 1);
}

unsigned int				Grid::getDiagLeftTopRightBottomNbStone(Player const &player) const
{
	return (this->countLeftTop(player) + this->countRightBottom(player) + 1);
}

unsigned int				Grid::getDiagRightTopLeftBottomNbStone(Player const &player) const
{
	return (this->countTopRight(player) + this->countBottomLeft(player) + 1);
}

bool						Grid::play(Player_human &player)
{
	unsigned int			x;
	unsigned int			y;
	unsigned int			deep;
	char					buff[SIZE_CMD + 1];
	ssize_t					len;

	if (player.getX() < SIZE_GRID && player.getY() < SIZE_GRID && m_cell[player.getY()][player.getX()] == EMPTY_CELL)
	{
		this->checkCaptures(player);
		m_cell[player.getY()][player.getX()] = player.getValue();
		if (player.isOnline() != OFFLINE)
		{
			deep = player.getDeep();
			player.send_to_server(player.isOnline() == ONLINE ? IA : LAN, SIZE_CMD);
			if (player.isOnline() == ONLINE)
			{
				player.send_to_server(&deep, sizeof(deep));
				player.send_to_server(m_cell, sizeof(m_cell));
			}
			else if (player.isOnline() == ONLINE_LAN)
			{
				y = player.getY();
				x = player.getX();
				player.send_to_server(&y, sizeof(y));
				player.send_to_server(&x, sizeof(x));
			}
			len = player.read_from_server(buff, SIZE_CMD);
			buff[len] = '\0';
			if (player.isOnline() == ONLINE)
			{
				if (strcmp(buff, TIME_SPEND) != 0)
					return (false);
				player.read_from_server(&m_time_spend, sizeof(m_time_spend));
				player.setDisable();//pour que updateGrid fonctionne
			}
			else if (player.isOnline() == ONLINE_LAN)
			{
				if (strcmp(buff, CONNECTED2) != 0)
					return (false);
				player.setDisable();
			}
			this->updateGrid(player);
		}
		return (true);
	}
	return (false);
}

double						Grid::get_time_spend(void) const
{
	return (m_time_spend);
}