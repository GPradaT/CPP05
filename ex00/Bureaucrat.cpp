/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprada-t <gprada-t@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 10:43:26 by gprada-t          #+#    #+#             */
/*   Updated: 2024/07/27 12:07:17 by gprada-t         ###   ########.fr       */
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

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
	_grade = grade;
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
