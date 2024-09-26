/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 21:19:59 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/25 15:48:58 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

# define RESET   "\033[0m"
# define RED     "\033[31m"
# define YELLOW  "\033[33m"
# define GREEN   "\033[32m" 


class ICharacter;

class AMateria	{
	protected:
			std::string _type;
			AMateria(void);
	public:
		AMateria(std::string const &src);
		AMateria(const AMateria &src);
		AMateria	&operator=(const AMateria &src);
		virtual 	~AMateria(void);
		const std::string	&getType(void) const;
		virtual AMateria	*clone() const = 0;
		virtual void 		use(ICharacter& target);
};

#endif
