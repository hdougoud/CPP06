/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:23:24 by hdougoud          #+#    #+#             */
/*   Updated: 2025/11/26 23:31:25 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include "color.hpp"

using namespace std;

static char		sChar;
static int		sInt;
static float	sFloat;
static double	sDouble;

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

	idx = _detectType(value);
	_convertValue(idx);
	_printResult();
}

int	ScalarConverter::_detectType(std::string type)
{
	std::string::iterator	it;
	const char				*cstr = type.c_str();

	if (type.length() == 1 && std::isprint(cstr[0]) && !std::isdigit(cstr[0]))
	{
		sChar = cstr[0];
		return (0);
	}
	if (it == type.end())
	{
		sInt = std::strtol(cstr, NULL, 10);
		return (1);
	}
	it++;
	if (*it == '.')
	{	
		for(it = type.begin(); it != type.end() && isdigit(*it); it++)
			;
		if (it == type.end())
		{
			sDouble = std::strtod(cstr, NULL);
			return (3);
		}
		it++;
		if (*it == 'f' && it == type.end())
		{
			sFloat = std::strtod(cstr, NULL);
			return (2);
		}
	}
	return 4;
}

void	ScalarConverter::_convertValue(int idx)
{
	switch (idx)
	{
		case 0:
			sInt = static_cast<int>(sChar);
			sFloat = static_cast<float>(sChar);
			sDouble = static_cast<double>(sChar);
			break ;
		case 1:
			sChar = static_cast<char>(sInt);
			sFloat = static_cast<float>(sInt);
			sDouble = static_cast<double>(sInt);
			break ;
		case 2:
			sChar = static_cast<char>(sFloat);
			sInt = static_cast<int>(sFloat);
			sDouble = static_cast<double>(sFloat);
			break ;
		case 3:
			sChar = static_cast<char>(sDouble);
			sInt = static_cast<int>(sInt);
			sFloat = static_cast<float>(sFloat);
			break ;
		default:
			sChar = '0';
			sInt = 0;
			sFloat = 0;
			sDouble = 0;
	}
}

void	ScalarConverter::_printResult(void)
{
	std::cout << C_PURPLE << "char:   ";
	isprint(sChar) ? std::cout << sChar << "\n" : std::cout << "N/A\n";
	std::cout << C_PINK << "int:    " << sInt << "\n";
	std::cout << C_CORAL << "float:  " << sFloat;
	if (std::floor(sFloat) == sFloat)
		std::cout << ".0";
	std::cout << "f" << "\n";
	std::cout << C_MAGENTA << "double: " << sDouble;
	if (floor(sFloat) == sFloat)
		std::cout << ".0";
	std::cout << RESET << std::endl;
}

