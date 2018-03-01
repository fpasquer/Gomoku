/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Grid.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 21:30:05 by fpasquer          #+#    #+#             */
/*   Updated: 2018/03/01 09:51:36 by fpasquer         ###   ########.fr       */
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

# define NB_WAY_POSSIBLE 8
# define DEPTH_FREETHREE 3
# define DECALAGE_TAKE_OFF_CAPTURE 2

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

		bool				play(Player_ia &player);
		void				destroyFreeThree(Player const &player);
		void				setUnavailable(unsigned int const y_tmp, unsigned int const x_tmp, short const val);
		void				setAvailable(unsigned int const y_tmp, unsigned int const x_tmp, short const val);
		void				checkFreethreeAgent(unsigned int const y1, unsigned int const x1,
				unsigned int const y2, unsigned int const x2, char const other_perm, char const other_val);
		static unsigned int	m_last_x;
		static unsigned int	m_last_y;
		double				m_time_spend;
		Player_ia			m_ia;
};

#endif