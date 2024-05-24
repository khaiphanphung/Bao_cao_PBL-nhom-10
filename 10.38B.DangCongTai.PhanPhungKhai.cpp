
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class ThongTin {
private:
    string tenTaiXe;
    string soCCCD;
    string bienSoXe;
    string thoiDiem;
    string loaiXe;
    string hinhThucThuPhi;
    int tienThu;

public:
    ThongTin(string ten, string cccd, string bienSo, string thoiDiem, string loai, string hinhThuc, int tien) {
        tenTaiXe = ten;
        soCCCD = cccd;
        bienSoXe = bienSo;
        this->thoiDiem = thoiDiem;
        loaiXe = loai;
        hinhThucThuPhi = hinhThuc;
        tienThu = tien;
    }


    string getTenTaiXe() {
        return tenTaiXe;
    }

    string getSoCCCD() {
        return soCCCD;
    }

    string getBienSoXe() {
        return bienSoXe;
    }

    string getThoiDiem() {
        return thoiDiem;
    }

    string getLoaiXe() {
        return loaiXe;
    }

    string getHinhThucThuPhi() {
        return hinhThucThuPhi;
    }

    int getTienThu() {
        return tienThu;
    }
};


void nhapLoaiXe(string &loaiXe, int &tienThu) {
    int loai;
    cout << "Nhap loai xe :"<<endl;
    cout<<"Xe oto, nhap 1"<<endl;
    cout<<"Xe khach, nhap 2"<<endl;
    cout<<"Xe cho hang, nhap 3"<<endl;
    cin >> loai;
    switch (loai) {
        case 1:
            cout<<"Nhap so cho ngoi: "<<endl;
            int loaiOto;
            cin >> loaiOto;
            if (loaiOto <= 4) {
                loaiXe = "Xe Oto duoi 4 cho";
                tienThu = 40000;
                cout << "So tien phai thu la: " << tienThu << endl;
            } else if (loaiOto > 4 && loaiOto <= 8) {
                loaiXe = "Xe Oto 4 - 8 cho";
                tienThu = 50000;
                cout << "So tien phai thu la: " << tienThu << endl;
            } else {
                cout << "Loai xe khong hop le!" << endl;
                return;
            }
            break;
        case 2:
            cout<<"Nhap so cho ngoi: "<<endl;
            int loaiXeKhach;
            cin >> loaiXeKhach;
            if (loaiXeKhach <= 16) {
                loaiXe = "Xe Khach duoi 16 cho";
                tienThu = 80000;
                cout << "So tien phai thu la: " << tienThu << endl;
            } else if (loaiXeKhach > 16 && loaiXeKhach <= 32) {
                loaiXe = "Xe Khach 16 - 32 cho";
                tienThu = 100000;
                cout << "So tien phai thu la: " << tienThu << endl;
            } else if (loaiXeKhach > 32 && loaiXeKhach <= 40) {
                loaiXe = "Xe Khach 32 - 40 cho";
                tienThu = 150000;
                cout << "So tien phai thu la: " << tienThu << endl;
            } else if (loaiXeKhach > 40) {
                loaiXe = "Xe Khach tren 40 cho";
                tienThu = 180000;
                cout << "So tien phai thu la: " << tienThu << endl;
            } else {
                cout << "Loai xe khong hop le!" << endl;
                return;
            }
            break;
        case 3:
            cout << "Nhap tai trong xe: " << endl;
            int loaiXeChoHang;
            cin >> loaiXeChoHang;
            if (loaiXeChoHang <= 1) {
                loaiXe = "Xe Cho hang duoi 1 tan";
                tienThu = 80000;
                cout << "So tien phai thu la: " << tienThu << endl;
            } else if (loaiXeChoHang > 1 && loaiXeChoHang <= 3) {
                loaiXe = "Xe Cho hang 1 - 3 tan";
                tienThu = 100000;
                cout << "So tien phai thu la: " << tienThu << endl;
            } else if (loaiXeChoHang > 3 && loaiXeChoHang <= 5) {
                loaiXe = "Xe Cho hang 3 - 5 tan";
                tienThu = 150000;
                cout << "So tien phai thu la: " << tienThu << endl;
            } else if (loaiXeChoHang > 5) {
                loaiXe = "Xe Cho hang tren 5 tan";
                tienThu = 200000;
                cout << "So tien phai thu la: " << tienThu << endl;
            } else {
                cout << "Loai xe khong hop le!" << endl;
                return;
            }
            
            break;
        default:
            cout << "Loai xe khong hop le!" << endl;
            return;
    }
    ofstream file("Dulieu.txt",std::ios_base::app);
    file << "so tien:"<< tienThu <<" ";

}


void nhapThongTinXe(vector<ThongTin> &danhSach) {
    while (true) {
        string ten, cccd, bienSo, thoiDiem, loaiXe, hinhThuc;
        int tienThu;

        cout << "Nhap ten tai xe: ";
        cin.ignore();
        getline(cin,ten);
        cout << "Nhap so CCCD: ";
        cin >> cccd;
        cout << "Nhap bien so xe: ";
        cin >> bienSo;
        cout << "Nhap thoi diem di qua tram thu phi: ";
        cin >> thoiDiem;
        ofstream file("Dulieu.txt",std::ios_base::app);
        file <<"ho ten:"<<ten<<"  "<<"CCCD:"<<cccd<<" "<<"bien so:"<<bienSo<<" "<<"thoi gian:"<<thoiDiem<<" "<<endl;

        nhapLoaiXe(loaiXe, tienThu);

        cout << "Chon hinh thuc thu phi " << endl;
        cout << "Tien mat, nhap 1 " << endl;
        cout << "Chuyen Khoan, nhap 2 " << endl;
        cout << "The tin dung, nhap 3 " << endl;
        int nhapHinhThucThuPhi;
        cin >> nhapHinhThucThuPhi;
        if (nhapHinhThucThuPhi == 1) {
            hinhThuc = "Tien mat";
        } else if (nhapHinhThucThuPhi == 2) {
            hinhThuc = "Chuyen khoan";
        } else if (nhapHinhThucThuPhi == 3) {
            hinhThuc = "The tin dung";
        } else {
            cout << "Hinh thuc thu phi khong hop le!" << endl;
            continue;
        }
        
        file << hinhThuc << endl;
        danhSach.push_back(ThongTin(ten, cccd, bienSo, thoiDiem, loaiXe, hinhThuc, tienThu));

        cout << "Neu tiep tuc nhap thong tin xe, nhap T" << endl;
        cout << "Neu ket thuc, nhap K" << endl;
        char luachon;
        cin >> luachon;
        if (luachon != 'T' && luachon != 't') {
            break;
        }
    }
}


void inThongTinXe(const vector<ThongTin> &danhSach) {
    cout << "\tThong tin tung xe:" << endl;
    for (int i = 0; i < danhSach.size(); ++i) {
        ThongTin xe = danhSach[i];
        cout << "\tTen tai xe: " << xe.getTenTaiXe() << endl;
        cout << "\tSo CCCD: " << xe.getSoCCCD() << endl;
        cout << "\tBien so xe: " << xe.getBienSoXe() << endl;
        cout << "\tThoi diem di qua tram thu phi: " << xe.getThoiDiem() << endl;
        cout << "\tLoai xe: " << xe.getLoaiXe() << endl;
        cout << "\tHinh thuc thu phi: " << xe.getHinhThucThuPhi() << endl;
        cout << "\tTien thu: " << xe.getTienThu() << endl;
        cout << endl;
    }
}


void tinhTongTien(const vector<ThongTin> &danhSach) {
    int tongTienMat = 0,tongChuyenKhoan = 0,tongTheTinDung = 0;
    for (int i = 0; i < danhSach.size(); ++i) {
        ThongTin xe = danhSach[i];
        if (xe.getHinhThucThuPhi() == "Tien mat") {
            tongTienMat += xe.getTienThu();
        } else if (xe.getHinhThucThuPhi() == "Chuyen khoan") {
            tongChuyenKhoan += xe.getTienThu();
        } else if (xe.getHinhThucThuPhi() == "The tin dung") {
            tongTheTinDung += xe.getTienThu();
        }
    }
    cout << "\tTong tien thu theo Tien mat: " << tongTienMat << endl;
    cout << "\tTong tien thu theo Chuyen khoan: " << tongChuyenKhoan << endl;
    cout << "\tTong tien thu theo The tin dung: " << tongTheTinDung << endl;
    ofstream file("Dulieu.txt",std::ios_base::app);
    file << "Tong tien mat: "<< tongTienMat << endl;
    file << "Tong tien chuyen khoan: "<< tongChuyenKhoan << endl;
    file << "Tong the tin dung: " << tongTheTinDung << endl;
}

void tinhTongTienTheoLoaiXe(const vector<ThongTin> &danhSach) {
	int tongTienOto = 0, tongTienKhach = 0, tongTienChoHang = 0;
    for (int i = 0; i < danhSach.size(); ++i) {
        ThongTin xe = danhSach[i];
        if (xe.getLoaiXe() == "Xe Oto duoi 4 cho" || xe.getLoaiXe() == "Xe Oto 4 - 8 cho") {
            tongTienOto += xe.getTienThu();
        } else if (xe.getLoaiXe() == "Xe Khach duoi 16 cho" || xe.getLoaiXe() == "Xe Khach 16 - 32 cho"
        ||xe.getLoaiXe() == "Xe Khach 32 - 40 cho" || xe.getLoaiXe() == "Xe Khach tren 40 cho") {
            tongTienKhach += xe.getTienThu();
        } else if (xe.getLoaiXe() == "Xe Cho hang duoi 1 tan" || xe.getLoaiXe() == "Xe Cho hang 1 - 3 tan" 
        || xe.getLoaiXe() == "Xe Cho hang 3 - 5 tan" || xe.getLoaiXe() == "Xe Cho hang tren 5 tan") {
            tongTienChoHang += xe.getTienThu();
        }
    }
    cout << "\tTong tien tinh theo Xe Oto: " << tongTienOto << endl;
    cout << "\tTong tien tinh theo Xe Khach: " << tongTienKhach << endl;
    cout << "\tTong tien tinh theo Xe cho hang: " << tongTienChoHang << endl;
    ofstream file("Dulieu.txt",std::ios_base::app);
    file << "Tong tien thu xe Oto: "<<tongTienOto << endl;
    file << "Tong tien thu xe khach: "<<tongTienKhach << endl;
    file << "Tong tien thu xe cho hang: "<<tongTienChoHang << endl;
}
void tinhTongTatCa(const vector<ThongTin> &danhSach) {
    int tongTienAll = 0;
    for (int i = 0; i < danhSach.size(); ++i) {
        ThongTin xe = danhSach[i];
        tongTienAll += xe.getTienThu();
    }
    cout << "\tTong tien thu cua tat ca xe: " << tongTienAll << endl;
    ofstream file("Dulieu.txt",std::ios_base::app);
    file << "Tong tat ca tien thu: "<< tongTienAll << endl;
}
void xoaThongTinXe(vector<ThongTin> &danhSach) {
    string bienSoXe;
    cout << "Nhap bien so xe can xoa: ";
    cin >> bienSoXe;

    for (int i = 0; i < danhSach.size(); ++i) {
        if (danhSach[i].getBienSoXe() == bienSoXe) {
            danhSach.erase(danhSach.begin() + i);
            cout << "\tDa xoa thong tin xe voi bien so: " << bienSoXe << endl;
            return;
        }
    }
    cout << "\tKhong tim thay thong tin xe voi bien so: " << bienSoXe << endl;
}


int main() {
    vector<ThongTin> danhSach;
	cout << "\t\t\tDO AN LAP TRINH" << endl;
	cout << "\tTHUC HIEN BOI DANG CONG TAI & PHAN PHUNG KHAI\n" << endl;
	cout << "------------------ QUAN LI THU PHI QUOC LO 1A ------------------" << endl;
    while (true) {
        cout << "Chon chuc nang:" << endl;
        cout << "1. Nhap thong tin xe" << endl;
        cout << "2. In thong tin xe" << endl;
        cout << "3. Xoa thong tin xe" << endl;
        cout << "4. Tinh tong tien thu theo hinh thuc thu" << endl;
        cout << "5. Tinh tong tien thu theo loai xe" << endl;
        cout << "6. Tinh tong tien cua tat ca loai xe:" << endl;
        cout << "7. Thoat chuong trinh" << endl;
		
        int luaChon;
        cin >> luaChon;

        switch (luaChon) {
            case 1:
                nhapThongTinXe(danhSach);
                break;
            case 2:
                inThongTinXe(danhSach);
                break;
            case 3:
                xoaThongTinXe(danhSach);
                break;
            case 4:
                tinhTongTien(danhSach);
                break;
			case 5:
				tinhTongTienTheoLoaiXe(danhSach);
				break;
			case 6:
			    tinhTongTatCa(danhSach);
			    break;
			case 7:
                return 0;
            default:
                cout << "\tLua chon khong hop le, vui long chon lai." << endl;
        }
    }

    return 0;
}



