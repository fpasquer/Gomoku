/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cell.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 09:12:58 by fpasquer          #+#    #+#             */
/*   Updated: 2018/03/01 09:14:46 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CELL_HPP
# define CELL_HPP
# include "../../Gomoku.hpp"

class Cell
{
    public:
                            Cell(void);
    protected:
        short               m_cell[SIZE_GRID][SIZE_GRID];
};

#endif