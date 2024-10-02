/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:49:34 by anovio-c          #+#    #+#             */
/*   Updated: 2024/10/02 15:54:33 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void) {
	std::cout << "Default constructor called." << std::endl;
}

Serializer::Serializer(const Serializer &src) {
	std::cout << "Default constructor called." << std::endl;
	*this = src;
}

Serializer &Serializer::operator=(const Serializer &src) {
	std::cout << "Equal operator" << std::endl;
	(void)src;
	return *this;
}

Serializer::~Serializer(void) {
	std::cout << "Default destructor called." << std::endl;
}

uintptr_t	Serializer::serialize(Data *ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data		*Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}