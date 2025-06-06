/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:45:14 by mstrauss          #+#    #+#             */
/*   Updated: 2024/11/23 18:19:41 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string name, int sigGrade, int execGrade) : _name(name), _signed(false), _sigGrade(sigGrade), _execGrade(execGrade) {
	if (sigGrade > 150)
		throw Form::GradeTooLowException();
	else if (sigGrade < 1)
		throw Form::GradeTooHighException();
	if (execGrade < 1)
		throw Form::GradeTooHighException();
	if (execGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &other) : _name(other._name), _signed(other._signed), _sigGrade(other._sigGrade), _execGrade(other._execGrade) {
}

Form::~Form() {
}

Form &Form::operator=(const Form &other) {
	if (this != &other) {
		_signed = other._signed;
	}
	return *this;
}

const std::string &Form::getName() const {
	return _name;
}

int Form::getSigGrade() const {
	return _sigGrade;
}

int Form::getExecGrade() const {
	return _execGrade;
}

bool Form::isSigned() const {
	return _signed;
}
std::ostream &operator<<(std::ostream &os, const Form &form) {
	os << "Form: " << form.getName() << "; Signed: " << (form.isSigned() ? "YES" : "NO") << "; Grade required to sign: " << form.getSigGrade() << "; Grade to execute: " << form.getExecGrade() << std::endl;
	return os;
}

void Form::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() <= this->getSigGrade())
		this->_signed = true;
	else
		throw Form::GradeTooLowException();
}
