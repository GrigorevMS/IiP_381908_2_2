#include"coniow.h"
#include<iostream>
#include"TextEditor.h"
#include<locale.h>
using namespace std;
int main() {
	setlocale(LC_CTYPE, "Russian");
	bool exit = true;
	TextEditor Window(1, 1, 40);
	while (exit) {
		unsigned int choise;	
		cout << "�������� ���������� ��������" << '\n';
		cout << "    1 - ���� ��������� � ������� ����" << '\n';
		cout << "    2 - �������� ��������" << '\n';
		cout << "    3 - ������ ��������" << '\n';
		cout << "    4 - ���� � �������������� ������" << '\n';
		cout << "    5 - ���������� ������" << '\n';
		cout << "��� �����: ";
		cin >> choise;
		switch(choise){
		case(1):
			textbackground(BLUE);
			textcolor(WHITE);
			Window.SetSize(0, 0, 10);
			break;
		case(2): // �������� ��������
			textbackground(BLUE);
			textcolor(WHITE);
			Window.OutputText();
			break;
		case(3): // ������ ��������
			break;
		case(4): // ������� � �������������� �����
			textbackground(BLUE);
			textcolor(WHITE);
			Window.InputText();
			break;
		case(5): // ���������� ������
			exit = false;
			cout << '\n' << "�� ��������! �������� ���!" << '\n';
			break;
		}
	}
}