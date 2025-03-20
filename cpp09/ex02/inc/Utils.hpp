/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noda <noda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:29:04 by noda              #+#    #+#             */
/*   Updated: 2025/02/07 16:12:06 by noda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <sstream>
#include <ctime>
#include <iostream>
#include <list>
#include <vector>

std::string utoa(unsigned int nb);
float	getTime();
unsigned int getJacob(const unsigned int &nb);
void	printList(std::list<unsigned int> list);
void	printVec(std::vector<unsigned int> vector);