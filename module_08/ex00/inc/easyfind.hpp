/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyFind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:04:21 by anovio-c          #+#    #+#             */
/*   Updated: 2024/10/08 17:09:50 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include <algorithm>
#include <array>


class notFind : public std::exception {
	public:
		virtual const char *what(void) const throw() {
			return ("This parameter was not found in the container of ints.");
		};
};

// Iterator std::find(Iterator first, Iterator last, const T& value);
template<typename T>
typename T::iterator	easyfind(T &src, int toFind) {
	typename T::iterator	it = std::find(src.begin(), src.end(), toFind);
	if (it == src.end())
		throw notFind();
	return (it);
}
