/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 16:19:12 by maeskhai          #+#    #+#             */
/*   Updated: 2026/06/21 16:19:17 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	Intern intern;

	AForm *f1 =
		intern.makeForm("robotomy request", "Bender");

	if (f1)
	{
		std::cout << *f1 << std::endl;
		delete f1;
	}

	std::cout << std::endl;

	AForm *f2 =
		intern.makeForm("presidential pardon", "Arthur Dent");

	if (f2)
	{
		std::cout << *f2 << std::endl;
		delete f2;
	}

	std::cout << std::endl;

	AForm *f3 =
		intern.makeForm("shrubbery creation", "Garden");

	if (f3)
	{
		std::cout << *f3 << std::endl;
		delete f3;
	}

	std::cout << std::endl;

	AForm *f4 =
		intern.makeForm("coffee request", "Student");

	delete f4;

	return 0;
}