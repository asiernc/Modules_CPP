/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 19:50:22 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/04 21:23:31 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include "Brain.hpp"

# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m" 

class AAnimal {
	protected:
		std::string _type;
		AAnimal(void);
		AAnimal(std::string type);

	public:
		AAnimal(const AAnimal &src);
		AAnimal &operator=(const AAnimal &src);
		virtual ~AAnimal(void);

		std::string	getType(void) const;
		virtual void	makeSound(void) const;
		// Sí, al declarar funciones como virtuales en la clase base Animal, permites
		// que las clases derivadas sobrescriban estas funciones. Esto habilita el
		// polimorfismo, lo que significa que puedes llamar a las funciones de las
		// clases derivadas a través de un puntero o referencia a la clase base.
		virtual	void		setIdea(int index, const std::string &idea) = 0;
		virtual std::string	getIdea(int index) = 0;
		//virtual Brain	*getBrain(void) = 0;
};

#endif
