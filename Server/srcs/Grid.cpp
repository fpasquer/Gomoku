/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Grid.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 08:01:10 by fpasquer          #+#    #+#             */
/*   Updated: 2018/03/02 11:07:39 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Grid.hpp"

                            Grid::Grid(void) : Captures(), HaveWin()
{

}

bool                        Grid::setValue(short const val, unsigned int const y, unsigned int const x)
{
    m_cell[y][x] = SET_VAL(m_cell[y][x], GET_VAL(val));
    return (true);
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
	std::string				str = "";

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