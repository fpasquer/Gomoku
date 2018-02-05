/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Grid.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 21:30:05 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/05 21:55:12 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRID_HPP
# define GRID_HPP

# include "Cell.hpp"
# include <string>

class Grid
{
	public:
							Grid(void);
		std::string			show(void) const;
		bool				play(Player const &player);
							~Grid(void);
	private:
		Cell				*m_cell[SIZE_GRID][SIZE_GRID];
		std::string const	m_border;
};

#endif