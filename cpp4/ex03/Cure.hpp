/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:29:43 by mvoisin           #+#    #+#             */
/*   Updated: 2025/04/08 18:12:41 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "AMateria.hpp"

class Cure : public AMateria {
	public:
		Cure							( void );
		Cure							( Cure const &rhs );
		virtual ~Cure					( void );
		Cure 			&operator=		( Cure const &rhs );
		AMateria		*clone			( void ) const;
		void			use				( ICharacter &target);
};
