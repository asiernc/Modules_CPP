/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:43:07 by anovio-c          #+#    #+#             */
/*   Updated: 2024/10/02 20:56:33 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <stdint.h>

typedef struct Data {
	std::string	name;
	int			age;
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
