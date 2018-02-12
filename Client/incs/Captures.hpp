/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Captures.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 13:42:56 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/12 14:54:22 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAPTURES_HPP
# define CAPTURES_HPP

# include "Grid.hpp"
# include "Player.hpp"

# define NB_STONE_CAPTURE 2

class Captures
{
	public:
		static bool			checkCapture(Player const &player);

	private:
							Captures(Grid &grid, Player const &player);
		Grid				m_grid;
		bool				checkLeft(Player const &player);
		// bool				checkLeftTop(Player const &player);
		// bool				checkTop(Player const &player);
		// bool				checkTopRight(Player const &player);
		// bool				checkRightBottom(Player const &player);
		// bool				checkBottom(Player const &player);
		// bool				checkBottomLeft(Player const &player);
};

#endif