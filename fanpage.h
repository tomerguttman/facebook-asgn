/****************************
Tomer Guttman - 204381487	*
Ohad Sluzky -	305070831   *
****************************/
#define _CRT_SECURE_NO_WARNINGS

#ifndef __FANPAGE_H
#define __FANPAGE_H

#include "status.h"
#include "member.h"

class Member;

using namespace std;

class Fan_page :public User
{
private:

public:
	Fan_page(string name) : User(name) {}// c'tor.

	Fan_page(const Fan_page& source_fanpage) : User(source_fanpage) {} 	//cpy c'tor

	~Fan_page() {} // d'tor.

	void show_page_members();

	void showPage();

};
#endif // __FANPAGE.H