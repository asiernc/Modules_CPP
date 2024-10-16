/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:41:59 by anovio-c          #+#    #+#             */
/*   Updated: 2024/10/15 11:35:47 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Span.hpp"

Span::Span(void) : _maxSize(0) {
	
}

Span::Span(unsigned int size) : _maxSize(size) {
	std::cout << "Span is created with size " << size << std::endl;
}

Span::Span(const Span &src) : _maxSize(src._maxSize) {
	*this = src;
}

Span	&Span::operator=(const Span &src) {
	if (this != &src)
		this->_container = src._container;
	return (*this);
}

Span::~Span(void) {
	
}

void	Span::addNumber(unsigned int num) {
	if (this->_container.size() == this->_maxSize)
		throw maxReached();
	this->_container.push_back(num);
}

unsigned int	Span::shortestSpan(void) {
	if (this->_container.size() < 2) {
		if (this->_container.empty())
			throw emptyArray();
		else
			throw onlyOne();
	}
	std::sort(_container.begin(), _container.end());
	std::vector<unsigned int>::iterator it = this->_container.begin();
	unsigned int shortestSpan = UINT_MAX;
	for (; it != this->_container.end() - 1; ++it) {
		unsigned int newSpan = *(it + 1) - *it;
		if (newSpan < shortestSpan)
			shortestSpan = newSpan;
	}
	return (shortestSpan);
}

unsigned int	Span::longestSpan(void) {
	if (this->_container.size() < 2) {
		if (this->_container.empty())
			throw emptyArray();
		else
			throw onlyOne();
	}
	std::sort(_container.begin(), _container.end());
	unsigned int longestSpan = this->_container.back() - this->_container.front();
	return (longestSpan);
}

void	Span::fillRandom(unsigned int size) {
	if (size == 0)
        throw moreThanOne();
    // Verificar si el nuevo tamaño excede la capacidad
    if (this->_container.size() + size > this->_maxSize)
        throw sizeMax();
	srand(time(NULL));
	for (unsigned int i = 0; i < size; i++)
		this->addNumber(static_cast<unsigned int>(rand()));
}

void	Span::showArray(void) {
	if (this->_container.size() > 0) {
		std::vector<unsigned int>::iterator it = this->_container.begin();
		for (; it != this->_container.end(); it++) {
			if (*(it + 1))
				std::cout << *it << " - ";
			else
				std::cout << *it << std::endl;
		}
	}
}

void	Span::cleanVector(void) {
	if (this->_container.empty())
		this->_container.clear();
}
