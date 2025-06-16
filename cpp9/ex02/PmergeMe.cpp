/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:58:59 by Matprod           #+#    #+#             */
/*   Updated: 2025/06/16 15:40:41 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe( int argc, char **argv ) {
	long	firstTime;
	long	secondTime;

	_parseArgs(argc, argv);
	_printArgs(BEFORE);
	firstTime = _getTime();
	_mergeInsertionSort(_args);
	firstTime = _getTime() - firstTime;
	secondTime = _getTime();
	_mergeInsertionSort(_args2);
	secondTime = _getTime() - secondTime;
	_printArgs(AFTER);
	cout << BOLD_BLUE"Time for std::vector for " << _args.size() << " elements: " BLUE << firstTime << " us" RESET << endl;
	cout << BOLD_BLUE" Time for std::deque for " << _args2.size() << " elements: " BLUE << secondTime << " us" RESET << endl;
}

template <typename T>
void	PmergeMe::_insertionSort(T &container)
{
	if (container.size() < 2)
		return ;

	typedef typename T::iterator iterator;

	for (iterator i = container.begin(); i != container.end(); i++)
	{
		iterator j = i;
		while (j != container.begin() && *(j - 1) > *j)
		{
			std::iter_swap(j - 1, j);
			j--;
		}
	}
}

template <typename T>
void	PmergeMe::_mergeSort(T &left, T &right, T &container) {
	typename T::iterator itLeft = left.begin(), itRight = right.begin(), itContainer = container.begin();

	while (itLeft != left.end() && itRight != right.end()) {
		*itContainer++ = (*itLeft < *itRight) ? *itLeft++ : *itRight++;
	}
	while (itLeft != left.end()) {
		*itContainer++ = *itLeft++;
	}
	while (itRight != right.end()) {
		*itContainer++ = *itRight++;
	}
}

template <typename T>
void	PmergeMe::_mergeInsertionSort(T &container) {
	int const	limit = 16;
	T			left;
	T			right;
	typename T::iterator middle;

	if (container.size() < limit)
	{
		_insertionSort(container);
		return ;
	}

	middle = container.begin();
	advance(middle, container.size() / 2);
	left = T(container.begin(), middle);
	right = T(middle, container.end());
	_mergeInsertionSort(left);
	_mergeInsertionSort(right);
	_mergeSort(left, right, container);
}

void	PmergeMe::_parseArgs( int argc, char **argv ) {
	char		*endptr;
	string		arg;
	long		tmp;
	long *seen = new long[argc + 1];

	for (int i = 1; i < argc; ++i) {
		arg = argv[i];
		tmp = strtol(arg.c_str(), &endptr, 10);
		if (arg.find('-') != string::npos)
			throw NegativeNumberException();
		if (arg.find_first_not_of("0123456789+") != string::npos)
			throw NotANumberException();
		else if (*endptr != '\0' && tmp > INT_MAX)
			throw TooBigNumberException();
		else if (*endptr != '\0')
			throw NotANumberException();
		_args.push_back((int)tmp);
		_args2.push_back((int)tmp);
		seen[i -1] = tmp;
		for (int j = 0; j < i -1; j++){
			if (seen[j] == tmp)
				throw DuplicateNumberException();
		}
	}
	delete[] seen;
	
}

void	PmergeMe::_printArgs( bool state ) const {
	cout << BOLD_GREEN << (state ? "[BEFORE]" : "[AFTER]") << GREEN": ";
	for (vector<int>::const_iterator it = _args.begin(); it != _args.end(); ++it) {
		cout << *it;
		if (it + 1 != _args.end())
			cout << ", ";
	}
	cout << RESET << endl;
}

long	PmergeMe::_getTime( void ) const {
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000 + tv.tv_usec);
}

const char *PmergeMe::NotANumberException::what( void ) const throw() {
	return (BOLD_RED"[ERROR] " RED"Only numbers are allowed as arguments !");
}

const char *PmergeMe::NegativeNumberException::what( void ) const throw() {
	return (BOLD_RED"[ERROR] " RED"Negative numbers are not allowed as arguments !");
}

const char *PmergeMe::TooBigNumberException::what( void ) const throw() {
	return (BOLD_RED"[ERROR] " RED"Numbers must be a positive integer less than INT_MAX !(2147483647)");
}

const char *PmergeMe::DuplicateNumberException::what( void ) const throw() {
	return (BOLD_RED"[ERROR] " RED"Duplicate numbers are not allowed as arguments !");
}