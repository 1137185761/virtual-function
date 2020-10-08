#include<iostream>

using namespace std;

class father
{
public:
	virtual void func1() { cout << "调用func1" << endl; }
	virtual void func2() { cout << "调用func2" << endl; }
	virtual void func3() { cout << "调用func3" << endl; }
public:
	int x = 0;
	int y = 2;
};

class mother
{
public:
	virtual void handle1() { cout << "调用handle1" << endl; }
	virtual void handle2() { cout << "调用handle2" << endl; }
	virtual void handle3() { cout << "调用handle3" << endl; }
public:
	int m = 5;
	int n = 8;
};

class son :public father, public mother
{
public:
	void func1()override { cout << "调用son1" << endl; }
	void handle2()override { cout << "调用son2" << endl; }
	virtual void son3() { cout << "调用son3" << endl; }

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

	//父亲类对象的虚函数表
	int* pFather = (int*)*(int*)&father1;//其中pFather就是父亲类的虚表指针;
	cout << "通过父类虚表指针来调用虚函数" << endl;
	for (int i= 0; i < 3; i++)
	{
		(*((func_t*)pFather+i))();
	}

	cout <<endl<< "通过父类对象指针找出数据成员" << endl;
	for (int i = 0; i < 2; i++)
	{
		cout << *((int*)&father1 + 1 + i) << endl;
	}

	//通过子类对象指针了解子类对象数据的内存分布

	//子类对象的第一个数据成员(即按继承顺序第一个基类的虚表指针)
	int* pSon1 = (int*)*(int*)&son1;
	cout <<endl<< "调用第一个虚函数表" << endl;
	for (int i = 0; i < 4; i++)
	{
		(*((func_t*)pSon1+i))();
	}
	cout << endl << "调用第二个虚函数表" << endl;
	int *pSon2 = (int*)*((int*)(&son1) + 3);
	for (int i = 0; i < 3; i++)
	{
		(*((func_t*)pSon2 + i))();
	}

	//输出son1中的所有数据成员
	cout << endl<<"子类对象的数据成员" << endl;
	for (int i = 0; i < sizeof(son1)/sizeof(int); i++)
	{
		cout << *((int*)&son1 + i) << endl;
	}

	//输出pSon1和pSon2
	cout << endl << "第一个基类的虚表表指针" << endl;
	cout << hex<<(int)pSon1 << endl;
	cout << "第二个基类的虚表指针" << endl;
	cout << (int)pSon2 << endl;
	return 0;
}            