/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:45:12 by mstrauss          #+#    #+#             */
/*   Updated: 2025/04/15 17:29:43 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include <ostream>
#include <string>

class Bureaucrat;

class Form {
private:
	const std::string _name;
	bool _signed;
	const int _sigGrade;
	const int _execGrade;
	Form();

public:
	Form(std::string name, int sigGrade, int execGrade);
	Form(const Form &other);
	~Form();
	Form &operator=(const Form &other);
	const std::string &getName() const;
	bool isSigned() const;
	int getSigGrade() const;
	int getExecGrade() const;

	void beSigned(Bureaucrat &bureaucrat);

	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw() { return "Grade is too high"; }
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw() { return "Grade is too low"; }
	};
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif
