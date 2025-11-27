/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:23:24 by hdougoud          #+#    #+#             */
/*   Updated: 2025/11/27 16:37:22 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <errno.h>
#include <iostream>
#include <limits>
#include <string>
#include "color.hpp"

int		detectType(std::string type);
void	convertValue(const std::string &type, int idx);
void	printPseudo(const std::string &value);
void	printPseudo(const std::string &value);
void	castAndPrintValue(char value);
void	castAndPrintValue(int value);
void	castAndPrintValue(float value);
void	castAndPrintValue(double value);

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

void	ScalarConverter::convert(const std::string &value)
{
	int				idx;

	idx = detectType(value);
	convertValue(value, idx);
}

int	detectType(std::string type)
{
	errno = 0;
	std::string::iterator	it;
	const char				*cstr = type.c_str();

	if (type == "nan" || type == "nanf" || type ==  "inf" || type == "-inf" || type == "inff" || type == "-inff")
		return (PSEUDO);
	if (type.length() == 1 && std::isprint(static_cast<unsigned char>(cstr[0])) && !std::isdigit(cstr[0]))
		return (CHAR);
	for(it = type.begin(); it != type.end() && isdigit(*it); it++)
		;
	if (it == type.end())
	{
		long	temp;

		temp	= std::strtol(cstr, NULL, 10);
		if (!(temp > std::numeric_limits<int>::max() || temp < std::numeric_limits<int>::min()) && !errno)
			return (INT);
		return (IMPOSSIBLE);
	}
	if (*it == '.')
	{
		it++;
		while (it != type.end() && isdigit(*it))
			it++;
		if (it == type.end())
			return (DOUBLE);
		it++;
		if (*it == 'f' && it == type.end())
			return (FLOAT);
	}
	return (IMPOSSIBLE);
}

void	convertValue(const std::string &type, int idx)
{
	switch(idx)
	{
		case CHAR:
			castAndPrintValue(type.c_str()[0]);
			return ;
		case INT:
			castAndPrintValue(static_cast<int>(strtol(type.c_str(), NULL, 10)));
			break;
		case FLOAT:
			break;
		case DOUBLE:
			break;
		case PSEUDO:
			
			return;
		std::cout << C_RED
		<< "Impossible\n"
		<< "Impossible\n"
		<< "Impossible\n"
		<< "Impossible"
		<< RESET << std::endl;
	};
}

void	printPseudo(const std::string &value)
{
	(void) value;
}

void	castAndPrintValue(char value)
{
	std::cout << C_PURPLE << "char: " << value << "\n" \
	<< C_MAGENTA << "int: " << static_cast<int>(value) << "\n" \
	<< C_PINK << "float: " << static_cast<float>(value) << ".0f\n" \
	<< C_CORAL << "double: " << static_cast<double>(value) << ".0\n" << RESET << std::endl;
}

void	castAndPrintValue(int value)
{
	std::cout << value << std::endl;
}

void	castAndPrintValue(float value)
{
	std::cout << "char: ";
	value < 0 || value > 128 ? std::cout << "impossible" : isprint(value) ? 
	
}

void	castAndPrintValue(double value)
{
	(void) value;
}

