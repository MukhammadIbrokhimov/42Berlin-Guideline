/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   namespaces.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:58:22 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/10 16:06:58 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	gl_var = 3;
int	f(void) { return (2); }

namespace	foo{
	int	gl_var = 4;
	int f(void) { return (2); }
}

namespace Moo{
	int	gl_var = 8;
	int f(void) { return (2); }
}

namespace Noo = Moo;

int	main(void){
	using namespace std;
	cout << "gl_var: " << ::gl_var << endl;
	cout << "f: " << ::f() << endl;
	cout << "foo, gl_var: " << foo::gl_var << endl;
	cout << "foo, f: " << foo::f() << endl;
	cout << "moo, gl_var: " << Moo::gl_var << endl;
	cout << "moo, f: " << Moo::f() << endl;
	cout << "moo, gl_var: " << Noo::gl_var << endl;
	cout << "moo, f: " << Noo::f() << endl;
}