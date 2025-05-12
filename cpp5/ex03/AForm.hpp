/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 17:46:19 by Matprod           #+#    #+#             */
/*   Updated: 2025/04/28 15:29:09 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Bureaucrat.hpp"

# define MAX_GRADE 1
# define MIN_GRADE 150

using std::string;
using std::cout;
using std::cin;
using std::exception;
using std::endl;

class Bureaucrat;

class	AForm {
	protected:
		string const	_name;
		bool			_signed;
		const int		_gradeToSign;
		const int		_gradeToExecute;
	public:
		AForm( void );
		AForm( string name, int gradeToSign, int gradeToExecute );
		AForm( AForm const & src );
		AForm	&operator=( AForm const & rhs );
		virtual ~AForm( void );

		string	getName( void ) const;
		bool	getSigned( void ) const;
		int		getGradeToSign( void ) const;
		int		getGradeToExecute( void ) const;

		void	beSigned( Bureaucrat const & bureaucrat );
		virtual void execute(Bureaucrat const &executor) const = 0;
		class GradeTooHighException: public exception {
			public:
				virtual const char	*what() const throw();
		};
		
		class GradeTooLowException: public exception {
			public:
				virtual const char	*what() const throw();
		};
		class NotSignedException: public exception {
			public:
				virtual const char	*what() const throw();
		};

		class FileException: public exception {
			public:
				virtual const char	*what() const throw();
		};
		
};

std::ostream	&operator<<( std::ostream & o, AForm const & rhs );
