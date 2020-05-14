#include"Songs.h"
#include<iostream>
#include<fstream>
#include<locale.h>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	Songs obj;
	ifstream fin;
	ofstream fout;
	fin.open("D://IIP/IiP_381908_2_2/grigorev.ms/x64/Release/input.txt");
	bool check = true;
	while (check) {
		cout << endl << "�������� ���������� ��������:" << endl;
		cout << "    1 - �������� �����" << endl;
		cout << "    2 - �������� ������ �����, ��������� �� ��������" << endl;
		cout << "    3 - ����� ����� �� �������� � �����������" << endl;
		cout << "    4 - ������ ��� ����� ��������� �����" << endl;
		cout << "    5 - ������ ��� ����� ��������� �����������" << endl;
		cout << "    6 - ������ ��� ����� ��������� �����������" << endl;
		cout << "    7 - ������ ������� ����� �����" << endl;
		cout << "    8 - ������� ����� �� ��������" << endl;
		cout << "    9 - ��������� �������� � ���� ��� ������� �������� �� �����" << endl;
		cout << "    0 - �����" << endl << endl;
		cout << "��� ����� - ";
		int choise, pos;
		string name_c, lyric_c, music_c, singer_c, album_c, release_date_c;
		cin >> choise;
		switch (choise) {
		case(0):
			cout << "�� ��������!!!" << endl;
			check = false;
			break;
		case(1):
			cout << endl << "������� �������� - ";
			cin >> name_c;
			cout << "������� ������ ������ - ";
			cin >> lyric_c;
			cout << "������� ������ ������ - ";
			cin >> music_c;
			cout  << "������� ����������� - ";
			cin >> singer_c;
			cout  << "�������� �������� ������� - ";
			cin >> album_c;
			cout  << "������� ���� ������ - ";
			cin >> release_date_c;
			cout << endl;
			obj.Add(name_c, lyric_c, music_c, singer_c, album_c, release_date_c);
			break;
		case(2):
			cout << endl << "������� �������� - ";
			cin >> name_c;
			obj.Change(name_c);
			cout << "�������� ���������� �������" << endl;
			break;
		case(3):
			cout << endl << "������� �������� - ";
			cin >> name_c;
			cout << "������� ��� ����������� - ";
			cin >> singer_c;
			obj.Find(name_c, singer_c);
			break;
		case(4):
			cout << endl << "������� ������ ������ - ";
			cin >> lyric_c;
			for (int i = 0; i < 256; i++) {
				if (obj.list[i].Get_Lyric() == lyric_c) {
					obj.list[i].Get_Info();
					cout << endl;
				}
			}
			break;
		case(5):
			cout << endl << "������� ������ ������ - ";
			cin >> music_c;
			for (int i = 0; i < 256; i++) {
				if (obj.list[i].Get_Music() == music_c) {
					obj.list[i].Get_Info();
					cout << endl;
				}
			}
			break;
		case(6):
			cout << endl << "������� ����������� - ";
			cin >> singer_c;
			for (int i = 0; i < 256; i++) {
				if (obj.list[i].Get_Singer() == singer_c) {
					obj.list[i].Get_Info();
					cout << endl;
				}
			}
			break;
		case(7):
			cout << endl << "������� ����� ����� - " << obj.Get_Size() << endl;
			break;
		case(8):
			cout << endl << "������� �������� - ";
			cin >> name_c;
			obj.Delete(name_c);
			break;
		case(9):
			cout << endl << "    �������� ���������� ��������:";
			cout << endl << "        1 - ��������� � ����";
			cout << endl << "        2 - ��������� �� �����" << endl;
			cout << "��� ����� - ";
			int way;
			cin >> way;
			if (way == 1) {
				cout << "����� ��������� " << obj.size << " �����" << endl;
				fout.open("D://IIP/IiP_381908_2_2/grigorev.ms/x64/Release/input.txt");
				fout << obj.size << endl;
				for (int i = 0; i < obj.size; i++) {
					fout << obj.list[i].Get_Name() << " " << obj.list[i].Get_Lyric() << " " << obj.list[i].Get_Music() << " " << obj.list[i].Get_Singer() << " " << obj.list[i].Get_Album() << " " << obj.list[i].Get_Date() << endl;
				}
			}
			else if (way == 2) {
				int fsize;
				fin >> fsize;
				cout << "����� ��������� " << fsize << " �����" << endl;
				for (int i = 0; i < fsize; i++) {
					fin >> name_c >> lyric_c >> music_c >> singer_c >> album_c >> release_date_c;
					obj.Add(name_c, lyric_c, music_c, singer_c, album_c, release_date_c);
				}
			}
			break;
		}
	}
}