#pragma once
#include "my_lib.h"
#include "All_function.h"
char menu[][50] =
{
	"DOC GIA                    ",
	"DAU SACH                   ",
	"MUON SACH                  ",
	"TRA SACH                   ",
	"LAM MAT SACH               ",
	"TIM SACH DOC GIA DANG MUON ",
	"DANH SACH DOC GIA QUA HAN  ",
	"TOP 10 SACH MUON NHIEU NHAT",
	"THOAT  CHUONG TRINH        "
};
void menuChinh() {
	ShowCur(0);
	int chon, sum = 9;
	while (1) {
		chon = MenuDong(menu, sum);
		switch (chon) {
		case 1: {
			break;
		}
		case 2: {
			return;
		}
		}
	}
}
void menuDocGia() {
	ShowCur(0);
	int chon, sum = 9;
	while (1) {
		chon = MenuDong(menu, sum);
		switch (chon) {
		case 1: {
			break;
		}

		}
	}
}
