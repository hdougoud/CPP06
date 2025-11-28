/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baseUtils.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 21:56:04 by hdougoud          #+#    #+#             */
/*   Updated: 2025/11/28 23:05:18 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>
#include <new>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "color.hpp"

Base *generate(void)
{
	int	type;
	std::srand(std::time(0));

	type = rand() % 3;
	switch (type)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		default:
			return (new C());
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << C_PURPLE << "A" << RESET << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << C_MAGENTA << "B" << RESET << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << C_CORAL << "C" << RESET << std::endl;
}

void identify(Base& p)
{
	try
	{
		A &test = dynamic_cast<A &>(p);
		std::cout << C_PURPLE << "A" << RESET << std::endl;
		(void) test;
	}
	catch (std::exception &e) {}
	try
	{
		B &test = dynamic_cast<B &>(p);
		std::cout << C_MAGENTA << "B" << RESET << std::endl;
		(void) test;
	}
	catch (std::exception &e) {}
	try
	{
		C &test = dynamic_cast<C &>(p);
		std::cout << C_PINK << "C" << RESET << std::endl;
		(void) test;
	}
	catch (std::exception &e) {}
}
