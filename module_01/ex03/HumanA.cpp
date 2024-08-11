/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 20:47:49 by anovio-c          #+#    #+#             */
/*   Updated: 2024/08/10 21:18:55 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// ¿Por Qué Usar la Lista de Inicialización?
// Eficiencia: Al inicializar los miembros en la lista de inicialización, evitas
// primero crear un objeto con un constructor por defecto y luego asignarle un nuevo
// valor en el cuerpo del constructor.
// Referencias y Constantes: Las referencias y los miembros constantes deben ser
// inicializados en la lista de inicialización porque no pueden ser asignados
// después de que el objeto ha sido creado.

HumanA::HumanA(std::string name, Weapon &weapon) : _weapon(weapon) {
	std::cout << "Constructor of Player A" << std::endl;
	this->_name = name;
}

HumanA::~HumanA() {
}

void	HumanA::attack(void) {
	std::cout << this->_name 
		<< "attacks with their "
		<< this->_weapon.getType()
		<< std::endl;
}
