/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Captures.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 09:36:28 by fpasquer          #+#    #+#             */
/*   Updated: 2018/03/01 10:23:56 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAPTURES_HPP
# define CAPTURES_HPP

# include "FreeThree.hpp"
#include "Player.hpp"

# define NB_STONE_CAPTURE 2

typedef enum				e_way
{
	NONE, LEFT, LEFT_TOP, TOP, TOP_RIGHT, RIGHT, RIGHT_BOTTOM, BOTTOM, BOTTOM_LEFT
}							t_way;

class Captures : public FreeThree
{
	protected:
							Captures(void);
        typedef struct		s_list_way
		{
			t_way			way;
			t_way			(Captures::*f)(Player const &);
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
        void				captureFreethree(unsigned int const y_tmp, unsigned int const x_tmp, short const val);
};

#endif