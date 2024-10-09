/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:04:21 by anovio-c          #+#    #+#             */
/*   Updated: 2024/10/08 11:26:38 by anovio-c         ###   ########.fr       */
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
			std::cout << "Creating new empty array of size " << n << "..." << std::endl;
			this->_arr = new T[this->_size];
		};
		Array(const Array &src) : _arr(NULL) {
			std::cout << "Copy constructor." << std::endl;
			std::cout << "Creating a new copy of the array, size " << src.size() << "..." << std::endl;
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
			if (this->_size > 0)
				delete [] this->_arr;
		};

		T	&operator[](const int num) {
			if (num < 0 || static_cast<unsigned int>(num) >= this->_size)
				throw Array<T>::accessDenied();
			return (this->_arr[num]);
		};

		unsigned int	size(void) const {
			return (this->_size);
		};

		void	showArray(void) {
			if (this->_size > 0) {
				for (unsigned int i = 0; i < this->_size; i++)
					std::cout << this->_arr[i] << " - ";
				std::cout << std::endl;
			}
			return ;
		}
		
		class accessDenied : public std::exception {
			public:
				virtual const char* what(void) const throw() {
					return ("Index access to the array is out of range.");
				}
		};
};
