/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:23:24 by hdougoud          #+#    #+#             */
/*   Updated: 2025/11/28 11:41:14 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cctype>
#include <cstdlib>
#include <errno.h>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include "color.hpp"

void	printPseudo(const std::string &value);
void	castAndPrintValue(char value);
void	castAndPrintValue(int value);
void	castAndPrintValue(float value, unsigned int precision);
void	castAndPrintValue(double value, unsigned int precision);
void	printImpossible(void);

ScalarConverter::ScalarConverter()
{
	return ;
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	(void) src;
	return ;
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &src)
{
	(void) src;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	return ;
}

void	ScalarConverter::convert(std::string type)
{
	errno = 0;
	std::string::iterator it = type.begin();

	std::cout << C_WHITE << "Trying to convert: " << type << RESET << std::endl;
	if (type == "nan" || type == "nanf" || type ==  "inf" || type == "inff" \
		|| type == "-inff" || type == "-inf" || type == "+inf" || type == "+inff")
	{
		printPseudo(type);
		return ;
	}

	if (type.length() == 1 && std::isprint(*it) && !std::isdigit(*it))
	{
		castAndPrintValue(type.c_str()[0]);
		return ;
	}

	if (*it == '+' || *it == '-')
		it++;
	while (it != type.end() && isdigit(*it))
		it++;

	if (it == type.end())
	{
		long tint = std::strtol(type.c_str(), NULL, 10);
		if (!(tint > std::numeric_limits<int>::max() || tint < std::numeric_limits<int>::min()) && !errno)
		{
			castAndPrintValue(static_cast<int>(tint));
			return ;
		}
		printImpossible();
		return ;
	}

	if (*it == '.')
	{
		it++;
		unsigned int precision = std::distance(it, type.end());
		while (it != type.end() && isdigit(*it))
			it++;
		if (it == type.end())
		{
			double tdouble = (strtod(type.c_str(), NULL));
			if (errno)
			{
				printImpossible();
				return ;
			}
			castAndPrintValue(tdouble, precision);
			return ;
		}
		if (*it == 'f' && ++it == type.end())
		{
			float tfloat = (strtof(type.c_str(), NULL));
			if (errno)
			{
				printImpossible();
				return ;
			}
			castAndPrintValue(tfloat, precision - 1);
			return ;
		}
	}
	printImpossible();
}

void	printPseudo(const std::string &value)
{
	std::cout << C_PURPLE << "char:   " << "impossible\n";
	std::cout << C_MAGENTA << "int:    " << "impossible\n";

	if (value == "nan" || value == "nanf")
	{
		std::cout << C_PINK << "float:  nanf\n" \
		<< C_CORAL << "double: nan" << std::endl;
	}
	else if (value == "inf" || value == "+inf" || value == "inff" || value == "+inff")
	{
		std::cout << C_PINK << "float:  inff\n" \
		<< C_CORAL << "double: inf" << std::endl;
	}
	else if (value == "-inf" || value == "-inff")
	{
		std::cout << C_PINK << "float:  -inff\n" \
		<< C_CORAL << "double: -inf" << std::endl;
	}
}

void	castAndPrintValue(char value)
{
	std::cout << std::fixed << std::setprecision(1) \
	<< C_PURPLE << "char:   " << value << "\n" \
	<< C_MAGENTA << "int:    " << static_cast<int>(value) << "\n" \
	<< C_PINK << "float:  " << static_cast<float>(value) << "f\n" \
	<< C_CORAL << "double: " << static_cast<double>(value)  << RESET << std::endl;
}

void	castAndPrintValue(int value)
{
	std::cout << std::fixed << std::setprecision(1);
	std::cout << C_PURPLE << "char:   ";
	value < 0 || value > 128 ? std::cout << "impossible" : (isprint(value) ? std::cout << static_cast<char>(value) : std::cout << "non displayable");
	std::cout << "\n";
	std::cout << C_MAGENTA << "int:    " << value << "\n";
	std::cout << C_PINK << "float:  " << static_cast<float>(value) << "f\n";
	std::cout << C_CORAL << "double: " << static_cast<double>(value) << "\n";
}

void	castAndPrintValue(float value, unsigned int precision)
{
	if (!precision)
		precision = 1;
	std::cout << std::fixed << std::setprecision(precision);
	std::cout << C_PURPLE << "char:   ";
	value < 0 || value > 128 ? std::cout << "impossible" : (isprint(value) ? std::cout << static_cast<char>(value) : std::cout << "non displayable");
	std::cout << "\n";

	std::cout << C_MAGENTA << "int:    ";
	(value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min()) ? std::cout << "impossible" : std::cout << static_cast<int>(value);
	std::cout << "\n";

	std::cout << C_PINK << "float:  " << value << "f\n";

	std::cout << C_CORAL << "double: " << static_cast<double>(value) << RESET << std::endl;
}

void	castAndPrintValue(double value, unsigned int precision)
{
	if (!precision)
		precision = 1;
	std::cout << std::fixed << std::setprecision(precision);
	std::cout << C_PURPLE << "char:   ";
	value < 0 || value > 128 ? std::cout << "impossible" : (isprint(value) ? std::cout << static_cast<char>(value) : std::cout << "non displayable");
	std::cout << "\n";

	std::cout << C_MAGENTA << "int:    ";
	(value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min()) ? std::cout << "impossible" : std::cout << static_cast<int>(value);
	std::cout << "\n";

	std::cout << C_PINK << "float:  ";
	(value > std::numeric_limits<float>::max() || value < std::numeric_limits<float>::min()) ? std::cout << "impossible" : std::cout << static_cast<float>(value);
	std::cout << "\n";

	std::cout << C_CORAL << "double: " << value << RESET << std::endl;
}

void	printImpossible(void)
{
	std::cout << C_RED
	<< "impossible\n"
	<< "impossible\n"
	<< "impossible\n"
	<< "impossible"
	<< RESET << std::endl;
}

