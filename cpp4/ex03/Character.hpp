/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoisin <mvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:34:37 by mvoisin           #+#    #+#             */
/*   Updated: 2025/04/03 16:35:23 by mvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# define MAX_MATERIA 4

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