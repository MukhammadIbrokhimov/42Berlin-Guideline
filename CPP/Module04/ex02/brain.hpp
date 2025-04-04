/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:35:11 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/23 18:36:23 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef _BRAIN_HPP_

#define _BRAIN_HPP_
#include <iostream>

class Brain{
	private:
		std::string ideas[100];
	public:
		Brain();
		~Brain();

		Brain(const Brain &brain);
		Brain& operator=(const Brain& brain);
		std::string getIdea(int index);
		void setIdea(int index, std::string idea);
};

#endif