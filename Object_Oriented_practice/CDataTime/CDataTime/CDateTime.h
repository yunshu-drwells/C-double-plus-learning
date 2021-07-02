#ifndef _CDATE_TIME_H_
#define _CDATE_TIME_H_

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<time.h>
#include<windows.h>
#include<conio.h>
using namespace std;

struct Date
{
	int year;
	int month;
	int day;
};
struct Time
{
	int hour;
	int minute;
	int second;
};

class CDateTime
{
public:
	CDateTime();
	~CDateTime();
public:
	void GetCurDateTime();
	void DateTimeShow();
	void DateTimeDShow();
	void DateTimeMonthCalenderShow();
private:
	Date m_date;
	Time m_time;
};


#endif /* _CDATE_TIME_H_ */