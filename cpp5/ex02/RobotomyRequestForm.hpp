/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:48:42 by Matprod           #+#    #+#             */
/*   Updated: 2025/04/28 16:48:46 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <fstream>
# include <cstdlib>
# include <ctime>

using std::ofstream;
using std::ifstream;
using std::rand;
using std::srand;
using std::time;

class RobotomyRequestForm : public AForm
{
	private:
		string	_target;
	public:
		RobotomyRequestForm				( void );
		RobotomyRequestForm				( string target );
		RobotomyRequestForm				( RobotomyRequestForm const &rhs );
		RobotomyRequestForm	&operator=	( RobotomyRequestForm const &rhs );
		~RobotomyRequestForm				( void );

		void execute						(Bureaucrat const &executor) const;
};

#endif