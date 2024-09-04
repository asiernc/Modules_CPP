/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 20:00:24 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/02 19:17:28 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char *argv[]) {
	Harl		harl;
	//std::string	str;

	if (argc != 2) {
		std::cout << "What happens if I change the argument?" << std::endl;
		std::cout << "Hint: 'DEBUG', 'INFO', 'WARNING' OR 'ERROR'" << std::endl;
		return (1);
	}
	//str = std::string(argv[1]);
	if (harl.complain(std::string(argv[1])))
		return (0);
	else {
		std::cout << "What happens if I change the argument another time?" << std::endl;
		return (1);
	}
}
