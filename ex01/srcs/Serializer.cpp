/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 13:30:54 by hdougoud          #+#    #+#             */
/*   Updated: 2025/11/28 15:32:38 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "data.hpp"

Serializer::Serializer()
{
	return ;
}

Serializer::Serializer(const Serializer &src)
{
	(void) src;
	return ;
}

Serializer	&Serializer::operator=(const Serializer &src)
{
	(void) src;
	return *(this);
}

Serializer::~Serializer()
{
	return ;
}

uintptr_t	Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
