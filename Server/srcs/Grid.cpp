/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Grid.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 08:01:10 by fpasquer          #+#    #+#             */
/*   Updated: 2018/03/02 09:30:52 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Grid.hpp"

                            Grid::Grid(void) : Captures(), HaveWin()
{

}

bool                        Grid::updateInfoGrid(Client const &player)
{
    
    player.read_from_client(&m_depth, sizeof(m_depth));
	player.read_from_client(&m_cell, sizeof(m_cell));
	player.read_from_client(&m_nb_capture_player, sizeof(m_nb_capture_player));
	player.read_from_client(&m_nb_capture_ia, sizeof(m_nb_capture_ia));
    if (m_depth < MIN_DEEP || m_depth > MAX_DEEP || m_nb_capture_ia > NB_WIN_CAPTURE ||
            m_nb_capture_player > NB_WIN_CAPTURE)
        return false;
    return (true);
}

unsigned int                Grid::getDepth(void) const
{
    return (m_depth);
}

size_t                      Grid::getNbCaptureIa(void) const
{
    return (m_nb_capture_ia);
}

size_t                      Grid::getNbCapturePlayer(void) const
{
    return (m_nb_capture_player);
}