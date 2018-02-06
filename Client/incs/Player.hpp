/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 20:30:15 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/06 14:13:23 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "Gomoku.hpp"
# include <string>

class Player
{
	public:
							Player(unsigned int const &x = 0, unsigned int const &y = 0);
		bool				setX(unsigned int const &x);
		unsigned int		getX(void) const;
		bool				setY(unsigned int const &y);
		unsigned int		getY(void) const;
		bool				checkKeySelect(std::string const &key);
		std::string			getValue(void) const;
		static std::string	player1;
		static std::string	player2;

	private:
		static unsigned int	m_count;
		unsigned int		m_i;
		std::string			m_val;
		unsigned int		m_x;
		unsigned int		m_y;
};



#endif