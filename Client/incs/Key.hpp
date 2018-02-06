/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Key.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 22:04:20 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/06 21:05:25 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_HPP
# define KEY_HPP

# include <string>
# include "Gomoku_client.hpp"
# include <unistd.h>

class Key
{
	public:
		static bool			getKey(std::string &key);
};

#endif