/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 21:28:32 by anovio-c          #+#    #+#             */
/*   Updated: 2024/08/15 12:33:54 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void	replaceFile(std::fstream &oldFile, std::fstream &newFile, std::string s1, std::string s2) {
	std::string	line;
	bool		endLine = false;

	while (std::getline(oldFile, line)) {
		if (endLine)
			newFile << std::endl;
		endLine = true;
		std::size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos) {
			newFile << line.substr(0, pos);
			newFile << s2;
			line = line.substr(pos + s1.size());
			pos = 0;
		}
		newFile << line;
	}
}

int main(int argc, char **argv) {
	std::fstream	file;
	std::string		newFileExtension = ".replace";
	
	if (argc != 4) { // || *argv[2]
		std::cout << "Please use ./sedIsForLosers <filepath> <string1> <string2>" << std::endl;
	}
	file.open(argv[1], std::fstream::in);
	if (!file) {
		std::cout << "Error opening the file." << std::endl;
		return (1);
	}
	newFileExtension.insert(0, argv[1]);
	std::cout << "new file extension: " << newFileExtension << std::endl;
	// new_str es un objeto de tipo std::string. El método c_str() de std::string
	// convierte el std::string en un puntero a un array de caracteres
	// (const char*), que es lo que ofstream espera como argumento. Este array de
	// caracteres representa el nombre del archivo que se va a abrir o crear.
	
	std::fstream newFile (newFileExtension.c_str(), std::fstream::out);
	if (!newFile) {
		std::cout << "Error creating the new file." << std::endl;
		file.close();
		return (1);
	}
	replaceFile(file, newFile, std::string(argv[2]), std::string(argv[3]));
	file.close();
	newFile.close();
}