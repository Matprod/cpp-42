/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:49:03 by Matprod           #+#    #+#             */
/*   Updated: 2025/04/28 16:49:06 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

using std::ofstream;
using std::ifstream;

class ShrubberyCreationForm : public AForm
{
	private:
		string	_target;
	public:
		ShrubberyCreationForm				( void );
		ShrubberyCreationForm				( string target );
		ShrubberyCreationForm				( ShrubberyCreationForm const &rhs );
		ShrubberyCreationForm	&operator=	( ShrubberyCreationForm const &rhs );
		~ShrubberyCreationForm				( void );

		void execute						(Bureaucrat const &executor) const;
};

#endif