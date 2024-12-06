/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:04:55 by mstrauss          #+#    #+#             */
/*   Updated: 2024/11/24 15:54:51 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "AForm.hpp"
#include <exception>
#include <iostream>
#include <string>

class Bureaucrat {
private:
	const std::string _name;
	int _grade;
	Bureaucrat();

public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat();
	void setGrade(int grade);
	const std::string &getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();

	void signForm(Form &form);

	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw() { return "Grade is too high"; }
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw() { return "Grade is too low"; }
	};
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif
