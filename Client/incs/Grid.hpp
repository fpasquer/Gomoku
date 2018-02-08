/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Grid.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 21:30:05 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/08 08:36:05 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRID_HPP
# define GRID_HPP

# include "Player.hpp"
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
		bool				play(Player const &player, Client const &client);
		double				get_time_spend(void) const;

	private:
		bool				play_ia(Player const &ia);
		static unsigned int	m_last_x;
		static unsigned int	m_last_y;
		char				m_cell[SIZE_GRID][SIZE_GRID];
		double				m_time_spend;
		Player				m_player2;

};

#endif