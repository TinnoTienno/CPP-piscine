/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:50:45 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/06 17:46:20 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATES_HPP
# define TEMPLATES_HPP

template <typename T>

void swap(T& a, T& b)
{
	T c = a;
	a = b;
	b = c;
}

template <typename T>

T& min(T& a, T& b)
{
	return (a > b ? b : a);
}

template <typename T>
T& max(T& a, T& b)
{
	return (a > b ? a : b);
}
#endif
