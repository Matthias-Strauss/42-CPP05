/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 19:57:01 by mstrauss          #+#    #+#             */
/*   Updated: 2024/11/17 17:31:09 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Exceptions.hpp"

GradeTooHighException::GradeTooHighException()
{
}

GradeTooLowException::GradeTooLowException()
{
}

const char *GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}
