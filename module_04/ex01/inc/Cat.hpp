/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 20:23:30 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/04 13:12:58 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal {
	private:
		Brain	*_brain;

	public:
		Cat(void);
		Cat(const Cat &src);
		Cat &operator=(const Cat &src);
		~Cat(void);

		std::string	getType(void) const;
		void makeSound(void) const ;
		Brain	*getBrain(void) const;
		void	setIdea(int index, std::string idea);
		std::string	getIdea(int index);
};

#endif
