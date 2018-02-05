/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 20:35:27 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/05 21:57:52 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Player.hpp"

unsigned int				Player::m_count = 0;
std::string					Player::player1 = "X\033[0m";
std::string					Player::player2 = "O\033[0m";
t_color						Player::tab_color[] = {{"\033[31m"},{"\033[31;01m"},{"\033[32m"},{"\033[32;01m"}};

							Player::Player(unsigned int const &x, unsigned int const &y) : m_x(x), m_y(y)
{
	m_x = (m_x >= SIZE_GRID) ? 0 : m_x;
	m_y = (m_y >= SIZE_GRID) ? 0 : m_y;
	m_i = m_count;
	m_val = (m_count++ == 0) ? Player::player1 : Player::player2;
}

bool						Player::setX(unsigned int const &x)
{
	if (x >= SIZE_GRID)
		return (false);
	m_x = x;
	return (true);
}

unsigned int				Player::getX(void) const
{
	return (m_x);
}

bool						Player::setY(unsigned int const &y)
{
	if (y >= SIZE_GRID)
		return (false);
	m_y = y;
	return (true);
}

unsigned int				Player::getY(void) const
{
	return (m_y);
}

std::string					Player::getValue(unsigned int const &x, unsigned int const &y) const
{
	if (x == this->getX() && y == this->getY())
		return (tab_color[m_i * 2 + 1].color + m_val);
	return (tab_color[m_i * 2].color + m_val);
}