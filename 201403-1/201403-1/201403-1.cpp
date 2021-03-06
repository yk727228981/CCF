// 201403-1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<cmath>
#include<map>

using namespace std;

void parser(map<int,int> &m,int &count) {
	int n;
	cin >> n;
	int i;
	for (i = 0; i < n; i++) {
		int num;
		cin >> num;
		map<int, int>::iterator it = m.find(abs(num));
		if (it == m.end()) { 
			m.insert(pair<int, int>(abs(num), num)); 
			continue;
		}
		if ((it->second + num) == 0)count++;
	}
}

int main()
{
	map<int, int> m;
	int count = 0;
	parser(m, count);
	cout << count << endl;
	return 0;
}

