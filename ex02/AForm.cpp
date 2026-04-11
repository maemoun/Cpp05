/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 18:53:43 by maeskhai          #+#    #+#             */
/*   Updated: 2026/04/09 18:53:45 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
    : name("Default"), isSigned(false), gradeToSign(150), gradeToExecute(150) {}

AForm::AForm(const std::string& name, int gSign, int gExec)
    : name(name), isSigned(false), gradeToSign(gSign), gradeToExecute(gExec)
{
    if (gSign < 1 || gExec < 1)
        throw GradeTooHighException();
    if (gSign > 150 || gExec > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& o)
    : name(o.name), isSigned(o.isSigned),
      gradeToSign(o.gradeToSign), gradeToExecute(o.gradeToExecute) {}

AForm& AForm::operator=(const AForm& o)
{
    if (this != &o)
        isSigned = o.isSigned;
    return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const { return name; }
bool AForm::getIsSigned() const { return isSigned; }
int AForm::getGradeToSign() const { return gradeToSign; }
int AForm::getGradeToExecute() const { return gradeToExecute; }

void AForm::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (!isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > gradeToExecute)
        throw GradeTooLowException();

    executeAction();
}

const char* AForm::GradeTooHighException::what() const throw()
{ return "Grade too high"; }

const char* AForm::GradeTooLowException::what() const throw()
{ return "Grade too low"; }

const char* AForm::FormNotSignedException::what() const throw()
{ return "Form not signed"; }

std::ostream& operator<<(std::ostream& out, const AForm& f)
{
    out << f.getName() << ", signed: " << f.getIsSigned();
    return out;
}