/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 21:41:41 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/06 22:05:40 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria {
	private:
	
	public:
		Cure(void);
		Cure(const Cure &src);
		Cure	&operator=(const Cure &src);
		~Cure(void);

		Cure	*clone() const;
		void 		use(ICharacter& target);
};

#endif