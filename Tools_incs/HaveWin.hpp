/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HaveWin.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 11:33:37 by fpasquer          #+#    #+#             */
/*   Updated: 2018/03/06 10:25:23 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HAVE_WIN_HPP
# define HAVE_WIN_HPP

# include "CountStone.hpp"

class HaveWin : public virtual CountStone
{
	public:
							HaveWin(void);
							HaveWin(short const cell[SIZE_GRID][SIZE_GRID]);
		bool				haveWin(unsigned int const y, unsigned int const x,
				short const val, std::string const &capture) const;
};

#endif