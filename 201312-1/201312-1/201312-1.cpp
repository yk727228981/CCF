// 201312-1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<map>
#include<iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	map<int, int> m;
	vector<pair<int, int> > arr;
	int i;
	for (i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (arr.empty()) {
			arr.push_back(pair<int, int>(num, 0));
			continue;
		}
		vector<pair<int, int> >::iterator j;
		bool flag = true;
		for (j = arr.begin(); j != arr.end(); j++) {
			if (j->first == num) {
				j->second++;
				flag = false;
				break;
			}
		}
		if(flag)arr.push_back(pair<int, int>(num, 0));
	}
	vector<pair<int, int> >::iterator i2;
	int cut = 0;
	for (i2 = arr.begin(); i2 != arr.end(); i2++) {
		if (i2->second > cut)cut = i2->second;
	}
	for (i2 = arr.begin(); i2 != arr.end(); i2++) {
		if (i2->second == cut) {
			m.insert(pair<int, int>(i2->first, i2->second));
		}
	}
	cout << m.begin()->first << endl;
	return 0;
}
