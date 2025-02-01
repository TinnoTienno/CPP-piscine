/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noda <noda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:53:45 by eschussl          #+#    #+#             */
/*   Updated: 2025/02/01 12:39:00 by noda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <list>
# include <vector>
# include <string>
#include <ctime>
#include <iostream>
# define K_SIZE 2

class PmergeMe
{
	private :
		float m_starttime;
		// std::clock_t m_list_compute_time;
	public :
		PmergeMe();
		PmergeMe(const std::string&);
		PmergeMe(const PmergeMe&);
		PmergeMe& operator=(const PmergeMe&);
		virtual ~PmergeMe();
		
		virtual std::string print() const = 0;
		std::string			getDuration() const;
		virtual void	pairSort(size_t level) = 0;

		// void printCompTime() const;
}	;

std::ostream &operator<<(std::ostream &os, const PmergeMe &obj);

#endif