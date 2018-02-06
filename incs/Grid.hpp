/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Grid.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 21:30:05 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/06 10:39:22 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRID_HPP
# define GRID_HPP

# include "Cell.hpp"
# include <string>
# include <ncurses.h>

class Grid
{
	public:
							Grid(void);
		void				show(WINDOW *win, unsigned int start_x, unsigned int start_y, Player const &player) const;
		bool				play(Player const &player);
							~Grid(void);
	private:
		Cell				*m_cell[SIZE_GRID][SIZE_GRID];
		std::string const	m_border;
};

#endif