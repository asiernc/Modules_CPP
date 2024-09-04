/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 21:14:17 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/04 10:44:44 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/Animal.hpp"
# include "../inc/Cat.hpp"
# include "../inc/Dog.hpp"

// In your main function, create and fill an array of Animal objects. Half of it
// will be Dog objects and the other half will be Cat objects. At the end of your
// program execution, loop over this array and delete every Animal. You must
// delete directly dogs and cats as Animals. The appropriate destructors must be
// called in the expected order.

int main() {
	std::cout << "Fill an array of Animal objects" << std::endl;

	Animal *animals[MAX_IDEAS];
	
	for (int i = 0; i < MAX_IDEAS; i++) {
		if (i % 2 == 0)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
		//animals[i]->makeSound();
	}
	animals[0]->setIdea(0, "I'm a cat");
	std::cout << animals[0]->getType() << "'s idea: " << animals[0]->getIdea(0) << std::endl;
	for (int i = 0; i < MAX_IDEAS; i++) {
		std::string	idea = (i % 2 == 0) ? "Chase mice" : "Fetch ball";
		animals[i]->setIdea(i, idea);
		std::cout << animals[i]->getType() << "'s idea: " << animals[i]->getIdea(i) << std::endl;
	}

	for (int i = 0; i < MAX_IDEAS; i++) {
		delete animals[i];
	}
	
	return 0;
}
