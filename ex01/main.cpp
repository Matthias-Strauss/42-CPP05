/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:28:37 by mstrauss          #+#    #+#             */
/*   Updated: 2024/11/20 13:55:51 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	// ########################################
	// ################ TESTS #################
	// ########################################
	std::cout << "#############################################################" << std::endl;
	std::cout << "################ Testing Operator Overload << ###############" << std::endl;
	std::cout << "#############################################################" << std::endl;
	std::cout << "Initializing Bureaucrat using name:Anna, grade:100." << std::endl;
	Bureaucrat B0 = Bureaucrat("Anna", 100);
	std::cout << "testing operator overload by calling 'std::cout << B0 << std::endl'." << std::endl;
	std::cout << B0 << std::endl;
	std::cout << std::endl;

	std::cout << "#############################################################" << std::endl;
	std::cout << "######## Testing Constructor with invalid GRADE #############" << std::endl;
	std::cout << "#############################################################" << std::endl;
	std::cout << "Initializing Bureaucrat with invalid grade 151." << std::endl;
	try
	{
		// init with too low grade
		Bureaucrat B1 = Bureaucrat("Bob", 151);
		// -> constructor throws exception
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "#############################################################" << std::endl;
	std::cout << "######## Testing Constructor with invalid GRADE #############" << std::endl;
	std::cout << "#############################################################" << std::endl;
	std::cout << "Initializing Bureaucrat with invalid grade 0." << std::endl;
	try
	{
		// init with too high grade
		Bureaucrat *B2 = new Bureaucrat("Chris", 0);
		//  -> constructor throws exception
		(void)B2;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "#############################################################" << std::endl;
	std::cout << "################ Testing incrementGrade() ###################" << std::endl;
	std::cout << "#############################################################" << std::endl;
	// ########################################
	// init with correct grade
	std::cout << "Init B3 with valid arguments (name:Dennis, score:2) on heap using 'new'." << std::endl;
	Bureaucrat *B3 = new Bureaucrat("Dennis", 2);
	// increment grade
	std::cout << "Increment B3's grade from 2 to 1 using .incrementGrade()" << std::endl;
	B3->incrementGrade();
	std::cout << "B3's grade is: " << B3->getGrade() << std::endl;
	// increment grade past threshhold
	std::cout << "Incrementing B3's grade from 1 to 0 using .incrementGrade()" << std::endl;
	// -> incrementGrade throws exception
	try
	{
		B3->incrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	// print for confirmation
	std::cout << "B3's grade is: " << B3->getGrade() << std::endl;

	// destroy bureaucrat
	delete B3;
	std::cout << std::endl;
	{
		std::cout << "#############################################################" << std::endl;
		std::cout << "################ Testing decrementGrade() ###################" << std::endl;
		std::cout << "#############################################################" << std::endl;
		// #######################################
		// init with correct grade

		std::cout << "Init B4 with valid arguments (name:Eve, score:149) on stack." << std::endl;
		Bureaucrat B4 = Bureaucrat("Eve", 149);

		// decrement grade
		std::cout << "Decrementing B4's grade using .decrementGrade()" << std::endl;
		B4.decrementGrade();
		std::cout << "B4's grade is: " << B4.getGrade() << std::endl;

		try
		{
			std::cout << "Decrementing B4's grade using .decrementGrade()" << std::endl;
			// decrement grade past threshhold
			B4.decrementGrade();
			// -> decrementGrade throws exception
		}
		catch (const std::exception &e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
		// print for confirmation
		std::cout << "Eve's grade is: " << B4.getGrade() << std::endl;

		// destroy bureaucrat
		// -> Bureaucrat is on stack, deconstructor gets called by exit of scope
		std::cout << std::endl;
	}
	// ########################################
	std::cout << "#############################################################" << std::endl;
	std::cout << "################ Testing Setters & Getters ##################" << std::endl;
	std::cout << "#############################################################" << std::endl;
	{
		// setter & getter check
		std::cout << "Initializing Bureaucrat B5 with the arguments name:Frank, grade:42" << std::endl;
		Bureaucrat B5 = Bureaucrat("Frank", 42);
		std::cout << "calling .getName() on B5" << std::endl;
		std::cout << "B5's name is: " << B5.getName() << std::endl;
		std::cout << "calling .getGrade() on B5" << std::endl;
		std::cout << "B5's grade is: " << B5.getGrade() << std::endl;
		std::cout << "calling setGrade(69) on B5" << std::endl;
		B5.setGrade(69);
		std::cout << "B5's grade is: " << B5.getGrade() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "#############################################################" << std::endl;
	std::cout << "############## Testing setGrade() Exceptions ################" << std::endl;
	std::cout << "#############################################################" << std::endl;
	{
		std::cout << "Initializing Bureaucrat B6 with arguments name:Hans, grade:42" << std::endl;
		Bureaucrat B6 = Bureaucrat("Hans", 42);
		std::cout << "calling .setGrade(0) (too low) on B6" << std::endl;
		try
		{
			B6.setGrade(0);
		}
		catch (std::exception &e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}
	// try to set grade too low
	{
		std::cout << "Initializing Bureaucrat B7 with arguments name:Irwin, grade:42" << std::endl;
		Bureaucrat B7 = Bureaucrat("Irwin", 42);
		std::cout << "calling .setGrade(151) (too high) on B7" << std::endl;
		try
		{
			B7.setGrade(151);
		}
		catch (std::exception &e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl;

	std::cout << "\n\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
	std::cout << "!!!!!!!!!!!!!!!!!!!!!!! EX01 !!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
	std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"
			  << std::endl;

	{
		Bureaucrat B = Bureaucrat("Bob", 10);
		Form F = Form("28C", 10);
	}
	return 0;
}
