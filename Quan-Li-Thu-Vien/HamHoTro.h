#pragma once
#include "ctdl.h"
#include "All_function.h"
using namespace std;
int i = 0;
//void themPhanTuVaoCayTam(treeDG& tam, DocGia a) 
//{
//	if (tam == NULL) {
//		nodeDG* p = khoitaoDG(a);
//		tam = p;
//	}
//	else {
//		if (tam->data.ten > a.ten || (tam->data.ten == a.ten && tam->data.ho > a.ho))
//		{
//			themPhanTuVaoCayTam(tam->pleft, a);
//		}
//		else {
//			themPhanTuVaoCayTam(tam->pright, a);
//		}
//	}
//}
//void taoCayTam(treeDG t, treeDG& tam) 
//{
//	if (t != NULL) {
//		themPhanTuVaoCayTam(tam, t->data);
//		taoCayTam(t->pleft, tam);
//		taoCayTam(t->pright, tam);
//	}
//}
void swapSoNguyen(int &a, int &b) {
	int c = a;
	a = b;
	b = c;
}
void taoMaDocGia() {
	srand(time(NULL));
	int a[10001];
	for (int i = 1; i <= 10000; i++) {
		a[i] = i;
	}
	for (int i = 1; i <= 10000; i++) {
		int j = rand() % 10000 + 1;
		swapSoNguyen(a[i], a[j]);
	}
	ofstream fileout("MaDG.txt");
	for (int i = 1; i <= 10000; i++) {
		fileout << a[i];
		if (i < 10000) fileout << " ";
	}
	fileout.close();
}
void caySangMang(treeDG t, DocGia *a[],int &n)
{
	if (t != NULL) {
		a[i] = new DocGia;
		*a[i] = t->data;
		i++;
		n = i;
		caySangMang(t->pleft,a,n);
		caySangMang(t->pright, a,n);
	}
}
void swapDG(DocGia &a,DocGia &b) {
	DocGia tam=a;
	a = b;
	b = tam;
}
void sapXepMangDG(DocGia *a[], int n)
{
	for (int i = 0; i < n-1; i++) 
	{
		for (int j = i+1; j < n; j++) {
			if (a[i]->ten > a[j]->ten) {
				swapDG(*a[i], *a[j]);
			}
			else if (a[i]->ten == a[j]->ten && a[i]->ho > a[i]->ho) {
				swapDG(*a[i], *a[j]);
			}
		}
	}
}

