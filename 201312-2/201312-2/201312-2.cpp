// 201312-2.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<string>
#include<iostream>

using namespace std;

int ctoi(const char &c) {
	return c - '0';
}

string parserSring(string &s) {
	string a, b, c, d, f;
	a = s.substr(0, 1);
	b = s.substr(2, 3);
	c = s.substr(6, 5);
	d = s.substr(12, 1);
	f = a + b + c + d;
	return f;
}

int calCode(string &s) {
	string::iterator i;
	int val = 0,cot = 1;
	for (i = s.begin(); i != s.end(); i++) {
		if(cot<10)val += (ctoi(*i)*cot);
		cot++;
	}
	val %= 11;
	return val;
}


int main()
{
	string s;
	cin >> s;
	int val;
	string pVal = parserSring(s);
	val = calCode(pVal);
	string temp = pVal.substr(9, 1);
	if (val == ctoi(*temp.begin())||(temp=="X"&&val==10)) {
		cout << "Right" << endl;
	}else {
		if (val == 10) {
			cout << s.replace(12, 1, "X") << endl;
			return 0;
		}
		int c = '0';
		char a = val + c;
		string b(&a);
		string d = b.substr(0, 1);
		cout << s.replace(12, 1, d) << endl;
	}
    return 0;
}

