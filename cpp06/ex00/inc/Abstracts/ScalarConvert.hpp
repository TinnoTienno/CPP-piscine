/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:15:44 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/05 17:54:12 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <string>

enum Type
{
	Char, Int, Float, Double, Other
} ;

class ScalarConvert
{
	public:
		ScalarConvert();
		ScalarConvert(const ScalarConvert&);
		ScalarConvert& operator=(const ScalarConvert&);
		virtual ~ScalarConvert() = 0;
	
		static void Convert(const std::string&);
};


#endif