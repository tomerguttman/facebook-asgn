#include "user.h"
#include "fanpage.h"

const User& User::operator= (const User& inputUser)
{
	name = inputUser.name;
	friendsList = inputUser.friendsList;
	statusList = inputUser.statusList;
	return *this;
}//end operator= .

User::User(const User& inputUser)
{
	*this = inputUser;
}//end copy c'tor;

// adds Member to friends list or a fanpage member list.
void User::addMember(User * newMember)
{
	*this += *newMember;
}//end addMember;

void User::addStatus(Status * new_status)
{
	int num_statuses;
	statusList.push_back(new_status);
	num_statuses = statusList.size();
	if (statusList.size() >= 2)
	{
		if (*statusList[ num_statuses- 1] != *statusList[num_statuses - 2])
			cout << "The status entered is different from the last status that was entered to " << this->name << endl;
		else if(*statusList[num_statuses - 1] == *statusList[num_statuses - 2])
			cout << "The status entered is the same as the last status that was entered to " << this->name << endl;
	}//end if;
}//end addStatus.

void User::showStatuses()
{
	int i = 0;
	vector<Status*>::iterator itr = statusList.begin();
	vector<Status*>::iterator itrEnd = statusList.end();
	cout << name << "'s statuses are:\n";
	Status* temp;
	for (; itr != itrEnd; ++itr, i++)
	{
		temp = dynamic_cast<Status*>(*itr);
		cout << "  " << i + 1 << ") ";
		temp->show_status();
	}//end for.
}

const User& User::operator+= (const User& inputUser)
{
	User* tempUser = const_cast<User*>(&inputUser);
	friendsList.push_back(tempUser);
	return *this;
}//end operator+=

bool User::operator> (const User& inputUser) const
{
	if (this->friendsList.capacity() > inputUser.friendsList.capacity())
		return true;
	else
		return false;
}

User* User::findFriend(const User& inputUser)
{
	int i = 0;
	bool found = false;
	vector<User*>::iterator itr = friendsList.begin();
	vector<User*>::iterator itrEnd = friendsList.end();

	for (;((itr != itrEnd) && (!found));++itr )
	{
		if (**itr == inputUser)
			found = true;
	}
	return (found == true) ? *itr : nullptr;
}

void User::showFriends()
{
	int i = 0;
	vector<User*>::iterator itr = friendsList.begin();
	vector<User*>::iterator itrEnd = friendsList.end();

	for (; itr != itrEnd; ++itr, i++)
	{
		Member * temp = dynamic_cast<Member*>(*itr);
		cout << i + 1 << ") ";
		temp->showMember();
	}//end for.
}//end showFriends.