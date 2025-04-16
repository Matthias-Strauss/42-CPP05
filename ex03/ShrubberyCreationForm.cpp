/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:47:00 by mstrauss          #+#    #+#             */
/*   Updated: 2024/12/06 18:22:16 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreation", signGrade, execGrade), _target("default") {
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreation", signGrade, execGrade), _target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other), _target(other._target) {
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

void ShrubberyCreationForm::executeAction(const Bureaucrat &executor) const {
	(void) executor;// Unused parameter
	std::string filename = _target + "_shrubbery";
	std::ofstream outFile(filename.c_str());

	if (!outFile.is_open())
		throw std::runtime_error("Cannot create file");

	outFile << "                    .s.s." << std::endl;
	outFile << "                  `'`Y8bso." << std::endl;
	outFile << "                ,d88bso y'd8l" << std::endl;
	outFile << "              \"`^,8K j8P?*2b." << std::endl;
	outFile << "             ,bonsai_`o.o" << std::endl;
	outFile << "           ,r.osbJ--',' e8b?Y.." << std::endl;
	outFile << "         j*Y888P*{ `,'_-'\" 888b" << std::endl;
	outFile << "           `\"'`` ,'._-`\"*?*P\"" << std::endl;
	outFile << "              db8sld-',',):5ls." << std::endl;
	outFile << "        <sd88P,-d888P'd888d8888Rdbc" << std::endl;
	outFile << "       `\"*j*CJ8*d8888l:`  `88?bl.o" << std::endl;
	outFile << "     .o.sl.rsdP^*8bdbs.. *\"?**l888s." << std::endl;
	outFile << "        JYsd88P88ld?/**\"`*`-." << std::endl;
	outFile << "     dPJ88*J?P;Pd888D;=-. -.l.s." << std::endl;
	outFile << "   .'`\"*Y,.sbsdkc l.    ?(    ^.   l" << std::endl;
	outFile << "        .Y8*?8P*\"`      )`  .' :   b" << std::endl;
	outFile << "         `\"`          _.-'  ,   k.  s" << std::endl;
	outFile << "                    (`  :  ;  ('" << std::endl;
	outFile << "                     '`_ )`. `'l" << std::endl;
	outFile << "        r=========-==`==-=-=-==---------7" << std::endl;
	outFile << "       'Y  -- ---- -- -    .      '    '" << std::endl;
	outFile << "         :                            ;" << std::endl;
	outFile << "         \\-.. .. .. . . . . .     ,/" << std::endl;
	outFile << "          .-<=:'._____________________,.:'>=-.'" << std::endl;
	outFile << "         L_____________________________________J" << std::endl;

	outFile.close();
}
