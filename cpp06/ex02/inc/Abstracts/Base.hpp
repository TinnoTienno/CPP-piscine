/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:41:09 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/06 15:48:02 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

class Base
{
	public :
		virtual ~Base();
}	;

class A : public Base{ } ;
class B : public Base{ } ;
class C : public Base{ } ;

#endif