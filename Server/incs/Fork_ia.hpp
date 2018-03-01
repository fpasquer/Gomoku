/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fork_ia.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 09:11:30 by fpasquer          #+#    #+#             */
/*   Updated: 2018/03/01 14:59:47 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORK_IA_HPP
# define FORK_IA_HPP

# include "Fork_abstract.hpp"
# include "../../Tools_incs/Gomoku.hpp"
# include "Ia_player.hpp"
# include "Client.hpp"
# include "Error.hpp"
# include <signal.h>
# include <time.h>

class Fork_ia : public Fork_abstract
{
	public:
							Fork_ia(Client const &player);

	protected:
		void				play_ia(void) const;
		virtual void		run_loop(void) const;
};

#endif