/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:11:00 by anovio-c          #+#    #+#             */
/*   Updated: 2024/10/15 15:51:30 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template<class T>
MutantStack<T>::MutantStack(void) : std::stack<T>() {
	
}

template<class T>
MutantStack<T>::MutantStack(const MutantStack<T> &src) : std::stack<T>(src) {
	
}

template<class T>
MutantStack<T>	&MutantStack<T>::operator=(const MutantStack<T> &src) {
	if (this != &src)
		std::stack<T>::operator=(src);
	return (*this);
}

template<class T>
MutantStack<T>::~MutantStack(void) {
	
}

template<class T>
typename MutantStack<T>::iterator	MutantStack<T>::begin(void) {
	// c es el contenedor subyacente (deque, list, vector), donde se almacenan
	// los datos de la pila.
	// cuando se hereda std::stack se obtiene acceso a c, miembro protegido de std::stack
	return (this->c.begin());
}

template<class T>
typename MutantStack<T>::iterator	MutantStack<T>::end(void) {
	return (this->c.end());
}

template<class T>
typename MutantStack<T>::const_iterator	MutantStack<T>::begin(void) const {
	return (this->c.begin());
}

template<class T>
typename MutantStack<T>::const_iterator	MutantStack<T>::end(void) const {
	return (this->c.end());
}
