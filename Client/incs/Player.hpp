/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 20:30:15 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/07 14:53:07 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "Gomoku_client.hpp"
# include "../../Gomoku.hpp"
# include <string>

class Player
{
	public:
							Player(unsigned int const &x = 0, unsigned int const &y = 0, unsigned int const &deep = INIT_DEEP);
		bool				setX(unsigned int const &x);
		unsigned int		getX(void) const;
		bool				setY(unsigned int const &y);
		unsigned int		getY(void) const;
		bool				checkKeySelect(std::string const &key);
		char				getValue(void) const;
		unsigned int		getDeep(void) const;
		bool				moveLeft(void);
		bool				moveRight(void);
		bool				moveUp(void);
		bool				moveDown(void);
		bool				deepMore(void);
		bool				deepMinus(void);

	private:
		typedef struct		s_cmd
		{
			char			*key;
			bool			(Player::*f) (void);
		}					t_cmd;
		static t_cmd const	m_cmd[];
		bool				isSpace(void);
		static unsigned int	m_count;
		unsigned int		m_i;
		char				m_val;
		unsigned int		m_x;
		unsigned int		m_y;
		unsigned int		m_deep;
};



#endif