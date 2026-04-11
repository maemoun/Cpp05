/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 18:55:27 by maeskhai          #+#    #+#             */
/*   Updated: 2026/04/09 18:55:29 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>

int main()
{
    srand(time(NULL));

    Bureaucrat boss("Boss", 1);

    ShrubberyCreationForm s("home");
    RobotomyRequestForm r("Bender");
    PresidentialPardonForm p("Marvin");

    boss.signForm(s);
    boss.executeForm(s);

    boss.signForm(r);
    boss.executeForm(r);

    boss.signForm(p);
    boss.executeForm(p);

    return 0;
}