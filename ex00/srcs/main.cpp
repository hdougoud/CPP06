/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 22:28:11 by hdougoud          #+#    #+#             */
/*   Updated: 2025/11/25 14:39:03 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

int main(void)
{
	std::string test = "a";
	ScalarConverter::convert(test);
	test = "b";
	ScalarConverter::convert(test);
	test = "Hello";
	ScalarConverter::convert(test);
	test = "7";
	ScalarConverter::convert(test);
	test = "711abx";
	ScalarConverter::convert(test);
	return (0);
}
