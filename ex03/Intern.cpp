/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:54:36 by mstrauss          #+#    #+#             */
/*   Updated: 2025/04/15 19:07:14 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
}

Intern::Intern(const Intern &other) {
	(void) other;
}

Intern::~Intern() {
}

Intern &Intern::operator=(const Intern &other) {
	(void) other;
	return *this;
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const {
	struct FormType {
		std::string name;
		AForm *(*create)(const std::string &);
	};

	static const FormType forms[] = {
			{"shrubbery creation", [](const std::string &t) -> AForm * { return new ShrubberyCreationForm(t); }},
			{"robotomy request", [](const std::string &t) -> AForm * { return new RobotomyRequestForm(t); }},
			{"presidential pardon", [](const std::string &t) -> AForm * { return new PresidentialPardonForm(t); }}};

	for (const FormType &form: forms) {
		if (formName == form.name) {
			AForm *newForm = form.create(target);
			std::cout << "Intern creates " << newForm->getName() << std::endl;
			return newForm;
		}
	}

	throw FormNotFoundException();
}