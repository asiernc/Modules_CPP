/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 21:28:32 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/02 19:14:44 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

static int	openFile(std::fstream &filepath, std::string path) {
	// std::fstream::in: Abre el archivo especificado por path en modo de lectura.
	filepath.open(path, std::fstream::in);
	if (!filepath) {
		std::cout << "Error opening the filepath." << std::endl;
		return (1);
	}
	return (0);
}

static int	createNewFile(std::fstream &newFileObj, std::string newPath) {
	// newPath es un objeto de tipo std::string. El método c_str() de std::string
	// convierte el std::string en un puntero a un array de caracteres
	// (const char*), que es lo que ofstream espera como argumento. Este array de
	// caracteres representa el nombre del archivo que se va a abrir o crear.
	
	// std::fstream::out se usa para crear un archivo nuevo o sobrescribir uno existente.
	newFileObj.open(newPath.c_str(), std::fstream::out);
	if (!newFileObj) {
		std::cout << "Error creating the new filepath." << std::endl;
		return (1);
	}
	return (0);
}

static void	replaceFilepath(std::fstream &oldFilepath, std::fstream &newFilepath, std::string s1, std::string s2) {
	std::string	line;
	bool		endLine = false;

	while (std::getline(oldFilepath, line)) {
		if (endLine)
			newFilepath << std::endl;
		endLine = true;
		std::size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos) {
			newFilepath << line.substr(0, pos);
			newFilepath << s2;
			line = line.substr(pos + s1.size());
			pos = 0;
		}
		newFilepath << line;
	}
}

int main(int argc, char *argv[]) {
	std::string		s1;
	std::fstream	fileObj;
	std::fstream	newFileObj;
	std::string		newFilepathExtension = ".replace";
	
	if (argc != 4 || std::string(argv[1]).empty()) {
		std::cout << "Please use ./sedIsForLosers <filepathpath> <string1> <string2>" << std::endl;
		return (1);
	}
	if (openFile(fileObj, argv[1]))
		return (1);
	newFilepathExtension.insert(0, argv[1]);
	if (createNewFile(newFileObj, newFilepathExtension)) {
		fileObj.close();
		return (1);
	}
	replaceFilepath(fileObj, newFileObj, std::string(argv[2]), std::string(argv[3]));
	fileObj.close();
	newFileObj.close();
}
