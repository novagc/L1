#define _CRT_SECURE_NO_WARNINGS
#define ll long long

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

using namespace std;

ll Fact(int n) {
	ll res = 1;

	for (int i = 2; i < 100000000 * n; i++) {
		if (res == 0)
			res = 1;
		res *= i;
	}

	return res;
}

int main()
{
	DateTime a;
	DateTime b(a);
	DateTime c(a);

	a.Fprint("%d = %A");
	cout << Fact(2) << '\n';
	cout << b.SetTime(time(0)) << '\n';
	cout << a.GetTime() << '\n';
	cout << b.GetTime() << '\n';
	cout << b.Format("%d = %A") << '\n';
	cout << DateTime::IsCorrect(c.GetTime()) << '\n';
	cout << Fact(3) << '\n';
	cout << c.Now().GetTime() << '\n';
	cout << DateTime::Parse("10 11 12 9 8 2007", "smhDMY").GetTime() << '\n';
	cout << DateTime::Parse("12 11 10 2007 8 9", "hmsYMD").GetTime() << '\n';

	return 0;
}
