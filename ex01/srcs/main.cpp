/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:17:39 by hdougoud          #+#    #+#             */
/*   Updated: 2025/11/28 18:18:28 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "color.hpp"
#include "Serializer.hpp"
#include "data.hpp"

void	printData(Data *data);
Data	*createData(std::string str, int nb);

int main(void)
{
	uintptr_t	dataInt;
	Data		*dataPtr;

	dataPtr = createData("Hello", 10);
	dataInt = Serializer::serialize(dataPtr);
	dataPtr = NULL;
	printData(dataPtr);
	dataPtr = Serializer::deserialize(dataInt);
	printData(dataPtr);
	delete dataPtr;
	return (0);
}

void	printData(Data *data)
{
	if (!data)
	{
		std::cout << C_YELLOW << "data is null" << RESET << std::endl;
		return ;
	}
	std::cout << C_BLUE << data->str << "\n" \
		<< data->nb << RESET <<RESET <<  std::endl; 
}

Data	*createData(std::string str, int nb)
{
	Data *ptr = new Data();
	
	ptr->str = str;
	ptr->nb = nb;
	return (ptr);
}
