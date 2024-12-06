/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:04:47 by mstrauss          #+#    #+#             */
/*   Updated: 2024/12/06 18:22:16 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
protected:
	void executeAction(const Bureaucrat &executor) const;

private:
	std::string _target;

public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	~PresidentialPardonForm();

	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

	void execute(const Bureaucrat &executor) const;
	static const int signGrade = 25;
	static const int execGrade = 5;
};

#endif
