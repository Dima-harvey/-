// АиСД1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <algorithm> 

using namespace std;



int main() {
	int amountOfDays;
	cout << "Enter amount of days: ";
	cin >> amountOfDays;
	int *stocks = new int[amountOfDays - 1];
	int *cost_stocks = new int[amountOfDays];
	int counter = 0;
	int status = true;


	for (int i = 0; i < amountOfDays; i++)
	{
		cout << "Enter cost in day " << i << ":";
		cin >> cost_stocks[i];
		if (cost_stocks[i] < 0) {
			cout << "Stocks can't be negative" << endl;
			status = false;
			break;

		}
		/*if (cost_stocks[i] <= 0)
		{
			counter++;
		}*/
	}
	if (status == true) {

		for (int i = 0; i < (amountOfDays - 1); i++)
		{
			stocks[i] = cost_stocks[i + 1] - cost_stocks[i];
			if (stocks[i] <= 0)
			{
				counter++;
			}
		}
		/*for (int i = 0; i < amountOfDays; i++)
		{
			cout << "Enter change in day " << i << ":";
			cin >> stocks[i];
			if (stocks[i] <= 0)
			{
				counter++;
			}
		}*/
		if (counter == (amountOfDays - 1))
		{
			cout << "We can't get profit" << endl;
		}
		else {

			if (1 == amountOfDays)
			{
				cout << "We have only one day" << endl;
			}
			else
			{
				int mid = (int)((/*1 + */amountOfDays - 1) / 2);


				int leftSum = 0;
				int partialSum = 0;
				int leftLow = 0;
				int leftHigh = 0;
				for (int i = 0; i < mid; i++)
				{
					partialSum += stocks[i];



					if (partialSum > leftSum)
					{
						leftHigh = i;
						leftSum = partialSum;
					}

					//leftSum = max(leftSum, partialSum);
					if (partialSum < 0)
					{
						leftLow = i + 1;
						partialSum = 0;
					}
				}

				int rightSum = 0;
				partialSum = 0;
				int rightLow = 0;
				int rightHigh = 0;
				for (int i = mid; i < amountOfDays - 1; i++)
				{
					partialSum += stocks[i];

					if (partialSum > rightSum)
					{
						rightHigh = i;
						rightSum = partialSum;
					}

					//rightSum = max(rightSum, partialSum);
					if (partialSum < 0)
					{
						rightLow = i + 1;
						partialSum = 0;
					}
				}

				int left_sum = -1000;
				int sum = 0;
				int max_left = 0;
				for (int i = mid - 1; i >= 0; i--)
				{
					sum = sum + stocks[i];
					if (sum > left_sum)
					{
						left_sum = sum;
						max_left = i;
					}
				}

				int right_sum = -1000;
				sum = 0;
				int max_right = 0;
				for (int j = mid; j < amountOfDays - 1; j++)
				{
					sum = sum + stocks[j];
					if (sum > right_sum)
					{
						right_sum = sum;
						max_right = j;
					}
				}

				int cross_low = max_left;
				int cross_high = max_right + 1;
				int cross_sum = right_sum + left_sum;

				cout << "Growth graphic: ";
				for (int i = 0; i < amountOfDays - 1; i++)
				{
					cout << stocks[i] << "  ";
				}
				if (leftSum >= rightSum && leftSum >= cross_sum)
				{
					cout << "\nBuy: " << leftLow << " Sell: " << leftHigh + 1 << " Profit: " << leftSum << endl;
				}
				else if (rightSum >= leftSum && rightSum >= cross_sum)
				{
					cout << "\nBuy: " << rightLow << " Sell: " << rightHigh + 1 << " Profit: " << rightSum << endl;
				}
				else
				{
					cout << "\nBuy: " << cross_low << " Sell: " << cross_high << " Profit: " << cross_sum << endl;
				}


			}
		}
	}

	system("pause");
	return 0;

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
