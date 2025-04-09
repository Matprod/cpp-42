/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:29:36 by mvoisin           #+#    #+#             */
/*   Updated: 2025/04/08 18:12:34 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "AMateria.hpp"

class Ice : public AMateria {
	public:
		Ice							( void );
		Ice							( Ice const &rhs );
		virtual ~Ice				( void );
		Ice 			&operator=	( Ice const &rhs );
		AMateria		*clone		( void ) const;
		void			use			( ICharacter &target);
};
