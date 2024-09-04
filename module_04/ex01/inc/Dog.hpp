/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 19:57:09 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/03 20:33:38 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"


class Dog : public Animal {
	private:
		Brain *_brain;

	public:	
		Dog(void);
		Dog(const Dog &src);
		Dog &operator=(const Dog &src);
		~Dog(void);

		std::string	getType(void);
		void	makeSound(void) const;
		Brain	*getBrain(void);
		void	setIdea(int index, std::string &idea);
		std::string	getIdea(int index);
		
};

#endif
