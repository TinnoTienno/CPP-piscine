/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeList.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noda <noda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:15:17 by noda              #+#    #+#             */
/*   Updated: 2025/02/05 21:51:29 by noda             ###   ########.fr       */
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

		~PmergeMeList();
}	;


#endif