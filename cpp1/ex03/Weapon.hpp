/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 20:14:45 by Matprod           #+#    #+#             */
/*   Updated: 2025/03/09 20:50:56 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include "iostream"
#include "iomanip"
#include "cstdlib"
#include <string>

typedef	std::string string;

class Weapon {
	public:
		const string	&getType();
		void			setType(string type);
		Weapon();
		Weapon(string type);
		~Weapon();
	private:
		string _type;
};


#endif
