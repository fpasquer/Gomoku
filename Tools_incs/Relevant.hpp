/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Relevant.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 13:33:34 by amaindro          #+#    #+#             */
/*   Updated: 2018/03/16 14:17:37 by amaindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RELEVANT_HPP
# define RELEVANT_HPP

# include "Cell.hpp"

class Relevant : public virtual Cell
{
	public:
							Relevant();
		void				relevant(unsigned int const y, unsigned int const x, short const relevant_mask);
		void				relevant_agent(int const i_y, int const i_x, unsigned int const start_y, unsigned int const start_x, short const relevant_mask);
		void				unset_relevant(unsigned int const y, unsigned int const x, short const relevant_mask);
		void				unset_relevant_agent(int const i_y, int const i_x, unsigned int const start_y, unsigned int const start_x, short const relevant_mask);
};
#endif
