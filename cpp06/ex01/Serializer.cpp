/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:04:51 by mvicedo           #+#    #+#             */
/*   Updated: 2023/11/09 14:55:25 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer:: Serializer()
{
	
}

Serializer:: Serializer(const Serializer &other)
{
	*this = other;
}

Serializer &Serializer:: operator=(const Serializer &other)
{
	if (this != &other)
	{
		
	}
	return (*this);
}

Serializer:: ~Serializer()
{
	
}

uintptr_t Serializer:: serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer:: deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
