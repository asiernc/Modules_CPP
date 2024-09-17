/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 19:57:09 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/11 20:23:14 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"


class Dog : public AAnimal {
	private:
		Brain 		*_brain;

	public:	
		Dog(void);
		Dog(const Dog &src);
		Dog &operator=(const Dog &src);
		~Dog(void);

		std::string	getType(void) const;
		void		makeSound(void) const;
		void		setIdea(int index, const std::string &idea);
		std::string	getIdea(int index);
		
};

#endif
