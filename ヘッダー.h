#pragma once
#include<iostream>
#include<fstream>
#include<vector>

using namespace std;
//読み取り用
string   Name0, Name, Name01 , Id, Name01_2, How0, Which0, When0 ;
int N, Year;


class Student {
private:
	string name1;
	string id;
	string name;
	string name1_2;
	string when;
	string how;
	string which;
	int n;
	int year;
	int hyouka;

public:
	void setName(const string& newName) { name = newName; }
	string getName() { return name; }

	void setName1(const string& newName1) { name1 = newName1; }
	string getName1() { return name1; }
	void setName1_2(const string& newName1_2) { name1_2 = newName1_2; }
	string getName1_2() { return name1_2; }

	void setWhen(const string& newWhen) { when = newWhen; }
	string getWhen() { return when; }
	void setHow(const string& newHow) { how = newHow; }
	string getHow() { return how; }
	void setWhich(const string& newWhich) { which = newWhich; }
	string getWhich() { return which; }

	void setN(int newN) { n = newN; }
	int getN() { return n; }
	void setYear(int newYear) { year = newYear; }
	int getYear() { return year; }

	void setId(const string& newId) { id = newId; }
	string getId() { return id; }

	void show();

	void setHyouka(int newHyouka) { hyouka = newHyouka; }
	int getHyouka() { return hyouka; }
};
void Student::show() {
	cout << "授業番号:" << id << "\t " << name1 << "\t "  << name1_2 << "\t 科目名:" << name
		<< "\t 単位数:" << n << "\t 取得年度:" << year << when << "\t 評語:" << how << "\t 評価:" << hyouka << "\t 合否:" << which <<endl<< endl;
}

