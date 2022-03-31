#pragma once
#include <iostream>
#include "my_lib.h"
using namespace std;
void BangDS_DocGia() {
	for (int i = 5; i <= 150; i++) {  // ve canh ngang
		gotoXY(i, 7);
		cout << char(220);
		gotoXY(i, 9);
		cout << char(220);
		gotoXY(i, 41);
		cout << char(223);
	}
	for (int i = 8; i <= 40; i++) { // ve canh doc
		gotoXY(5, i);
		cout << char(219);
		gotoXY(20, i);
		cout << char(219);
		gotoXY(60, i);
		cout << char(219);
		gotoXY(80, i);
		cout << char(219);
		gotoXY(90, i);
		cout << char(219);
		gotoXY(150, i);
		cout << char(219);
	}
	textcolor(14);
	gotoXY(10, 8);
	cout << "MA THE";
	gotoXY(34, 8);
	cout << "HO VA TEN DEM";
	gotoXY(69, 8);
	cout << "TEN";
	gotoXY(84, 8);
	cout << "PHAI";
	gotoXY(110, 8);
	cout << "TRANG THAI";
}
