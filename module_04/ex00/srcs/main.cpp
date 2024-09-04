/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 21:14:17 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/03 17:27:55 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/Animal.hpp"
# include "../inc/Cat.hpp"
# include "../inc/Dog.hpp"
# include "../inc/WrongAnimal.hpp"
# include "../inc/WrongCat.hpp"

int main() {
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << meta->getType() << " " << std::endl;
    meta->makeSound();
	std::cout << j->getType() << " " << std::endl;
	j->makeSound();
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!

	delete meta;
	delete j;
	delete i;

	std::cout << "_________________________" << std::endl << std::endl;

	// la linea manolo = cat()
	// causa una fragmentacion del objeto, porque estoy asignando a un objeto
	// tipo animal , un tipo cat, lo que hace que solo la parte Animal es
	// asignada a manolo, cortandose la parte Cat.
	Animal manolo = Animal();
	manolo.makeSound();
	manolo = Cat();
	manolo.makeSound();
	
	std::cout << "_________________________" << std::endl << std::endl;

	Animal asier = Animal();
	std::cout << asier.getType() << " " << std::endl;
	asier.makeSound();
	
	Cat cat;
	Animal &asierRef = cat;
	std::cout << asierRef.getType() << " " << std::endl;
	asierRef.makeSound();
	
	std::cout << "_________________________" << std::endl << std::endl;
	
	const WrongAnimal* meta2 = new WrongAnimal();
	const WrongAnimal* i2 = new WrongCat();

	std::cout << meta2->getType() << " " << std::endl;
    meta2->makeSound();
	std::cout << i2->getType() << " " << std::endl;
	i2->makeSound();
	
	delete meta2;
	delete i2;

		std::cout << "_________________________" << std::endl << std::endl;

	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << std::endl;
	wrongCat->makeSound();
	wrongAnimal->makeSound();

	delete wrongAnimal;
	delete wrongCat;
	
	return 0;
}
