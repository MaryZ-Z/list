#include "ellipse.h"
#include <iostream>
#include <locale.h>
void addtoEndSpis(); // ���������� � ����� ������
void delfromSpis(); // �������� �� ������
void ShowSpis(); // ����� ����������� ������
void addtoStartSpis(); // ���������� � ������ ������
void addBefore(); // ���������� �� ��������� ��������
void addAfter(); // ���������� ����� ��������� ��������
void Find(); // ����� �� ������
typedef struct Spis // ��������� ��� ������
{
	int numb; // id ������
	ellipse elem; 
	Spis* next; // ��������� �������
	Spis* prev; // ���������� ������� ������
}Spis;
int nomber = 1;
Spis* Start = NULL; // ������ ������
int main()
{
	setlocale(LC_ALL, "RUSSIAN");	//��������� ����� �� �������
	int n;
	while (true) // ����������� ������� � ���������, ����� ������� ������� ���������� ������� �������
	{
		cout << "�������� ��������:" << endl <<  "1. �������� ������ � ������ ������" << endl << "2. �������� ������ � ����� ������" << endl
		<< "3. �������� ������ ����� ��������" << endl << "4. �������� ������ ����� ���������" << endl << "5. ����� ������"
		<< endl << "6. ������� ������" << endl << "7. ���������� ������ ��������" <<
		endl << "0. ������� ���������" << endl;
		cin >> n;
		switch (n)
		{
		case 1: addtoStartSpis(); break;
		case 2: addtoEndSpis(); break;
		case 3: addBefore(); break;
		case 4: addAfter(); break;
		case 5: Find(); break;
		case 6: delfromSpis(); break;
		case 7: ShowSpis(); break;
		case 0: return 0;
		}
		system("pause");
		system("cls");
	}
    return 0;
}
void addtoEndSpis()  {  
	Spis* temp = new Spis();
	temp->elem.input();	//���� �������� ��� �������
	temp->numb = nomber++; // ������ id � ����������� ��� �� �������
	if (Start == NULL) { // ���� ������ ��� �� ��������� ����� ������� � ������ ������
		Start = temp;
		Start->next = NULL;
		Start->prev = NULL;
	}
	else{
		while (Start->next != NULL) {// ����� �������� � ����� ������ � ��������� ���� �������
			Start = Start->next;
		}
		Start->next = temp;
		Start->next->next = NULL;
		Start->next->prev = Start;
		while (Start->prev != NULL)Start = Start->prev; // ���� � ����� ������ � ������ ����� ���������� Start ��������� �� ������
	}
	ShowSpis();
}
void addtoStartSpis() {
	Spis* temp = new Spis();
	temp->elem.input();	//���� �������� ��� �������
	temp->numb = nomber++; // ������ id � ����������� ��� �� �������
	if (Start == NULL) { // ���� ������ ��� �� ��������� ����� ������� � ������ ������
		Start = temp;
		Start->next = NULL;
		Start->prev = NULL;
	}
	else {
		Spis* oldStart = Start;// ���������� ����� �������� ������
		Start = temp; // ��������� ����� ������� � ������
		Start->prev = NULL;
		Start->next = oldStart; // ��������� ������ ������ ����� ������
		oldStart->prev = Start;
	}
	ShowSpis();
}
void addBefore() { // ���������� �� ���������
	if (Start == NULL) return;
	ShowSpis();
	int temp_num;
	cout << "������� ����� ������� ";
	cin >> temp_num;
	Spis* cur = Start; // ������ ������� ������ ������
	Spis* prev = NULL; // � ����� ����������
	while (cur != NULL) { // �������� �� ������
		if (cur->numb == temp_num) {// ���� ����� ������ id
			Spis* temp = new Spis();
			temp->elem.input();	//���� �������� ��� �������
			temp->numb = nomber++; // ������ id � ����������� ��� �� �������
			temp->next = cur; // ��������� � ������ �� �������� ����� prev � cur
			temp->prev = prev;
			cur->prev = temp;
			if(prev!=NULL)prev->next = temp;
			ShowSpis();
			return;
		}
		prev = cur;
		cur = cur->next;
	}
	cout << "������� ������ �� ������\n";
}
void addAfter() { // ���������� ����� ���������
	if (Start == NULL) return;
	ShowSpis();
	int temp_num;
	cout << "������� ����� ������� ";
	cin >> temp_num;
	Spis* next = Start->next; // ������ ��������� ������� ������
	Spis* cur = Start; // � ����� �������
	while (cur != NULL) { // �������� �� ������
		if (cur->numb == temp_num) {// ���� ����� ������ id
			Spis* temp = new Spis();
			temp->elem.input();	//���� �������� ��� �������
			temp->numb = nomber++; // ������ id � ����������� ��� �� �������
			temp->next = next; // ��������� � ������ �� �������� ����� cur � next
			temp->prev = cur;
			cur->next = temp;
			if (next != NULL)next->prev = temp;
			ShowSpis();
			return;
		}
		cur = next;
		next = next->next;
	}
	cout << "������� ������ �� ������\n";
}
void Find(){
if (Start == NULL) return;
int temp_num;
cout << "������� ����� ������� ";
cin >> temp_num;
Spis* cur = Start; // ������ ������� ������ ������
Spis* prev = NULL; // � ����� ����������
while (cur != NULL) { // �������� �� ������
	if (cur->numb == temp_num) {// ���� ����� ������ id ������� � ��� ����������
		cout << "�" << cur->numb << " ";
		cout << "������� �������: " << cur->elem.getSquare() << endl;
		point f1 = (cur->elem.getFocus()).first, f2 = (cur->elem.getFocus()).second;	//��������� ������� � ������� ������ ��������� ���� �� �������
		cout << "������ �������: " << endl;
		cout << "f1 = (" << f1.x << " " << f1.y << ")" << endl;
		cout << "f2 = (" << f2.x << " " << f2.y << ")" << endl;
		return;
	}
	prev = cur;
	cur = cur->next;
}
cout << "������� ������ �� ������\n";
}
void delfromSpis() {
	if (Start == NULL) return;
	ShowSpis();
	int temp_num;
	cout << "������� ����� ������� ";
	cin >> temp_num;
	Spis* cur = Start; // ������ ������� ������ ������
	Spis* prev = NULL; // � ����� ����������
	while (cur != NULL) { // �������� �� ������
		if (cur->numb == temp_num) {// ���� ����� ������ id
			if (prev != NULL)cur->prev->next = cur->next; // �������� ������� �� ������ ����� ��������� next � prev
			if (cur->next != NULL)cur->next->prev = prev;
			if (cur == Start)Start = NULL; // ���� ��������� ������������ ������� �� ������ ����� ������
			delete(cur); // ������� ������� �� ������
			return;
		}
		prev = cur;
		cur = cur->next;
	}
	cout << "������� ������ �� ������\n";
}
void ShowSpis() {
	Spis* cur = Start;
	while(cur!=NULL){
		cout << "�" << cur->numb << " ";
		cout << "������� �������: " << cur->elem.getSquare() << endl;
		point f1 = (cur->elem.getFocus()).first, f2 = (cur->elem.getFocus()).second;	//��������� ������� � ������� ������ ��������� ���� �� �������
		cout << "������ �������: " << endl;
		cout << "f1 = (" << f1.x << " " << f1.y << ")" << endl;
		cout << "f2 = (" << f2.x << " " << f2.y << ")" << endl;
		cur = cur->next;
	}
}