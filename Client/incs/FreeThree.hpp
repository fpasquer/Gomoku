/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FreeThree.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:21:16 by fpasquer          #+#    #+#             */
/*   Updated: 2018/03/01 11:52:35 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_THREE_HPP
# define FREE_THREE_HPP

# include "Player.hpp"
# include "CountStone.hpp"

# define DEPTH_FREETHREE 3

class FreeThree : public virtual CountStone
{
	protected:
							FreeThree(void);
		bool				checkFreeThree(unsigned int const y, unsigned int const x, short const val) const;
		bool				updateFreeThree(unsigned int const y, unsigned int const x, short const val) const;
		void				destroyFreeThree(Player const &player);
		void				setUnavailable(unsigned int const y_tmp, unsigned int const x_tmp, short const val);
		void				setAvailable(unsigned int const y_tmp, unsigned int const x_tmp, short const val);

	private:
		typedef struct		s_checkFreeT
		{
			bool			(FreeThree::*f)(unsigned const int, unsigned const int, short const) const;
		}					t_checkFreet;
		static t_checkFreet const
							m_func[];
		bool				checkFTLeft(unsigned const int y_tmp, unsigned const int x_tmp, short const val) const;
		bool				checkFTTopLeft(unsigned const int y_tmp, unsigned const int x_tmp, short const val) const;
		bool				checkFTTop(unsigned const int y_tmp, unsigned const int x_tmp, short const val) const;
		bool				checkFTTopRight(unsigned const int y_tmp, unsigned const int x_tmp, short const val) const;
		bool				checkFTRight(unsigned const int y_tmp, unsigned const int x_tmp, short const val) const;
		bool				checkFTBottomRight(unsigned const int y_tmp, unsigned const int x_tmp, short const val) const;
		bool				checkFTBottom(unsigned const int y_tmp, unsigned const int x_tmp, short const val) const;
		bool				checkFTBottomLeft(unsigned const int y_tmp, unsigned const int x_tmp, short const val) const;
		void				checkFreethreeAgent(unsigned int const y1, unsigned int const x1,
				unsigned int const y2, unsigned int const x2, char const other_perm, char const other_val);
};

#endif