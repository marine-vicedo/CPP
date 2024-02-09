/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:41:18 by mvicedo           #+#    #+#             */
/*   Updated: 2023/12/13 14:08:31 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

# define MICROSECOND 100000

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src) 
{
	_vectorNb = src._vectorNb;
	_listNb = src._listNb;
}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
	if (this != &rhs)
	{
		_vectorNb = rhs._vectorNb;
		_listNb = rhs._listNb;
	}
	return (*this);
}

std::vector<unsigned int> PmergeMe:: mergeVecs(std::vector<unsigned int>& left, std::vector<unsigned int>& right)
{
	std::vector<unsigned int> result;

	while (!left.empty() && !right.empty())
	{
		if (left.front() <= right.front())
		{
			result.push_back(left.front());
			left.erase(left.begin());
		}
		else
		{
			result.push_back(right.front());
			right.erase(right.begin());
		}
	}
	while (!left.empty())
	{
		result.push_back(left.front());
		left.erase(left.begin());
	}
	while (!right.empty())
	{
		result.push_back(right.front());
		right.erase(right.begin());
	}
	return result;
}

void PmergeMe:: insertionSort (std::vector<unsigned int>& vec)
{
	for (size_t i = 1; i < vec.size(); ++i)
	{
		unsigned int current = vec[i];
		int j = i - 1;

		while (j >= 0 && vec[j] > current)
		{
			vec[j + 1] = vec[j];
			j--;
		}
		vec[j + 1] = current;
	}
}

std::vector<unsigned int> PmergeMe:: mergeInsertVec(std::vector<unsigned int>& vec)
{
	size_t threshold = 2;
	if (vec.size() <= threshold)
	{
		insertionSort(vec);
		return vec;
	}

	int mid = vec.size() / 2;
	std::vector<unsigned int> left(vec.begin(), vec.begin() + mid);
	std::vector<unsigned int> right(vec.begin() + mid, vec.end());

	left = mergeInsertVec(left);
	right = mergeInsertVec(right);

	std::vector<unsigned int> result = mergeVecs(left, right);
	return result;
}


void PmergeMe ::sortVector(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
	{
		unsigned int num = atoi(av[i]);
		_vectorNb.push_back(num);
	}

	displayMsg("Before sort", _vectorNb);

	std::clock_t start = std::clock();
	std::cout << start << std::endl;

	_vectorNb = mergeInsertVec(_vectorNb);

	double time_taken = static_cast<double>(std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC) * MICROSECOND;

	displayMsg("After sort", _vectorNb);

	std::cout << "Time to process a range of " << ac - 1
		 << " elements " << "with std::vector<unsigned int> : " 
		 << time_taken << " µs" << std::endl;
	
}

std::list<unsigned int> PmergeMe:: mergeLists(std::list<unsigned int>& left, std::list<unsigned int>& right)
{
	std::list<unsigned int> result;

	while (!left.empty() && !right.empty())
	{
		if (left.front() <= right.front())
		{
			result.push_back(left.front());
			left.erase(left.begin());
		}
		else
		{
			result.push_back(right.front());
			right.erase(right.begin());
		}
	}

	while (!left.empty())
	{
		result.push_back(left.front());
		left.erase(left.begin());
	}

	while (!right.empty())
	{
		result.push_back(right.front());
		right.erase(right.begin());
	}
	return result;
}

void PmergeMe:: insertionSort(std::list<unsigned int> &list)
{

	for (std::list<unsigned int>::iterator it = ++list.begin(); it != list.end(); ++it)
	{
		unsigned int current = *it;
		std::list<unsigned int>::iterator it2 = it;

		while (it2 != list.begin())
		{
			std::list<unsigned int>::iterator prev = it2;
			--prev;

			if (*prev > current)
			{
				*it2 = *prev;
				--it2;
			}
			else
				break;
		}
		*it2 = current;
	}
}

std::list<unsigned int> PmergeMe:: mergeInsertList(std::list<unsigned int>& list)
{
	size_t threshold = 2;
	if (list.size() <= threshold)
	{
		insertionSort(list);
		return list;
	}

	int mid = list.size() / 2;
	std::list<unsigned int> left;
	std::list<unsigned int> right;

	std::list<unsigned int>::iterator it = list.begin();
	for(int i = 0; i < mid; i++)
	{
		left.push_back(*it);
		++it;
	}
	while (it != list.end())
	{
		right.push_back(*it);
		++it;
	}

	left = mergeInsertList(left);
	right = mergeInsertList(right);

	std::list<unsigned int> result = mergeLists(left, right);
	return result;
}

void PmergeMe:: sortList(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
	{
		unsigned int num = atoi(av[i]);
		_listNb.push_back(num);
	}
	//displayMsg("Before sort", _listNb);
	
	std::clock_t start = std::clock();
	std::cout << start << std::endl;

	_listNb = mergeInsertList(_listNb);

	double time_taken = static_cast<double>(std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC) * MICROSECOND;

	//displayMsg("After sort", _listNb);
	
	std::cout << "Time to process a range of " << ac - 1
		 << " elements " << "with std::list<unsigned int> : " 
		 << time_taken << " µs" << std::endl;
}