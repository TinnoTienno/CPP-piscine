/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noda <noda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:29:04 by noda              #+#    #+#             */
/*   Updated: 2025/02/01 12:32:45 by noda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <sstream>
#include <ctime>
#include <iostream>

std::string utoa(unsigned int nb);
float	getTime();
void	memswap(unsigned int *ptr1, unsigned int *ptr2, size_t swapsize);