/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:32:39 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/14 18:46:58 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

bool	performText(std::ifstream &fileName, char **argv){
	int				flag = 1;
	size_t			pos;
	std::string		line;
	std::string		name = argv[1];
	std::string		findText = argv[2];
	std::string		replaceText = argv[3];
	name.insert(4, ".replace");
	std::ofstream	outputFile(name.c_str());
	if (!outputFile.is_open()){
		return (perror("\033[31mNot possible to create a file!\n\033[31m 😭"), false);
	}
	while (getline(fileName, line)){
		pos	= line.find(findText);
		if (pos != std::string::npos){
			line.erase(pos, replaceText.length());
			line.insert(pos, replaceText);
			flag = 0;
		}
		outputFile << line << "\n";
	}
	if (!flag){
		std::cout << "\033[36m"
				<< findText <<" \033[32mwas replaced with\033[32m " 
				<< "\033[36m" << replaceText << " 😎 🕺" << std::endl;
	}
	else{
		std::cout << "\033[36m" << findText <<" \033[31mnot found 🤷‍♂️" << std::endl;
	}
	return ((flag) ? false : true);
}

int	main(int argc, char **argv){
	if (argc != 4){
		std::cerr << "\033[31mProvide with correct arguments!\033[0m 😡" << std::endl;
		return (1);
	}
	std::ifstream	readFile(argv[1]);
	if (!readFile.is_open()){
		return (perror("\033[31mNot possible to read file!\n\033[31m 🤷‍♂️"), 1);
	}
	std::string	findText = argv[2];
	std::string	replaceText = argv[3];
	if (!performText(readFile, argv)){
		std::cerr << "\033[31mFailed to replace\033[0m  😭" << std::endl;
		return (readFile.close(), 1);
	}
	return (readFile.close(), 0);
}