/****************************
Tomer Guttman - 204381487	*
Ohad Sluzky -	305070831   *
****************************/
#define _CRT_SECURE_NO_WARNINGS

#ifndef __MEMBER_H
#define __MEMBER_H

#define TEN 10

#include "user.h"
#include "status.h"
#include "fanpage.h"

class Fan_page;

using namespace std;

class Member : public User
{
private:
	//char * name;
	string b_day;
	vector<Member*> friendsList;
	vector<Fan_page*> LikedPages;
	vector<Status*> member_statuses;
	//vector<Status*> member_recent10;
	//int num_statuses_member;
	//int num_friends;
	//int num_liked_pages;

public:

	Member(string member_name, string member_bday); //c'tor

	Member(const Member& source_member);

	~Member() {};

	// get commands.

	vector<Fan_page*> getLikedPages() { return LikedPages; }

	//vector<Status*> getRecent10() { return member_recent10; }

	//int getNumStatuses() { return num_statuses_member; }

	//int getNumFriends() { return num_friends; }

	//int getNumLikedPages() { return num_liked_pages; }

	//char * getName() { return name; }

	string getBday() { return b_day; }

	// show commands.
	void showMember();

	void showFriends();

	void showLikedPages();

	void showRecent10();

	// add commands.

	void addFanPage(Fan_page* likedFanPage);

	void addStatus(Status * new_status);

};
#endif // __MEMBER.H