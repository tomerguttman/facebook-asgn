/****************************
Tomer Guttman - 204381487	*
Ohad Sluzky -	305070831   *
****************************/

#define _CRT_SECURE_NO_WARNINGS

#ifndef __FACEBOOK_H
#define __FACEBOOK_H

#define MAX_NAME 100
#define MAX_TXT 1000
#define BD_LENGTH 11
#define STATIC_VP 17
#define MEMBERS 0
#define FAN_PAGES 1

#include "fanpage.h"
#include <algorithm>
using namespace std;

class Facebook
{
private:
	vector<User*> Users[2]; 

public:
	Facebook() {}// c'tor.

	Facebook(const Facebook& inputFacebook);//copy c'tor

	~Facebook() {} //d'tor.

	//get commands.

	vector<User*> getFacebookMembers() { return Users[MEMBERS]; }

	vector<User*> getFacebookPages() { return Users[FAN_PAGES]; }

	//add commands.

	void addNewMember();

	void addNewPage();

	//show commands.

	void showMembersAndFanPages();

	//get commands.

	User * getFanPageFromFacebook(const string& fanPageName);

	User * getMemberFromFacebook(const string& MemberName);

	void compareFriendsBetweenEntities();

	void printMembersAndPages();

	void printMemberFriendsRecent10Statuses();

	void addNewFriendship();

	void addNewMemberToPage();

	void printMemberLikedPages();

	void deleteFacebookData();

	void printUserStatuses(char typeEntity);

	void addNewStatusToUser();

	void printUserFriends(char typeEntity);
};

#endif // __FACEBOOK.H