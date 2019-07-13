/****************************
Tomer Guttman - 204381487	*
Ohad Sluzky -	305070831   *
****************************/

#include "main_functions.h"

void printMenu()
{
	cout << "---------------------ActionMenu----------------------\n";
	cout << "Please choose one of the following actions by choosing the action's number:\n";
	cout << " 1) Add a new member to facebook.\n";
	cout << " 2) Add a new fan page to facebook.\n";
	cout << " 3) Post a new status as a member.\n";
	cout << " 4) Post a new status as a fan page.\n";
	cout << " 5) Show all statuses of a member.\n";
	cout << " 6) Show all statuses of a fan page.\n";
	cout << " 7) Add a new friend to a member.\n";
	cout << " 8) Like a fan page with a member.\n";
	cout << " 9) Show all members and pages on Facebook.\n";
	cout << " 10) Show all friends of a member.\n";
	cout << " 11) Show all members that liked a specific page.\n";
	cout << " 12) Show a member's friends recent 10 statuses.\n";
	cout << " 13) Show all liked pages of a specific member\n";
	cout << " 14) Compare number of friends between two entities\n";
	cout << " 15) Exit.\n\n";

	cout << "----> ";

}

void getActionChosen(Facebook &my_facebook, bool &fContinue, int &numOfAction)
{
	switch (numOfAction)
	{
	case 1:
	{
		my_facebook.addNewMember();
		break;
	}
	case 2:
	{
		my_facebook.addNewPage();
		break;
	}
	case 3:
	{
		my_facebook.addNewStatusToUser();
		break;
	}
	case 4:
	{
		my_facebook.addNewStatusToUser();
		break;
	}
	case 5:
	{
		my_facebook.printUserStatuses('m');
		break;
	}
	case 6:
	{
		my_facebook.printUserStatuses('f');
		break;
	}
	case 7:
	{
		my_facebook.addNewFriendship();
		break;
	}
	case 8:
	{
		my_facebook.addNewMemberToPage();
		break;
	}
	case 9:
	{
		my_facebook.printMembersAndPages();
		break;
	}
	case 10:
	{
		my_facebook.printUserFriends('m');
		break;
	}
	case 11:
	{
		my_facebook.printUserFriends('f');
		break;
	}
	case 12:
	{
		my_facebook.printMemberFriendsRecent10Statuses();
		break;
	}
	case 13:
	{
		my_facebook.printMemberLikedPages();
		break;
	}
	case 14:
	{
		my_facebook.compareFriendsBetweenEntities();
		break;
	}
	case 15:
	{
		my_facebook.deleteFacebookData();
		fContinue = false;
		cout << "Goodbye! thank you for using our platform\n";
		break;
	}

	default:
	{
		cout << "Action number invalid/n/n";
		break;
	}
	}//end switch case.
}//end getActionChosen.

