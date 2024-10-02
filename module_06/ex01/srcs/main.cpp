/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:54:44 by anovio-c          #+#    #+#             */
/*   Updated: 2024/10/02 16:39:49 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(int argc, char **argv) {
	Data	*data1 = NULL;
	

	/*if (argc != 3) {
		std::cerr << "Please use: ./programName <name> <age>" << std::endl;
		return (1);
	}*/
	data1 = new Data;
	data1->name = "Asier";
	data1->age = 26;

	(void)argv;
	(void)argc;
	(void)data1;
	std::cout << "Data Structure:" << std::endl;
	std::cout << "Name: " << data1->name << std::endl;
	std::cout << "Age: " << data1->age << std::endl;
	uintptr_t ptr = Serializer::serialize(data1);
	Data *data2 = Serializer::deserialize(ptr);

	std::cout << "Serializer: " << ptr << std::endl;
	std::cout << "Deserializer: " << data2->name << std::endl;
}