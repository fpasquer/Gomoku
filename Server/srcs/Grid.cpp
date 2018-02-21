/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Grid.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 21:33:00 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/21 15:30:42 by amaindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Grid.hpp"
//#include "../incs/FreeThree.hpp"

unsigned int				Grid::m_last_x = SIZE_GRID;
unsigned int				Grid::m_last_y = SIZE_GRID;

							Grid::Grid(short const grid[SIZE_GRID][SIZE_GRID]) : m_time_spend(0.0)
{
	unsigned int			x;
	unsigned int			y;

	for (y = 0; y < SIZE_GRID; y++)
		for (x = 0; x < SIZE_GRID; x++)
			m_cell[y][x] = (GET_VAL(grid[y][x]) == PLAYER1 || GET_VAL(grid[y][x]) == PLAYER2) ? grid[y][x] : EMPTY_CELL;
}

							Grid::Grid(void) : m_time_spend(0.0)
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

bool						Grid::getValue(short &val, unsigned int const x, unsigned int const y) const
{
	if (x >= SIZE_GRID || y >= SIZE_GRID)
		return (false);
	val = m_cell[y][x];
	return (true);
}

bool						Grid::setValue(short val, unsigned int const x, unsigned int const y)
{
	if (x >= SIZE_GRID || y >= SIZE_GRID)
		return (false);
	m_cell[y][x] = val;
	return (true);
}

/*bool						Grid::haveWin(Player const &player) const
{
	return (this->haveWin(player.getY(), player.getX(), player.getValue(), player.getCapture()));
}*/

bool						Grid::haveWin(unsigned int const y, unsigned int const x, short const val, std::string const &capture) const
{
	unsigned int			count1;
	unsigned int			count2;

	this->countLeft(y, x, val, count1);
	this->countRight(y, x, val, count2);
	if (count1 + count2 + 1 >= NB_STONE_WIN)
		return (true);
	this->countTop(y, x, val, count1);
	this->countBottom(y, x, val, count2);
	if (count1 + count2 + 1 >= NB_STONE_WIN)
		return (true);
	this->countLeftTop(y, x, val, count1);
	this->countRightBottom(y, x, val, count2);
	if (count1 + count2 + 1 >= NB_STONE_WIN)
		return (true);
	this->countTopRight(y, x, val, count1);
	this->countBottomLeft(y, x, val, count2);
	if (count1 + count2 + 1 >= NB_STONE_WIN)
		return (true);
	return (capture.size() >= NB_WIN_CAPTURE ? true : false);
}

/*bool						Grid::play(Player_ia &player)
{
	if (player.getX() < SIZE_GRID && player.getY() < SIZE_GRID && GET_VAL(m_cell[player.getY()][player.getX()]) == EMPTY_CELL)
	{
		m_last_x = player.getX();
		m_last_y = player.getY();
		m_cell[m_last_y][m_last_x] = player.getValue();
		this->checkCaptures(player);
		//this->setUnavalable(player);
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
}*/

/*void						Grid::setUnavalable(unsigned int const y_tmp, unsigned int const x_tmp, short const val, char const unpossible, short const val2, char const unpossible2)
{
	FreeThree				freeThree(*this);
	unsigned int			y;
	unsigned int			x;
	unsigned int			decalage;
	unsigned int			end;

	end = DEPTH_FREETHREE * 2 + 1;
	for (y = y_tmp - DEPTH_FREETHREE, x = x_tmp - DEPTH_FREETHREE, decalage = 0; decalage < end; decalage++)//check gauche haut bas droit
	{
		if (y + decalage == y_tmp && x + decalage == x_tmp)
			continue ;
		if (y + decalage < SIZE_GRID && x + decalage < SIZE_GRID && freeThree.checkFreeThree(y + decalage, x + decalage, val) == true)
			m_cell[y + decalage][x + decalage] = SET_PERM(m_cell[y + decalage][x + decalage], unpossible);
		if ((y + decalage < SIZE_GRID && x + decalage < SIZE_GRID && freeThree.updateFreeThree(y + decalage, x + decalage, val) == true))
			this->setUnavalable(y + decalage, x + decalage, val2, unpossible2, val, unpossible);
	}
	for (y = y_tmp - DEPTH_FREETHREE, x = x_tmp, decalage = 0; decalage < end; decalage++)//check haut bas
	{
		if (y + decalage == y_tmp)
			continue ;
		if (y + decalage < SIZE_GRID && freeThree.checkFreeThree(y + decalage, x, val) == true)
			m_cell[y + decalage][x] = SET_PERM(m_cell[y + decalage][x], unpossible);
		if (y + decalage < SIZE_GRID && freeThree.updateFreeThree(y + decalage, x, val) == true)
			this->setUnavalable(y + decalage, x, val2, unpossible2, val, unpossible);
	}
	for (y = y_tmp - DEPTH_FREETHREE, x = x_tmp + DEPTH_FREETHREE, decalage = 0; decalage < end; decalage++)//check Haut droit bas gauche
	{
		if (y + decalage == y_tmp && x - decalage == x_tmp)
			continue ;
		if (y + decalage < SIZE_GRID && x - decalage < SIZE_GRID && freeThree.checkFreeThree(y + decalage, x - decalage, val) == true)
			m_cell[y + decalage][x - decalage] = SET_PERM(m_cell[y + decalage][x - decalage], unpossible);
		if (y + decalage < SIZE_GRID && x - decalage < SIZE_GRID && freeThree.updateFreeThree(y + decalage, x - decalage, val) == true)
			this->setUnavalable(y + decalage, x - decalage, val2, unpossible2, val, unpossible);
	}
	for (y = y_tmp, x = x_tmp  - DEPTH_FREETHREE, decalage = 0; decalage < end; decalage++)//check gauche droit
	{
		if (x + decalage == x_tmp)
			continue ;
		if (x + decalage < SIZE_GRID && freeThree.checkFreeThree(y, x + decalage, val) == true)
			m_cell[y][x + decalage] = SET_PERM(m_cell[y][x + decalage], unpossible);
		if (x + decalage < SIZE_GRID && freeThree.updateFreeThree(y, x + decalage, val) == true)
			this->setUnavalable(y, x + decalage, val2, unpossible2, val, unpossible);
	}
}*/

/*bool						Grid::play(Player_human &player, Player const &player2)
{
	unsigned int			x;
	unsigned int			y;
	unsigned int			deep;
	char					buff[SIZE_CMD + 1];
	ssize_t					len;

	if (player.getX() < SIZE_GRID && player.getY() < SIZE_GRID && GET_VAL(m_cell[player.getY()][player.getX()]) == EMPTY_CELL &&
			(GET_PERM(m_cell[player.getY()][player.getX()]) & player.getUnpossible()) == 0)
	{
		m_cell[player.getY()][player.getX()] = SET_VAL(m_cell[player.getY()][player.getX()], GET_VAL(player.getValue()));
		this->checkCaptures(player);
		if (player.isOnline() != OFFLINE)
		{
			this->setUnavalable(player.getY(), player.getX(), player.getValue(), player.getUnpossible(), m_ia.getValue(), m_ia.getUnpossible());
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
		else
			this->setUnavalable(player.getY(), player.getX(), player.getValue(), player.getUnpossible(), player2.getValue(), player2.getUnpossible());
		return (true);
	}
	return (false);
}*/

double						Grid::get_time_spend(void) const
{
	return (m_time_spend);
}
