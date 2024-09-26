/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 21:14:17 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/25 16:02:24 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/AAnimal.hpp"
# include "../inc/Cat.hpp"
# include "../inc/Dog.hpp"

int main() {
	/*Dog base;
	{
		Dog tmp = base;
		base.setIdea(0, "test");
		std::cerr << "Perfect\n";
		std::cout << tmp.getIdea(0) << std::endl;
	}*/
	Dog basic;
	AAnimal basic2;
	{
		basic2.makeSound()
		basic.makeSound();
		basic.AAnimal::makeSound();
		Dog tmp = basic;
	}
	return 0;
}
