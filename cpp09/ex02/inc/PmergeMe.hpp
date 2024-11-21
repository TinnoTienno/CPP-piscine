/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:53:45 by eschussl          #+#    #+#             */
/*   Updated: 2024/11/21 15:55:04 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <list>
# include <vector>
# include <string>
#include <ctime>

class PmergeMe
{
	private :
		unsigned int m_size;
		std::list<unsigned int> m_list;
		std::vector<unsigned int> m_vector;
		std::clock_t starttime;
		std::clock_t m_list_compute_time;
		std::clock_t m_vector_compute_time;
		void toList(const std::string &);
	public :
		PmergeMe();
		PmergeMe(const std::string&);
		PmergeMe(const PmergeMe&);
		PmergeMe& operator=(const PmergeMe&);
		~PmergeMe();
		
		void printList() const;
		void printVector() const;
		void printListCompTime() const;
		void printVectorCompTime() const;
}	;
#endif