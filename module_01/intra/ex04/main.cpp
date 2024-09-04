/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 21:28:32 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/03 10:39:38 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

static int	openFile(std::fstream &filepath, std::string path) {
	filepath.open(path.c_str(), std::fstream::in);
	if (!filepath) {
		std::cout << "Error opening the filepath." << std::endl;
		return (1);
	}
	return (0);
}

static int	createNewFile(std::fstream &newFileObj, std::string newPath) {
	newFileObj.open(newPath.c_str(), std::fstream::out);
	if (!newFileObj) {
		std::cout << "Error creating the new filepath." << std::endl;
		return (1);
	}
	return (0);
}

static void	replaceFileStrings(std::fstream &oldFilepath, std::fstream &newFilepath, std::string s1, std::string s2) {
	std::string	line;
	bool		firstLine = true;

	if (!oldFilepath.is_open()) {
        std::cerr << "Error: oldFilepath is not open." << std::endl;
        return;
    }
    if (!newFilepath.is_open()) {
        std::cerr << "Error: newFilepath is not open." << std::endl;
        return;
    }
	while (std::getline(oldFilepath, line)) {
		if (!firstLine)
			newFilepath << std::endl;
		firstLine = false;
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

int main(int argc, char **argv) {
	std::fstream	fileObj;
	std::fstream	newFileObj;
	std::string		newFilepathExtension = ".replace";
	
	if (argc != 4 || std::string(argv[2]).empty()) {
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
	replaceFileStrings(fileObj, newFileObj, std::string(argv[2]), std::string(argv[3]));
	fileObj.close();
	newFileObj.close();
}
