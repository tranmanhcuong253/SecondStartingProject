#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

typedef struct Monhoc{
	string MaMH;
	int soTinChi;
	int soTinChiLT;
	int soTinChiTH;
	int soTinChiBT;
	double soTinChiHocPhi;
	string loaiGio; 
}Monhoc; 

typedef struct Hocvien{
	string MaHV;
	string hoTen;
	int soMonHoc;
	double soTienHoc;
	double soTienDaNop;
	double tienHocMotTinChi;
	vector<Monhoc>dsMonHoc;
}Hocvien;

vector<Hocvien>dsHocVien;

int main(){
	printf("De2_6_IT3040_20231\n");
	printf("\nPhan Hoang Nam - 20215434 - 732826\n");
	while(1){
		printf("**	CHUONG TRINH QUAN LY HOC PHI\t**\n");
		printf("**1. Nhap cac sinh vien, va mon hoc\t**\n");
		printf("**2. In ds sinh vien va hoc phi cac mon\t**\n");
		printf("**0. Thoat\t**\n");
		printf("**************************************\n");
		printf("**\tNhap lua chon cua ban\t**\n");
		int cmd;
		cin>>cmd;
		switch(cmd){
			case 0: break;
			case 1:{
				printf("Ban da chon nhap ds sinh vien!\n");
				int n;
				printf("Nhap so hoc vien: ");
				cin>>n;
				for(int i=0; i<n; i++){
					Hocvien student;
					printf("Nhap thong tin cua sv thu %d\n", i+1);
					printf("\tTen sinh vien: ");
					cin.ignore();
					getline(cin, student.hoTen);
					printf("\tSo mon hoc: ");
					int numOfSubject;
					cin>>numOfSubject;
					student.soMonHoc = numOfSubject;
					printf("\tSo tien mot tin chi: ");
					double x;
					cin>>x;
					student.tienHocMotTinChi = x;
					for(int j=0; j<numOfSubject; j++){
						Monhoc subject;
						printf("\tMon hoc thu %d\n", j+1);
						printf("\tMa mon hoc: ");
						string maMH;
						cin>>maMH;
						printf("\t\tSo tin chi: ");
						int soTinChi;
						cin>>soTinChi;
						if(soTinChi==12){
							subject.loaiGio = "DATN Ky su";
							subject.soTinChiLT = 0;
							subject.soTinChiBT = 0;
							subject.soTinChiTH = 0;
						}
						else if(soTinChi==6){
							subject.loaiGio = "DATN Cu nhan";
							subject.soTinChiLT = 0;
							subject.soTinChiBT = 0;
							subject.soTinChiTH = 0;
						}
						else{
							printf("\t\tNhap tin chi LT: ");
							int tcLT;
							cin>>tcLT;
							printf("\t\tNhap tin chi BT: ");
							int tcBT;
							cin>>tcBT;
							printf("\t\tNhap tin chi TH: ");
							int tcTH;
							cin>>tcTH;
							subject.soTinChiLT = tcLT;
							subject.soTinChiBT = tcBT;
							subject.soTinChiTH = tcTH;
							if(tcLT==0&&tcBT==0&&tcTH==3) subject.loaiGio = "DAMH";
							else if(tcLT>0&&tcBT>0&&tcTH>0) subject.loaiGio = "LT-BT-TN";
							else if(tcLT>0&&tcBT>0&&tcTH==0) subject.loaiGio = "LT-BT";
							else if(tcLT>0&&tcBT==0&&tcTH>0) subject.loaiGio = "LT-TN";
							else if(tcLT==0&&tcBT==0&&tcTH>0) subject.loaiGio = "DA";
							else if(tcLT==0&&tcBT>0&&tcTH>0) subject.loaiGio = "BT-TH";
						}
						subject.soTinChiHocPhi = subject.soTinChiLT + subject.soTinChiBT + subject.soTinChiTH*1.5;
						subject.MaMH = maMH;
						subject.soTinChi = soTinChi;
						student.dsMonHoc.push_back(subject);
					}
					for(auto e:student.dsMonHoc){
						student.soTienHoc += e.soTinChiHocPhi * student.tienHocMotTinChi;
					}
					printf("Hoc phi da nop: ");
					cin>>student.soTienDaNop;
					dsHocVien.push_back(student);
				}
				printf("Ban da nhap thanh cong!\n");
				printf("Bam phim bat ky de tiep tuc!\n");
				char c;
				c = getch();				
				break;
			}
			case 2:{
				printf("Ban da chon xuat DS sinh vien!\n");
				for(auto x:dsHocVien){
					cout<<"Ten sv: "<<x.hoTen<<"\n";
					printf("So mon hoc: %d\n", x.soMonHoc);
					printf("So tien 1 TC: %.2lf\n", x.tienHocMotTinChi);
					
					printf("Phai nop: %.2lf\n", x.soTienHoc);
					printf("Da nop dot 1: %.2lf\n", x.soTienDaNop);
					printf("So tien thieu: %.2lf\n", x.soTienHoc - x.soTienDaNop);
					string state;
					if(x.soTienHoc > x.soTienDaNop) state = "Con thieu";
					else state = "Da nop du";
					printf("Tinh trang nop HP: %s\n", state.c_str());					
					printf("Chi tiet hoc phi cac mon hoc:\n");
					printf("\tMaMH\tLoaiGio\t\tKhoi luong\t\tHoc phi phai nop\n");
					for(auto e:x.dsMonHoc){
						double hp = e.soTinChiHocPhi * x.tienHocMotTinChi;						
						printf("\t%s\t%s\t\t%d(%d-%d-%d-%d)\t\t%.2lf\n", e.MaMH.c_str(), e.loaiGio.c_str(), e.soTinChi, e.soTinChiLT, e.soTinChiBT, e.soTinChiTH, 2*e.soTinChi, hp);
					}
				}
				printf("Bam phim bat ky de tiep tuc!\n");
				char c;
				c = getch();
				break;}
		}
		
			
	}
}