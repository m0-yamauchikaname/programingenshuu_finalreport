#pragma once
#include<iostream>
#include<istream>
#include<regex>
#include<fstream>
#include<string>
#include<vector>
#include"ヘッダー.h"
#include"strconv.h"
#include <windows.h>
#include"ヘッダー2.h"
using namespace std;
void Id_read(vector<Student >) {};
void name_read(vector<Student>) {};
void department_read(vector<Student>) {};
int cousu;
int main(int argc, char* argv[]) {
	

	


	
	vector<Student>gakuseibo;

	ifstream datafile("seiseki");
	
	
	int tanikamoku = 0;

	//データの読みとりとクラスへの入力
	while (datafile >> Id >> Name01 >> Name01_2 >> Name0 >> N >> Year >> When0 >> How0 >> Which0) {
		
		

		string Name = wide_to_sjis(utf8_to_wide(Name0));
		string Name1 = wide_to_sjis(utf8_to_wide(Name01));
		string Name1_2 = wide_to_sjis(utf8_to_wide(Name01_2));
	
		string How = wide_to_sjis(utf8_to_wide(How0));
		string Which = wide_to_sjis(utf8_to_wide(Which0));
		string When = wide_to_sjis(utf8_to_wide(When0));
		

		hyoukahenkan(How);
		
		if (Which == "合") {
			tanikamoku += 1;
		}

		gakuseibo.emplace_back();
		gakuseibo[gakuseibo.size() - 1].setId(Id);
		gakuseibo[gakuseibo.size() - 1].setName1(Name1);
		gakuseibo[gakuseibo.size() - 1].setName1_2(Name1_2);
		gakuseibo[gakuseibo.size() - 1].setName(Name);
		gakuseibo[gakuseibo.size() - 1].setN(N);
		gakuseibo[gakuseibo.size() - 1].setYear(Year);
		gakuseibo[gakuseibo.size() - 1].setWhen(When);
		gakuseibo[gakuseibo.size() - 1].setHow(How);
		gakuseibo[gakuseibo.size() - 1].setWhich(Which);
		gakuseibo[gakuseibo.size() - 1].setHyouka(ahyouka);







	}
	datafile.close();
	//GPAの計算
	for (int i = 0; i < gakuseibo.size(); i++) {
		GPAhenkan(gakuseibo[i].getHyouka());
	}
	GPA = GPA / gakuseibo.size();

	//単位のカテゴリ分け
	for (int i = 0; i < gakuseibo.size(); i++) {
		//取得している単位のみを検索
		if (gakuseibo[i].getWhich() == "合") {

			//教養科目の場合
			if (gakuseibo[i].getName1() == "教養科目")kyouyou += gakuseibo[i].getN();

			//教養科目の場合
			if (gakuseibo[i].getName1() == "基盤科目")kiban += gakuseibo[i].getN();

			//基礎科目の場合
			if (gakuseibo[i].getName1() == "基礎科目") {
				if (gakuseibo[i].getName1_2() == "キャリア教育")career += gakuseibo[i].getN();
				if (gakuseibo[i].getName1_2() == "情報リテラシーI")jourite += gakuseibo[i].getN();
				if (gakuseibo[i].getName1_2() == "基礎ゼミナール")kisozemi += gakuseibo[i].getN();
				if (gakuseibo[i].getName1_2() == "実践英語")jissenneigo += gakuseibo[i].getN();
				if (gakuseibo[i].getName1_2() == "未修言語")mishuugengo += gakuseibo[i].getN();
				if (gakuseibo[i].getName1_2() == "保健体育")hokentaiiku += gakuseibo[i].getN();
				if (gakuseibo[i].getName1_2() == "理系共通基礎科目")rikekyo += gakuseibo[i].getN();
			}

			//専門教育科目の場合
			if (gakuseibo[i].getName1() == "専門教育科目") {
				if (gakuseibo[i].getName1_2() == "コース共通基礎科目")koukiso += gakuseibo[i].getN();
				if (gakuseibo[i].getName1_2() == "コース共通専門科目")kousen += gakuseibo[i].getN();
				if (gakuseibo[i].getName1_2() == "知能機械コース共通専門科目")kousen += gakuseibo[i].getN();
				if (gakuseibo[i].getName1_2() == "知能機械応用実験")ouyoujik += gakuseibo[i].getN();
				else senmonk += gakuseibo[i].getN();


			}


		}
	}

	cout << "2年後期時点でのあなたの成績からデータを算出します。"<<"\n成績を表示しますか?表示する時はyを、しない場合は他の文字を入力してください。\n";
	string a;
	std::cin >> a;
	if(a=="y")for (int i = 0; i < gakuseibo.size(); i++)gakuseibo[i].show();


	cout << endl << "GPA:" << GPA << "\t受講科目数:" << gakuseibo.size() << "\t単位取得科目数 :" << tanikamoku << endl;
	cout << endl << "教養科目:" << kyouyou << "\t基盤:" << kiban << "\t基礎科目:" << career + kisozemi + jissenneigo + mishuugengo + hokentaiiku + rikekyo << "\t専門教育科目:" << koukiso + kousen + ouyoujik + senmonk << endl << endl;

	string b;
	string B;
	
		cout << "修了に必要な単位を表示します.3年と4年のどちらの修了要件にしますか?\n";

		std::cin >> b;
		regex rx(R"(\d{1})");
		regex rrx(R"(\d+\w)");
		sregex_iterator it(b.begin(), b.end(), rx);
		sregex_iterator end;
		while (it != end) {
			string sttr = (it++)->str();
			if (regex_match(sttr, rx))
				B = sttr;


			else
				cout << "学年が違います、正しい番号を入力してください";
				
				
		}
		cout << "現在受講している講義の数を教えてください\n";
		int ab;
		cout << "コース専門科目";
		std::cin >> ab;
		cout << "知能機械応用実験" << endl;
		int bb;
		std::cin >> bb;

		kousen = kousen + ab * 2;
		ouyoujik = ouyoujik + bb * 2;
	if (B == "3") {
		

		if (kyouyou + kiban + career < 14)cout << "教養,基盤,キャリア教育の単位が" << 14 - (kyouyou + kiban + career) << "単位たりません。" << endl;
		if (kisozemi < 2)cout << "基礎ゼミナールの単位が" << "2単位たりません。" << endl;
		if (jissenneigo < 8)cout << "実践英語の単位が" << 8 - jissenneigo << "単位たりません。" << endl;
		if (rikekyo < 20)cout << "理系共通基礎科目の単位が" << 20 - rikekyo << "単位たりません。" << endl;
		if (koukiso < 26)cout << "コース共通基礎科目の単位が" << 26 - koukiso << "単位たりません。" << endl;
		if (kousen < 30)cout << "コース共通専門科目,コース専門科目の単位が" << 30 - kousen << "単位たりません。" << endl;
		if (ouyoujik < 2)cout << "知能機械応用実験の単位が" << "2単位たりません。" << endl;
		if (koukiso + kousen + ouyoujik + senmonk < 62)cout << "専門教育科目の単位が" << 62 - (koukiso + kousen + ouyoujik + senmonk)<< "単位たりません。" << endl;

	}
	else if (B == "4") {



		if (kyouyou + kiban + career < 14)cout << "教養,基盤,キャリア教育の単位が" << 14 - (kyouyou + kiban + career) << "単位たりません。" << endl;
		if (kisozemi < 2)cout << "基礎ゼミナールの単位が" << "2単位たりません。" << endl;
		if (jissenneigo < 8)cout << "実践英語の単位が" << 8 - jissenneigo << "単位たりません。" << endl;
		if (rikekyo < 20)cout << "理系共通基礎科目の単位が" << 20 - rikekyo << "単位たりません。" << endl;
		if (kousen+ koukiso < 56)cout << "コース共通基礎科目,コース共通専門科目,コース専門科目の単位が" << 30 - kousen << "単位たりません。" << endl;
		if (ouyoujik < 2)cout << "知能機械応用実験の単位が" << "2単位たりません。" << endl;
		if (koukiso + kousen + ouyoujik + senmonk < 80)cout << "専門教育科目の単位が" << 62 - (koukiso + kousen + ouyoujik + senmonk) << "単位たりません。" << endl;
		if (tokuken < 8)cout << "知能機械知能機械特別研究の単位が" << "8単位たりません。" << endl;


	}
	else cout << "学年が違います、ただしい学年を入力してください";

	cout << endl << "もう一方も表示しますか ? 表示する時はyを、しない場合は他の文字を入力してください。\n";
	std::cin >> a;
	if (a == "y") {
		if (B == "4") {


			if (kyouyou + kiban + career < 14)cout << "教養,基盤,キャリア教育の単位が" << 14 - (kyouyou + kiban + career) << "単位たりません。" << endl;
			if (kisozemi < 2)cout << "基礎ゼミナールの単位が" << "2単位たりません。" << endl;
			if (jissenneigo < 8)cout << "実践英語の単位が" << 8 - jissenneigo << "単位たりません。" << endl;
			if (rikekyo < 20)cout << "理系共通基礎科目の単位が" << 20 - rikekyo << "単位たりません。" << endl;
			if (koukiso < 26)cout << "コース共通基礎科目の単位が" << 26 - koukiso << "単位たりません。" << endl;
			if (kousen < 30)cout << "コース共通専門科目,コース専門科目の単位が" << 30 - kousen << "単位たりません。" << endl;
			if (ouyoujik < 2)cout << "知能機械応用実験の単位が" << "2単位たりません。" << endl;
			if (koukiso + kousen + ouyoujik + senmonk < 62)cout << "専門教育科目の単位が" << 62 - (koukiso + kousen + ouyoujik + senmonk) << "単位たりません。" << endl;

		}
		else if (B == "3") {



			if (kyouyou + kiban + career < 14)cout << "教養,基盤,キャリア教育の単位が" << 14 - (kyouyou + kiban + career) << "単位たりません。" << endl;
			if (kisozemi < 2)cout << "基礎ゼミナールの単位が" << "2単位たりません。" << endl;
			if (jissenneigo < 8)cout << "実践英語の単位が" << 8 - jissenneigo << "単位たりません。" << endl;
			if (rikekyo < 20)cout << "理系共通基礎科目の単位が" << 20 - rikekyo << "単位たりません。" << endl;
			if (kousen + koukiso < 56)cout << "コース共通基礎科目,コース共通専門科目,コース専門科目の単位が" << 30 - kousen << "単位たりません。" << endl;
			if (ouyoujik < 2)cout << "知能機械応用実験の単位が" << "2単位たりません。" << endl;
			if (koukiso + kousen + ouyoujik + senmonk < 80)cout << "専門教育科目の単位が" << 62 - (koukiso + kousen + ouyoujik + senmonk) << "単位たりません。" << endl;
			if (tokuken < 8)cout << "知能機械知能機械特別研究の単位が" << "8単位たりません。" << endl;


		}
	}
	cout << endl << "ご利用ありがとうございました。\n";

}
