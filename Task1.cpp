// Аисд.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <iomanip>
using namespace std;
int masx[8] = { 1,2,2,1,-1,-2,-2,-1 };
int masy[8] = { 2,1,-1,-2,-2,-1,1,2 };
void Print(int SIZE, int **mas)
{
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++)
		{
			cout << setw(3) << mas[i][j];
		}
		cout << "\n";
	}
}
//Функция  для обхода шахматного поля коня.
//Mars-шахматное поле
//num-номер хода
//i0,j0 -координаты клетки,т.е текущего положения коня
void Horse(int SIZE, int **mas, int num, int i0, int j0)
{
	static int kol = 0;//количество общих ходов коня
	kol++;
	mas[i0][j0] = num++;//отметить ход коня на клетке,в которой он стоит
	for (int i = 0; i < 8; i++)//перебор всех направляющих ходов коня
	{
		int inew = i0 + masy[i];//новое возможное расположение коня
		int jnew = j0 + masx[i];

		if (num > SIZE*SIZE) {//проверка что все ходы сделаны
			cout << kol << endl;
			Print(SIZE, mas);
			exit(0);
		}


		//проверка что клетка пустая и лежит в пределах шахматного поля
		if (inew<0 || inew>SIZE - 1 || jnew<0 || jnew>SIZE - 1 || mas[inew][jnew] != 0) {
			continue;
		}
		//сделать ход конём на выбранную клетку
		Horse(SIZE, mas, num, inew, jnew);
		//выполняется откат хода и выбирается новое направление движения коня
		//а в клетке ,где стоял конь номер хода заменяется на 0
		mas[inew][jnew] = 0;
	}
}
void Horse1(int SIZE, int** mas, int num, int i0, int j0)
{
	static int kol = 0;
	kol++;
	mas[i0][j0] = num++;
	for (int i = 0; i < 8; i++)
	{
		int inew = i0 + masy[i];
		int jnew = j0 + masx[i];

		if (num > (SIZE*SIZE) - 1) {
			cout << kol << endl;
			Print(SIZE, mas);
			exit(0);
		}
		if (inew<0 || inew>SIZE - 1 || jnew<0 || jnew>SIZE - 1 || mas[inew][jnew] != 0) {
			continue;
		}
		Horse1(SIZE, mas, num, inew, jnew);
		mas[inew][jnew] = 0;
	}
}
void main() {
	setlocale(LC_ALL, "ru");
	int **Matr;
	int SIZE;
	cout << "Введите размерность доски:NxN" << endl;
	cout << "N->";
	cin >> SIZE;
	while (true)
	{
		
		if (SIZE >= 3 && SIZE <= 7)
			break;

		else
			cout << "Не правильный ввод(((" << endl;
		cout << "Повторите ввод:";
		cin >> SIZE;

	}
	Matr = new int*[SIZE];
	for (int i = 0; i < SIZE; i++) {
		Matr[i] = new int[SIZE];
	}
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			Matr[i][j] = 0;

		}
	}
	if (SIZE == 3 || SIZE == 4) {
		Horse1(SIZE, Matr, 1, 0, 0);
	}
	else {
		Horse(SIZE, Matr, 1, 0, 0);
	}
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
