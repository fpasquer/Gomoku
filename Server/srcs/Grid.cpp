/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Grid.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 08:01:10 by fpasquer          #+#    #+#             */
/*   Updated: 2018/03/06 11:01:04 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Grid.hpp"

							Grid::Grid(void) : Captures(), HaveWin()
{

}

bool						Grid::unsetValueAgent(std::string *ptr, char const flag_way,
		short const val, unsigned int const y1, unsigned int const x1,
		unsigned int const y2, unsigned int const x2, char const way_captures)
{
	if ((way_captures & flag_way) != 0 && y1 < SIZE_GRID && x1 < SIZE_GRID &&
			y2 < SIZE_GRID && x2 < SIZE_GRID)
	{
		*ptr = ptr->substr(0, ptr->size()-2);
		m_cell[y1][x1] = SET_VAL(m_cell[y1][x1], GET_VAL(val));
		m_cell[y2][x2] = SET_VAL(m_cell[y2][x2], GET_VAL(val));
		this->checkFreeThree(y1, x1, val);
		this->checkFreeThree(y2, x2, val);
		return (true);
	}
	return (false);
}

bool						Grid::setValue(short const val, unsigned int const y, unsigned int const x, char *way_capture)
{
	std::string				*ptr;
	unsigned int			count;
	
	m_cell[y][x] = SET_VAL(m_cell[y][x], GET_VAL(val));
	this->destroyFreeThree(y, x, val);
	ptr = GET_VAL(val) == PLAYER1 ? &m_nb_capture_player : &m_nb_capture_ia;
	for (count = this->checkCaptures(y, x, val, way_capture); count > 0; count --)
		(*ptr) += "**";
	this->setUnavailable(y, x, val);
	this->setAvailable(y, x, val);
	return (true);
}

bool						Grid::unsetValue(short const val, unsigned int const y, unsigned int const x, char const way_capture)
{
	char					tmp_player;
	short					other_player;
	std::string				*ptr;

	m_cell[y][x] = SET_VAL(m_cell[y][x], EMPTY_CELL);
	ptr = (tmp_player = GET_VAL(val)) == PLAYER1 ? &m_nb_capture_player : &m_nb_capture_ia;
	other_player = (tmp_player == PLAYER1) ? PLAYER2 : PLAYER1;
	tmp_player = GET_PERM(val) == CAN_NOT_PLAY1 ? CAN_NOT_PLAY2 : CAN_NOT_PLAY1;
	other_player = SET_PERM(other_player, tmp_player);
	//reset left
	this->unsetValueAgent(ptr, LEFT, other_player, y, x - 1, y, x - 2, way_capture);
	//reset top left
	this->unsetValueAgent(ptr, LEFT_TOP, other_player, y - 1, x - 1, y - 2, x - 2, way_capture);
	//reset top
	this->unsetValueAgent(ptr, TOP, other_player, y - 1, x, y - 2, x, way_capture);
	//reset top right
	this->unsetValueAgent(ptr, TOP_RIGHT, other_player, y - 1, x + 1, y - 2, x + 2, way_capture);
	//reset right
	this->unsetValueAgent(ptr, RIGHT, other_player, y, x + 1, y, x + 2, way_capture);
	//reset bottom right
	this->unsetValueAgent(ptr, RIGHT_BOTTOM, other_player, y, x + 1, y, x + 2, way_capture);
	//reset bottom
	this->unsetValueAgent(ptr, BOTTOM, other_player, y + 1, x, y + 2, x, way_capture);
	//reset bottom left
	this->unsetValueAgent(ptr, BOTTOM_LEFT, other_player, y, x + 1, y, x + 2, way_capture);
	this->setUnavailable(y, x, val);
	this->setAvailable(y, x, val);
	return (true);
}

bool						Grid::readInfoGrid(Client const &player)
{
	char					buff[NB_WIN_CAPTURE];

	player.read_from_client(&m_depth, sizeof(m_depth));
	player.read_from_client(&m_cell, sizeof(m_cell));
	std::memset(buff, 0, NB_WIN_CAPTURE);
	player.read_from_client(buff, NB_WIN_CAPTURE);
	m_nb_capture_player = buff;
	std::memset(buff, 0, NB_WIN_CAPTURE);
	player.read_from_client(buff, NB_WIN_CAPTURE);
	m_nb_capture_ia = buff;
	if (m_depth < MIN_DEEP || m_depth > MAX_DEEP || m_nb_capture_ia.size() > NB_WIN_CAPTURE ||
			m_nb_capture_player.size() > NB_WIN_CAPTURE)
		return false;
	return (true);
}

unsigned int				Grid::getDepth(void) const
{
	return (m_depth);
}

std::string					Grid::getNbCaptureIa(void) const
{
	return (m_nb_capture_ia);
}

std::string					Grid::getNbCapturePlayer(void) const
{
	return (m_nb_capture_player);
}

void						Grid::show(unsigned int const y, unsigned int const x) const
{
	char					buff[5];
	unsigned int			y_ia;
	unsigned int			x_ia;
	std::string				str = "Player capture : ";

	str += m_nb_capture_player + "\n\tia      capture : " + m_nb_capture_ia + "\n\n\t";
	for (y_ia = 0; y_ia < SIZE_GRID; y_ia++)
	{
		for (x_ia = 0; x_ia < SIZE_GRID; x_ia++)
		{
			if (y == y_ia && x == x_ia)
				str += "\033[31m";
			if (snprintf(buff, 5, "%4d", (int)m_cell[y_ia][x_ia]) > 0)
				str += m_cell[y_ia][x_ia] == ' ' ? "  . " : buff;
			if (y == y_ia && x == x_ia)
				str += "\033[0m";
		}
		str += "\n\t";
	}
	std::cout << str;
}