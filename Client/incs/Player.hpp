/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 20:30:15 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/08 11:20:15 by fpasquer         ###   ########.fr       */
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
							Player(unsigned int const &x = 0, unsigned int const &y = 0);
		unsigned int		getX(void) const;
		unsigned int		getY(void) const;
		char				getValue(void) const;

	protected:
		bool				setX(unsigned int const &x);
		bool				setY(unsigned int const &y);
		static unsigned int	m_count;
		char				m_val;
		unsigned int		m_x;
		unsigned int		m_y;
};



#endif