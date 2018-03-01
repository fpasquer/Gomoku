/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 22:37:42 by fpasquer          #+#    #+#             */
/*   Updated: 2018/03/01 15:17:31 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_HPP
# define WINDOW_HPP

# include <ncurses.h>
# include <stdlib.h>
# include <stdio.h>
# include <string>
# include "Grid.hpp"
# include "Gomoku_client.hpp"

# define HEIGHT_TITLE 12

typedef struct				s_color
{
	short					pair;
	short					font;
	short					background;
}							t_color;

class Window
{
	public:
							Window(void);
		bool				show(Grid const &grid, Player_human const &player, std::string const &key, Player_human const &player_other);
		bool				show_resize(void);
							~Window(void);
		int					disconnected(void) const;
	private:
		static t_color const
							m_color[];
		bool				show_grid(Grid const &grid, Player_human const &player);
		void				write_title(void) const;
		void				show_each_loop(Grid const &grid,Player_human const &player, std::string const &key) const;
		unsigned int		m_cols;
		unsigned int		m_lines;
		WINDOW				*m_win_left;
		WINDOW				*m_win_right;
		WINDOW				*m_win_title;
		WINDOW				*m_win_refresh_each_loop;
		Grid const			*m_last_grid;
		Player_human const 	*m_last_player;
		Player_human const	*m_last_player_other;
		std::string	const	*m_last_key;
		std::string const	m_border;
};

#endif