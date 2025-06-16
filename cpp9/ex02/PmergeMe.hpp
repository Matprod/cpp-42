/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:59:13 by Matprod           #+#    #+#             */
/*   Updated: 2025/06/16 14:59:18 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "colors.hpp"

# include <iostream>
# include <cstdlib>
# include <vector>
# include <climits>
# include <algorithm>
# include <set>
# include <deque>
# include <sys/time.h>
# include "colors.hpp"

# define BEFORE true
# define AFTER false

using	std::string;
using	std::cout;
using	std::endl;
using	std::vector;
using	std::deque;
using	std::set;
using	std::iter_swap;
using	std::merge;
using	std::advance;


class	PmergeMe {
	public:
		PmergeMe( int argc, char **argv );
		~PmergeMe( void ) {};
	private:
		class	NotANumberException : public std::exception {
			public:
				virtual const char *what( void ) const throw();
		};

		class	NegativeNumberException : public std::exception {
			public:
				virtual const char *what( void ) const throw();
		};

		class	TooBigNumberException : public std::exception {
			public:
				virtual const char *what( void ) const throw();
		};

		class	DuplicateNumberException : public std::exception {
			public:
				virtual const char *what( void ) const throw();
		};

		PmergeMe						( void );
		PmergeMe		&operator=		( PmergeMe const & rhs );
		PmergeMe						( PmergeMe const & src );

		void			_parseArgs		( int argc, char **argv );
		void			_printArgs		( bool state ) const;
		
		long			_getTime( void ) const;

		template <typename T>
		void			_insertionSort	( T &container );

		template <typename T>
		void			_mergeSort(T &left, T &right, T &container);

		template <typename T>
		void			_mergeInsertionSort(T &container);
		vector<int>		_args;
		deque<int>		_args2;
};