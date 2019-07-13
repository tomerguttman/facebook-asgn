/****************************
Tomer Guttman - 204381487	*
Ohad Sluzky -	305070831   *
****************************/
#include "status.h"
#include <Windows.h>

Status::Status(const Status& source_status) //cpy c'tor
{ 
	type = source_status.type;
	content = source_status.content;
	videoOrPhoto = source_status.videoOrPhoto;
	upload_time = source_status.upload_time;
}//end cpy c'tor

void Status::show_status()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	time_t status_time;
	status_time = Status::get_time();
	if (type == "t")
		cout << content << " -" << asctime(localtime(&status_time));
	else if (type == "v")
	{
		SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << content << " -" << asctime(localtime(&status_time));
		SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

	}//end else if;
	else if (type == "p")
	{
		SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cout << content << " -" << asctime(localtime(&status_time));
		SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	}//end else;
	else if (type == "pt")
	{
		SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cout << videoOrPhoto << endl;
		SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "\t   " << content << " -" << asctime(localtime(&status_time));
	}
	else if (type == "vt")
	{
		SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << videoOrPhoto << endl;
		SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "\t   " << content << " -" << asctime(localtime(&status_time));
	}

}//end show_status.

bool Status::operator!= (const Status& inputStatus) const
{
	if (type != inputStatus.content)
		return true;
	return (content != inputStatus.content);
}

bool Status::operator== (const Status& inputStatus) const
{
	if (type != inputStatus.type)
		return false;
	return (content == inputStatus.content);
}

string* Status::get_content()
{
	string* theContent = new string[2];
	if (type == "vt" || type == "pt")
	{
		theContent[0] = this->videoOrPhoto;
		theContent[1] = this->content;
	}
	else
	{
		theContent[0] = this->content;
		theContent[1] = nullptr;
	}

	return theContent;
}
