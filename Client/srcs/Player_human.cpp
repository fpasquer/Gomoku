/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player_human.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 09:03:26 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/08 12:01:09 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Player_human.hpp"

Player_human::t_cmd const	Player_human::m_cmd[] = {
	{KEY_ARROW_LEFT_, &Player_human::moveLeft},
	{KEY_ARROW_RIGHT_, &Player_human::moveRight},
	{KEY_ARROW_DOWN_, &Player_human::moveDown},
	{KEY_ARROW_UP_, &Player_human::moveUp},
	{KEY_SPACE_, &Player_human::isSpace},
	{KEY_MORE_, &Player_human::deepMore},
	{KEY_MINUS_, &Player_human::deepMinus},
	{0, NULL}
};

							Player_human::Player_human(unsigned int const &x, unsigned int const &y, unsigned int const &deep) : Player(x, y), m_deep(deep), m_client()
{
	m_deep = (m_deep > MAX_DEEP) ? INIT_DEEP : m_deep;
}

bool						Player_human::checkKeySelect(std::string const &key)
{
	unsigned int			i;

	for (i = 0; m_cmd[i].key != 0; i++)
		if (key == m_cmd[i].key)
			return ((*(this).*m_cmd[i].f)());
	return (false);
}

unsigned int				Player_human::getDeep(void) const
{
	return (m_deep);
}

bool						Player_human::moveLeft(void)
{
	this->setX(m_x - 1);
	return (false);
}

bool						Player_human::moveRight(void)
{
	this->setX(m_x + 1);
	return (false);
}

bool						Player_human::moveUp(void)
{
	this->setY(m_y - 1);
	return (false);
}

bool						Player_human::moveDown(void)
{
	this->setY(m_y + 1);
	return (false);
}

bool						Player_human::deepMore(void)
{
	if (m_deep < MAX_DEEP)
		m_deep++;
	return (false);
}

bool						Player_human::deepMinus(void)
{
	if (m_deep > MIN_DEEP)
		m_deep--;
	return (false);
}

bool						Player_human::isSpace(void)
{
	return (true);
}

void						Player_human::set_online(std::string const &addr, int const &port)
{
	m_client.set_addr(addr);
	m_client.set_port(port);
	m_client.connect_to_server();
}

bool						Player_human::isOnline(void) const
{
	return (m_client.connected());
}

ssize_t						Player_human::send_to_server(void const *data, size_t const &len) const
{
	if (this->isOnline() == false)
		return (-1);
	return (m_client.send_to_server(data, len));
}

ssize_t						Player_human::read_from_server(void *data, size_t const &len) const
{
	if (this->isOnline() == false)
		return (-1);
	return (m_client.read_from_server(data, len));
}