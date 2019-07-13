/****************************
Tomer Guttman - 204381487	*
Ohad Sluzky -	305070831   *
****************************/

#include "member.h"

Member::Member(string member_name, string member_bday): User(member_name)
{
	b_day = member_bday;
}//end c'tor.

Member::Member(const Member& source_member): User(source_member)
{
	//copy strings.
	b_day = source_member.b_day;
	friendsList = source_member.friendsList;
	LikedPages = source_member.LikedPages;
	statusList = source_member.statusList;
}//end cpy c'tor.

 //show commands.

void Member::showFriends()
{
	int i = 0;
	vector<Member*>::iterator itr = friendsList.begin();
	vector<Member*>::iterator itrEnd = friendsList.end();
	cout << name << "'s friends are:\n";
	for (; itr != itrEnd; ++itr, i++)
	{
		Member * temp = dynamic_cast<Member*>(*itr);
		cout << "  " << i + 1 << ") ";
		temp->showMember();
	}//end for.
}//end showFriends.

void Member::showLikedPages()
{
	int i = 0;
	vector<Fan_page*>::iterator itr = LikedPages.begin();
	vector<Fan_page*>::iterator itrEnd = LikedPages.end();
	cout << name << "'s liked pages are:\n";
	for (; itr != itrEnd; ++itr, i++)
	{
		Fan_page * temp = dynamic_cast<Fan_page*>(*itr);
		cout << "  " << i + 1 << ") ";
		temp->showPage();
	}//end for.
}//end showLikedPages.

void Member::showMember()
{
	cout << " Name: " << name << ", birthday: " << b_day << endl;
}//end showMember;

 //add commands.

void Member::addFanPage(Fan_page * likedFanPage)
{
	LikedPages.push_back(likedFanPage);
}//endFanPage.

void Member::addStatus(Status * new_status)
{
	User::addStatus(new_status);
	cout << "The new status was add to " << name << endl;
	cout << "-----------------------------------------------------\n";
}//end addStatus.