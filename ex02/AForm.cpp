/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:45:14 by mstrauss          #+#    #+#             */
/*   Updated: 2024/11/23 18:18:24 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string name, int sigGrade, int execGrade) : _name(name), _signed(false), _sigGrade(sigGrade), _execGrade(execGrade) {
	if (sigGrade > 150)
		throw AForm::GradeTooLowException();
	else if (sigGrade < 1)
		throw AForm::GradeTooHighException();
	if (execGrade < 1)
		throw AForm::GradeTooHighException();
	if (execGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other) : _name(other._name), _signed(other._signed), _sigGrade(other._sigGrade), _execGrade(other._execGrade) {
}

AForm::~AForm() {
}

AForm &AForm::operator=(const AForm &other) {
	if (this != &other) {
		_signed = other._signed;
	}
	return *this;
}

const std::string &AForm::getName() const {
	return _name;
}

int AForm::getSigGrade() const {
	return _sigGrade;
}

int AForm::getExecGrade() const {
	return _execGrade;
}

bool AForm::isSigned() const {
	return _signed;
}
std::ostream &operator<<(std::ostream &os, const AForm &aform) {
	os << "Form: " << aform.getName() << "; Signed: " << (aform.isSigned() ? "YES" : "NO") << "; Grade required to sign: " << aform.getSigGrade() << "; Grade to execute: " << aform.getExecGrade() << std::endl;
	return os;
}

void AForm::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() <= this->getSigGrade())
		this->_signed = true;
	else
		throw AForm::GradeTooLowException();
}
