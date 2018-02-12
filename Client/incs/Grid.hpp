/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Grid.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 21:30:05 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/12 15:37:31 by fpasquer         ###   ########.fr       */
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

typedef enum				e_way
{
	NONE, LEFT, LEFT_TOP, TOP, TOP_RIGHT, RIGHT, RIGHT_BOTTOM, BOTTOM, BOTTOM_LEFT
}							t_way;

# define NB_WAY_POSSIBLE 8

class Grid
{
	public:
							Grid(void);
		bool				getValue(char &val, unsigned int const x, unsigned int const y) const;
		unsigned int		getLastY(void) const;
		unsigned int		getLastX(void) const;
		bool				updateGrid(Player_human &player);
		bool				play(Player_human &player);
		double				get_time_spend(void) const;
		std::string			captureIa(void) const;

	private:
		typedef struct		s_list_way
		{
			t_way			way;
			t_way			(Grid::*f)(Player_human &);
		}					t_list_way;
		static t_list_way const
							m_list_way[];
		t_way				checkCaptures(Player_human &player);
		t_way				checkLeft(Player_human &player);
		// t_way			checkLeftTop(Player const &player);
		// t_way			checkTop(Player const &player);
		// t_way			checkTopRight(Player const &player);
		// t_way			checkRight(Player const &player);
		// t_way			checkRightBottom(Player const &player);
		// t_way			checkBottom(Player const &player);
		// t_way			checkBottomLeft(Player const &player);
		bool				play(Player_ia const &player);
		static unsigned int	m_last_x;
		static unsigned int	m_last_y;
		char				m_cell[SIZE_GRID][SIZE_GRID];
		double				m_time_spend;
		Player_ia			m_ia;
};

#endif