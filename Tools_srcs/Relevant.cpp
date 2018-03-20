/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Relevant.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 13:41:19 by amaindro          #+#    #+#             */
/*   Updated: 2018/03/20 10:49:24 by amaindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Tools_incs/Relevant.hpp"

							Relevant::Relevant() : Cell()
{
	
}

void						Relevant::relevant_agent(int const i_y, int const i_x,
		unsigned int const start_y, unsigned int const start_x, short const relevant_mask)
{
	int			i;

	for (i = 0; i < 2; i++)
	{
		if (i * i_y + start_y >= SIZE_GRID || i * i_x + start_x >= SIZE_GRID)
			break ;
		m_cell[i * i_y + start_y][i * i_x + start_x] = m_cell[i * i_y + start_y][i * i_x + start_x] | relevant_mask;
	}
}

void						Relevant::relevant(unsigned int const y, unsigned int const x, short const relevant_mask)
{
	//gauche
	this->relevant_agent(0, -1, y, x, relevant_mask);
	//haut gauche
	this->relevant_agent(-1, -1, y, x, relevant_mask);
	//haut
	this->relevant_agent(-1, 0, y, x, relevant_mask);
	//haut droit
	this->relevant_agent(-1, 1, y, x, relevant_mask);
	//droite
	this->relevant_agent(0, 1, y, x, relevant_mask);
	//bas droit
	this->relevant_agent(1, 1, y, x, relevant_mask);
	//bas
	this->relevant_agent(1, 0, y, x, relevant_mask);
	//bas gauche
	this->relevant_agent(1, -1, y, x, relevant_mask);
}

void						Relevant::unset_relevant_agent(int const i_y, int const i_x,
		unsigned int const start_y, unsigned int const start_x, short const relevant_mask)
{
	int			i;

	for (i = 0; i < 2; i++)
	{
		if (i * i_y + start_y >= SIZE_GRID || i * i_x + start_x >= SIZE_GRID)
			break ;
		m_cell[i * i_y + start_y][i * i_x + start_x] = m_cell[i * i_y + start_y][i * i_x + start_x] & relevant_mask;
	}
}

void						Relevant::unset_relevant(unsigned int const y, unsigned int const x, short const relevant_mask)
{
	//gauche
	this->unset_relevant_agent(0, -1, y, x, relevant_mask);
	//haut gauche
	this->unset_relevant_agent(-1, -1, y, x, relevant_mask);
	//haut
	this->unset_relevant_agent(-1, 0, y, x, relevant_mask);
	//haut droit
	this->unset_relevant_agent(-1, 1, y, x, relevant_mask);
	//droite
	this->unset_relevant_agent(0, 1, y, x, relevant_mask);
	//bas droit
	this->unset_relevant_agent(1, 1, y, x, relevant_mask);
	//bas
	this->unset_relevant_agent(1, 0, y, x, relevant_mask);
	//bas gauche
	this->unset_relevant_agent(1, -1, y, x, relevant_mask);
}
