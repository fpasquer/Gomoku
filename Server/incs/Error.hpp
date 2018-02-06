/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 13:40:24 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/06 13:47:09 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HPP
# define ERROR_HPP

# include <exception>
# include <string>

class Error : public std::exception
{
	public:
							Error(std::string const &error);
		virtual const char	*what(void) const throw();
		virtual				~Error(void) throw();

	private:
		std::string			m_error;
};

#endif