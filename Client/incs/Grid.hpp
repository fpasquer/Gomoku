/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Grid.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 21:30:05 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/28 11:53:26 by fpasquer         ###   ########.fr       */
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
# include "CountWin.hpp"

typedef enum				e_way
{
	NONE, LEFT, LEFT_TOP, TOP, TOP_RIGHT, RIGHT, RIGHT_BOTTOM, BOTTOM, BOTTOM_LEFT
}							t_way;

# define NB_WAY_POSSIBLE 8
# define NB_STONE_CAPTURE 2
# define DEPTH_FREETHREE 3
# define DECALAGE_TAKE_OFF_CAPTURE 2

class Grid
{
	public:
							Grid(void);
							Grid(short const grid[SIZE_GRID][SIZE_GRID]);
		bool				getValue(short &val, unsigned int const x, unsigned int const y) const;
		unsigned int		getLastY(void) const;
		unsigned int		getLastX(void) const;
		bool				updateGrid(Player_human &player);
		bool				play(Player_human &player);
		double				get_time_spend(void) const;
		bool				getLineNbStone(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const;
		bool				getColNbStone(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const;
		bool				getDiagLeftTopRightBottomNbStone(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const;
		bool				getDiagRightTopLeftBottomNbStone(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const;
		std::string			getCaptureIa(void) const;
		bool				countLeft(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const;
		bool				countRight(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const;
		bool				countTop(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const;
		bool				countBottom(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const;
		bool				countLeftTop(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const;
		bool				countRightBottom(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const;
		bool				countTopRight(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const;
		bool				countBottomLeft(unsigned int const y, unsigned int const x, short const val, unsigned int &count) const;
		bool				haveWin(unsigned int const y, unsigned int const x, short const val, std::string const &capture) const;
		bool				haveWin(Player const &player) const;
		bool				checkIaWin(Player_human const &player) const;

	private:
		typedef struct		s_list_way
		{
			t_way			way;
			t_way			(Grid::*f)(Player const &);
		}					t_list_way;
		static t_list_way const
							m_list_way[];
		t_way				checkCaptures(Player &player);
		t_way				checkLeft(Player const &player);
		t_way				checkLeftTop(Player const &player);
		t_way				checkTop(Player const &player);
		t_way				checkTopRight(Player const &player);
		t_way				checkRight(Player const &player);
		t_way				checkRightBottom(Player const &player);
		t_way				checkBottom(Player const &player);
		t_way				checkBottomLeft(Player const &player);
		bool				play(Player_ia &player);
		void				destroyFreeThree(Player const &player);
		void				setUnavailable(unsigned int const y_tmp, unsigned int const x_tmp, short const val);
		void				setAvailable(unsigned int const y_tmp, unsigned int const x_tmp, short const val);
		void				checkFreethreeAgent(unsigned int const y1, unsigned int const x1,
				unsigned int const y2, unsigned int const x2, char const other_perm, char const other_val);
		static unsigned int	m_last_x;
		static unsigned int	m_last_y;
		short				m_cell[SIZE_GRID][SIZE_GRID];
		double				m_time_spend;
		Player_ia			m_ia;
};

#endif