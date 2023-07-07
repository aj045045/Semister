/*
	11) Write a program to input two polynomial expressions and make sum of it and display the result.
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

struct terms
{
	int coefficient, expression;
};

struct polynomial
{
	int num;
	struct terms *term;
};

void createNew(struct polynomial *val)
{
	cout << "Enter number of terms :";
	cin >> val->num;
	val->term = (struct terms *)malloc(sizeof(struct terms) * val->num);
	for (int i = 0; i < val->num; i++)
	{
		cout << "Enter the value of (eg.coefficient and expression) :" << i + 1 << endl;
		cin >> val->term[i].coefficient >> val->term[i].expression;
	}
	cout << endl;
}

void display(struct polynomial val)
{
	for (int i = 0; i < val.num; i++)
	{
		cout << val.term[i].coefficient << "x^" << val.term[i].expression;
		if (i + 1 < val.num)
			cout << " + ";
	}
	cout << endl;
}

struct polynomial *sum(struct polynomial *p1, struct polynomial *p2)
{
	int i, j, k;
	struct polynomial *sum;
	sum = (struct polynomial *)malloc(sizeof(struct polynomial));
	sum->term = (struct terms *)malloc((p1->num + p2->num) * sizeof(struct terms));
	i = j = k = 0;
	while (i < p1->num && j < p2->num)
	{
		if (p1->term[i].expression > p2->term[j].expression)
			sum->term[k++] = p1->term[i++];
		else if (p1->term[i].expression < p2->term[j].expression)
			sum->term[k++] = p2->term[j++];
		else
		{
			sum->term[k].expression = p1->term[i].expression;
			sum->term[k++].coefficient = p1->term[i++].coefficient + p2->term[j++].coefficient;
		}
	}
	// for (; i < p1->num; i++)
	// 	sum->term[k++] = p1->term[i];
	// for (; j < p2->num; j++)
	// 	sum->term[k++] = p2->term[j];
	sum->num = k;
	return sum;
}

int main()
{
	struct polynomial p1, p2, *p3;
	cout << "Enter the first polynomial equations " << endl;
	createNew(&p1);
	display(p1);
	cout << "Enter the second polynomial equations" << endl;
	createNew(&p2);
	display(p2);
	p3 = sum(&p1, &p2);
	cout << "Sum of both the equations" << endl;
	cout << "First equation is :";
	display(p1);
	cout << "Second equation is :";
	display(p2);
	cout << "Sum of first and second is :";
	display(*p3);
}
