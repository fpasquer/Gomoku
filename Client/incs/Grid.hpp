/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Grid.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 21:30:05 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/07 11:17:26 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRID_HPP
# define GRID_HPP

# include "Cell.hpp"
# include <string>
# include <ncurses.h>
# include "Error.hpp"
# include <iostream>
# include "Client.hpp"
# include "../../Gomoku.hpp"

class Grid
{
	public:
							Grid(void) throw();
		void				show(WINDOW *win, unsigned int start_x, unsigned int start_y, Player const &player) const;
		bool				play(Player const &player, Client const &client);
		double				get_time_spend(void) const;
							~Grid(void);
	private:
		bool				play_ia(Player const &ia);
		static unsigned int	m_last_x;
		static unsigned int	m_last_y;
		Cell				*m_cell[SIZE_GRID][SIZE_GRID];
		std::string const	m_border;
		double				m_time_spend;
		Player				m_player2;

};

#endif