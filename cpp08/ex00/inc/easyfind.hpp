/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:44:11 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/18 15:16:36 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
// # include <exception>
# include <stdexcept>


template <typename T>
typename T::iterator	easyfind(T container, int n)
{
	for (typename T::iterator it = container.begin(); it != container.end(); ++it)
    {
        if (*it == n)
            return it;
    }
	throw (std::runtime_error("Value not found"));
}
#endif