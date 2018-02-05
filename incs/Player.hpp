/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 20:30:15 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/05 21:12:18 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "Gomoku.hpp"
# include <string>

typedef struct				s_color
{
	std::string				color;
}							t_color;

class Player
{
	public:
							Player(unsigned int const &x = 0, unsigned int const &y = 0);
		bool				setX(unsigned int const &x);
		unsigned int		getX(void) const;
		bool				setY(unsigned int const &y);
		unsigned int		getY(void) const;
		std::string			getValue(unsigned int const &x, unsigned int const &y) const;
		static std::string	player1;
		static std::string	player2;

	private:
		static t_color		tab_color[];
		static unsigned int	m_count;
		unsigned int		m_i;
		std::string			m_val;
		unsigned int		m_x;
		unsigned int		m_y;
};

#endif