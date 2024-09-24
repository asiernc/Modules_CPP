/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 21:14:17 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/19 19:47:49 by anovio-c         ###   ########.fr       */
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

static void	testBrainDeepCopy(void) {
	Brain	*gyarados = new Brain();

	Brain	*lugia = new Brain();
	lugia->setIdea(0, "first idea");
	// assignment
	*gyarados = *lugia;
	std::cout << "Lugia 1st idea: " << lugia->getIdea(0) << std::endl;
	lugia->setIdea(0, "Another first idea");
	// copy constructor
	Brain *groudon = new Brain(*lugia);
	lugia->setIdea(0, "The third first idea");
	std::cout << "Lugia 2nd idea: " << lugia->getIdea(0) << std::endl;
	delete lugia;
	std::cout << "groundon 3st idea: " << groudon->getIdea(0) << std::endl;
	delete groudon;
	std::cout << "Gyarados 1st idea: " << gyarados->getIdea(0) << std::endl;
	delete gyarados;
}

static void testBrainCatDeepCopy(void) {
	Cat	*negro = new Cat();

	Cat *blanco = new Cat();
	blanco->setIdea(0, "brrrrrrr");
	*negro = *blanco;
	blanco->setIdea(0, "miaauuuuu");
	std::cout << GREEN << "Negro's first idea: " << negro->getIdea(0) << RESET << std::endl;
	delete negro;
	std::cout << GREEN << "Blanco's first idea : " << blanco->getIdea(0) << RESET << std::endl;
	std::cout << GREEN << "Setting new first idea in blanco (not brrr)" << RESET << std::endl;
	blanco->setIdea(0, "BRRRRRRRR");
	std::cout << GREEN << "Blanco's second idea: " << blanco->getIdea(0) << RESET << std::endl;
	delete blanco;
}

static void	testExercise(void) {
	Animal *animals[MAX_IDEAS];
	
	std::cout << std::endl << "______________________________" << std::endl;
	for (int i = 0; i < MAX_IDEAS; i++) {
		if (i % 2 == 0)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
		std::cout << "\t";
		animals[i]->makeSound();
	}
	std::cout << std::endl << "______________________________" << std::endl << std::endl;
	for (int i = 0; i < MAX_IDEAS; i++) {
		std::string	idea = (i % 2 == 0) ? "Chase mice" : "Fetch ball";
		animals[i]->setIdea(i, idea);
		std::cout << animals[i]->getType() << "'s idea: " << animals[i]->getIdea(i) << std::endl;
	}
	std::cout << std::endl << "______________________________" << std::endl << std::endl;
	for (int i = 0; i < MAX_IDEAS; i++) {
		delete animals[i];
	}
}

int main() {
	std::string str;
	
	std::cout << "Write 1 for run brain deepcopy test" << std::endl;
	std::cout << "Write 2 for cat brain deepcopy test" << std::endl;
	std::cout << "Write 3 for run exercise test" << std::endl;
	if (std::getline(std::cin, str) && str != "") {
		switch (str[0]) {
			case '1':
				testBrainDeepCopy();
				break ;
			case '2':
				testBrainCatDeepCopy();
				break ;
			case '3':
				testExercise();
				break ;
			default:
				break ;
		}
	}
	return 0;
}
