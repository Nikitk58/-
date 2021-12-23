#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include <conio.h>

#include <time.h>

#include <stack>

#include <queue>

#include <stdio.h>

#include <Windows.h>

#include <stdlib.h>

using namespace std;

queue <int> Q;

int i, j, N, st, menu, mean;

char save_matr[3], save_result[3];

char Yes[] = "��", yes[] = "��";

int** graph; // ������� ���������

int* visited; // ��������� �������

FILE* result;

void BFS(int st) // ����� � ������

{

	Q.push(st);

	visited[st] = true;

	while (!Q.empty())

	{

		st = Q.front();

		Q.pop();

		printf("%d ", st + 1);

		for (j = 0; j < N; j++)

		{

			if ((graph[st][j] == 1) && (!visited[j]))

			{

				visited[j] = true;

				Q.push(j);

			}

		}

	}

}

void BFS_SAVE(int st) // ���������� ����������� � ���� ������ � ������

{

	result = fopen("���������.txt", "a");

	fprintf(result, "\n ��������� ������ � ������: ");

	Q.push(st);

	visited[st] = true;

	while (!Q.empty())

	{

		st = Q.front();

		Q.pop();

		fprintf(result, "%d ", st + 1);

		for (j = 0; j < N; j++)

		{

			if ((graph[st][j] == 1) && (!visited[j]))

			{

				visited[j] = true;

				Q.push(j);

			}

		}

	}

	fclose(result);

}

void MENU()

{

	system("cls");

	printf("\n ���� ��������� ");

	printf("\n 1. ������ ������");

	printf("\n 2. ��������� ������");

	printf("\n\n ������� ����� ������� - ");

	scanf("%d", &menu);

	while (menu > 2 || menu < 1)//��������, ����� �� ����� ���-������ ������

	{

		system("cls");

		printf("\n ���� ��������� ");

		printf("\n 1. ������ ������");

		printf("\n 2. ��������� ������");

		printf("\n\n ������� ����� ������� - ");

		scanf("%d", &menu);

	}

	system("cls");

	return;

}

void MMM() // ����

{

	SetConsoleCP(1251);

	SetConsoleOutputCP(1251);

	printf("\n ������� ������ ������� ");

	scanf_s("%d", &N);

	printf("\n ������ �������� �������\n 1. ������ ����������\n 2. �������������� ���������� \n\n �������� ������ - ");

	scanf("%d", &mean);

	while ((mean > 2) || (mean < 1))

	{

		printf("\n ����� ������ ������� �� ����������\n �������� ������ ������ - ");

		scanf("%d", &mean);

	}

	printf("\n");

	srand(time(NULL));

	graph = new int* [N];

	visited = new int[N];

	for (int i = 0; i < N; i++) {

		graph[i] = new int[N];

	}

	if (mean == 1) {//������������ ����� ������ ���������� �������

		for (i = 0; i < N; i++)

		{

			for (j = i + 1; j < N; j++)

			{

				printf(" ����� ����� %d � %d - ", i + 1, j + 1);

				scanf_s("%d", &graph[i][j]);

				graph[j][i] = graph[i][j];

				graph[i][i] = graph[j][j] = 0;

			}

		}

	}

	if (mean == 2) {//������������ ����� ������ �������

		for (i = 0; i < N; ++i)

		{

			for (j = i; j < N; ++j)

			{

				graph[i][j] = graph[j][i] = rand() % 2;

				graph[i][i] = graph[j][j] = 0;

			}

		}

		printf("\n ");

	}

	for (j = 0; j < N; j++)//����� �������

	{

		printf("%4d ", j + 1);

	}

	printf("\n\n");

	for (i = 0; i < N; i++)//����� �������

	{

		printf(" %d ", i + 1);

		for (j = 0; j < N; j++)

		{

			printf("%4d ", graph[i][j]);

		}

		printf("\n\n");

	}

	printf("\n ������� �������: ");

	scanf_s("%d", &st);

	while ((st > N) || (st < 0)) {

		printf("\n ����� ������� �� ����������!\n");

		printf("\n ������� �������: ");

		scanf_s("%d", &st);

	}

	for (i = 0; i < N; i++)

	{

		visited[i] = false;

	}

	printf("\n ��������� ������ � ������: ");

	BFS(st - 1);

	printf("\n\n");

	printf(" ��������� ������� � ����? ");

	scanf("%s", &save_matr);

	if ((strcmp(Yes, save_matr) == 0) || (strcmp(yes, save_matr) == 0))

	{

		result = fopen("���������.txt", "w");

		fprintf(result, " ������ ������� %dx%d \n\n ", N, N);

		for (j = 0; j < N; j++)

		{

			fprintf(result, "%4d ", j + 1);

		}

		fprintf(result, "\n\n");

		for (i = 0; i < N; i++)

		{

			fprintf(result, " %d ", i + 1);

			for (j = 0; j < N; j++)

			{

				fprintf(result, "%4d ", graph[i][j]);

			}

			fprintf(result, "\n\n");

		}

		fclose(result);

	}

	printf(" ��������� ��������� ������ � ����? ");

	scanf("%s", &save_result);

	if ((strcmp(Yes, save_result) == 0) || (strcmp(yes, save_result) == 0))

	{

		for (i = 0; i < N; i++)

		{

			visited[i] = false;

		}

		BFS_SAVE(st - 1);

	}

	return;

}

int main()

{

	SetConsoleCP(1251);

	SetConsoleOutputCP(1251);

	do {

		MENU();

		switch (menu)

		{

		case 1:

			MMM();

			break;

		case 2:

			return 0;

		}

		if (menu != 2)

			system("pause");

	} while (menu != 2);

}