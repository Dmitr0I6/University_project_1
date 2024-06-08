#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<locale.h>

struct Student {
	unsigned numPoPor;
	unsigned num;
	char name[20];
	char surname[20];
	unsigned yearOfBirth;
	unsigned yearOfJoining;
	struct Marks {
		unsigned phis;
		unsigned math;
		unsigned programming;
		unsigned history;
	}marks;
};
struct myTree
{
	Student info;
	myTree* left;
	myTree* right;
};
const int sizeOfTree = sizeof(myTree);
Student readData();
myTree* createTree();
myTree* addElement(myTree* top,const Student &data);
void showTree(myTree* top);
void otobr(myTree* top, int otstup);
int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	myTree* top = NULL;
	FILE* f;
	int answer;
	while (1) {
		puts("1- ������ ������ ��������");
		puts("2- ������ � �����");
		puts("3- �������� ������");
		puts("4- �������� ������");
		puts("5- �������� ������");
		puts("6- ������� � ����� ������");
		puts("7- ������� ������ � ����");
		puts("8- ���������� 2-� ��������� ����� ��������� ���������");
		puts("0- �����");
		puts("______________________________");
		puts("������� ����� ������ ����\n");
		scanf_s("%d", &answer);
		switch (answer) {
		case 1:
			top = addElement(top, readData());
			break;
		case 2:
			
			break;
		case 3:
			top = createTree();
			break;
		case 4:
			showTree(top);
			break;
		case 5:
			otobr(top,3);
			break;
		case 6:
			fopen_s(&f, "data.dat", "rb+");
			
			fclose(f);
			break;
		case 7:
			fopen_s(&f, "data.dat", "wb");
			
			fclose(f);
			break;
		case 8:
			
			break;
		case 0:
			
			return 0;
		default:
			puts("INCORRECT NUMBER");
			break;
		}
	}
	return 0;
}
Student readData() {
	Student student;
	printf("\n�����:");
	scanf_s("%u", &student.num);
	printf("���:");
	scanf_s("%19s", student.name, (unsigned)_countof(student.name));
	printf("�������:");
	scanf_s("%19s", student.surname, (unsigned)_countof(student.surname));
	printf("��� ��������:");
	scanf_s("%u", &student.yearOfBirth);
	printf("��� ����������� � �����������:");
	scanf_s("%u", &student.yearOfJoining);
	printf("������ �� ������:");
	scanf_s("%u", &student.marks.phis);
	printf("������ �� ����������:");
	scanf_s("%u", &student.marks.math);
	printf("������ �� �����������������:");
	scanf_s("%u", &student.marks.programming);
	printf("������ �� �������:");
	scanf_s("%u", &student.marks.history);
	puts("______________________________");
	return student;
}
myTree* addElement(myTree* top,const Student& data) {
	if (!top) {
		top = (myTree*)malloc(sizeOfTree);
		if (!top) {
			puts("Error");
			return NULL;
		}
		top->info = data;
		top->left = NULL;
		top->right = NULL;
	}
	else {
		if (top->info.num > data.num) { top->left = addElement(top->left, data); }
		else { top->right = addElement(top->right, data);}
	}
	return top;
}
void showTree(myTree* top) {
	if(top==NULL) {
		return;
	}
	else {
		printf("\n�����: %u|", top->info.num);
		printf("���:%s|", top->info.name);
		printf("�������:%s|", top->info.surname);
		printf("��� ��������: %u|", top->info.yearOfBirth);
		printf("��� ����������� � �����������: %u|", top->info.yearOfJoining);
		printf("������ �� ������: %u|", top->info.marks.phis);
		printf("������ �� ����������:%u|", top->info.marks.math);
		printf("������ �� �����������������:%u|", top->info.marks.programming);
		printf("������ �� �������:%u\n", top->info.marks.history);
		showTree(top->left);
		showTree(top->right);
	}
}
myTree* createTree() {
	myTree* top=NULL;
	int flag = 1;
	while (1) {
		top = addElement(top,readData());
		printf("������ ���������� (����� - 0)");
		scanf_s("%d", &flag);
		if (flag == 0)
			break;
	}
	return top;
}

void otobr(myTree* top, int otstup) {
	if (top) {
		otstup += 3; //������ �� ���� ������
		otobr(top->right, otstup); //����� ������� ���������
		//����� ������, ���������������� ����
		for (int i = 0; i < otstup; i++) printf(" ");
		printf("%d\n", top->info.num);
		otobr(top->left, otstup); //����� ������ ���������
	}
}

