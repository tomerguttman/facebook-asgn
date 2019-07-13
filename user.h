#pragma warning(disable : 4996)
/****************************
Tomer Guttman - 204381487	*
Ohad Sluzky -	305070831   *
****************************/
#define _CRT_SECURE_NO_WARNINGS

#ifndef __USER_H
#define __USER_H

#define RECENT_TEN 10

#include "status.h"

using namespace std;

class User
{
protected:
	string name;
	vector<User*> friendsList;//User ** friendsList;
	vector<Status*> statusList;//Status ** statusList;
	User(string& name) { this->name = name; }
public:
	//Class methods.
	virtual ~User() {}
	User(const User& inputUser);
	const User& operator= (const User& inputUser);
	const User& operator+= (const User& inputUser);
	bool operator==(const User& inputUser) { return (name == inputUser.name); }
	bool operator> (const User& inputUser) const;

	//Get commands.
	int getNumStatuses() const { return statusList.size(); }
	int getNumFriends() const { return friendsList.size(); }
	const string& getName() const { return name; }
	vector<User*> getFriendsList() const { return friendsList; }
	vector<Status*> getStatusList() const { return statusList; }
	//
	void addMember(User * newMember);
	void addStatus(Status * newStatus);
	//
	void showStatuses();
	void showFriends();
	
	User* findFriend(const User& inputUser);

};
#endif // __USER_H