/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:55:28 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/06 15:31:12 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
#include <stdint.h>
#include <iostream>

typedef struct Data
{
	int nb;
}	Data;

class Serializer
{
	public :
		Serializer();
		Serializer(const Serializer&);
		const Serializer& operator=(const Serializer&);
		virtual ~Serializer() = 0;

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
}	;
#endif