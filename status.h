#pragma warning(disable : 4996)
/****************************
Tomer Guttman - 204381487	*
Ohad Sluzky -	305070831   *
****************************/
#define _CRT_SECURE_NO_WARNINGS

#ifndef __STATUS_H
#define __STATUS_H

#define V_P_STR 16
#define MAX_TYPE 3
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <ctime>
#include <time.h>

using namespace std;

class Status
{
private:
	string type; //the type of the status.
	string content; //string which contains the status itself.
	string videoOrPhoto;
	time_t upload_time;

public:
	Status(string status_type, string content, string videoOrPhoto)
	{
		type = status_type;
		this->content = content;
		this->videoOrPhoto = videoOrPhoto;
		time(&upload_time);
	}//end status c'tor.

	Status(const Status& source_status);

	~Status() {//d'tor
	}//end d'tor.

	string get_type() { return type; }

	time_t get_time() { return upload_time; }

	string* get_content();

	void show_status();

	bool operator!= (const Status& inputStatus) const;

	bool operator== (const Status& inputStatus) const;
};

#endif // STATUS_H