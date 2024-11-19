/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 17:45:12 by mstrauss          #+#    #+#             */
/*   Updated: 2024/11/17 17:49:16 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <bool>
// Then, let’s make a Form class. It has:
// • A constant name.
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
	const int _sigGrade;
	const int _execGrade;
	bool _signed;

public:
};
