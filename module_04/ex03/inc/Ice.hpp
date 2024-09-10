/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 21:41:41 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/07 21:18:22 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria {
	private:
	
	public:
		Ice(void);
		Ice(const Ice &src);
		Ice	&operator=(const Ice &src);
		~Ice(void);

		Ice	*clone() const;
		void 		use(ICharacter& target);
};

#endif