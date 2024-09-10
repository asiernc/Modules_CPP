/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 21:19:59 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/07 21:20:41 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class AMateria	{
	protected:
			std::string _type;
			AMateria(void);
	public:
		AMateria(std::string const &src);
		AMateria	&operator=(const AMateria &src);
		virtual ~AMateria(void);
		const std::string	&getType(void) const;
		virtual AMateria	*clone() const = 0;
		virtual void 		use(ICharacter& target);
};

#endif