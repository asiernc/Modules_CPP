/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:20:47 by anovio-c          #+#    #+#             */
/*   Updated: 2024/10/18 12:34:03 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <deque>
#include <stdbool.h>



class PmergeMe {
	private:

	public:
		PmergeMe(void);
		PmergeMe(std::string algo);
		PmergeMe(const PmergeMe &src);
		PmergeMe	&operator=(const PmergeMe &src);
		~PmergeMe(void);
};
