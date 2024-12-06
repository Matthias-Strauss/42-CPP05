/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:28:37 by mstrauss          #+#    #+#             */
/*   Updated: 2024/12/06 18:58:01 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
	std::cout << "\n#############################################################" << std::endl;
	std::cout << "############### Testing Bureaucrat Creation #################" << std::endl;
	std::cout << "#############################################################" << std::endl;
	try {
		std::cout << "\nTrying to create bureaucrat with grade 0 (too high):" << std::endl;
		Bureaucrat tooHigh("TooHigh", 0);
	} catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try {
		std::cout << "\nTrying to create bureaucrat with grade 151 (too low):" << std::endl;
		Bureaucrat tooLow("TooLow", 151);
	} catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n#############################################################" << std::endl;
	std::cout << "############## Testing ShrubberyCreationForm ################" << std::endl;
	std::cout << "#############################################################" << std::endl;
	try {
		Bureaucrat highGrade("HighGrade", 1);
		Bureaucrat lowGrade("LowGrade", 150);
		ShrubberyCreationForm form("garden");

		std::cout << "\nTrying to execute unsigned form:" << std::endl;
		highGrade.executeForm(form);

		std::cout << "\nTrying to sign with low grade (should fail):" << std::endl;
		lowGrade.signForm(form);

		std::cout << "\nSigning with high grade:" << std::endl;
		highGrade.signForm(form);

		std::cout << "\nTrying to execute with low grade (should fail):" << std::endl;
		lowGrade.executeForm(form);

		std::cout << "\nExecuting with high grade:" << std::endl;
		highGrade.executeForm(form);
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n#############################################################" << std::endl;
	std::cout << "############### Testing RobotomyRequestForm #################" << std::endl;
	std::cout << "#############################################################" << std::endl;
	try {
		Bureaucrat boss("Boss", 1);
		Bureaucrat intern("Intern", 150);
		RobotomyRequestForm form("target");

		std::cout << "\nTrying to execute unsigned form:" << std::endl;
		boss.executeForm(form);

		std::cout << "\nTrying to sign with low grade (should fail):" << std::endl;
		intern.signForm(form);

		std::cout << "\nSigning with high grade:" << std::endl;
		boss.signForm(form);

		std::cout << "\nTrying to execute with low grade (should fail):" << std::endl;
		intern.executeForm(form);

		std::cout << "\nExecuting with high grade multiple times (50% success rate):" << std::endl;
		boss.executeForm(form);
		std::cout << std::endl;
		boss.executeForm(form);
		std::cout << std::endl;
		boss.executeForm(form);
		std::cout << std::endl;
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n#############################################################" << std::endl;
	std::cout << "############## Testing PresidentialPardonForm ###############" << std::endl;
	std::cout << "#############################################################" << std::endl;
	try {
		Bureaucrat president("President", 1);
		Bureaucrat secretary("Secretary", 25);
		PresidentialPardonForm form("criminal");

		std::cout << "\nTrying to execute unsigned form:" << std::endl;
		president.executeForm(form);

		std::cout << "\nSigning with secretary (exactly right grade for signing):" << std::endl;
		secretary.signForm(form);

		std::cout << "\nTrying to execute with secretary (too low grade):" << std::endl;
		secretary.executeForm(form);

		std::cout << "\nExecuting with president:" << std::endl;
		president.executeForm(form);
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	return 0;
}
