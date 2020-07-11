#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <limits.h>

#include <algorithm>
#include <stdexcept>
#include <iterator>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <cstdio>
#include <random>
#include <deque>
#include <queue>
#include <stack>
#include <ctime>
#include <cmath>
#include <regex>
#include <tuple>
#include <map>
#include <set>

#include "DateTime.h"

DateTime::DateTime() {
	this->time = std::time(0);
}

DateTime::DateTime(DateTime *clone) {
	this->time = clone->time;
}

DateTime::DateTime(long long time) {
	this->time = time;
}

DateTime& DateTime::Now() {
	this->time = std::time(0);
	return *this;
}

bool DateTime::IsCorrect(long long time) {
	return time >= 0;
}

string DateTime::Format(string format) {
	std::stringstream temp("");
	char buffer[1024];
	std::tm* t = std::localtime(&(this->time));
	std::strftime(buffer, 1024, format.c_str(), t);
	temp << buffer;
	return temp.str();
}

void DateTime::Fprint(string format) {
	cout << Format(format) << '\n';
}

DateTime DateTime::Parse(string line, string format) {
	std::tm dt; 
	std::istringstream temp(line);

	for (int i = 0, _; i < format.length(); i++) {
		temp >> _;
		switch (format[i])
		{
		case 's':
			dt.tm_sec = _;
			break;
		case 'm':
			dt.tm_min = _;
			break;
		case 'h':
			dt.tm_hour = _;
			break;
		case 'D':
			dt.tm_mday = _;
			break;
		case 'M':
			dt.tm_mon = _ - 1;
			break;
		case 'Y':
			dt.tm_year = _ - 1900;
			break;
		}
	}

	DateTime res(mktime(&dt));
	return res;
}