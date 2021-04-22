#include <stdio.h>

#define Pi 3.1415592654 // задаем значение пи

#define accuracy 0.0000000001 // задаем точность вычислений

double transfet(double ang) // осуществляем перевод градусов в радианы

{

	float radian = ang * Pi / 180;

	return radian;

}

double function(double degree)// целевая функция для нахождения косинуса

{

	int n = 1;

	double value = 1;

	double final_value = 1;

	double tmp = 0;

	while (value > accuracy)// сравниваем вычисляемый член функции с точностью

	{

		value *= degree * degree / (2 * n * (2 * n - 1)); //формула соответствующая разложе-нию функции косинуса в ряд Тейлора

		if (n % 2 == 1) // вычисление остатка от деления на 2, где n - номер элемента после единицы, в зависимости от его номера меняется знак

		{

			tmp = -value;

		}

		else

		{

			tmp = value;

		}

		n++;

		final_value += tmp;

	}

	return final_value;

}

int main() // тестирующая функция

{

	double angle[6] = { 0 , 30 , 45 , 60 ,90, 120 }; // массив углов, косинусы которых будут сравниваться с эталонными значениями

	double e = 0.0001;

	double cos_reference[6] = { 1, 0.866025, 0.707107, 0.5, 0 , -0.5 }; // массив эталонных значений коси-нусов (0, 30, 60, 90 ,120 градусов )

	double cos_true[5];

	double cos;

	int res;
	int n = 1;
	int i;

	for (i = 0; i < 6; i++ ) // сравниваем и получаем результаты

	{

		double radian = transfet(angle[i]);

		cos = function(radian);

		if ((cos - cos_reference[i]) <= e) //сравн. полученных значений и эталонных, путем нахождение разности между ними и сравн. с заданной точн.

		{

			res = 0;

			cos_true[i] = cos_reference[i]; // присваивание эталонного значения получившемуся для вывода на экран

		}

		else

		{
			res = 1;
			printf("Error\n");

		}

	}

	for (int i = 0; i < 6; i++)

	printf("Received value is correct: %.10f\n", cos_true[i]);
  return res;
}
