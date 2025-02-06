/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noda <noda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:29:04 by noda              #+#    #+#             */
/*   Updated: 2025/02/06 11:18:21 by noda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <sstream>
#include <ctime>
#include <iostream>
#include <list>

std::string utoa(unsigned int nb);
float	getTime();
unsigned int getJacob(const unsigned int &nb);
void	printList(std::list<unsigned int> list);