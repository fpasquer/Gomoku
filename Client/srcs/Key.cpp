/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Key.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpasquer <fpasquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 22:06:42 by fpasquer          #+#    #+#             */
/*   Updated: 2018/02/05 22:34:25 by fpasquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/Key.hpp"

bool						Key::getKey(std::string &key)
{
	char					buff[SIZE_BUFF];

	memset(buff, 0, SIZE_BUFF);
	key = "";
	if (read(STDIN_FILENO, &buff, SIZE_BUFF) < 0)
		return (false);
	key = buff;
	return (true);
}