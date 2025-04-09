/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:34:37 by mvoisin           #+#    #+#             */
/*   Updated: 2025/04/08 18:48:05 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# define MAX_MATERIA 4

#include "ICharacter.hpp"
#include "AMateria.hpp"
class Character : public ICharacter
{
	private:
		std::string		_name;
		AMateria		*_inventory[MAX_MATERIA];
		int				_materiaCount;

	public:
		Character					( void );
		Character					( string name );
		Character					( Character const &rhs );
		Character		&operator=	( Character const &rhs );
		~Character					( void );

		string const	&getName	( void ) const;
		void 			equip		( AMateria* materia );
		void			unequip		( int idx );
		void			use			( int idx, ICharacter &target );
};