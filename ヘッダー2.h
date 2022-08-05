#pragma once
#include<iostream>
#include<fstream>
#include"strconv.h"
#include"ヘッダー.h"

using namespace std;
int kyouyou = 0, kiban = 0;
//基礎科目の単位数
int career =0,kisozemi = 0, jourite = 0, jissenneigo = 0, mishuugengo = 0, hokentaiiku = 0, rikekyo = 0;

//専門科目の単位数
int senmonk = 0, koukiso = 0, kousen = 0, ouyoujik = 0, tokuken=0;


int ahyouka;
float GPA;

//評語を評価に変換する
void hyoukahenkan(string a) {
	vector<string>x = { "不可","可","良","優","秀" };
	vector<int>y = { 1,2,3,4,5 };

	//イテレータを用いて評語と評価の組み合わせを形作る
	auto ot = y.begin();
	auto it = x.begin();

	for (ot = y.begin(),it = x.begin(); it != x.end(); ++it,++ot) {
		if (a == *it) { 
			ahyouka = *ot;
		}
	}
}




//GPAの計算
void GPAhenkan(int a) {
	GPA = GPA + (a - 1);

};

//文字コードutf8からwstring変換を介したstringへの文字変換
void mojihenkan(string x, string y) {
	 y = wide_to_sjis(utf8_to_wide(x));
}

