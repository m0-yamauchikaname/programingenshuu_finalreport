#pragma once
#include<iostream>
#include<istream>
#include<regex>
#include<fstream>
#include<string>
#include<vector>
#include"�w�b�_�[.h"
#include"strconv.h"
#include <windows.h>
#include"�w�b�_�[2.h"
using namespace std;
void Id_read(vector<Student >) {};
void name_read(vector<Student>) {};
void department_read(vector<Student>) {};
int cousu;
int main(int argc, char* argv[]) {
	

	


	
	vector<Student>gakuseibo;

	ifstream datafile("seiseki");
	
	
	int tanikamoku = 0;

	//�f�[�^�̓ǂ݂Ƃ�ƃN���X�ւ̓���
	while (datafile >> Id >> Name01 >> Name01_2 >> Name0 >> N >> Year >> When0 >> How0 >> Which0) {
		
		

		string Name = wide_to_sjis(utf8_to_wide(Name0));
		string Name1 = wide_to_sjis(utf8_to_wide(Name01));
		string Name1_2 = wide_to_sjis(utf8_to_wide(Name01_2));
	
		string How = wide_to_sjis(utf8_to_wide(How0));
		string Which = wide_to_sjis(utf8_to_wide(Which0));
		string When = wide_to_sjis(utf8_to_wide(When0));
		

		hyoukahenkan(How);
		
		if (Which == "��") {
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
	//GPA�̌v�Z
	for (int i = 0; i < gakuseibo.size(); i++) {
		GPAhenkan(gakuseibo[i].getHyouka());
	}
	GPA = GPA / gakuseibo.size();

	//�P�ʂ̃J�e�S������
	for (int i = 0; i < gakuseibo.size(); i++) {
		//�擾���Ă���P�ʂ݂̂�����
		if (gakuseibo[i].getWhich() == "��") {

			//���{�Ȗڂ̏ꍇ
			if (gakuseibo[i].getName1() == "���{�Ȗ�")kyouyou += gakuseibo[i].getN();

			//���{�Ȗڂ̏ꍇ
			if (gakuseibo[i].getName1() == "��ՉȖ�")kiban += gakuseibo[i].getN();

			//��b�Ȗڂ̏ꍇ
			if (gakuseibo[i].getName1() == "��b�Ȗ�") {
				if (gakuseibo[i].getName1_2() == "�L�����A����")career += gakuseibo[i].getN();
				if (gakuseibo[i].getName1_2() == "��񃊃e���V�[I")jourite += gakuseibo[i].getN();
				if (gakuseibo[i].getName1_2() == "��b�[�~�i�[��")kisozemi += gakuseibo[i].getN();
				if (gakuseibo[i].getName1_2() == "���H�p��")jissenneigo += gakuseibo[i].getN();
				if (gakuseibo[i].getName1_2() == "���C����")mishuugengo += gakuseibo[i].getN();
				if (gakuseibo[i].getName1_2() == "�ی��̈�")hokentaiiku += gakuseibo[i].getN();
				if (gakuseibo[i].getName1_2() == "���n���ʊ�b�Ȗ�")rikekyo += gakuseibo[i].getN();
			}

			//��勳��Ȗڂ̏ꍇ
			if (gakuseibo[i].getName1() == "��勳��Ȗ�") {
				if (gakuseibo[i].getName1_2() == "�R�[�X���ʊ�b�Ȗ�")koukiso += gakuseibo[i].getN();
				if (gakuseibo[i].getName1_2() == "�R�[�X���ʐ��Ȗ�")kousen += gakuseibo[i].getN();
				if (gakuseibo[i].getName1_2() == "�m�\�@�B�R�[�X���ʐ��Ȗ�")kousen += gakuseibo[i].getN();
				if (gakuseibo[i].getName1_2() == "�m�\�@�B���p����")ouyoujik += gakuseibo[i].getN();
				else senmonk += gakuseibo[i].getN();


			}


		}
	}

	cout << "2�N������_�ł̂��Ȃ��̐��т���f�[�^���Z�o���܂��B"<<"\n���т�\�����܂���?�\�����鎞��y���A���Ȃ��ꍇ�͑��̕�������͂��Ă��������B\n";
	string a;
	std::cin >> a;
	if(a=="y")for (int i = 0; i < gakuseibo.size(); i++)gakuseibo[i].show();


	cout << endl << "GPA:" << GPA << "\t��u�Ȗڐ�:" << gakuseibo.size() << "\t�P�ʎ擾�Ȗڐ� :" << tanikamoku << endl;
	cout << endl << "���{�Ȗ�:" << kyouyou << "\t���:" << kiban << "\t��b�Ȗ�:" << career + kisozemi + jissenneigo + mishuugengo + hokentaiiku + rikekyo << "\t��勳��Ȗ�:" << koukiso + kousen + ouyoujik + senmonk << endl << endl;

	string b;
	string B;
	
		cout << "�C���ɕK�v�ȒP�ʂ�\�����܂�.3�N��4�N�̂ǂ���̏C���v���ɂ��܂���?\n";

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
				cout << "�w�N���Ⴂ�܂��A�������ԍ�����͂��Ă�������";
				
				
		}
		cout << "���ݎ�u���Ă���u�`�̐��������Ă�������\n";
		int ab;
		cout << "�R�[�X���Ȗ�";
		std::cin >> ab;
		cout << "�m�\�@�B���p����" << endl;
		int bb;
		std::cin >> bb;

		kousen = kousen + ab * 2;
		ouyoujik = ouyoujik + bb * 2;
	if (B == "3") {
		

		if (kyouyou + kiban + career < 14)cout << "���{,���,�L�����A����̒P�ʂ�" << 14 - (kyouyou + kiban + career) << "�P�ʂ���܂���B" << endl;
		if (kisozemi < 2)cout << "��b�[�~�i�[���̒P�ʂ�" << "2�P�ʂ���܂���B" << endl;
		if (jissenneigo < 8)cout << "���H�p��̒P�ʂ�" << 8 - jissenneigo << "�P�ʂ���܂���B" << endl;
		if (rikekyo < 20)cout << "���n���ʊ�b�Ȗڂ̒P�ʂ�" << 20 - rikekyo << "�P�ʂ���܂���B" << endl;
		if (koukiso < 26)cout << "�R�[�X���ʊ�b�Ȗڂ̒P�ʂ�" << 26 - koukiso << "�P�ʂ���܂���B" << endl;
		if (kousen < 30)cout << "�R�[�X���ʐ��Ȗ�,�R�[�X���Ȗڂ̒P�ʂ�" << 30 - kousen << "�P�ʂ���܂���B" << endl;
		if (ouyoujik < 2)cout << "�m�\�@�B���p�����̒P�ʂ�" << "2�P�ʂ���܂���B" << endl;
		if (koukiso + kousen + ouyoujik + senmonk < 62)cout << "��勳��Ȗڂ̒P�ʂ�" << 62 - (koukiso + kousen + ouyoujik + senmonk)<< "�P�ʂ���܂���B" << endl;

	}
	else if (B == "4") {



		if (kyouyou + kiban + career < 14)cout << "���{,���,�L�����A����̒P�ʂ�" << 14 - (kyouyou + kiban + career) << "�P�ʂ���܂���B" << endl;
		if (kisozemi < 2)cout << "��b�[�~�i�[���̒P�ʂ�" << "2�P�ʂ���܂���B" << endl;
		if (jissenneigo < 8)cout << "���H�p��̒P�ʂ�" << 8 - jissenneigo << "�P�ʂ���܂���B" << endl;
		if (rikekyo < 20)cout << "���n���ʊ�b�Ȗڂ̒P�ʂ�" << 20 - rikekyo << "�P�ʂ���܂���B" << endl;
		if (kousen+ koukiso < 56)cout << "�R�[�X���ʊ�b�Ȗ�,�R�[�X���ʐ��Ȗ�,�R�[�X���Ȗڂ̒P�ʂ�" << 30 - kousen << "�P�ʂ���܂���B" << endl;
		if (ouyoujik < 2)cout << "�m�\�@�B���p�����̒P�ʂ�" << "2�P�ʂ���܂���B" << endl;
		if (koukiso + kousen + ouyoujik + senmonk < 80)cout << "��勳��Ȗڂ̒P�ʂ�" << 62 - (koukiso + kousen + ouyoujik + senmonk) << "�P�ʂ���܂���B" << endl;
		if (tokuken < 8)cout << "�m�\�@�B�m�\�@�B���ʌ����̒P�ʂ�" << "8�P�ʂ���܂���B" << endl;


	}
	else cout << "�w�N���Ⴂ�܂��A���������w�N����͂��Ă�������";

	cout << endl << "����������\�����܂��� ? �\�����鎞��y���A���Ȃ��ꍇ�͑��̕�������͂��Ă��������B\n";
	std::cin >> a;
	if (a == "y") {
		if (B == "4") {


			if (kyouyou + kiban + career < 14)cout << "���{,���,�L�����A����̒P�ʂ�" << 14 - (kyouyou + kiban + career) << "�P�ʂ���܂���B" << endl;
			if (kisozemi < 2)cout << "��b�[�~�i�[���̒P�ʂ�" << "2�P�ʂ���܂���B" << endl;
			if (jissenneigo < 8)cout << "���H�p��̒P�ʂ�" << 8 - jissenneigo << "�P�ʂ���܂���B" << endl;
			if (rikekyo < 20)cout << "���n���ʊ�b�Ȗڂ̒P�ʂ�" << 20 - rikekyo << "�P�ʂ���܂���B" << endl;
			if (koukiso < 26)cout << "�R�[�X���ʊ�b�Ȗڂ̒P�ʂ�" << 26 - koukiso << "�P�ʂ���܂���B" << endl;
			if (kousen < 30)cout << "�R�[�X���ʐ��Ȗ�,�R�[�X���Ȗڂ̒P�ʂ�" << 30 - kousen << "�P�ʂ���܂���B" << endl;
			if (ouyoujik < 2)cout << "�m�\�@�B���p�����̒P�ʂ�" << "2�P�ʂ���܂���B" << endl;
			if (koukiso + kousen + ouyoujik + senmonk < 62)cout << "��勳��Ȗڂ̒P�ʂ�" << 62 - (koukiso + kousen + ouyoujik + senmonk) << "�P�ʂ���܂���B" << endl;

		}
		else if (B == "3") {



			if (kyouyou + kiban + career < 14)cout << "���{,���,�L�����A����̒P�ʂ�" << 14 - (kyouyou + kiban + career) << "�P�ʂ���܂���B" << endl;
			if (kisozemi < 2)cout << "��b�[�~�i�[���̒P�ʂ�" << "2�P�ʂ���܂���B" << endl;
			if (jissenneigo < 8)cout << "���H�p��̒P�ʂ�" << 8 - jissenneigo << "�P�ʂ���܂���B" << endl;
			if (rikekyo < 20)cout << "���n���ʊ�b�Ȗڂ̒P�ʂ�" << 20 - rikekyo << "�P�ʂ���܂���B" << endl;
			if (kousen + koukiso < 56)cout << "�R�[�X���ʊ�b�Ȗ�,�R�[�X���ʐ��Ȗ�,�R�[�X���Ȗڂ̒P�ʂ�" << 30 - kousen << "�P�ʂ���܂���B" << endl;
			if (ouyoujik < 2)cout << "�m�\�@�B���p�����̒P�ʂ�" << "2�P�ʂ���܂���B" << endl;
			if (koukiso + kousen + ouyoujik + senmonk < 80)cout << "��勳��Ȗڂ̒P�ʂ�" << 62 - (koukiso + kousen + ouyoujik + senmonk) << "�P�ʂ���܂���B" << endl;
			if (tokuken < 8)cout << "�m�\�@�B�m�\�@�B���ʌ����̒P�ʂ�" << "8�P�ʂ���܂���B" << endl;


		}
	}
	cout << endl << "�����p���肪�Ƃ��������܂����B\n";

}
