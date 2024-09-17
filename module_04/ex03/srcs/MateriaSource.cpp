/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 21:31:07 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/11 20:35:06 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < INVENTORY_SIZE; i++)
		this->_materiasLearned[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &src) {
	*this = src;
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &src) {
	if (this != &src) {
		for (int i = 0; i < INVENTORY_SIZE; i++) {
			if (this->_materiasLearned[i])
				delete this->_materiasLearned[i];
			if (src._materiasLearned[i])
				this->_materiasLearned[i] = src._materiasLearned[i];
			else
				this->_materiasLearned[i] = NULL;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < INVENTORY_SIZE; i++) {
		if (this->_materiasLearned[i])
			delete this->_materiasLearned[i];
	}
}

void	MateriaSource::learnMateria(AMateria *materia) {
	for (int i = 0; i < INVENTORY_SIZE; i++) {
		if (this->_materiasLearned[i] == NULL) {
			this->_materiasLearned[i] = materia;
			std::cout << "Learning " << materia->getType() << " materia..." << std::endl;
			return ;
		}
	}
	std::cout << "My brain is full. Deleting materia..." << std::endl;
	delete materia;
}

AMateria	*MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < INVENTORY_SIZE; i++) {
		if (this->_materiasLearned[i] != NULL
			&& this->_materiasLearned[i]->getType() == type)
			return (this->_materiasLearned[i]->clone());
		else
			continue;
	}
	return (0);
}
