// 201403-2.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<iostream>

using namespace std;

class window {
public:
	window() {}
	~window() {}
	void setVal(int sx, int sxf, int sy, int syf, int sn) {
		x = sx;
		xOffest = sxf;
		y = sy;
		yOffest = syf;
		num = sn;
	}
	void getVal(int &gx, int &gxf, int &gy, int &gyf) {
		gx = x;
		gxf = xOffest;
		gy = y;
		gyf = yOffest;
	}
	int getNum() {
		return num;
	}
private:
	int x;
	int xOffest;
	int y;
	int yOffest;
	int num;
};

class windowsQueen {
public:
	windowsQueen() {}
	~windowsQueen() {}
	void parser() {
		int n = 0, m = 0;
		cin >> n;
		cin >> m;
		int i;
		for (i = 0; i < n; i++) {
			window temp;
			int x = 0, xf = 0, y = 0, yf = 0;
			cin >> x;
			cin >> y;
			cin >> xf;
			cin >> yf;
			temp.setVal(x, xf, y, yf, i + 1);
			arr.insert(arr.begin(), temp);
		}
		for (i = 0; i < m; i++) {
			int x, y;
			cin >> x;
			cin >> y;
			cArr.push_back(pair<int, int>(x, y));
		}
	}
	void exploit() {
		vector<pair<int, int> >::iterator it;
		for (it = cArr.begin(); it != cArr.end(); it++) {
			int num;
			num = click(it->first, it->second);
			if (num != 0) {
				cout << num << endl;
			}
			else {
				cout << "IGNORED" << endl;
			}
		}
	}
private:
	vector<window> arr;
	vector<pair<int, int> > cArr;
	int click(int x, int y) {
		vector<window>::iterator it;
		for (it = arr.begin(); it != arr.end(); it++) {
			int gx = 0, gxf = 0, gy = 0, gyf = 0;
			it->getVal(gx, gxf, gy, gyf);
			if ((x >= gx && x <= gxf) && (y >= gy && y <= gyf)) {
				window temp = *it;
				int num = it->getNum();
				arr.erase(it);
				arr.insert(arr.begin(), temp);
				return num;
			}
		}
		return 0;
	}
};


int main()
{
	windowsQueen *m = new windowsQueen();
	m->parser();
	m->exploit();
	return 0;
}

