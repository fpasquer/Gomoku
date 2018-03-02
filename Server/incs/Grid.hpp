/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Grid.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 07:57:19 by fpasquer          #+#    #+#             */
/*   Updated: 2018/03/02 09:28:32 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRID_HPP
# define GRID_HPP

# include "../../Tools_incs/Captures.hpp"
# include "../../Tools_incs/Gomoku.hpp"
# include "../../Tools_incs/HaveWin.hpp"
# include "Client.hpp"

class Grid :  public Captures , public HaveWin
{
    public:
                            Grid(void);
        bool                updateInfoGrid(Client const & player);
        unsigned int        getDepth(void) const;
        size_t              getNbCaptureIa(void) const;
        size_t              getNbCapturePlayer(void) const;

    private:
        unsigned int        m_depth;
        size_t				m_nb_capture_ia;
        size_t              m_nb_capture_player;
};

#endif