/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cell.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 20:27:05 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/05 21:28:10 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CELL_HPP
# define CELL_HPP

# include "../incs/Gomoku.hpp"
# include <string>
# include "Player.hpp"

class Cell
{
	public:
							Cell(unsigned int const &x, unsigned int const &y);
		bool				setVal(Player const &player);
		std::string			getVal(void) const;

	private:
		std::string			m_val;
		unsigned int		m_x;
		unsigned int		m_y;
};

#endif