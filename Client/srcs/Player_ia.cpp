/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player_ia.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 09:58:13 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/08 10:17:29 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Player_ia.hpp"

							Player_ia::Player_ia(unsigned int const &x, unsigned int const &y) : Player(x, y)
{
	
}

bool						Player_ia::setX(unsigned int const &x)
{
	if (x >= SIZE_GRID)
		return (false);
	m_x = x;
	return (true);
}

bool						Player_ia::setY(unsigned int const &y)
{
	if (y >= SIZE_GRID)
		return (false);
	m_y = y;
	return (true);
}