/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 18:54:12 by maeskhai          #+#    #+#             */
/*   Updated: 2026/06/29 18:08:36 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("Shrubbery", 145, 137), target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::executeAction() const
{
    std::ofstream file((target + "_shrubbery").c_str());

file << "          * " << std::endl
     << "         /.\\ " << std::endl
     << "        /..'\\ " << std::endl
     << "        /'.'\\ " << std::endl
     << "       /.''.'\\ " << std::endl
     << "       /.'.'.\\ " << std::endl
     << "      /'.''.'.\\ " << std::endl     
     << "      ^^^[_]^^^ " << std::endl;

}