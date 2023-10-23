/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:39:51 by mvicedo           #+#    #+#             */
/*   Updated: 2023/10/20 15:07:26 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGDOG_HPP
# define WRONGDOG_HPP

#include "WrongAnimal.hpp"
#include <iostream>
#include <string>

class WrongDog : public WrongAnimal
{

	public :
		WrongDog();
		WrongDog(const WrongDog &other);
		WrongDog &operator=(const WrongDog &other);
		~WrongDog();
		void makeSound() const;
};

#endif