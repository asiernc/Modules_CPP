/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 19:52:07 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/03 13:12:34 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Brain.hpp"

Brain::Brain()  {
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &src) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = src;
}

Brain	&Brain::operator=(const Brain &src) {
	std::cout << "Brain equal operator called" << std::endl;
	//if (this != &src)
	*this->_ideas = *src._ideas;
	return (*this);
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

void	Brain::setIdea(int index, std::string idea) {
	if (index >= 0 && index < MAX_IDEAS)
		this->_ideas[index] = idea;
}

std::string	Brain::getIdea(int index) {
	std::string tmp;

	if (this->_ideas[index].empty())
		return ("Empty");
	return (this->_ideas[index]);
}
