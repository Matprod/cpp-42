/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoisin <mvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:41:08 by mvoisin           #+#    #+#             */
/*   Updated: 2025/05/16 15:34:25 by mvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "getType.hpp"
#include "print.hpp"

# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"

# define BOLD_BLACK "\033[1;30m"
# define BOLD_RED "\033[1;31m"
# define BOLD_GREEN "\033[1;32m"
# define BOLD_YELLOW "\033[1;33m"
# define BOLD_BLUE "\033[1;34m"
# define BOLD_MAGENTA "\033[1;35m"
# define BOLD_CYAN "\033[1;36m"
# define BOLD_WHITE "\033[1;37m"

# define UNDERLINE_BLACK "\033[4;30m"
# define UNDERLINE_RED "\033[4;31m"
# define UNDERLINE_GREEN "\033[4;32m"
# define UNDERLINE_YELLOW "\033[4;33m"
# define UNDERLINE_BLUE "\033[4;34m"
# define UNDERLINE_MAGENTA "\033[4;35m"
# define UNDERLINE_CYAN "\033[4;36m"
# define UNDERLINE_WHITE "\033[4;37m"

# define BACKGROUND_BLACK "\033[40m"
# define BACKGROUND_RED "\033[41m"
# define BACKGROUND_GREEN "\033[42m"
# define BACKGROUND_YELLOW "\033[43m"
# define BACKGROUND_BLUE "\033[44m"
# define BACKGROUND_MAGENTA "\033[45m"
# define BACKGROUND_CYAN "\033[46m"
# define BACKGROUND_WHITE "\033[47m"

# define RESET "\033[0m"

using std::string;
using std::endl;
using std::cout;

void 	converter(string const &str);
void	convertFromChar( string const &str );
void	convertFromInt( string const &str );
void	convertFromFloat( string const &str );
void	convertFromDouble( string const &str );
void	convertFromNanOrInf( string const &str );