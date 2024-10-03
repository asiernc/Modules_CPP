/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:47:26 by anovio-c          #+#    #+#             */
/*   Updated: 2024/10/03 15:17:20 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

#include <cstdlib>
#include <ctime>

// Base * generate(void);
// It randomly instanciates A, B or C and returns the instance as a Base pointer. Feel free
// to use anything you like for the random choice implementation.

// void identify(Base* p);
// It prints the actual type of the object pointed to by p: "A", "B" or "C".

// void identify(Base& p);
// It prints the actual type of the object pointed to by p: "A", "B" or "C". Using a pointer
// inside this function is forbidden.


// Including the typeinfo header is forbidden.
// Write a program to test that everything works as expected.

static Base *generate(void) {
	switch (std::rand() % 3) {
		case 1:
			return new A();
		case 2:
			return new B();
		case 3:
			return new C();
		default:
			std::cerr << "Error at generating the new class." << std::endl;
	}
}

static void	identify(Base *ptr) {
	if (dynamic_cast<A *>(ptr))
		std::cout << "The pointer was identified as A." << std::endl;
	else if (dynamic_cast<B*>(ptr))
		std::cout << "The pointer was identified as B." << std::endl;
	else if (dynamic_cast<C*>(ptr))
		std::cout << "The pointer was identified as C." << std::endl;
	else
		std::cout << "Pointer type not recognised." << std::endl;
}

static void	identify(Base &ptr) {
	
}

int main(void) {
	std::srand(std::time(0));
}