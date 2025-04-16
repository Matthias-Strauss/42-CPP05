/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:05:11 by mstrauss          #+#    #+#             */
/*   Updated: 2024/12/06 18:26:17 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardon", signGrade, execGrade), _target("default") {
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("PresidentialPardon", signGrade, execGrade), _target(target) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
	: AForm(other), _target(other._target) {
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

void PresidentialPardonForm::executeAction(const Bureaucrat &executor) const {
	(void) executor;// Unused parameter
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
