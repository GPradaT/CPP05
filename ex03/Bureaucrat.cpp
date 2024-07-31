/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprada-t <gprada-t@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 10:43:26 by gprada-t          #+#    #+#             */
/*   Updated: 2024/07/30 15:25:43 by gprada-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("noName"), _grade(150)
{
	std::cout << "Bureaucrat CONSTRUCTOR" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat DESTRUCTOR" << std::endl;
}


Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
	*this = src;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &src)
{
	_grade = src._grade;
	return *this;
}

std::string	Bureaucrat::getName() const
{
	return _name;
}

int		Bureaucrat::getGrade() const
{
	return _grade;
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &src)
{
	out << src.getName() + ", bureaucrat grade " << src.getGrade() << std::endl;
	return out;
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Is not possible to get higher grade than 1.";
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Is not possible to get lower grade than 150.";
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

void	Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

void	Bureaucrat::signForm(AForm &toSign)
{
	if (toSign.getIsSigned())
		return ;
	try
	{
		toSign.beSigned(*this);
		std::cout << this->getName() << " signed " 
			<< toSign.getName() << std::endl;
	} catch (std::exception &e) {
		std::cout << this->getName() << " couldn't sign "
			<< toSign.getName() << " because "
			<< e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(const AForm &form)
{
	try
	{
		form.execute(*this);
	} catch (std::exception &e) {
		std::cout << this->getName() << " couldn't execute "
			<< form.getName() << " because " << e.what()
			<< std::endl;
	}
}
