/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:05:47 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/05 20:07:01 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP

# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>
# include <stdbool.h>

class ScavTrap : virtual public ClapTrap {
	protected:
		bool	_gateMode;
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &src);
		ScavTrap	&operator=(const ScavTrap &src);
		~ScavTrap(void);

		void		sayHello(void);
		void 		attack(const std::string& target);
		bool		getGuardGate(void) const;
		void 		guardGate(void);
};

#endif
