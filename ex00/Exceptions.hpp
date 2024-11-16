/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 19:55:46 by mstrauss          #+#    #+#             */
/*   Updated: 2024/11/16 19:58:39 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>

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
