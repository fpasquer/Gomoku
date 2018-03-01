/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cell.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 09:12:58 by fpasquer          #+#    #+#             */
/*   Updated: 2018/03/01 14:08:54 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CELL_HPP
# define CELL_HPP
# include "Gomoku.hpp"

class Cell
{
    public:
                            Cell(void);
        bool				getValue(short &val, unsigned int const x, unsigned int const y) const;
    protected:
        short               m_cell[SIZE_GRID][SIZE_GRID];
        static unsigned int	m_last_x;
		static unsigned int	m_last_y;
};

#endif