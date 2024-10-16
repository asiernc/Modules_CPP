/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:08:24 by anovio-c          #+#    #+#             */
/*   Updated: 2024/10/15 15:50:45 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <deque>
#include <list>

// queremos modificar o añadir un comportamiento determinado a un contenedor
// que no permite eso. Hacemos una clase que herede de base la clase stack con
// sus funciones miembro pertinentes, push, pop top...
// y añadimos el sufijo <T> para que acepte cualquier tipo de dato dentro,
// y el MutantStack<T> para que pueda la clase ser el tipo que sea, int, char*..

template<typename T>
class MutantStack : public std::stack<T> {
	public:
		typedef typename std::deque<T>::iterator 		iterator;
		typedef typename std::deque<T>::const_iterator	const_iterator;
		
		MutantStack<T>(void);
		MutantStack<T>(const MutantStack<T> &src);
		MutantStack<T> &operator=(const MutantStack<T> &src);
		~MutantStack<T>(void);

		iterator		begin(void);
		iterator		end(void);
		const_iterator	begin(void) const;
		const_iterator	end(void) const;
};

#include "../srcs/MutantStack.tpp"
