/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:23:12 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/11 14:11:37 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _INIT_CLASS_HPP_
# define _INIT_CLASS_HPP_

#include <iostream>

class	Sample{
	private:
		static int created;
		int		a1;
		int		b1;
		char	c1;
	public:

		Sample(void);
		Sample(int p1, int p2, char p3);
		~Sample(void);

		void	pressed(void);
		static int	get_d1(void);
};

class	Student{
	private:
		std::string name = "new student";
		int			age;
	public:
		Student(void){
			std::cout << "Student" << name << "born" << std::endl;
		}
		Student(std::string name, int age) : name(name), age(age){
			std::cout << "Student" << name << "born" << std::endl;
		}
		~Student(void){
			std::cout << "Student" << name << "died" << std::endl;
		}
};

#endif