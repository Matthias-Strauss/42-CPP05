/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:59:14 by mstrauss          #+#    #+#             */
/*   Updated: 2024/12/06 18:26:17 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequest", signGrade, execGrade), _target("default") {
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequest", signGrade, execGrade), _target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other), _target(other._target) {
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

void RobotomyRequestForm::executeAction(const Bureaucrat &executor) const {
	(void) executor;// Unused parameter
	std::cout << "* SOME DRILLING NOISES *" << std::endl;

	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	if (std::rand() % 2) {
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	} else {
		std::cout << "Robotomy failed for " << _target << "." << std::endl;
	}
}
