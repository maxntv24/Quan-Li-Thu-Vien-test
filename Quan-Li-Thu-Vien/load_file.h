#pragma once
#include "ctdl.h"
#include "string"
#include<fstream>
#include "All_function.h"
void load_file_Dau_Sach(listDauSach& DS)
{
	ifstream in("DAU_SACH.txt");
	dauSach data;
	DanhMucSach x;
	int n, temp;
	in >> n;
	in.ignore();
	for (int i = 0; i < n; i++) {
		getline(in, data.ISBN, ',');
		getline(in, data.tenSach, ',');
		in >> data.soTrang;
		in.ignore();
		getline(in, data.tacGia, ',');
		in >> data.namXuatBan;
		in.ignore();
		getline(in, data.theLoai);
		themDauSach(DS, data);
	}
}
void load_file_Doc_Gia(treeDG& t)
{
	ifstream in("DocGia.txt");
	DocGia data;
	while (!in.eof()) {
		in >> data.maThe;
		in.ignore();
		getline(in, data.ho, ',');
		getline(in, data.ten, ',');
		getline(in, data.phai, ',');
		in >> data.trangThai;
		in.ignore();
		themDocGia(t, data);
	}
	in.close();
}