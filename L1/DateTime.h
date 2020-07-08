#pragma once

#include<string>

#define ll long long

using namespace std;

struct Date {
	int year;
	int mouth;
	int day;
};

struct Time {
	int hour;
	int minutes;
	int seconds;
};

class DateTime {
private:
	ll time;
public:
	DateTime();
	DateTime(DateTime* clone);
	DateTime(ll value);

	inline ll GetTime();
	inline ll SetTime(ll value);

	DateTime& Now();
	string Format(string format);
	void Fprint(string format);

	static bool IsCorrect(ll value);
	static DateTime Parse(string text, string format);
};

inline ll DateTime::GetTime() {
	return time;
}

inline ll DateTime::SetTime(ll value) {
	time = value;
	return time;
}
