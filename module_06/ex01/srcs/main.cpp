/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:54:44 by anovio-c          #+#    #+#             */
/*   Updated: 2024/10/02 20:56:42 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(int argc, char **argv) {
	if (argc != 1) {
		std::cerr << "Please use: ./programName" << std::endl;
		return (1);
	}
	(void)argv;
	Data	*data = new Data;
	
	std::cout << "Initialising the machine that creates specimens..." << std::endl;
	// Human name
	std::cout << "Enter human's name: " << std::endl;
    std::string str;
    while (true) {
        std::getline(std::cin, str);
        if (!str.empty()) {
            data->name = str;
            break;
        } else {
            std::cout << "Name cannot be empty. Please enter a valid name." << std::endl;
        }
    }
	// Human age
	std::cout << "Enter human's age: " << std::endl;
	int age = 0;
	while (true) {
		std::cin >> age;
		if (std::cin.fail()) {  // Check for invalid input
			std::cin.clear();  // Clear the fail state
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discard invalid input
			std::cout << "Invalid age. Please enter a valid integer." << std::endl;
		} else {
			data->age = age;
			break;
		}
	}
	std::cout << "Creating new human..." << std::endl;
	std::cout << "Name: " << data->name << std::endl;
	std::cout << "Age: " << data->age << std::endl;
	
	
	uintptr_t ptr = Serializer::serialize(data);
	std::cout << "Unsigned int returned: " << ptr << std::endl;

	Data *dataCopy = Serializer::deserialize(ptr);
	std::cout << "Deserializer complete. New element copy created." << std::endl;
	std::cout << "Unsigned int returned: " << Serializer::serialize(dataCopy) << std::endl;
	std::cout << "Human copy name: " << dataCopy->name << std::endl;
	std::cout << "Human copy age: " << dataCopy->age << std::endl;

	std::cout << "Deleting structures..." << std::endl;
	delete data;
	return (0);
}
