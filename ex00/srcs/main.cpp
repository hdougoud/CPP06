/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 22:28:11 by hdougoud          #+#    #+#             */
/*   Updated: 2025/11/27 23:05:27 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.hpp"
#include "ScalarConverter.hpp"


int main(void)
{
	ScalarConverter::convert("a");
	ScalarConverter::convert("2147483");
	ScalarConverter::convert("127");
	ScalarConverter::convert("56");
	ScalarConverter::convert("123.123f");
	ScalarConverter::convert("12.45");
	return (0);
}
