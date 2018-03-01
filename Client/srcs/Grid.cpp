/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Grid.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 21:33:00 by fpasquer          #+#    #+#             */
/*   Updated: 2018/03/01 15:01:00 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Grid.hpp"

							Grid::Grid(void) : Captures(), HaveWin(), m_time_spend(0.0), m_ia()
{
	
}

std::string					Grid::getCaptureIa(void) const
{
	return (m_ia.getCapture());
}

unsigned int				Grid::getLastY(void) const
{
	return (m_last_y);
}

unsigned int				Grid::getLastX(void) const
{
	return (m_last_x);
}

bool						Grid::checkIaWin(Player_human const &player) const
{
	if (player.isOnline() == OFFLINE)
		return (false);
	return (this->haveWin(m_ia.getY(), m_ia.getX(), m_ia.getValue(),
		m_ia.getCapture()));
}

bool						Grid::putStone(Player &player)
{
	short					val;
	unsigned int			y;
	unsigned int			x;
	unsigned int			count;

	x = player.getX();
	y = player.getY();
	val = player.getValue();
	if (x < SIZE_GRID && y < SIZE_GRID && GET_VAL(m_cell[y][x]) == EMPTY_CELL &&
			(GET_PERM(m_cell[y][x]) & GET_PERM(val)) == 0)
	{
		m_last_x = x;
		m_last_y = y;
		m_cell[m_last_y][m_last_x] = GET_VAL(val);
		this->destroyFreeThree(y, x, val);
		for (count = this->checkCaptures(y, x, val); count > 0; count --)
			player.addCapture();
		this->setUnavailable(m_last_y, m_last_x, val);
		this->setAvailable(m_last_y, m_last_x, val);
		return (true);
	}
	return (false);
}

bool						Grid::win(Player const &player) const
{
	return (this->haveWin(player.getY(), player.getX(), player.getValue(),
			player.getCapture()));
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
		if (this->putStone(m_ia) == false)
			return (false);
		player.setEnable();
	}
	return (true);
}

bool						Grid::play(Player_human &player)
{
	unsigned int			x;
	unsigned int			y;
	unsigned int			deep;
	char					buff[SIZE_CMD + 1];
	ssize_t					len;

	if (player.getX() < SIZE_GRID && player.getY() < SIZE_GRID && GET_VAL(m_cell[player.getY()][player.getX()]) == EMPTY_CELL &&
			(GET_PERM(m_cell[player.getY()][player.getX()]) & player.getUnpossible()) == 0 && this->putStone(player) == true)
	{
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
			return (this->updateGrid(player));
		}
		return (true);
	}
	return (false);
}

double						Grid::get_time_spend(void) const
{
	return (m_time_spend);
}
