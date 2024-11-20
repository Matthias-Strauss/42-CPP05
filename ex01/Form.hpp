/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:45:12 by mstrauss          #+#    #+#             */
/*   Updated: 2024/11/20 13:46:21 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# ifndef FORM_HPP
# define FORM_HPP
# include <string>
# include <ostream>
#include <iostream>
# include "Exceptions.hpp"

// Then, let’s make a Form class. It has:
// • A constant name.					DONE
// • A boolean indicating whether it is signed (at construction, it’s not).
// • A constant grade required to sign it.
// • And a constant grade required to execute it.
// All these attributes are private, not protected.
// The grades of the Form follow the same rules that apply to the Bureaucrat. Thus,
// the following exceptions will be thrown if a form grade is out of bounds:
// Form::GradeTooHighException and Form::GradeTooLowException.
// Same as before, write getters for all attributes and an overload of the insertion («)
// operator that prints all the form’s informations.

class Form
{
private:
	const std::string _name;
	bool _signed;
	const int _sigGrade;
	const int _execGrade;

public:
	Form();
	Form(std::string name, int sigGrade, int execGrade);
	~Form();
	const std::string &getName() const;
	bool isSigned() const;
	int getSigGrade() const;
	int getExecGrade() const;

	void beSigned(Bureaucrat bureaucrat);
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif
