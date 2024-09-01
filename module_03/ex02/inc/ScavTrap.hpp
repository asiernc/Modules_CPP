/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 17:05:47 by anovio-c          #+#    #+#             */
/*   Updated: 2024/08/27 18:17:35 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP

# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>
# include <stdbool.h>

class ScavTrap : public ClapTrap {
	private:
		bool	_gateMode;
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &src);
		~ScavTrap();
		ScavTrap	&operator=(const ScavTrap &src);

		bool		getGuardGate(void) const;
		void 		guardGate(void);

};

#endif
