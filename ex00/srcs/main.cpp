/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 22:28:11 by hdougoud          #+#    #+#             */
/*   Updated: 2025/11/28 11:52:15 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "color.hpp"
#include "ScalarConverter.hpp"

void	test_char(void);
void	test_int(void);
void	test_float(void);
void	test_double(void);
void	test_pseudo(void);

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << F_BOLD << F_UNDERLINED << C_BLUE \
			<< "TEST MODE\n" << RESET << std::endl;
		test_char();
		test_int();
		test_float();
		test_double();
		test_pseudo();
	}
	else if (argc == 2)
		ScalarConverter::convert(argv[1]);
	else
	{
		std::cout << F_BOLD << C_RED << "Too much args" << RESET << std::endl;
		return (1);
	}
	return (0);
}

void	test_char(void)
{
	std::cout << F_BOLD << C_WHITE << "Convert from char" << RESET << std::endl;
	ScalarConverter::convert("a");
	std::endl(std::cout);
	ScalarConverter::convert("b");
	std::endl(std::cout);
	ScalarConverter::convert("c");
	std::endl(std::cout);
	ScalarConverter::convert("a");
	std::endl(std::cout);
	ScalarConverter::convert("~");
	std::endl(std::cout);
	ScalarConverter::convert("");
	std::endl(std::cout);
}

void	test_int(void)
{
	std::cout << F_BOLD << C_WHITE << "\n\nConvert from int" << RESET << std::endl;
	ScalarConverter::convert("123");
	std::endl(std::cout);
	ScalarConverter::convert("+1");
	std::endl(std::cout);
	ScalarConverter::convert("-123");
	std::endl(std::cout);
	ScalarConverter::convert("+abc");
	std::endl(std::cout);
	ScalarConverter::convert("0");
	std::endl(std::cout);
	ScalarConverter::convert("2147483647");
	std::endl(std::cout);
	ScalarConverter::convert("2147483648");
	std::endl(std::cout);
	ScalarConverter::convert("-2147483648");
	std::endl(std::cout);
	ScalarConverter::convert("-2147483649");
	std::endl(std::cout);
	ScalarConverter::convert("-2147abc");
	std::endl(std::cout);
}

void	test_float(void)
{
	std::cout << F_BOLD << C_WHITE << "\n\nConvert from float" << RESET << std::endl;
	ScalarConverter::convert("123.12f");
	std::endl(std::cout);
	ScalarConverter::convert("+123.0f");
	std::endl(std::cout);
	ScalarConverter::convert("-123.105f");
	std::endl(std::cout);
	ScalarConverter::convert("+abc.12f");
	std::endl(std::cout);
	ScalarConverter::convert("1784.1245f");
	std::endl(std::cout);
	ScalarConverter::convert("340282346638587968796784989785978597854978497.1f");
	std::endl(std::cout);
	ScalarConverter::convert("1784.1245F");
	std::endl(std::cout);
	ScalarConverter::convert("1784.1245of");
	std::endl(std::cout);
	ScalarConverter::convert("1784.1245ff");
	std::endl(std::cout);

}

void	test_double(void)
{
	std::cout << F_BOLD << C_WHITE << "\n\nConvert from double" << RESET << std::endl;
	ScalarConverter::convert("123.12");
	std::endl(std::cout);
	ScalarConverter::convert("+123.0");
	std::endl(std::cout);
	ScalarConverter::convert("-123.105");
	std::endl(std::cout);
	ScalarConverter::convert("+abc.12");
	std::endl(std::cout);
	ScalarConverter::convert("1784.1245");
	std::endl(std::cout);
	ScalarConverter::convert("123..105");
	std::endl(std::cout);
	ScalarConverter::convert("123.1o5");
	std::endl(std::cout);
	ScalarConverter::convert("340282346638587968796784989785978597854978497.1");
	std::endl(std::cout);
}

void	test_pseudo(void)
{
	std::cout << F_BOLD << C_WHITE << "\n\nConvert from pseudo" << RESET << std::endl;
	ScalarConverter::convert("nan");
	std::endl(std::cout);
	ScalarConverter::convert("nanf");
	std::endl(std::cout);
	ScalarConverter::convert("inf");
	std::endl(std::cout);
	ScalarConverter::convert("+inf");
	std::endl(std::cout);
	ScalarConverter::convert("-inf");
	std::endl(std::cout);
	ScalarConverter::convert("inff");
	std::endl(std::cout);
	ScalarConverter::convert("+inff");
	std::endl(std::cout);
	ScalarConverter::convert("-inff");
	std::endl(std::cout);
	ScalarConverter::convert("random");
	std::endl(std::cout);
}
