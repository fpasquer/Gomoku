/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Grid.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 21:30:05 by fpasquer          #+#    #+#             */
/*   Updated: 2018/03/01 10:43:33 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRID_HPP
# define GRID_HPP

# include "Player_human.hpp"
# include "Player_ia.hpp"
# include <string>
# include <ncurses.h>
# include "Error.hpp"
# include <iostream>
# include "Client.hpp"
# include "../../Gomoku.hpp"
# include "Captures.hpp"

class Grid : public Captures
{
	public:
							Grid(void);
		unsigned int		getLastY(void) const;
		unsigned int		getLastX(void) const;
		bool				updateGrid(Player_human &player);
		bool				play(Player_human &player);
		bool				haveWin(unsigned int const y, unsigned int const x, short const val, std::string const &capture) const;
		double				get_time_spend(void) const;
		std::string			getCaptureIa(void) const;
		bool				haveWin(Player const &player) const;
		bool				checkIaWin(Player_human const &player) const;

	private:
		bool				putStone(Player &player);
		static unsigned int	m_last_x;
		static unsigned int	m_last_y;
		double				m_time_spend;
		Player_ia			m_ia;
};

#endif