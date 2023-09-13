#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct student
{
	char Famil[20];
	char Name[20], Facult[20];
	int Nomzach;
};

void findBy(student st[], int len) {
	//index 1 for name, 2 for famil, 3 for facul, 4 for nomzach
	printf("������� �������� ������\n");
	printf("1 - ��� \n2 - �������\n3 - ��������� \n4 - ����� �������\n");
	int index;
	int paramz = 0;
	char param[20];
	char ch;
	scanf("%d", &index);


	if ((index > 0) && (index < 4)) {
		printf("������� �������� ������: ");
		scanf("%20s", &param);
		printf("\n");
	}
	else if (index == 4) {
		printf("������� �����: ");
		scanf("%d", &paramz);
		printf("\n");
	}

	for (int i = 0; i < len; i++) {
		student stud = st[i];
		switch (index) {
		case 1:
			if (strcmp(stud.Name, param) == 0) {
				printf("C������ %s %s ��������� �� ���������� %s, ����� �������� ������ %d \n", st[i].Famil, st[i].Name, st[i].Facult, st[i].Nomzach);
			}
		case 2:
			if (strcmp(stud.Famil, param) == 0) {
				printf("C������ %s %s ��������� �� ���������� %s, ����� �������� ������ %d \n", st[i].Famil, st[i].Name, st[i].Facult, st[i].Nomzach);
			}
		case 3:
			if (strcmp(stud.Facult, param) == 0) {
				printf("C������ %s %s ��������� �� ���������� %s, ����� �������� ������ %d \n", st[i].Famil, st[i].Name, st[i].Facult, st[i].Nomzach);
			}
		case 4:
			if (stud.Nomzach == paramz) {
				printf("C������ %s %s ��������� �� ���������� %s, ����� �������� ������ %d \n", st[i].Famil, st[i].Name, st[i].Facult, st[i].Nomzach);
			}
		default:
			break;
		}
	}
	printf("\n");
}

int maxDiffMin(int mas[], int len) {

	int max = mas[0];
	int min = mas[0];
	for (int i = 0; i < len; i++) {
		max = max < mas[i] ? mas[i] : max;
		min = min > mas[i] ? mas[i] : min;
	}

	return max - min;
}

int* randMas(int size) {
	int* mas = (int*)malloc(size * sizeof(int));

	int min = 0;
	int max = 100;

	for (int i = 0; i < size; i++) {
		mas[i] = min + rand() % (max - min + 1);
	}

	return mas;
}

void sumRowCol(int mas[3][3]) {
	int rowsum = 0;
	int colsum = 0;

	for (int i = 0; i < 3; i++) {
		rowsum = 0;
		for (int j = 0; j < 3; j++)
		{
			rowsum = rowsum + mas[i][j];
		}
		printf("� %d ������: %d\n", i, rowsum);
	}

	for (int i = 0; i < 3; i++) {
		colsum = 0;
		for (int j = 0; j < 3; j++)
		{
			colsum = colsum + mas[j][i];
		}
		printf("� %d �������: %d\n", i, colsum);
	}
}

void createStudents(student stud[]) {
	char ch;
	for (int i = 0; i < 3; i++) {
		printf("������� ������� ��������\n");
		scanf("%20s", stud[i].Famil);

		printf("������� ��� �������� %s\n", stud[i].Famil);
		scanf("%20s", stud[i].Name);

		printf("������� �������� ���������� �������� %s %s\n", stud[i].Famil, stud[i].Name);
		scanf("%20s", stud[i].Facult);

		printf("������� ����� �������� ������ �������� %s %s\n", stud[i].Famil, stud[i].Name);
		scanf("%d", &stud[i].Nomzach);
		while ((ch = getchar()) != '\n' && ch != EOF);
	}
}


int main() {
	struct student stud[3];
	setlocale(LC_ALL, "Rus");

	//������ �������
	int intmas[5] = { 1,2,3,4,5 };
	int dif = maxDiffMin(intmas, 5);
	printf("������� 1\n");
	printf("������� ���������: %d\n", dif);

	//������ �������
	printf("������� 2\n");
	int size = 10;
	int* randmas = randMas(size);
	for (int i = 0; i < size; i++) {
		printf("%d ", randmas[i]);
	}
	printf("\n");

	//������ �������
	printf("������� 3\n");
	printf("������� ����� ���������: ");
	scanf("%d", &size);
	int* randmas2 = randMas(size);
	for (int i = 0; i < size; i++) {
		printf("%d ", randmas2[i]);
	}
	printf("\n");

	//��������� �������
	printf("������� 4\n");
	int mas[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
	sumRowCol(mas);

	//����� �������
	printf("������� 5\n");
	createStudents(stud);

	findBy(stud, 3);


	getchar();

	return 0;
}