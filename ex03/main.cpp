/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 16:19:12 by maeskhai          #+#    #+#             */
/*   Updated: 2026/06/29 18:40:28 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	try {
		Intern intern;
		Bureaucrat boss("Boss", 1);

		AForm *f1 =
			intern.makeForm("robotomy request", "Bender");


		if (f1)
		{	
			boss.signForm(*f1);
			boss.executeForm(*f1);
			delete f1;
		}
		std::cout << std::endl;

		AForm *f2 =
		intern.makeForm("presidential pardon", "Arthur Dent");

		if (f2)
		{
			boss.signForm(*f2);
			boss.executeForm(*f2);
			delete f2;
		}

		std::cout << std::endl;

		AForm *f3 =
			intern.makeForm("shrubbery creation", "Garden");

		if (f3)
		{
			boss.signForm(*f3);
			boss.executeForm(*f3);
			delete f3;
		}

		std::cout << std::endl;
	
		AForm *f4 =
			intern.makeForm("coffee request", "Student");

		if (f4)
		{
			std::cout << *f4 << std::endl;
			delete f4;
		}
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}