/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:53:45 by eschussl          #+#    #+#             */
/*   Updated: 2025/03/20 15:17:11 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <list>
# include <vector>
# include <string>
#include <ctime>
#include <iostream>

class PmergeMe
{
	protected :
		clock_t m_starttime;
		float m_endtime;
	public :
		PmergeMe();
		PmergeMe(const PmergeMe&);
		PmergeMe& operator=(const PmergeMe&);
		virtual ~PmergeMe();
		void		sort();
		virtual size_t		getSize() = 0;
		
		std::string			getDuration() const;
		void				setDuration();
		virtual std::string print() const = 0;
		virtual void		mergeSort(size_t &level) = 0;
		virtual void		binaryInsertionSort(size_t &level) = 0;
}	;

std::ostream &operator<<(std::ostream &os, const PmergeMe &obj);

#endif