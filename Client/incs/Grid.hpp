/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Grid.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 21:30:05 by fpasquer          #+#    #+#             */
/*   Updated: 2018/03/16 10:36:29 by amaindro         ###   ########.fr       */
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
# include "../../Tools_incs/Gomoku.hpp"
# include "../../Tools_incs/Captures.hpp"
# include "../../Tools_incs/HaveWin.hpp"

class Grid : public Captures , public HaveWin
{
	public:
							Grid(void);
		unsigned int		getLastY(void) const;
		unsigned int		getLastX(void) const;
		bool				updateGrid(Player_human &player);
		bool				play(Player_human &player);
		double				get_time_spend(void) const;
		std::string			getCaptureIa(void) const;
		bool				checkIaWin(Player_human const &player) const;
		bool				win(Player const &player) const;

	private:
		void				relevant_ia_agent(int const i_y, int const i_x, unsigned int const start_y, unsigned int const start_x);
		void				relevant_ia(unsigned int const y, unsigned int const x);
		bool				putStone(Player &player);
		double				m_time_spend;
		Player_ia			m_ia;
};

#endif
