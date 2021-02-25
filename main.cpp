#include "ellipse.h"
#include <iostream>
#include <locale.h>
void addtoEndSpis(); // Добавление в конец списка
void delfromSpis(); // Удаление по номеру
void ShowSpis(); // Вывод содержимого списка
void addtoStartSpis(); // Добавление в начало списка
void addBefore(); // Добавление до заданного элемента
void addAfter(); // Добавление после заданного элемента
void Find(); // Поиск по номеру
typedef struct Spis // Структура для списка
{
	int numb; // id записи
	ellipse elem; 
	Spis* next; // Следующий элемент
	Spis* prev; // Предыдущий элемент списка
}Spis;
int nomber = 1;
Spis* Start = NULL; // Начало списка
int main()
{
	setlocale(LC_ALL, "RUSSIAN");	//настройка языка на русский
	int n;
	while (true) // Простенькая менюшка в консольке, после нажатия пробела происходит очистка консоли
	{
		cout << "Выберите операцию:" << endl <<  "1. Добавить эллипс в начало списка" << endl << "2. Добавить эллипс в конец списка" << endl
		<< "3. Добавить эллипс перед заданным" << endl << "4. Добавить эллипс после заданного" << endl << "5. Найти эллипс"
		<< endl << "6. Удалить эллипс" << endl << "7. Посмотреть список эллипсов" <<
		endl << "0. Закрыть программу" << endl;
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
	temp->elem.input();	//ввод значений для эллипса
	temp->numb = nomber++; // Задаем id и увеличиваем его на единицу
	if (Start == NULL) { // если начала нет то добавляем новый элемент в начало списка
		Start = temp;
		Start->next = NULL;
		Start->prev = NULL;
	}
	else{
		while (Start->next != NULL) {// иначе проходим в конец списка и добавляем тужа элемент
			Start = Start->next;
		}
		Start->next = temp;
		Start->next->next = NULL;
		Start->next->prev = Start;
		while (Start->prev != NULL)Start = Start->prev; // Идем с конца списка к началу чтобы переменная Start указывала на начало
	}
	ShowSpis();
}
void addtoStartSpis() {
	Spis* temp = new Spis();
	temp->elem.input();	//ввод значений для эллипса
	temp->numb = nomber++; // Задаем id и увеличиваем его на единицу
	if (Start == NULL) { // если начала нет то добавляем новый элемент в начало списка
		Start = temp;
		Start->next = NULL;
		Start->prev = NULL;
	}
	else {
		Spis* oldStart = Start;// записываем адрес текущего начала
		Start = temp; // Вставляем новый элемент в начало
		Start->prev = NULL;
		Start->next = oldStart; // вставляем старое начало после нового
		oldStart->prev = Start;
	}
	ShowSpis();
}
void addBefore() { // добавление до заданного
	if (Start == NULL) return;
	ShowSpis();
	int temp_num;
	cout << "Введите номер эллипса ";
	cin >> temp_num;
	Spis* cur = Start; // хранит текущий элемен списка
	Spis* prev = NULL; // а здесь предыдущий
	while (cur != NULL) { // проходим по списку
		if (cur->numb == temp_num) {// если нашли нужный id
			Spis* temp = new Spis();
			temp->elem.input();	//ввод значений для эллипса
			temp->numb = nomber++; // Задаем id и увеличиваем его на единицу
			temp->next = cur; // вставляем в список по серенине между prev и cur
			temp->prev = prev;
			cur->prev = temp;
			if(prev!=NULL)prev->next = temp;
			ShowSpis();
			return;
		}
		prev = cur;
		cur = cur->next;
	}
	cout << "Элемент списка не найден\n";
}
void addAfter() { // добавление после заданного
	if (Start == NULL) return;
	ShowSpis();
	int temp_num;
	cout << "Введите номер эллипса ";
	cin >> temp_num;
	Spis* next = Start->next; // хранит следующий элемент списка
	Spis* cur = Start; // а здесь текущий
	while (cur != NULL) { // проходим по списку
		if (cur->numb == temp_num) {// если нашли нужный id
			Spis* temp = new Spis();
			temp->elem.input();	//ввод значений для эллипса
			temp->numb = nomber++; // Задаем id и увеличиваем его на единицу
			temp->next = next; // вставляем в список по серенине между cur и next
			temp->prev = cur;
			cur->next = temp;
			if (next != NULL)next->prev = temp;
			ShowSpis();
			return;
		}
		cur = next;
		next = next->next;
	}
	cout << "Элемент списка не найден\n";
}
void Find(){
if (Start == NULL) return;
int temp_num;
cout << "Введите номер эллипса ";
cin >> temp_num;
Spis* cur = Start; // хранит текущий элемен списка
Spis* prev = NULL; // а здесь предыдущий
while (cur != NULL) { // проходим по списку
	if (cur->numb == temp_num) {// если нашли нужный id выводим о нем информацию
		cout << "№" << cur->numb << " ";
		cout << "Площадь эллипса: " << cur->elem.getSquare() << endl;
		point f1 = (cur->elem.getFocus()).first, f2 = (cur->elem.getFocus()).second;	//получение первого и второго фокуса используя пару из фокусов
		cout << "Фокусы эллипса: " << endl;
		cout << "f1 = (" << f1.x << " " << f1.y << ")" << endl;
		cout << "f2 = (" << f2.x << " " << f2.y << ")" << endl;
		return;
	}
	prev = cur;
	cur = cur->next;
}
cout << "Элемент списка не найден\n";
}
void delfromSpis() {
	if (Start == NULL) return;
	ShowSpis();
	int temp_num;
	cout << "Введите номер эллипса ";
	cin >> temp_num;
	Spis* cur = Start; // хранит текущий элемен списка
	Spis* prev = NULL; // а здесь предыдущий
	while (cur != NULL) { // проходим по списку
		if (cur->numb == temp_num) {// если нашли нужный id
			if (prev != NULL)cur->prev->next = cur->next; // вырезаем элемент из списка меняя указатели next и prev
			if (cur->next != NULL)cur->next->prev = prev;
			if (cur == Start)Start = NULL; // если удаляется единственный элемент то начало будет пустым
			delete(cur); // удаляем элемент из памяти
			return;
		}
		prev = cur;
		cur = cur->next;
	}
	cout << "Элемент списка не найден\n";
}
void ShowSpis() {
	Spis* cur = Start;
	while(cur!=NULL){
		cout << "№" << cur->numb << " ";
		cout << "Площадь эллипса: " << cur->elem.getSquare() << endl;
		point f1 = (cur->elem.getFocus()).first, f2 = (cur->elem.getFocus()).second;	//получение первого и второго фокуса используя пару из фокусов
		cout << "Фокусы эллипса: " << endl;
		cout << "f1 = (" << f1.x << " " << f1.y << ")" << endl;
		cout << "f2 = (" << f2.x << " " << f2.y << ")" << endl;
		cur = cur->next;
	}
}