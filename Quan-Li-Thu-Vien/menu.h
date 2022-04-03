#pragma once
#include "my_lib.h"
#include "All_function.h"
#include "load_file.h"
#include "DoHoa.h"
char menu[][50] =
{
	"QUAN LI DOC GIA            ",
	"DAU SACH                   ",
	"MUON SACH                  ",
	"TRA SACH                   ",
	"LAM MAT SACH               ",
	"TIM SACH DOC GIA DANG MUON ",
	"DANH SACH DOC GIA QUA HAN  ",
	"TOP 10 SACH MUON NHIEU NHAT",
	"THOAT  CHUONG TRINH        "
};
char menuDG[][50] =
{
	"Them doc gia            ",
	"Xuat danh sach doc gia  ",
	"Xoa doc gia             ",
	"Hieu chinh doc gia      ",
};
char menuDS[][50] =
{
	"Them dau sach           ",
	"Xuat danh sach dau sach ",
	"Xoa doc gia             ",
	"Hieu chinh doc gia      ",
};
void menuDocGia(treeDG &t) {
	ShowCur(0);
	int chon, sum = 4;
	while (1) {
		chon = MenuDong(menuDG, sum, 3, 40);
		switch (chon) {
		case 1: {
			textcolor(3);
			DG a;
			cin >> a;
			themDocGia(t, a);
			system("cls");
			break;
		}
		case 2: {
			yDG = 10;
			SetBGColor(0);
			system("cls");
			BangDS_DocGia();
			gotoXY(0, 0);
			cout << "Nhap lua chon: ";
			int c;
			cin>>c;
			if (c == 1) {
				xuatDG_theoMa(t);
			}
			else
			{
				xuatDG_theoTen(t);
			}
			char x = _getch();
			break;
		}
		case 3: {
			SetBGColor(0);
			system("cls");
			cout << "Nhap ma the can xoa: ";
			int n;
			cin >> n;
			xoaDocGia(t, n);
			cout << "Da xoa!!!";
			system("pause");
		}
		case 4: {
			SetBGColor(0);
			system("cls");
			cout << "Nhap ma the can thay doi: ";
			int n;
			cin >> n;
			hieuchinhDG(t, n);
			cout << "Da hieu chinh!!!";
			system("pause");
		}
		default: break;
		}
	}
}
void menuDauSach(listDauSach& ds) {
	ShowCur(0);
	int chon, sum = 4;
	while (1) {
		chon = MenuDong(menuDS, sum, 3, 40);
		switch (chon) {
		case 1: {
			/*textcolor(3);
			DG a;
			cin >> a;
			themDocGia(t, a);
			system("cls");*/
			break;
		}
		case 2: {
			SetBGColor(0);
			system("cls");
			gotoXY(0, 0);
			textcolor(12);
			cout << "ISBN" << setw(30) << "Ten Sach" << setw(15) << "So trang" << setw(15) << "Tac gia" << setw(15) << "Nam Xuat Ban" << setw(15) << "The loai" << endl;
			textcolor(14);
			xuatDauSach(ds);
			system("pause");
			break;
		}
		
		default: break;
		}
	}
}
void menuChinh() {
	treeDG t = NULL;
	listDauSach ds;
	ds.sl = 0;
	load_file_Dau_Sach(ds);
	load_file_Doc_Gia(t);
	ShowCur(0);
	int chon, sum = 9;
	while (1) {
		chon = MenuDong(menu, sum,3,3);
		switch (chon) {
		case 1: {
			menuDocGia(t);
			break;
		}
		case 2: {
			menuDauSach(ds);
			break;
		}
		case 3: {
			SetBGColor(0);
			exit(0);
		}
		}
	}
}

