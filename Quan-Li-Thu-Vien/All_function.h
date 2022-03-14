#pragma once
#include <iostream>
#include "my_lib.h"
#include "ctdl.h"
#define LEN 72
#define XUONG 80
#define TRAI 75
#define PHAI 77
using namespace std;

// =================menu
void Normal() {
	SetBGColor(0);
	SetColor(14);
}
void HighLight() {
	SetColor(1);
	SetBGColor(6);
}
int MenuDong(char td[][50], int sum) {
	Normal();
	int dong = 15;
	int cot = 50;
	system("cls");   int chon = 0;
	int i;
	for (i = 0; i < sum; i++)
	{
		gotoXY(cot, dong + i);
		cout << td[i];
	}
	HighLight();
	gotoXY(cot, dong + chon);
	cout << td[chon];
	char kytu;
	while (1) {
		kytu = _getch();
		if (kytu == 0) kytu = _getch();
		switch (kytu) {
		case LEN:if (chon + 1 > 1)
		{
			Normal();
			gotoXY(cot, dong + chon);
			cout << td[chon];
			chon--;
			HighLight();
			gotoXY(cot, dong + chon);
			cout << td[chon];

		}
				break;
		case XUONG:if (chon + 1 < sum)
		{
			Normal();
			gotoXY(cot, dong + chon);
			cout << td[chon];
			chon++;
			HighLight();
			gotoXY(cot, dong + chon);
			cout << td[chon];

		}
				  break;
		case 13: return chon + 1;
		}  // end switch
	}
}
// ============ Xu li doc gia===============
nodeDG* khoitaoDG(DocGia x)
{
	nodeDG* p = new nodeDG;
	p->data = x;
	p->pleft = NULL;
	p->pright = NULL;
	return p;
}
void themDocGia(treeDG& t, DocGia x)
{
	if (t == NULL)
	{
		nodeDG* p = khoitaoDG(x);
		t = p;
	}
	else
	{
		if (x.maThe > t->data.maThe)
		{
			themDocGia(t->pright, x);
		}
		else
		{
			themDocGia(t->pleft, x);
		}
	}
}
void nodeTheMang(treeDG& t, nodeDG*& k)
{
	if (k->pright == NULL)
	{
		t->data = k->data;
		nodeDG* tam = k;
		k = k->pleft;
		delete tam;
	}
	else
	{
		nodeTheMang(t, k->pright);
	}
}
void xoaDocGia(treeDG& t, int x)
{
	if (t != NULL)
	{
		if (t->data.maThe == x) {
			
		}
		else if (x > t->data.maThe) {
			xoaDocGia(t->pright, x);
		}
		else {
			xoaDocGia(t->pleft, x);
		}
	}
}