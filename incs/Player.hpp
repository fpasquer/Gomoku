/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 20:30:15 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/06 12:33:08 by fpasquer         ###   ########.fr       */
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
		bool				checkKeyEntry(std::string const &key);
		std::string			getValue(void) const;
		static std::string	player1;
		static std::string	player2;

	private:
		// typedef struct		s_cmd
		// {
		// 	std::string		key;
		// 	int				decalage;
		// 	unsigned int	Player::*val;
		// 	bool			(Player::*f) (unsigned int const &val);
		// }					t_cmd;
		// static t_cmd const	m_cmd[];
		static unsigned int	m_count;
		unsigned int		m_i;
		std::string			m_val;
		unsigned int		m_x;
		unsigned int		m_y;
};



#endif