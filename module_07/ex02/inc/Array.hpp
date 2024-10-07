/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:04:21 by anovio-c          #+#    #+#             */
/*   Updated: 2024/10/07 20:49:24 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <stdexcept>

template<typename T>
class Array {
	private:
		unsigned int	_size;
		T				*_arr;

	public:
		Array(void) : _size(0) {
			std::cout << "Default constructor." << std::endl;
			this->_arr = new T[this->_size];
		};
		Array(unsigned int n) : _size(n) {
			std::cout << "Param constructor." << std::endl;
			this->_arr = new T[this->_size];
		};
		Array(const Array &src) : _arr(NULL) {
			std::cout << "Copy constructor." << std::endl;
			*this = src;
		};
		Array	&operator=(const Array &src) {
			if (this->_arr)
				delete [] this->_arr;
			if (src._size) {
				this->_size = src._size;
				this->_arr = new T[this->_size];
				for (unsigned int i = 0; i < this->_size; i++)
					this->_arr[i] = src._arr[i];
			}
			return (*this);
		};
		~Array(void) {
			if (this->_arr)
				delete [] this->_arr;
		};

		T	&operator[](unsigned int num) {
			if (this->_arr && num <= this->_size)
				return (this->_arr[num]);
			else
				throw accessDenied();
		};

		unsigned int	size(void) {
			return (this->_size);
		};
		
		class accessDenied : public std::exception {
			public:
				virtual const char* what(void) const throw() {
					return ("Index access to the array is prohibited.");
				}
		};
};

//# include "../srcs/Array.tpp"
//  : _size(0) {
// 			this->_arr = new T[this->_arr]
// 		};
