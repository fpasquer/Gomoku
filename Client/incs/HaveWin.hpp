/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HaveWin.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 11:33:37 by fpasquer          #+#    #+#             */
/*   Updated: 2018/03/01 11:52:44 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HAVE_WIN_HPP
# define HAVE_WIN_HPP

# include "CountStone.hpp"
# include "Player.hpp"

class HaveWin : public virtual CountStone
{
    public:
                            HaveWin();
        bool				haveWin(Player const &player) const;
        bool				haveWin(unsigned int const y, unsigned int const x,
                short const val, std::string const &capture) const;
};

#endif