/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdougoud <hdougoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 08:56:48 by hdougoud          #+#    #+#             */
/*   Updated: 2025/11/27 22:44:16 by hdougoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class ScalarConverter
{
	public:
		static void	convert(std::string value);
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter &operator=(const ScalarConverter &src);
		~ScalarConverter();

		int	_detectType(std::string type);
		void	_convertValue(int idx);
		void	_printResult(void);
};

enum TYPE {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO,
	IMPOSSIBLE,
};
