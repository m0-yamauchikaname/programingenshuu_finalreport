#pragma once
#include<iostream>
#include<fstream>
#include"strconv.h"
#include"�w�b�_�[.h"

using namespace std;
int kyouyou = 0, kiban = 0;
//��b�Ȗڂ̒P�ʐ�
int career =0,kisozemi = 0, jourite = 0, jissenneigo = 0, mishuugengo = 0, hokentaiiku = 0, rikekyo = 0;

//���Ȗڂ̒P�ʐ�
int senmonk = 0, koukiso = 0, kousen = 0, ouyoujik = 0, tokuken=0;


int ahyouka;
float GPA;

//�]���]���ɕϊ�����
void hyoukahenkan(string a) {
	vector<string>x = { "�s��","��","��","�D","�G" };
	vector<int>y = { 1,2,3,4,5 };

	//�C�e���[�^��p���ĕ]��ƕ]���̑g�ݍ��킹���`���
	auto ot = y.begin();
	auto it = x.begin();

	for (ot = y.begin(),it = x.begin(); it != x.end(); ++it,++ot) {
		if (a == *it) { 
			ahyouka = *ot;
		}
	}
}




//GPA�̌v�Z
void GPAhenkan(int a) {
	GPA = GPA + (a - 1);

};

//�����R�[�hutf8����wstring�ϊ������string�ւ̕����ϊ�
void mojihenkan(string x, string y) {
	 y = wide_to_sjis(utf8_to_wide(x));
}

