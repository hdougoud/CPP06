/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 22:28:11 by hdougoud          #+#    #+#             */
/*   Updated: 2025/11/21 02:10:22 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

int main(void)
{
	float test = 123.23;
	
	std::cout << (int)test << "\n" << test << "\n" << (double)test << "\n" << std::endl;
	return (0);
}
