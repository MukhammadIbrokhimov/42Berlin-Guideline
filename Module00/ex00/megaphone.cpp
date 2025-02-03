/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:49:08 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/03 20:06:10 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int	main(int argc, char **argv){
	using namespace std;
	if (argc != 1){
		for (int i = 1; argv[i]; i++){
			for (int j = 0; argv[i][j]; j++){
			cout << static_cast<char> (toupper(argv[i][j]));
			}
		}
		cout << endl;
	}
	else{
		string	text = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
		cout << text << endl;
	}
}