#include<iostream>

using namespace std;

class father
{
public:
	virtual void func1() { cout << "����func1" << endl; }
	virtual void func2() { cout << "����func2" << endl; }
	virtual void func3() { cout << "����func3" << endl; }
public:
	int x = 0;
	int y = 2;
};

class mother
{
public:
	virtual void handle1() { cout << "����handle1" << endl; }
	virtual void handle2() { cout << "����handle2" << endl; }
	virtual void handle3() { cout << "����handle3" << endl; }
public:
	int m = 5;
	int n = 8;
};

class son :public father, public mother
{
public:
	void func1()override { cout << "����son1" << endl; }
	void handle2()override { cout << "����son2" << endl; }
	virtual void son3() { cout << "����son3" << endl; }

public:
	int i = 10;
	int j = 20;
};

typedef void (*func_t)(void);

int main()
{
	father father1;
	mother mother1;
	son son1;

	//�����������麯����
	int* pFather = (int*)*(int*)&father1;//����pFather���Ǹ���������ָ��;
	cout << "ͨ���������ָ���������麯��" << endl;
	for (int i= 0; i < 3; i++)
	{
		(*((func_t*)pFather+i))();
	}

	cout <<endl<< "ͨ���������ָ���ҳ����ݳ�Ա" << endl;
	for (int i = 0; i < 2; i++)
	{
		cout << *((int*)&father1 + 1 + i) << endl;
	}

	//ͨ���������ָ���˽�����������ݵ��ڴ�ֲ�

	//�������ĵ�һ�����ݳ�Ա(�����̳�˳���һ����������ָ��)
	int* pSon1 = (int*)*(int*)&son1;
	cout <<endl<< "���õ�һ���麯����" << endl;
	for (int i = 0; i < 4; i++)
	{
		(*((func_t*)pSon1+i))();
	}
	cout << endl << "���õڶ����麯����" << endl;
	int *pSon2 = (int*)*((int*)(&son1) + 3);
	for (int i = 0; i < 3; i++)
	{
		(*((func_t*)pSon2 + i))();
	}

	//���son1�е��������ݳ�Ա
	cout << endl<<"�����������ݳ�Ա" << endl;
	for (int i = 0; i < sizeof(son1)/sizeof(int); i++)
	{
		cout << *((int*)&son1 + i) << endl;
	}

	//���pSon1��pSon2
	cout << endl << "��һ�����������ָ��" << endl;
	cout << hex<<(int)pSon1 << endl;
	cout << "�ڶ�����������ָ��" << endl;
	cout << (int)pSon2 << endl;
	return 0;
}            