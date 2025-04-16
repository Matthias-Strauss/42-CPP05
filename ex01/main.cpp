/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:28:37 by mstrauss          #+#    #+#             */
/*   Updated: 2025/04/16 19:16:00 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
  std::cout << "#############################################################"
            << std::endl;
  std::cout << "#################### Testing Form Class #####################"
            << std::endl;
  std::cout << "#############################################################"
            << std::endl;
  {
    std::cout << "//////////////////////////////////////" << std::endl;
    std::cout << "Testing signing using valid conditions" << std::endl;
    std::cout << "//////////////////////////////////////" << std::endl;
    std::cout << "Creating Form F1 with name:F1, sigGrade:50, execGrade:25"
              << std::endl;
    Form F1 = Form("F1", 50, 25);
    std::cout << "Form F1 details: " << F1 << std::endl;

    std::cout << "Creating Bureaucrat B1 with name:Alice, grade:45"
              << std::endl;
    Bureaucrat B1 = Bureaucrat("Alice", 45);
    std::cout << "B1 details: " << B1 << std::endl;

    std::cout << "B1 attempting to sign F1 ..." << std::endl;
    B1.signForm(F1);
    std::cout << "Form F1 details after signing: " << F1 << std::endl;

    std::cout << "Creating Bureaucrat B2 with name: 'Bob', grade: 55"
              << std::endl;
    Bureaucrat B2 = Bureaucrat("Bob", 55);
    std::cout << "B2 details: " << B2 << std::endl;

    std::cout << "B2 attempting to sign F1" << std::endl;
    B2.signForm(F1);
    std::cout << "Form F1 details after B2's attempt: " << F1 << std::endl;
  }
  std::cout << std::endl;

  std::cout << "#############################################################"
            << std::endl;
  std::cout << "############## Testing Form Constructor Exceptions ##########"
            << std::endl;
  std::cout << "#############################################################"
            << std::endl;
  {
    try {
      std::cout << "Creating Form F2 with invalid sign grade: 0" << std::endl;
      Form F2 = Form("Form2", 0, 25);
    } catch (const std::exception &e) {
      std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
      std::cout << "Creating Form F3 with invalid exec grade: 151" << std::endl;
      Form F3 = Form("Form3", 50, 151);
    } catch (const std::exception &e) {
      std::cout << "Exception caught: " << e.what() << std::endl;
    }
  }
  std::cout << std::endl;

  std::cout << "#############################################################"
            << std::endl;
  std::cout << "############## Testing Form Member Functions ################"
            << std::endl;
  std::cout << "#############################################################"
            << std::endl;
  {
    std::cout << "Creating Form F4 with name: 'F4', sigGrade:30, execGrade:20"
              << std::endl;
    Form F4 = Form("F4", 30, 20);
    std::cout << "Form F4 details: " << F4 << std::endl;

    std::cout << "Checking if F4 is signed (expected: false)" << std::endl;
    std::cout << "Is F4 signed? " << (F4.isSigned() ? "Yes" : "No")
              << std::endl;

    std::cout << "Creating Bureaucrat B3 with name: 'Charlie', grade: 25"
              << std::endl;
    Bureaucrat B3 = Bureaucrat("Charlie", 25);
    std::cout << "B3 details: " << B3 << std::endl;

    std::cout << "B3 attempting to sign F4" << std::endl;
    B3.signForm(F4);
    std::cout << "Form F4 details after signing: " << F4 << std::endl;

    std::cout << "Checking if F4 is signed (expected: true)" << std::endl;
    std::cout << "Is F4 signed? " << (F4.isSigned() ? "Yes" : "No")
              << std::endl;

    std::cout << "Getting the sign grade of F4 (should be 30)" << std::endl;
    std::cout << "Sign grade of F4: " << F4.getSigGrade() << std::endl;

    std::cout << "Getting the exec grade of F4 (should be 20)" << std::endl;
    std::cout << "Exec grade of F4: " << F4.getExecGrade() << std::endl;

    std::cout << "Attempting to exec F4 with B3(grade: 25)" << std::endl;
    B3.signForm(F4);
    std::cout << "Form F4 details after signing: " << F4 << std::endl;

    std::cout << "Creating Bureaucrat B4 with name: 'CEO', grade: 1"
              << std::endl;
    Bureaucrat B4 = Bureaucrat("CEO", 1);
    std::cout << "B4 details: " << B4 << std::endl;

    std::cout << "Attempting to sign F4 with B4(grade: 1)" << std::endl;
    B4.signForm(F4);
    std::cout << "Form F4 details after signing: " << F4 << std::endl;
  }
  std::cout << std::endl;

  return 0;
}
