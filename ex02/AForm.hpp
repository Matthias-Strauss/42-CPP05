/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:45:12 by mstrauss          #+#    #+#             */
/*   Updated: 2024/11/23 18:04:47 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include <ostream>
#include <string>

class Bureaucrat;

class AForm {
private:
	const std::string _name;
	bool _signed;
	const int _sigGrade;
	const int _execGrade;

public:
	AForm();
	AForm(std::string name, int sigGrade, int execGrade);
	AForm(const AForm &other);
	virtual ~AForm();
	AForm &operator=(const AForm &other);
	const std::string &getName() const;
	bool isSigned() const;
	int getSigGrade() const;
	int getExecGrade() const;

	void beSigned(Bureaucrat &bureaucrat);

	virtual void execute(Bureaucrat const &executor) const = 0;

	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw() { return "Grade is too high"; }
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw() { return "Grade is too low"; }
	};

	class NotSignedException : public std::exception {
	public:
		virtual const char *what() const throw() { return "Form is not signed"; }
	};
};

std::ostream &operator<<(std::ostream &os, const AForm &aform);

#endif
