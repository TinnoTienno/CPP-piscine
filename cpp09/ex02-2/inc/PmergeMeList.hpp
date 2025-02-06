/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeList.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noda <noda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:15:17 by noda              #+#    #+#             */
/*   Updated: 2025/02/06 01:58:10 by noda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEMELIST_HPP
# define PMERGEMELIST_HPP
# include "PmergeMe.hpp"
# include <list>
# include <iterator>

class PmergeMeList : public PmergeMe
{
	private :
		std::list<unsigned int> m_list;
	public :
		PmergeMeList();
		PmergeMeList(const std::string &list);
		std::string print() const;
		void		sort();
		void		mergeSort(size_t &level);
		void		binaryInsertionSort(size_t &level);
		void		oddFill(std::list<unsigned int> &odd, size_t level);
		void		pendFill(std::list<unsigned int> &pend, size_t level);
		std::list<unsigned int>::iterator binarySearch(unsigned int value, std::list<unsigned int>::iterator lowerbound, std::list<unsigned int>::iterator higherbound, size_t level);
		void 		jacobsthalSort(std::list<unsigned int> &pend, size_t level);
		std::list<unsigned int>::iterator higherBound(unsigned int i, size_t level);

		~PmergeMeList();
}	;


#endif