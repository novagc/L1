#pragma once

#include<string>

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
	long long time;
public:
	DateTime();
	DateTime(DateTime* clone);
	DateTime(long long value);

	inline long long GetTime();
	inline long long SetTime(long long value);

	DateTime& Now();
	string Format(string format);
	void Fprint(string format);

	static bool IsCorrect(long long value);
	static DateTime Parse(string text, string format);
};

inline long long DateTime::GetTime() {
	return time;
}

inline long long DateTime::SetTime(long long value) {
	time = value;
	return time;
}
