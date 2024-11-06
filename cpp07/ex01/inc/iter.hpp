/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:52:26 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/06 18:06:03 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

template <typename T>

void	iter(T* array, unsigned int length, void f(T&))
{
	for (unsigned int i = 0; i < length; i++)
		f(array[i]);
}

#endif
