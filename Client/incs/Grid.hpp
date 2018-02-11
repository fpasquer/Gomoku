/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Grid.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 21:30:05 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/11 13:51:46 by fpasquer         ###   ########.fr       */
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

class Grid
{
	public:
							Grid(void);
		bool				getValue(char &val, unsigned int const x, unsigned int const y) const;
		unsigned int		getLastY(void) const;
		unsigned int		getLastX(void) const;
		void				updateGrid(Player_human &player);
		bool				play(Player_human &player);
		double				get_time_spend(void) const;

	private:
		bool				play(Player_ia const &player);
		static unsigned int	m_last_x;
		static unsigned int	m_last_y;
		char				m_cell[SIZE_GRID][SIZE_GRID];
		double				m_time_spend;
		Player_ia			m_ia;
};

#endif