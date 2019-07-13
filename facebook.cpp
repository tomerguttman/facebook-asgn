/****************************
Tomer Guttman - 204381487	*
Ohad Sluzky -	305070831   *
****************************/

#include "facebook.h"

bool compFunc(Status* s1, Status* s2)
{
	return (s1->get_time() < s2->get_time());
}

Facebook::Facebook(const Facebook& inputFacebook)// copy c'tor.
{
	Users[0] = inputFacebook.Users[0];
	Users[1] = inputFacebook.Users[1];
}//end Facebook copy c'tor.


void Facebook::showMembersAndFanPages()
{
	int i = 1;
	cout << "---------------------------------------------------\n";
	cout << "The facebook currently contains\n";
	cout << Users[MEMBERS].size() << " members which are:\n";
	vector<User*>::iterator itr = Users[MEMBERS].begin();
	vector<User*>::iterator itrEnd = Users[MEMBERS].end();
	for (; itr != itrEnd ; ++itr,i++)
	{
		Member* temp = dynamic_cast<Member*>(*itr);
		cout << " " << i << ") ";
		temp->showMember();
	}//end for.
	i = 1;
	itr = Users[FAN_PAGES].begin();
	itrEnd = Users[FAN_PAGES].end();
	cout << Users[FAN_PAGES].size() << " fan pages which are:\n";
	for (; itr != itrEnd; ++itr,i++)
	{
		Fan_page* temp = dynamic_cast<Fan_page*>(*itr);
		cout << " " << i << ") ";
		temp->showPage();
	}//end for.
	cout << "---------------------------------------------------\n";
}//endShowMembersAndFanPages.

User * Facebook::getFanPageFromFacebook(const string& fanPageName)
{
	vector<User*>::iterator itr = Users[FAN_PAGES].begin();
	vector<User*>::iterator itrEnd = Users[FAN_PAGES].end();
	User* tempPage;
	for (; itr!=itrEnd; ++itr)
	{
		tempPage = dynamic_cast<User*>(*itr);
		if (tempPage->getName() == fanPageName)
			return tempPage;
	}//end for.
	return NULL;
}//end getFanPageFromFacebook.

User * Facebook::getMemberFromFacebook(const string& MemberName)
{
	vector<User*>::iterator itr = Users[MEMBERS].begin();
	vector<User*>::iterator itrEnd = Users[MEMBERS].end();
	User* tempMember;
	for (; itr != itrEnd; ++itr)
	{
		tempMember = dynamic_cast<User*>(*itr);
		if (tempMember->getName() == MemberName)
			return tempMember;
	}//end for.
	return NULL;
}//end getMemberFromFacebook.

void Facebook::addNewMember()
{
	//input string.
	string member_name;
	string dateOfBirth;
	User* check;
	cout << "-----------------------------------------------------\n";
	cout << "Please enter the new memeber's name\n";
	cin.ignore();
	getline(cin, member_name);
	cout << "Please enter the new member's date of birth (dd/mm/yyyy)\n";
	getline(cin, dateOfBirth);
	check = getMemberFromFacebook(member_name);
	if (!check)
	{
		//creating new member.
		User * newMember = new Member(member_name, dateOfBirth);
		if (newMember)
			cout << member_name << "'s profile was created! Welcome to Facebook.\n";
		Users[MEMBERS].push_back(newMember);
	}
	else
		cout << "Error, a member with the name " << member_name << " already exists!\n";
	cout << "-----------------------------------------------------\n";
}//end addNewMember.

void Facebook::addNewPage()
{
	string pageName;
	User* check;
	cout << "-----------------------------------------------------\n";
	cout << "Please enter the new page's name\n";
	cin.ignore();
	getline(cin, pageName);
	check = getFanPageFromFacebook(pageName);
	if (!check)
	{
		User * newPage = new Fan_page(pageName);
		if (newPage)
			cout << pageName << "'s fan page was created!\n";
		Users[FAN_PAGES].push_back(newPage);
	}

	else
		cout << "Error, a fan page with the name " << pageName << " already exists!\n";
	cout << "-----------------------------------------------------\n";
}//end addNewPage.

void Facebook::compareFriendsBetweenEntities()
{
	//input string.
	string EntityName_1;
	string EntityName_2;
	char type1, type2;
	User* entity1;
	User* entity2;
	cout << "----------------compareFriendsBetweenEntities------------------\n";
	cout << "Please enter the type of the first entity ('p' for page/'m' for member)\n";
	cin.ignore();
	cin >> type1;
	cout << "enter the name of the first entity\n";
	cin.ignore();
	getline(cin, EntityName_1);
	//cin.ignore();
	cout << "Please enter the type of the second entity ('p' for page/'m' for member)\n";
	cin >> type2;
	cin.ignore();
	cout << "enter the name of the second entity\n";
	getline(cin, EntityName_2);
	//getting the two entities, so we could work with them.
	//first entity.
	if (type1 == 'm')
		entity1 = getMemberFromFacebook(EntityName_1);
	else
		entity1 = getFanPageFromFacebook(EntityName_1);
	//second entity.
	if (type2 == 'm')
		entity2 = getMemberFromFacebook(EntityName_2);
	else
		entity2 = getFanPageFromFacebook(EntityName_2);
	//
	if (entity1 && entity2) // we have something that can be compared.
	{
		if ((type1 == type2) && EntityName_1 == EntityName_2)
			cout << "Equal entities were entered which means they have the same amout of friends [" << entity1->getNumFriends() << "]\n";
		else //the entities are different.
		{
			if (entity1->getNumFriends() == entity2->getNumFriends())
				cout <<entity1->getName()<<" and "<<entity2->getName()<<" have the same amount of friends [" << entity1->getNumFriends() << "].\n";
			else
			{
				if (*entity1 > *entity2)
					cout << entity1->getName() << " [" << entity1->getNumFriends() << "] has more friends than " << entity2->getName() << " [" << entity2->getNumFriends() << "].\n";
				else //(entity1->getNumFriends() < entity2->getNumFriends())
					cout << entity2->getName() << " [" << entity2->getNumFriends() << "] has more friends than " << entity1->getName() << " [" << entity1->getNumFriends() << "].\n";
			}//end else.
		}//end else.
	}//end if.
	else
		cout << "Error! at least one of the entities you entered does not exist.\n";
}//end compareFriendsBetweenIdentities.

void Facebook::deleteFacebookData()
{
	//delete members and their statuses.
	vector<User*>::iterator itr = Users[MEMBERS].begin();
	vector<User*>::iterator itrEnd = Users[MEMBERS].end();
	vector<Status*>::iterator itrStatus;
	vector<Status*>::iterator itrStatusEnd;
	User* temp;
	Status* tempStat;
	vector<Status*> statList;

	for (; itr != itrEnd; ++itr)
	{
		temp = dynamic_cast<User*>(*itr);
		statList = temp->getStatusList();
		itrStatus = statList.begin();
		itrStatusEnd = statList.end();
		for (; itrStatus != itrStatusEnd; ++itrStatus)
		{
			tempStat = dynamic_cast<Status*>(*itrStatus);
			delete tempStat;
		}//end for.
		delete temp;
	}//end for.

	itr = Users[FAN_PAGES].begin();
	itrEnd = Users[FAN_PAGES].end();

	 //delete arrays inside Fan_page and the page itself.
	for (; itr != itrEnd; ++itr)
	{
		temp = dynamic_cast<User*>(*itr);
		statList = temp->getStatusList();
		itrStatus = statList.begin();
		itrStatusEnd = statList.end();
		for (; itrStatus != itrStatusEnd; ++itrStatus)
		{
			tempStat = dynamic_cast<Status*>(*itrStatus);
			delete tempStat;
		}//end for.
		delete temp;
	}//end for.
}//end deleteFacebookData;

void Facebook::printMembersAndPages()
{
	showMembersAndFanPages();
}//end printMembersAndPages.

void Facebook::addNewFriendship()
{
	string member1Name;
	string member2Name;
	User* member1;
	User* member2;
	cout << "------------------addNewFriendship-------------------\n";
	//get both members' names from input and find members in facebook.
	cout << "Please enter the first member's name\n";
	cin.ignore();
	getline(cin, member1Name);
	member1 = getMemberFromFacebook(member1Name);
	cout << "Please enter the name of the friend you would like to add\n";
	getline(cin, member2Name);
	member2 = getMemberFromFacebook(member2Name);
	if (member1 && member2)
	{
		if (member1Name!=member2Name)
		{
			if (!(member1->findFriend(*member2)))
			{
				//add each of the members to the other's friend list.
				member1->addMember(member2);
				member2->addMember(member1);
				cout << member1->getName() << " and " << member2->getName() << " are now friends.\n";
			}
			else
				cout << "Error, " << member1Name << " and " << member2Name << " are already friends!\n";
		}
		else
			cout << "Error, a member cannot be friend with himself!\n";
	}
	else
		cout << "Error, at least on of the members entered was not found\n";
	cout << "-----------------------------------------------------\n";
}//end addNewFriendship.

void Facebook::addNewMemberToPage()
{
	string pageName;
	string memberName;
	User* page;
	User* member;
	cout << "----------------addMemberToPage(Like)----------------\n";
	//get the name of the page and the name of the member from input and find them in facebook.
	cout << "Please enter the name of the page you want to like\n";
	cin.ignore();
	getline(cin, pageName);
	page = getFanPageFromFacebook(pageName);
	if (!page)
	{
		cout << "The page you requested does no exist\n";
		return;
	}
	cout << "Please enter the name of the member that likes the page\n";
	getline(cin, memberName);
	member = getMemberFromFacebook(memberName);
	Member* temp = dynamic_cast<Member*>(member);
	if (!temp)
	{
		cout << "The member you requested does not exist\n";
		return;
	}
	//add the member to the page's member list and the page to the member's liked pages list.
	page->addMember(temp);
	temp->addFanPage((Fan_page*)page);
	cout << member->getName() << " liked the page " << page->getName() << ".\n";
	cout << "-----------------------------------------------------\n";
}//end addNewMemberToPage.

void Facebook::printMemberFriendsRecent10Statuses()
{
	cout << "------------MemberFriendsRecent10Statuses------------\n";
	User * currMember;
	vector<Status*> allFriendsStatuses;
	vector<User*> currMemberFriends;
	string memberName;
	vector<Status*> list;

	vector<User*>::iterator itr;
	vector<User*>::iterator itrEnd;
	vector<Status*>::iterator itrStatus;
	vector<Status*>::iterator itrStatusEnd;
	User* tempMember;
	int numOfStatuses = 0, i = 1;

	cout << "Which member you would like to see his friend's recent 10 statuses? \n";
	cin.ignore();
	getline(cin, memberName);
	currMember = getMemberFromFacebook(memberName);
	if (currMember)
	{
		currMemberFriends = currMember->getFriendsList();
		itr = currMemberFriends.begin();
		itrEnd = currMemberFriends.end();

		for (; itr != itrEnd; ++itr)
		{
			tempMember = dynamic_cast<User*>(*itr);
			numOfStatuses += tempMember->getNumStatuses();
		}
		allFriendsStatuses.reserve(numOfStatuses);

		itr = currMemberFriends.begin();
		for (; itr != itrEnd; ++itr)
		{
			tempMember = dynamic_cast<User*>(*itr);
			list = tempMember->getStatusList();
			itrStatus = list.begin();
			itrStatusEnd = list.end();
			for (; itrStatus != itrStatusEnd; ++itrStatus)
				allFriendsStatuses.push_back(*itrStatus);
		}//end for.

		 //Now we hold a big array of all the friends statuses.
		sort(allFriendsStatuses.begin(), allFriendsStatuses.end(), compFunc);
		cout << "Last 10 statuses of " << memberName << "'s friends are:\n\n";
		itrStatus = allFriendsStatuses.begin();
		itrStatusEnd = allFriendsStatuses.end();

		//if there are more than 10 statuses for loop runs 10 times.
		if (numOfStatuses > RECENT_TEN)
		{
			for (int j = numOfStatuses - 1; j >= numOfStatuses - RECENT_TEN; j--)
				if (allFriendsStatuses[j])
				{
					cout << "\t" << i << ") ";
					allFriendsStatuses[j]->show_status();
					i += 1;
				}//end if;
		}//end if

		 //else, for loop runs 'NumOfStatuses' times
		else
		{
			for (int l = numOfStatuses - 1; l >= 0; l--)
				if (allFriendsStatuses[l])
				{
					cout << "\t" << i << ") ";
					allFriendsStatuses[l]->show_status();
					i += 1;
				}//end if;
		}//end else
	}

	else
		cout << "The member you entered does not exist!!\n";
	cout << "-----------------------------------------------------\n";
}//printMemberFriendsRecent10Statuses;
 
void Facebook::printMemberLikedPages()
{
	int i = 1;
	string temp_name;
	User* temp;
	Member* member;
	Fan_page* tempPage;
	vector<Fan_page*> list;
	vector<User*> allMembers = Users[MEMBERS];

	vector<Fan_page*>::iterator itrPage;
	vector<Fan_page*>::iterator itrEndPage;

	cout << "----------------printMemberLikedPages----------------\n";
	cout << "Please enter the member name.\n";
	cin.ignore();
	getline(cin, temp_name);
	temp = getMemberFromFacebook(temp_name);
	if (temp)
	{
		member = dynamic_cast<Member*>(temp);
		list = member->getLikedPages();
		itrPage = list.begin();
		itrEndPage = list.end();

		cout << temp_name << "'s liked pages are:\n";
		for (; itrPage != itrEndPage; ++itrPage)
		{
			tempPage = dynamic_cast<Fan_page*>(*itrPage);
			cout << "  " << i << ") ";
			tempPage->showPage();
			i+=1;
		}//end for
	}
	else
		cout << "The member: " << temp_name << " does not exist.\n";
	cout << "-----------------------------------------------------\n";
}//end printMemberLikedPages
 
void Facebook::printUserStatuses( char typeEntity)
{
	bool found = false;
	string temp_name;
	vector<User*> allUsers;

	vector<User*>::iterator itr;
	vector<User*>::iterator itrEnd;
	User* temp;

	if (typeEntity == 'm')
	{
		allUsers = Users[MEMBERS];
		cout << "---------------printMemberStatuses-------------------\n";
		cout << "Please enter the member name\n";
	}
	else if (typeEntity == 'f')
	{
		allUsers = Users[FAN_PAGES];
		cout << "---------------printFanPageStatuses-------------------\n";
		cout << "Please enter the fan page name\n";
	}
	cin.ignore();
	getline(cin, temp_name);
	itr = allUsers.begin();
	itrEnd = allUsers.end();
	for (; itr != itrEnd; ++itr)
	{
		temp = dynamic_cast<User*>(*itr);
		if (temp_name == temp->getName())
		{
			temp->showStatuses();
			found = 1;
		}//end if;
	}//end for.
	if (!found)
		cout << temp_name << " does not exist.\n";
	cout << "-----------------------------------------------------\n";
}//end printUserStatuses.
 
void Facebook::addNewStatusToUser()
{
	string temp_name;
	string temp_status;
	string statusType;
	string videoOrPhoto;
	bool valid = false;

	User * currMember;
	Status * addedStatus;

	//get the member name, status type and status itself from input.
	cout << "-----------------addStatusToMember-------------------\n";
	cout << "Which kind of status would you like to post";
	cout << "('v' for video, 'p' for photo, 't' for text, 'pt' for photo text, 'vt' for video text)?\n";
	cin >> statusType;

	//different cases of statuses.
	if (statusType == "t")
	{
		cout << "Please enter the status (999 characters).\n";
		cin.ignore();
		getline(cin, temp_status);
		valid = true;
	}
	else if (statusType == "p")
	{
		temp_status = "Showing a photo.";
		cin.ignore();
		valid = true;
	}
	else if (statusType == "v")
	{
		temp_status = "Showing a video.";
		cin.ignore();
		valid = true;
	}
	else if (statusType == "pt")
	{
		videoOrPhoto = "Showing a photo.";
		cout << "Please enter the status (999 characters).\n";
		cin.ignore();
		getline(cin, temp_status);
		valid = true;
	}
	else if (statusType == "vt")
	{
		videoOrPhoto = "Showing a video.";
		cout << "Please enter the status (999 characters).\n";
		cin.ignore();
		getline(cin, temp_status);
		valid = true;
	}
	else
		cout << "The type of status entered is invalid!\n";

	if (valid)
	{
		cout << "To which user would you like to add the status?\n";
		getline(cin, temp_name);
		//search for member.
		currMember = getMemberFromFacebook(temp_name);
		if (!currMember)
		{
			//if member not found, search for fan page.
			currMember = getFanPageFromFacebook(temp_name);
			if (!currMember)
				//if fan page not found
				cout << temp_name << "'s profile wasn't found on Facebook.\n";
		}
		if (currMember)
		{
			addedStatus = new Status(statusType, temp_status, videoOrPhoto);
			currMember->addStatus(addedStatus);
			cout << "The status was added to " << temp_name << endl;
		}//end else;
	}
}//end addStatusToUser

void Facebook::printUserFriends(char typeEntity)
{
	bool found = false;
	string temp_name;
	vector<User*> allUsers;

	vector<User*>::iterator itr;
	vector<User*>::iterator itrEnd;
	User* temp;

	if (typeEntity == 'm')
	{
		allUsers = Users[MEMBERS];
		cout << "-----------------printMemberFriends------------------\n";
		cout << "Please enter the member name.\n";
	}

	else if (typeEntity == 'f')
	{
		allUsers = Users[FAN_PAGES];
		cout << "-----------------printFanPageMembers------------------\n";
		cout << "Please enter the fan page name.\n";
	}

	cin.ignore();
	getline(cin, temp_name);

	itr = allUsers.begin();
	itrEnd = allUsers.end();

	for (; itr != itrEnd && !found; ++itr)
	{
		temp = dynamic_cast<User*>(*itr);
		if (temp_name==temp->getName())
		{
			temp->showFriends();
			found = true;
		}//end if;
	}//end for.
	if (!found)
		cout << temp_name << " does not exist.\n";
	cout << "-----------------------------------------------------\n";
}//end printUserFriends.
