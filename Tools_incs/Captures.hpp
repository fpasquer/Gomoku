/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Captures.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 09:36:28 by fpasquer          #+#    #+#             */
/*   Updated: 2018/03/01 14:29:22 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAPTURES_HPP
# define CAPTURES_HPP

# include "FreeThree.hpp"

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
			t_way			(Captures::*f)(unsigned int const, unsigned int const, short const);
		}					t_list_way;
		static t_list_way const
							m_list_way[];
		unsigned int		checkCaptures(unsigned int const y_tmp, unsigned int const x_tmp, short const val);
		t_way				checkLeft(unsigned int const y, unsigned int const x, short const val);
		t_way				checkLeftTop(unsigned int const y, unsigned int const x, short const val);
		t_way				checkTop(unsigned int const y, unsigned int const x, short const val);
		t_way				checkTopRight(unsigned int const y, unsigned int const x, short const val);
		t_way				checkRight(unsigned int const y, unsigned int const x, short const val);
		t_way				checkRightBottom(unsigned int const y, unsigned int const x, short const val);
		t_way				checkBottom(unsigned int const y, unsigned int const x, short const val);
		t_way				checkBottomLeft(unsigned int const y, unsigned int const x, short const val);
        void				captureFreethree(unsigned int const y, unsigned int const x, short const val);
};

#endif