/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 19:50:22 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/04 10:35:28 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include "Brain.hpp"

class Animal {
	protected:
		std::string _type;

	public:
		Animal(void);
		Animal(std::string type);
		Animal(const Animal &src);
		Animal &operator=(const Animal &src);
		virtual ~Animal(void);

		std::string	getType(void) const;
		virtual void	makeSound(void) const;
		// Sí, al declarar funciones como virtuales en la clase base Animal, permites
		// que las clases derivadas sobrescriban estas funciones. Esto habilita el
		// polimorfismo, lo que significa que puedes llamar a las funciones de las
		// clases derivadas a través de un puntero o referencia a la clase base.
		virtual	void		setIdea(int index, std::string idea) = 0;
		virtual std::string	getIdea(int index) = 0;
};

#endif
