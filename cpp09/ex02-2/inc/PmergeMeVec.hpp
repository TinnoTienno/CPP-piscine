/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeVec.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noda <noda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:15:17 by noda              #+#    #+#             */
/*   Updated: 2025/02/07 17:23:28 by noda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEMEVEC_HPP
# define PMERGEMEVEC_HPP
# include "PmergeMe.hpp"
# include <vector>
# include <iterator>

class PmergeMevec : public PmergeMe
{
	private :
		std::vector<unsigned int> m_vector;
	public :
		PmergeMevec();
		PmergeMevec(const std::string &vector);
		size_t		getSize();
		std::string print() const;
		void		mergeSort(size_t &level);
		void		swap(size_t i1, size_t i2, size_t level);

		void		binaryInsertionSort(size_t &level);
		void		oddFill(std::vector<unsigned int> &odd, size_t level);
		void		pendFill(std::vector<unsigned int> &pend, size_t level);
		std::vector<unsigned int>::iterator binarySearch(unsigned int value, size_t lowerbound, size_t higherbound, size_t level);
		void 		jacobsthalSort(std::vector<unsigned int> &pend, size_t level);
		size_t 		higherBound(unsigned int i, size_t level);
		void		Insertion(std::vector<unsigned int> &pend, size_t level);
		

		~PmergeMevec();
}	;


#endif