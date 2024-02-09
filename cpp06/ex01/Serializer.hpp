/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:55:19 by mvicedo           #+#    #+#             */
/*   Updated: 2023/11/09 14:40:26 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include <string>

struct Data
{
	int value;
	std::string word;
};

class Serializer
{
	private:
		Serializer();
	
	public:
		Serializer(const Serializer &other);
		Serializer &operator=(const Serializer &other);
		~Serializer();
		
		static uintptr_t serialize(Data *ptr);//converts Data* to uintptr_t
		static Data *deserialize(uintptr_t raw);//converts uintptr_t to Data*
};

#endif