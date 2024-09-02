/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 19:50:22 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/01 21:44:31 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP

# define ANIMAL_HPP

# include <iostream>

class Dog {
	protected:
		std::string _type;

	public:
		Dog(void);
		Dog(std::string type);
		Dog(const Dog &src);
		Dog &operator=(const Dog &src);
		virtual ~Dog(void);

		std::string	getType(void) const;
		virtual void		makeSound(void) const;
};

#endif
