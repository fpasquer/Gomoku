/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 22:37:42 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/14 14:26:10 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_HPP
# define WINDOW_HPP

# include <ncurses.h>
# include <stdlib.h>
# include <string>
# include "Grid.hpp"
# include "Gomoku_client.hpp"
# include "FreeThree.hpp"
	
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
		bool				show(Grid const &grid, Player_human const &player, std::string const &key);
							~Window(void);
		int					disconnected(void) const;
	private:
		static t_color const
							m_color[];
		bool				show_grid(Grid const &grid, Player_human const &player);
		unsigned int		m_cols;
		unsigned int		m_lines;
		WINDOW				*m_win_left;
		WINDOW				*m_win_right;
		std::string const	m_border;
};

#endif