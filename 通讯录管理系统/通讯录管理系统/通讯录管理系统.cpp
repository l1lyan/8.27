#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

#define MAX 1000

//联系人结构体
struct Person
{
	string m_Name;
	int m_Sex;//1:男，2：女
	int m_Age;
	string m_Phone;
	string m_Address;
};
//通讯录结构体
struct Addressbooks
{
	Person personArray[MAX];//通讯录中保存的联系人数组
	int m_Size;//通讯录中当前联系人个数
};

void addPerson(Addressbooks* abs)
{
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满，无法添加" << endl;
		return;
	}
	else
	{
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		cout << "请输入性别（1：男，2：女）：" << endl;
		int sex;
		while (1)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			else
			{
				cout << "输入错误，重新输入" << endl;
			}
		}

		cout << "请输入年龄：" << endl;
		int age;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		cout << "请输入电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		cout << "请输入地址：" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Address= address;
		abs->m_Size++;
		cout << "添加成功" << endl;
		system("pause");//请按任意键继续
		system("cls");//清屏操作
	}
}

void showPerson(Addressbooks* abs)//显示联系人
{
	if (abs->m_Size == 0)
	{
		cout << "当前通讯录中人数为0" << endl;
		return;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << abs->personArray[i].m_Name << "\t";
			cout << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";//括号
			cout << abs->personArray[i].m_Age << "\t";
			cout << abs->personArray[i].m_Phone << "\t";
			cout << abs->personArray[i].m_Address << endl;
		}
	}
	system("pause");//请按任意键继续
	system("cls");//清屏操作
}

int isExit(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i;//返回联系人所在数组中的具体位置
		}
	}
	return -1;//遍历结束，没有找到
}

void deletePerson(Addressbooks* abs)
{
	cout << "请输入要删除的联系人姓名：" << endl;
	string name;
	cin >> name;
	int ret = isExit(abs, name);
	if (ret == -1)
	{
		cout << "查无此人" << endl;
	}
	else
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
	}
	system("pause");//请按任意键继续
	system("cls");//清屏操作
}

void findPerson(Addressbooks* abs)
{
	cout << "请输入要查找的联系人姓名：" << endl;
	string name;
	cin >> name;
	int ret = isExit(abs, name);
	if (ret == -1)
	{
		cout << "查无此人" << endl;
	}
	else
	{
		cout << abs->personArray[ret].m_Name << "\t";
		cout << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
		cout << abs->personArray[ret].m_Age << "\t";
		cout << abs->personArray[ret].m_Phone << "\t";
		cout << abs->personArray[ret].m_Address << endl;

	}
	system("pause");//请按任意键继续
	system("cls");//清屏操作
}

void modifyPerson(Addressbooks* abs)
{
	cout << "请输入要修改的联系人姓名：" << endl;
	string name;
	cin >> name;
	int ret = isExit(abs, name);
	if (ret == -1)
	{
		cout << "查无此人" << endl;
	}
	else
	{
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		cout << "请输入性别（1：男，2：女）：" << endl;
		int sex;
		while (1)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			else
			{
				cout << "输入错误，重新输入" << endl;
			}
		}

		cout << "请输入年龄：" << endl;
		int age;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		cout << "请输入电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		cout << "请输入地址：" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Address = address;
	}
	system("pause");//请按任意键继续
	system("cls");//清屏操作
}

void cleanPerson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "已清空通讯录" << endl;
	system("pause");//请按任意键继续
	system("cls");//清屏操作
}

void menu()
{
	cout << "************************" << endl;
	cout << "***** 1.添加联系人 *****" << endl;
	cout << "***** 2.显示联系人 *****" << endl;
	cout << "***** 3.删除联系人 *****" << endl;
	cout << "***** 4.查找联系人 *****" << endl;
	cout << "***** 5.修改联系人 *****" << endl;
	cout << "***** 6.清空联系人 *****" << endl;
	cout << "***** 0.退出通讯录 *****" << endl;
	cout << "************************" << endl;
}
int main()
{
	Addressbooks abs;//创建通讯录结构体变量
	abs.m_Size = 0;
	int input = 0;
	do 
	{
		menu();
		cout << "请选择操作：" << endl;
		cin >>  input;
		switch (input)
		{
		case 0:
			cout << "退出通讯录，欢迎下次使用" << endl;
			system("pause");
			break;
		case 1:
			cout << "添加联系人" << endl;
			addPerson(&abs);
			break; 
		case 2:
			cout << "显示联系人" << endl;
			showPerson(&abs);
			break;
		case 3:
			cout << "删除联系人" << endl;
			deletePerson(&abs);
			break;
		case 4:
			cout << "查找联系人" << endl;
			findPerson(&abs);
			break;
		case 5:
			cout << "修改联系人" << endl;
			modifyPerson(&abs);
			break;
		case 6:
			cout << "清空联系人" << endl;
			cleanPerson(&abs);
			break;
		default:
			cout << "输入错误" << endl;
			break;
		}
	} while (input);
	
	system("pause");
	return 0;
}