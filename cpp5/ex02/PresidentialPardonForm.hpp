/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:48:23 by Matprod           #+#    #+#             */
/*   Updated: 2025/04/28 16:48:26 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDONFORM_HPP
# define PRESIDENTIAL_PARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		string	_target;
	public:
		PresidentialPardonForm				( void );
		PresidentialPardonForm				( string target );
		PresidentialPardonForm				( PresidentialPardonForm const &rhs );
		PresidentialPardonForm	&operator=	( PresidentialPardonForm const &rhs );
		~PresidentialPardonForm				( void );

		void execute						(Bureaucrat const &executor) const;
};

#endif