/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 08:56:48 by hdougoud          #+#    #+#             */
/*   Updated: 2025/11/25 16:27:01 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class ScalarConverter
{
	public:
		static void	convert(const std::string &value);
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter &operator=(const ScalarConverter &src);
		~ScalarConverter();

		static int	_detectType(std::string type);
		static void	_convertValue(int idx);
		static void	_printResult(void);
};

