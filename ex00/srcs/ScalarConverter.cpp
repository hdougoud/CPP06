/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:23:24 by hdougoud          #+#    #+#             */
/*   Updated: 2025/11/25 16:27:29 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <bits/stdc++.h>

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
	std::cout << std::numeric_limits<float>::max() << std::endl;
	std::cout << std::numeric_limits<int>::max() << std::endl;
	std::cout << std::numeric_limits<double>::max() << std::endl;
}

int	ScalarConverter::_detectType(std::string type)
{
	//bool					isFloat = false;
	//bool					isOnlyDigit = false;
	const unsigned int		size = type.length();
	const char				*cstr = type.c_str();
	std::string::iterator	it;

	if (size == 1 && std::isprint(cstr[0]) && !std::isdigit(cstr[0]))
	{
		sChar = cstr[0];
		return (0);
	}
	for(it = type.begin(); it != type.end() && isdigit(*it); it++)
	{

	}
	//if(sFloat == static_cast<int>(sFloat))
	//std:::fixed << std::precision(2)
	//	std::cout << "same" << std::endl;
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
	//TODO:: add exception
	std::cout << "char: " << sChar << "\n" //TODO: add one color per type
	<< "int: " << sInt << "\n"
	<< "float: " << std::fixed << std::setprecision(1) << sFloat << "f\n"
	<< "double: " << sDouble << std::endl;
}
