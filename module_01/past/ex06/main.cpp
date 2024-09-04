/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 20:00:24 by anovio-c          #+#    #+#             */
/*   Updated: 2024/08/15 21:47:17 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char *argv[]) {
	Harl		harl;
	std::string	str;

	if (argc != 2)
		std::cout << "What happens if I change the argument?" << std::endl;
	str = std::string(argv[1]);
	if (str.size() && harl.complain(str))
		return (0);
	else {
		std::cout << "What happens if I change the argument another time?" << std::endl;
		return (1);
	}
}
