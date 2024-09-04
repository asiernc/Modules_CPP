/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 20:17:32 by anovio-c          #+#    #+#             */
/*   Updated: 2024/08/14 21:23:56 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

// En este caso, el str _type de weapon se establece con setType, pero eso es
// menos eficiente si la asignacion no tiene ningun procesamiento. porque cuando
// se inicializa el constructor inicializa tambien _type y luego se le llama a
// la funcion setType, que lo unico que hace es asignarlo.
// Se solucionaria inicializando _type en la lista de inicializacion, justo despues de la
// declaracion del constructor. Asi conseguimos que se inicialice directamente con el valor
// que le asignamos.

// Weapon::Weapon(std::string type) : _type(type) {}

Weapon::Weapon(std::string type) {
	this->setType(type);
	std::cout << "Weapon is created and setted with: " << _type << std::endl;
}

Weapon::~Weapon() {
	//std::cout << "Destructor Weapon called" << std::endl;
}

const std::string	&Weapon::getType(void) {
	return (this->_type);
}

void	Weapon::setType(std::string type) {
	this->_type = type;
}
