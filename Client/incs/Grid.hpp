/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Grid.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 21:30:05 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/14 11:29:01 by fpasquer         ###   ########.fr       */
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
		unsigned int		getLineNbStone(Player const &player) const;
		unsigned int		getColNbStone(Player const &player) const;
		unsigned int		getDiagLeftTopRightBottomNbStone(Player const &player) const;
		unsigned int		getDiagRightTopLeftBottomNbStone(Player const &player) const;
		std::string			captureIa(void) const;

	private:
		typedef struct		s_list_way
		{
			t_way			way;
			t_way			(Grid::*f)(Player &);
		}					t_list_way;
		static t_list_way const
							m_list_way[];
		t_way				checkCaptures(Player &player);
		t_way				checkLeft(Player &player);
		t_way				checkLeftTop(Player &player);
		t_way				checkTop(Player &player);
		t_way				checkTopRight(Player &player);
		t_way				checkRight(Player &player);
		t_way				checkRightBottom(Player &player);
		t_way				checkBottom(Player &player);
		t_way				checkBottomLeft(Player &player);
		bool				play(Player_ia &player);
		unsigned int		countLeft(Player const &player) const;
		unsigned int		countLeftTop(Player const &player) const;
		unsigned int		countTop(Player const &player) const;
		unsigned int		countTopRight(Player const &player) const;
		unsigned int		countRight(Player const &player) const;
		unsigned int		countRightBottom(Player const &player) const;
		unsigned int		countBottom(Player const &player) const;
		unsigned int		countBottomLeft(Player const &player) const;
		static unsigned int	m_last_x;
		static unsigned int	m_last_y;
		char				m_cell[SIZE_GRID][SIZE_GRID];
		double				m_time_spend;
		Player_ia			m_ia;
};

#endif