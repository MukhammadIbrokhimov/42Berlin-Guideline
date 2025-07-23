/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 17:37:39 by muxammad          #+#    #+#             */
/*   Updated: 2025/07/08 15:43:31 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

std::string manualReplace(const std::string& original,
						const std::string& search,
						const std::string& replace) {
	if (search.empty() || replace.empty()) {
		std::cerr << "\033[31mDid you really think I could replace NOTHING with SOMETHING?!\033[0m 🤯💥\n";
		return "";
	}

	std::string result = original;
	size_t pos = 0;
	while ((pos = result.find(search, pos)) != std::string::npos) {
		result.erase(pos, search.length());
		result.insert(pos, replace);
		pos += replace.length();
	}

	return result;
}

int saveChanges(const std::string& content, const std::string& fileName) {
	if (content.empty())
		return 1;
	std::string outFileName = fileName + ".replace";
	std::ofstream outPut(outFileName.c_str());
	if (!outPut.is_open()) {
		std::cerr << "\033[31mFailed to open the output file.🔒\033[0m\n";
		return 1;
	}
	outPut << content;
	outPut.close();
	std::cout << "\033[32mFile saved successfully: '" << outFileName << "'.\033[0m\n";
	return (0);
}

int main(int argc, char** argv) {
	if (argc != 4) {
		std::cerr << "\033[31mProvide correct arguments!\033[0m 😡" << std::endl;
		return 1;
	}

	std::string search = argv[2];
	std::string replace = argv[3];
	if (search == replace) {
		std::cerr << "\033[31mAre you serious? You gave me the SAME input twice 😡\033[0m" << std::endl;
		return 1;
	}

	std::ifstream infile(argv[1]);
	if (!infile.is_open()) {
		std::cerr << "\033[31mNot possible to read file! 🤷‍♂️\033[0m" << std::endl;
		return 1;
	}

	std::string line;
	std::string content;
	while (std::getline(infile, line)) {
		content += line + '\n';
	}
	infile.close();

	std::string updated = manualReplace(content, search, replace);
	if (updated.empty()) {
		std::cerr << "\033[33mNo changes made or input was invalid. Stopping.\033[0m 😤🛑📛\n";
		return 1;
	}

	saveChanges(updated, argv[1]);

	return 0;
}
