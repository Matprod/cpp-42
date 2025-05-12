/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:18:19 by Matprod           #+#    #+#             */
/*   Updated: 2025/04/28 17:35:50 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

using std::string;
using std::exception;

class Intern {

	private:
		string _name;
	public:

		Intern				( void );
		Intern				(Intern const &rhs);
		Intern	&operator=	(Intern const &rhs);
		~Intern				( void );

		AForm *makeForm( string name, string target );

		class FormNotFoundException: public exception {
			public:
				virtual const char *what() const throw();
		};
};
