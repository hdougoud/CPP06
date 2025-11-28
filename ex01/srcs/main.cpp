/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:17:39 by hdougoud          #+#    #+#             */
/*   Updated: 2025/11/28 15:34:57 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "color.hpp"
#include "Serializer.hpp"
#include "data.hpp"

Data *createData(std::string str, int nb);

int main(void)
{
	uintptr_t	dataInt;
	Data		*dataPtr;

	dataPtr = createData("Hello", 10);
	dataInt = Serializer(dataPtr);
	return (0);
}

void	printData(Data *data)
{
	if (!data)
		std::cout << C_YELLOW << "data is null" << RESET << std::endl;

}

Data *createData(std::string str, int nb)
{
	Data *ptr = new Data();
	
	ptr->str = str;
	ptr->nb = nb;
	return (ptr);
}
