/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:41:20 by mvicedo           #+#    #+#             */
/*   Updated: 2023/11/17 11:41:21 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Array.hpp"

#define SIZE 10

int main( void )
{
	{
		std::cout << std::endl << "------------------------------------" << std::endl
		<< "\tTESTING INT & FLOAT" << std::endl << "------------------------------------" << std::endl;

		std::cout << "CREATING AN EMPTY ARRAY :" << std::endl;
		Array<float> test;

		std::cout << std::endl << "CREATING TWO INT ARRAYS :" << std::endl;

		Array<int> intArray1(SIZE);
		for (size_t i = 0; i < intArray1.size(); i++ )
			intArray1[i] = i;
		std::cout << CYAN "intArray1 (size " << intArray1.size()  << "): " << intArray1 << NC << std::endl;

		Array<int> intArray2(SIZE - 5);
		for (size_t i = 0; i < intArray2.size(); i++ )
			intArray2[i] = i;
		std::cout << PURPLE "intArray2 (size " << intArray2.size() << "): " << intArray2 << NC << std::endl;

		std::cout << std::endl << "DEEP COPY :" << std::endl;
		std::cout << CYAN "intArray (size " << intArray1.size() << "): " << intArray1 << NC << std::endl;
		intArray2 = intArray1;
		std::cout << PURPLE "intArray2 (size " << intArray2.size() << "): " << intArray2 << NC << std::endl;

		std::cout << std::endl << "READING INDEXES :" << std::endl;
		try {
			std::cout << "Accessing a valid index: " << intArray1[5] << std::endl;
			std::cout << "Accessing an invalid index: " << intArray1[SIZE+1] << std::endl;
		} catch ( const std::exception & e ) {
			std::cout << RED "Error: " << e.what() << NC << std::endl;
		}
	}

	{
		std::cout << std::endl << "------------------------------------" << std::endl
		<< "\tTESTING STRING" << std::endl << "------------------------------------" << std::endl;

		Array<std::string>	String1(4);
		String1[0] = "My";
		String1[1] = "name";
		String1[2] = "is";
		String1[3] = "Dumbo";
		std::cout << CYAN "String1 (size " << String1.size()
			<< "): " << String1 << NC << std::endl;
		
		Array<std::string>	String2(2);
		String2[0] = "I am";
		String2[1] = "an Elephant.";
		std::cout << PURPLE "String2 (size " << String2.size()
			<< "): " << String2 << NC << std::endl;

		String1 = String2;
		std::cout << CYAN "String1 (size " << String1.size()
			<< "): " << String1 << NC << std::endl;
		try
		{
			String1[3] = "Something that doesn't exist.";
		}
		catch(const std::exception & e)
		{
			std::cout << RED "Accessed out of bounds index [3], "
				"and got exception: " << e.what() << NC << std::endl;
		}
	}
	return ( 0 );
}

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;
//     return 0;
// }