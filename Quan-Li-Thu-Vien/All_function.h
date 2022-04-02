#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "my_lib.h"
#include "ctdl.h"
#include "HamHoTro.h"
#define LEN 72
#define XUONG 80
#define TRAI 75
#define PHAI 77
using namespace std;
int yDG=10;
// =================menu==================
void Normal() {
	SetBGColor(0);
	SetColor(14);
}
void HighLight() {
	SetColor(1);
	SetBGColor(6);
}
int MenuDong(char td[][50], int sum,int dong,int cot) {
	Normal();
	int chon = 0;
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
istream& operator>>(istream& in, DG& a)
{
	int y = 3;
	gotoXY(80, y++);
	cout << "Nhap ma the: ";
	in >> a.maThe;
	in.ignore();
	gotoXY(80, y++);
	cout << "Nhap ho: ";
	getline(in, a.ho);
	gotoXY(80, y++);
	cout << "Nhap ten: ";
	getline(in, a.ten);
	gotoXY(80, y++);
	cout << "Nhap phai: ";
	getline(in, a.phai);
	gotoXY(80, y++);
	cout << "Nhap trang thai: ";
	in >> a.trangThai;
	return in;
}
ostream& operator<<(ostream& out, DG a) {
	gotoXY(7, yDG);
	out << a.maThe;
	gotoXY(22, yDG);
	out << a.ho;
	gotoXY(62, yDG);
	out <<a.ten ;
	gotoXY(82, yDG);
	out  << a.phai;
	gotoXY(92, yDG);
	if (a.trangThai == 1) {
		out << "Dang hoat dong";
	}
	else out << "Bi khoa";
	yDG++;
	return out;
}
void xuatDG_theoMa(treeDG t)  // ki thuat left-node-right  sẽ đi sâu xuống về bên trái nhất rồi xuất rồi sang phải
{							  // nên sẽ xuất ra danh sách theo key tăng dần  (key là mã độc giả)
	if (t != NULL) {
		xuatDG_theoMa(t->pleft);
		cout << t->data;
		xuatDG_theoMa(t->pright);
	}
}
void xuatDG_theoTen(treeDG t)
{
	int n=0;
	DocGia* a[10000];
	caySangMang(t,a,n);
	sapXepMangDG(a, n);
	gotoXY(2, 3);
	cout << n;
	for (int i = 0; i < n; i++) {
		cout << *a[i];
	}
}
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
	if (k->pright == NULL) // quy tắc phải cùng cây con trái
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
			if (t->pleft == NULL && t->pright == NULL)
			{
				nodeDG* tam = t;
				t = NULL;
				delete tam;
			}
			else if (t->pleft != NULL && t->pright == NULL) // node 1 con
			{
				nodeDG* tam = t;
				t = t->pleft;
				delete tam;
			}
			else if (t->pleft == NULL && t->pright != NULL) // node 1 con
			{
				nodeDG* tam = t;
				t = t->pright;
				delete tam;
			}
			else if (t->pleft != NULL && t->pright != NULL)    // node 2 con
			{
				nodeTheMang(t, t->pleft);
			}
		}
		else if (x > t->data.maThe) {
			xoaDocGia(t->pright, x);
		}
		else {
			xoaDocGia(t->pleft, x);
		}
	}
}
void hieuchinhDG(treeDG &t, int x)
{
	if (t != NULL)
	{
		if (t->data.maThe == x)
		{
			cin>> t->data;
		}
		else if (t->data.maThe < x)
		{
			hieuchinhDG(t->pright, x);
		}
		else
		{
			hieuchinhDG(t->pleft, x);
		}
	}
}
//============Xu li dau sach==============
ostream& operator<<(ostream& out, dauSach a) {
	cout << a.ISBN << setw(30) << a.tenSach << setw(10) << a.soTrang << setw(20) << a.tacGia << setw(10) << a.namXuatBan << setw(30) << a.theLoai << endl;
	return out;
}
istream& operator>>(istream& in, dauSach& a)
{
	int y = 3;
	gotoXY(80, y++);
	cout << "Nhap IBSN : ";
	in >> a.ISBN;
	in.ignore();
	gotoXY(80, y++);
	cout << "Nhap ten sach: ";
	getline(in, a.tenSach);
	gotoXY(80, y++);
	cout << "Nhap so trang: ";
	in>> a.soTrang;
	gotoXY(80, y++);
	cout << "Nhap tac gia: ";
	getline(in, a.tacGia);
	gotoXY(80, y++);
	cout << "Nhap nam xuat ban: ";
	in >> a.namXuatBan;
	cout << "Nhap the loai: ";
	in >> a.theLoai;
	return in;
}
void themDauSach(listDauSach& ds, dauSach x) 
{
	if (ds.sl < MAX) {
		ds.ds_DauSach[ds.sl] = new dauSach;
		*ds.ds_DauSach[ds.sl] = x;
		ds.sl++;
	}
}
void nhapDS(listDauSach& ds)
{
	dauSach a;
	cin >> a;
	themDauSach(ds, a);
}
void xuatDauSach(listDauSach ds) {
	for (int i = 0; i < ds.sl; i++) {
		cout << *ds.ds_DauSach[i];
	}
}
