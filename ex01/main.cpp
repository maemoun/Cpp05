/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 18:07:30 by maeskhai          #+#    #+#             */
/*   Updated: 2026/04/09 18:09:07 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat boss("Boss", 1);
        Bureaucrat intern("Intern", 150);

        Form contract("Contract", 50, 20);

        std::cout << contract << std::endl;

        intern.signForm(contract);
        boss.signForm(contract);

        std::cout << contract << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}