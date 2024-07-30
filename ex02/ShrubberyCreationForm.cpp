/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprada-t <gprada-t@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 08:46:00 by gprada-t          #+#    #+#             */
/*   Updated: 2024/07/30 16:15:25 by gprada-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Form")
{
	_gradeToSign = 145;
	_gradeToExecute = 137;
	std::cout << "ShrubberyCreationForm Default CONSTRUCTOR" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm ("Shrubbery Form")
{
	_target = target;
	_gradeToSign = 145;
	_gradeToExecute = 137;
	std::cout << "ShrubberyCreationForm Parametrized CONSTRUCTOR" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
{
	
	std::cout << "Copy ShrubberyCreationForm CONSTRUCTOR" << std::endl;
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm DESTRUCTOR" << std::endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	if (this != &src)
	{
		_isSigned = src._isSigned;
		_gradeToSign = src._gradeToSign;
		_gradeToExecute = src._gradeToExecute;
	}
	return *this;
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (getIsSigned() && executor.getGrade() < getGradeToExecute())
	{
		std::string fileName = _target + "_shrubbery";
		std::ofstream	myFile;
		myFile.open(fileName.c_str());
		myFile << " /\\ " << std::endl;
		myFile << "/  \\" << std::endl;
		myFile << " || " << std::endl;
	}
	else
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &src)
{
	out << "ShrubberyCreationForm: " << src.getName() << ", Sign status: "
		<< (src.getIsSigned() ? "signed" : "not signed")
		<< ", Grade to sign: " << src.getGradeToSign()
		<< ", Grade to execute: " << src.getGradeToExecute()
		<< std::endl;
	return out;
}

/*
const char	*ShrubberyCreationForm::GradeTooHighException::what() const throw()
{
	return "You need lower grade.";
}

const char	*ShrubberyCreationForm::GradeTooLowException::what() const throw()
{
	return "You need higher grade.";
}
*/
