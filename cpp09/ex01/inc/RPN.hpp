/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:25:39 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/21 14:35:18 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP
# include <stack>

typedef enum e_token 
{
	DIGIT, 
	OPERATOR,
	UNDEFINED
}	e_token;

typedef enum e_operator
{
	ADD,
	SUBSTRACT,
	MULTIPLY,
	DIVIDE,
	OTHER
}	e_operator;

class RPN
{
	public :
		RPN();
		RPN(char *);
		RPN(const RPN&);
		RPN& operator=(const RPN&);
		~RPN();
	class WrongInputException : public std::exception
	{
		private :
			const char *m_arg;
		public :
			WrongInputException(const char *);
			~WrongInputException() throw();
			const char *getArg() const;
			virtual const char* what() const throw();
	}	;
		float getRes() const;
	private :
		std::stack<float> m_vals;
		float m_res;
		void compute(const e_operator&);
	
}	;

#endif