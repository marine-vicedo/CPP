/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:39:55 by mvicedo           #+#    #+#             */
/*   Updated: 2023/12/12 10:30:28 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>

#define CYAN "\033[36m"
#define GREEN "\033[32m"
#define MAGENTA "\033[35m"
#define RED "\033[31m"
#define NC "\033[0m"

class PmergeMe
{
	private :
		std::vector<unsigned int> _vectorNb;
		std::list<unsigned int> _listNb;
	public :
		PmergeMe();
		PmergeMe(const PmergeMe &src);
		~PmergeMe();
		PmergeMe &operator=(const PmergeMe &rhs);

		void sortVector(int ac, char **av);
		std::vector<unsigned int> mergeVecs(std::vector<unsigned int>& left, std::vector<unsigned int>& right);
		std::vector<unsigned int> mergeInsertVec(std::vector<unsigned int>& vec);
		void insertionSort (std::vector<unsigned int>& vec);
		
		void sortList(int ac, char **av);
		std::list<unsigned int> mergeLists(std::list<unsigned int>& left, std::list<unsigned int>& right);
		std::list<unsigned int> mergeInsertList(std::list<unsigned int>& list);
		void insertionSort (std::list<unsigned int>& list);

		template <typename Container>
		void displayMsg(const std::string& msg, const Container& cont) {
		std::cout << msg << ": ";
		for (typename Container::const_iterator it = cont.begin(); it != cont.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;

}
};

#endif