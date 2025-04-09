/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:46:38 by Matprod           #+#    #+#             */
/*   Updated: 2025/04/08 19:46:49 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

# define MAX_MATERIA 4

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*_materia[MAX_MATERIA];
		int			_count;

	public:
		MateriaSource					( void );
		MateriaSource					( MateriaSource const &rhs );
		~MateriaSource					( void );
		MateriaSource	&operator=		( MateriaSource const &rhs );
		void			learnMateria	( AMateria *materia );
		AMateria		*createMateria	( string const &type );
};

#endif