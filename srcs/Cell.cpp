/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cell.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 21:20:06 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/05 21:25:23 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Cell.hpp"

							Cell::Cell(unsigned int const &x, unsigned int const &y) : m_val(EMPTY_CELL), m_x(x), m_y(y)
{
	
}

bool						Cell::setVal(Player const &player)
{
	if (m_val != EMPTY_CELL)
		return (false);
	m_val = player.getValue(m_x, m_y);
	return (true);
}

std::string					Cell::getVal(void) const
{
	return (m_val);
}