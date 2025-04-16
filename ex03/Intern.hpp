/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:54:31 by mstrauss          #+#    #+#             */
/*   Updated: 2024/12/06 19:55:05 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <string>

class Intern {
public:
	Intern();
	Intern(const Intern &other);
	~Intern();
	Intern &operator=(const Intern &other);

	AForm *makeForm(const std::string &formName, const std::string &target) const;

	class FormNotFoundException : public std::exception {
	public:
		virtual const char *what() const throw() {
			return "Form type not found";
		}
	};
};

#endif