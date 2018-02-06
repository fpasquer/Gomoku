/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 13:44:53 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/06 13:49:34 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Error.hpp"

							Error::Error(std::string const &error) : m_error(error)
{
	
}

const char					*Error::what(void) const throw()
{
	return (m_error.c_str());
}

							Error::~Error(void) throw()
{
	
}