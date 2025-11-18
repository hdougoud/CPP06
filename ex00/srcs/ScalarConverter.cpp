/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:36:04 by hdougoud          #+#    #+#             */
/*   Updated: 2025/11/18 17:40:37 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

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

void	ScalarConverter::convert(std::string value)
{
	std::cout << value << std::endl;
}
