/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:43:07 by anovio-c          #+#    #+#             */
/*   Updated: 2024/10/02 16:36:50 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <stdexcept>
# include <stdint.h>

typedef struct Data {
	std::string	name;
	int			age;
	//Data		*next;
}				Data;

class Serializer {
	private:
	public:
		Serializer(void);
		Serializer(const Serializer &src);
		Serializer &operator=(const Serializer &src);
		~Serializer(void);

		static uintptr_t	serialize(Data* ptr);
		static Data			*deserialize(uintptr_t raw);	 
};
