/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprada-t <gprada-t@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 08:46:00 by gprada-t          #+#    #+#             */
/*   Updated: 2024/07/30 17:34:50 by gprada-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form")
{
	_gradeToSign = 72;
	_gradeToExecute = 45;
	std::cout << "RobotomyRequestForm Default CONSTRUCTOR" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm ("Robotomy Request Form")
{
	_target = target;
	_gradeToSign = 72;
	_gradeToExecute = 45;
	std::cout << "RobotomyRequestForm Parametrized CONSTRUCTOR" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
{
	
	std::cout << "Copy RobotomyRequestForm CONSTRUCTOR" << std::endl;
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm DESTRUCTOR" << std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	if (this != &src)
	{
		_isSigned = src._isSigned;
		_gradeToSign = src._gradeToSign;
		_gradeToExecute = src._gradeToExecute;
	}
	return *this;
}

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (getIsSigned() && executor.getGrade() < getGradeToExecute())
	{
		std::cout << "ZZzzzZZzzZzZzzz" << std::endl;
		std::cout << _target << " has been robotomized successfully"
			<< " 50% of it's time" << std::endl;
	}
	else
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &src)
{
	out << "Form: " << src.getName() << ", Sign status: "
		<< (src.getIsSigned() ? "signed" : "not signed")
		<< ", Grade to sign: " << src.getGradeToSign()
		<< ", Grade to execute: " << src.getGradeToExecute()
		<< std::endl;
	return out;
}
/*
const char	*RobotomyRequestForm::GradeTooLowException::what() const throw()
{
	return "ROBOTOMY FAILED.";
}


const char	*RobotomyRequestForm::GradeTooHighException::what() const throw()
{
	return "You need lower grade.";
}
*/
