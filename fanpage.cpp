/****************************
Tomer Guttman - 204381487	*
Ohad Sluzky -	305070831   *
****************************/
#include "fanpage.h"

void Fan_page::show_page_members()
{
	cout << name << " fan page followers are:\n";
	int i = 0;
	vector<User*>::iterator itr = friendsList.begin();
	vector<User*>::iterator itrEnd = friendsList.end();
	for (; itr != itrEnd ; ++itr,i++)
	{
		cout << "  " << i + 1 << ")";
		Member* temp = dynamic_cast<Member*>(*itr);
		temp->showMember();
	}//end for.
}//end show_page_members.

 //shows page name and the amount of members who liked it.
void Fan_page::showPage()
{
	cout << "Page name: " << name << " - [number of likes: " << friendsList.capacity() << "]\n";
}//end showPage.