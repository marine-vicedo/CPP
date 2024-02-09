/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:19:16 by mvicedo           #+#    #+#             */
/*   Updated: 2023/11/09 15:01:09 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main(void)
{
	Data data;
	data.value = 5;
	data.word = "computer";

	uintptr_t raw = Serializer::serialize(&data);
	Data *dataPtr = Serializer::deserialize(raw);

	if (&data == dataPtr)
	{
		std::cout << "Reinterpret cast works\n" 
		<< "Adress of dataPtr: " << dataPtr << std::endl
		<< "Adress of data: " << &data << std::endl
		<< "dataPtr value & word : "<< dataPtr->value << " & " << dataPtr->word << std::endl
		<< "data value & word : "<< data.value << " & " << data.word << std::endl;
	}
	else
		std::cout << "Problem with the reinterpret cast\n";
	return (0);
}