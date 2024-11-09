/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:28:37 by mstrauss          #+#    #+#             */
/*   Updated: 2024/11/09 17:40:28 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{

	ADD TRY CATCH BLOCKS FOR EVALUATION !!!!!!!

	// ########################################
	// ################ TESTS #################
	// ########################################
	{
		// init with too low grade
		Bureaucrat *B1 = new Bureaucrat("Bob", 151);
		// -> constructor throws exception

		// init with too high grade
		Bureaucrat *B2 = new Bureaucrat("Chris", 0);
		//  -> constructor throws exception
	}
	// ########################################
	{
		// init with correct grade
		Bureaucrat *B3 = new Bureaucrat("Dennis", 2);
		// increment grade
		B3->incrementGrade();
		std::cout << "Dennis's grade is: " << B3->getGrade() << std::endl;
		// increment grade past threshhold
		// -> incrementGrade throws exception
		B3->incrementGrade();

		// print for confirmation
		std::cout << "Dennis's grade is: " << B3->getGrade() << std::endl;

		// destroy bureaucrat
		delete B3;
	}
	// ########################################
	{
		// init with correct grade
		Bureaucrat B4 = Bureaucrat("Eve", 149);

		// decrement grade
		B4.decrementGrade();
		std::cout << "Eve's grade is: " << B4.getGrade() << std::endl;

		// decrement grade past threshhold
		// -> decrementGrade throws exception
		B4.decrementGrade();

		// print for confirmation
		std::cout << "Eve's grade is: " << B4.getGrade() << std::endl;

		// destroy bureaucrat
		// -> Bureaucrat is on stack, deconstructor gets called by exit of scope
	}
	// ########################################
	{
		// setter & getter check
		Bureaucrat B5 = Bureaucrat("Frank", 42);
		std::cout << "B5's name is: " << B5.getName() << std::endl;
		std::cout << "B5's grade is: " << B5.getGrade() << std::endl;

		B5.setName("Georg");
		B5.setGrade(69);

		std::cout << "B5's name is: " << B5.getName() << std::endl;
		std::cout << "B5's grade is: " << B5.getGrade() << std::endl;
	}

	// ########################################
	// ############## Try & Catch #############
	// ########################################

	// try to set grade too high
	try
	{
		Bureaucrat B6 = Bureaucrat("Hans", 42);
		B6->setGrade(0);
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	// try to set grade too low
	try
	{
		Bureaucrat B7 = Bureaucrat("Irwin", 42);
		B7->setGrade(151);
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	return 0;
}
