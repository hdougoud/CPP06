/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:36:04 by hdougoud          #+#    #+#             */
/*   Updated: 2025/11/24 19:40:16 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

ScalarConverter::ScalarConverter() : _character(0), _integer(0), _floatPoint(0), _doublePoint(0)
{
	return ;
}

ScalarConverter::ScalarConverter(const ScalarConverter &src) :
	_character(src._character), _integer(src._integer), _floatPoint(src._floatPoint), _doublePoint(src._doublePoint)
{
	return ;
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &src)
{
	if (this != &src)
	{
		_character = src._character;
		_integer = src._integer;
		_floatPoint = src._floatPoint;
		_doublePoint = src._doublePoint;
	}
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	return ;
}

void	ScalarConverter::convert(const std::string &value)
{
	ScalarConverter converter;

	converter._printResult();
}

void	ScalarConverter::detectType(const std::string &type)
{
	//use switch case
}

void	ScalarConverter::convertData(int idx)
{
	switch (idx)
	{
		case 0:
			this->_integer = static_cast<int>(this->_character);
			this->_floatPoint = static_cast<float>(this->_character);
			this->_doublePoint = static_cast<double>(this->_character);
		case 1:
			this->_character = static_cast<char>(this->_integer);
			this->_floatPoint = static_cast<float>(this->_integer);
			this->_doublePoint = static_cast<double>(this->_integer);
		case 2:
			this->_character = static_cast<char>(this->_floatPoint);
			this->_integer = static_cast<int>(this->_floatPoint);
			this->_doublePoint = static_cast<double>(this->_floatPoint);
		case 3:
			this->_character = static_cast<char>(this->_doublePoint);
			this->_integer = static_cast<int>(this->_integer);
			this->_floatPoint = static_cast<float>(this->_floatPoint);
	}
}

void	ScalarConverter::_printResult(void)
{
	std::cout << "char: " << this->_character << "\n" //TODO: add one color per type
	<< "int: " << this->_integer << "\n"
	<< "float: " << this->_floatPoint << "f\n"
	<< "double: " << this->_doublePoint << std::endl;
}
