// 201312-3.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>

using namespace std;

class rect {
public:
	rect(){}
	~rect(){}
	void setHeight(int);
	void setAnchor(int);
	void setOffest(int);
	int getHeight();
	int getAnchor();
	int getOffest();
	int getArea();
private:
	int height;
	int anchor;
	int offest;
};

void scanRect(vector<rect> &r) {
	int n;
	cin >> n;
	vector<int> arr;
	int i;
	for (i = 0; i < n; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}
	vector<int>::iterator j;
	int k,cur=0;
	for (j = arr.begin(); j != arr.end(); j++) {
		int min = arr[cur];
		for (k = cur; k < arr.size(); k++) {
			if (min > arr[k])min = arr[k];
			rect temp;
			temp.setAnchor(cur);
			temp.setHeight(min);
			temp.setOffest(k-cur);
			r.push_back(temp);
		}
		cur++;
	}
}

int calMaxRect(vector<rect> &r) {
	map<int, rect> m;
	vector<rect>::iterator it;
	for (it = r.begin(); it != r.end(); it++) {
		m.insert(pair<int, rect>(it->getArea(), *it));
	}
	map<int, rect>::iterator max = m.end();
	max--;
	return max->first;
}


int main()
{
	vector<rect> r;
	scanRect(r);
	cout << calMaxRect(r) << endl;
}

void rect::setHeight(int i)
{
	height = i;
}

void rect::setAnchor(int i)
{
	anchor = i;
}

void rect::setOffest(int i)
{
	offest = i;
}

int rect::getHeight()
{
	return height;
}

int rect::getAnchor()
{
	return anchor;
}

int rect::getOffest()
{
	return offest;
}

int rect::getArea()
{
	return (offest+1)*height;
}
