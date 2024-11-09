/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:04:55 by mstrauss          #+#    #+#             */
/*   Updated: 2024/11/09 18:31:20 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <exception>

class GradeTooHighException : public std::exception
{
public:
	const char *what() const throw();
};

class GradeTooLowException : public std::exception
{
public:
	const char *what() const throw()
	{
		return "Grade is too low";
	}
};

typedef class Bureaucrat
{
public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat();
	void setName(std::string name);
	void setGrade(int grade);
	std::string getName();
	int getGrade();
	void incrementGrade();
	void decrementGrade();

private:
	std::string _name;
	int _grade;
};
