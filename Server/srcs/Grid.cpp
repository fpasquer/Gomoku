/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Grid.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 08:01:10 by fpasquer          #+#    #+#             */
/*   Updated: 2018/03/05 16:40:20 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Grid.hpp"

                            Grid::Grid(void) : Captures(), HaveWin()
{

}

bool                        Grid::setValue(short const val, unsigned int const y, unsigned int const x, char *way_captures)
{
    std::string             *ptr;
    unsigned int			count;
    
    m_cell[y][x] = SET_VAL(m_cell[y][x], GET_VAL(val));
    this->destroyFreeThree(y, x, val);
    ptr = GET_VAL(val) == PLAYER1 ? &m_nb_capture_player : &m_nb_capture_ia;
    for (count = this->checkCaptures(y, x, val, way_captures); count > 0; count--)
        (*ptr) += "**";
    if (*way_captures != NONE)
        std::cout << "capture : " << (unsigned int)*way_captures << " y : " << y << " x : " << x << std::endl;
    this->setUnavailable(m_last_y, m_last_x, val);
    this->setAvailable(m_last_y, m_last_x, val);
    return (true);
}

bool                        Grid::unsetValue(short const val, unsigned int const y, unsigned int const x, char const way_captures)
{
    short                   other_player;
    std::string             *ptr;
    // unsigned int			count;
    
    m_cell[y][x] = SET_VAL(m_cell[y][x], EMPTY_CELL);
    other_player = GET_VAL(val) == PLAYER1 ? PLAYER2 : PLAYER1;
    other_player = SET_PERM()
    ptr = GET_VAL(val) == PLAYER1 ? &m_nb_capture_player : &m_nb_capture_ia;
    if ((way_captures & LEFT) != 0)
    {
        *ptr = ptr->substr(0, ptr->size()-2);
        m_cell[y][x - 1] = SET_VAL(m_cell[y][x - 1], other_player);
        m_cell[y][x - 2] = SET_VAL(m_cell[y][x - 2], other_player);
        this->checkFreeThree(y, x - 1, other_player);
    this->checkFreeThree(y, x - 2, other_player);
    }
    if ((way_captures & LEFT_TOP) != 0)
    {
        *ptr = ptr->substr(0, ptr->size()-2);
        m_cell[y - 1][x - 1] = other_player;
        m_cell[y - 2][x - 2] = other_player;

    }
    if ((way_captures & TOP) != 0)
    {
        *ptr = ptr->substr(0, ptr->size()-2);
        m_cell[y - 1][x] = other_player;
        m_cell[y - 2][x] = other_player;
    }
    if ((way_captures & TOP_RIGHT) != 0)
    {
        *ptr = ptr->substr(0, ptr->size()-2);
        m_cell[y - 1][x + 1] = other_player;
        m_cell[y - 2][x + 2] = other_player;
    }
    if ((way_captures & RIGHT) != 0)
    {
        *ptr = ptr->substr(0, ptr->size()-2);
        m_cell[y][x + 1] = other_player;
        m_cell[y][x + 2] = other_player;
    }
    if ((way_captures & RIGHT_BOTTOM) != 0)
    {
        *ptr = ptr->substr(0, ptr->size()-2);
        m_cell[y + 1][x + 1] = other_player;
        m_cell[y + 2][x + 2] = other_player;
    }
    if ((way_captures & BOTTOM) != 0)
    {
        *ptr = ptr->substr(0, ptr->size()-2);
        m_cell[y + 1][x] = other_player;
        m_cell[y + 2][x] = other_player; 
    }
    if ((way_captures & BOTTOM_LEFT) != 0)
    {
        *ptr = ptr->substr(0, ptr->size()-2);
        m_cell[y + 1][x - 1] = other_player;
        m_cell[y + 2][x - 2] = other_player; 
    }
    // this->destroyFreeThree(y, x, val);
    this->setUnavailable(m_last_y, m_last_x, val);
    this->setAvailable(m_last_y, m_last_x, val);
    return (true);
    std::cout << "capture : " << (unsigned int)way_captures << val << std::endl; 
}

bool                        Grid::readInfoGrid(Client const &player)
{
    char                    buff[NB_WIN_CAPTURE];

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

unsigned int                Grid::getDepth(void) const
{
    return (m_depth);
}

std::string                 Grid::getNbCaptureIa(void) const
{
    return (m_nb_capture_ia);
}

std::string                 Grid::getNbCapturePlayer(void) const
{
    return (m_nb_capture_player);
}

void                        Grid::show(unsigned int const y, unsigned int const x) const
{
    char				    buff[5];
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