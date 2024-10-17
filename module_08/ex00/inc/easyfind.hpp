/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:04:21 by anovio-c          #+#    #+#             */
/*   Updated: 2024/10/17 11:54:25 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include <algorithm>
#include <vector>


class notFind : public std::exception {
	public:
		virtual const char *what(void) const throw() {
			return ("This parameter was not found in the container.");
		};
};

// Iterator std::find(Iterator first, Iterator last, const T& value);
template<typename T>
void	easyfind(T &src, int toFind) {
	if (std::find(src.begin(), src.end(), toFind) != src.end() )
		std::cout << "Number '" << toFind << "' has been found in the container." << std::endl; 
	else
		throw notFind();
}
