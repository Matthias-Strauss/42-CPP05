/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:36:37 by mstrauss          #+#    #+#             */
/*   Updated: 2024/11/20 13:37:09 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef EXCEPTIONS_HPP
# define EXCEPTIONS_HPP
# include <exception>

class GradeTooHighException : public std::exception
{
public:
	GradeTooHighException();
	virtual ~GradeTooHighException() throw() {}
	const char *what() const throw();
};

class GradeTooLowException : public std::exception
{
public:
	GradeTooLowException();
	virtual ~GradeTooLowException() throw() {}
	const char *what() const throw();
};

#endif
