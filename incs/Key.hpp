/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Key.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 22:04:20 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/05 22:25:03 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_HPP
# define KEY_HPP

# include <string>
# include "Gomoku.hpp"
# include <unistd.h>

class Key
{
	public:
		static bool			getKey(std::string &key);
};

#endif