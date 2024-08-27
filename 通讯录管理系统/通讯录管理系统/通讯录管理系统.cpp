#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

#define MAX 1000

//��ϵ�˽ṹ��
struct Person
{
	string m_Name;
	int m_Sex;//1:�У�2��Ů
	int m_Age;
	string m_Phone;
	string m_Address;
};
//ͨѶ¼�ṹ��
struct Addressbooks
{
	Person personArray[MAX];//ͨѶ¼�б������ϵ������
	int m_Size;//ͨѶ¼�е�ǰ��ϵ�˸���
};

void addPerson(Addressbooks* abs)
{
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼�������޷����" << endl;
		return;
	}
	else
	{
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		cout << "�������Ա�1���У�2��Ů����" << endl;
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
				cout << "���������������" << endl;
			}
		}

		cout << "���������䣺" << endl;
		int age;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		cout << "������绰��" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		cout << "�������ַ��" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Address= address;
		abs->m_Size++;
		cout << "��ӳɹ�" << endl;
		system("pause");//�밴���������
		system("cls");//��������
	}
}

void showPerson(Addressbooks* abs)//��ʾ��ϵ��
{
	if (abs->m_Size == 0)
	{
		cout << "��ǰͨѶ¼������Ϊ0" << endl;
		return;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << abs->personArray[i].m_Name << "\t";
			cout << (abs->personArray[i].m_Sex == 1 ? "��" : "Ů") << "\t";//����
			cout << abs->personArray[i].m_Age << "\t";
			cout << abs->personArray[i].m_Phone << "\t";
			cout << abs->personArray[i].m_Address << endl;
		}
	}
	system("pause");//�밴���������
	system("cls");//��������
}

int isExit(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i;//������ϵ�����������еľ���λ��
		}
	}
	return -1;//����������û���ҵ�
}

void deletePerson(Addressbooks* abs)
{
	cout << "������Ҫɾ������ϵ��������" << endl;
	string name;
	cin >> name;
	int ret = isExit(abs, name);
	if (ret == -1)
	{
		cout << "���޴���" << endl;
	}
	else
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
	}
	system("pause");//�밴���������
	system("cls");//��������
}

void findPerson(Addressbooks* abs)
{
	cout << "������Ҫ���ҵ���ϵ��������" << endl;
	string name;
	cin >> name;
	int ret = isExit(abs, name);
	if (ret == -1)
	{
		cout << "���޴���" << endl;
	}
	else
	{
		cout << abs->personArray[ret].m_Name << "\t";
		cout << (abs->personArray[ret].m_Sex == 1 ? "��" : "Ů") << "\t";
		cout << abs->personArray[ret].m_Age << "\t";
		cout << abs->personArray[ret].m_Phone << "\t";
		cout << abs->personArray[ret].m_Address << endl;

	}
	system("pause");//�밴���������
	system("cls");//��������
}

void modifyPerson(Addressbooks* abs)
{
	cout << "������Ҫ�޸ĵ���ϵ��������" << endl;
	string name;
	cin >> name;
	int ret = isExit(abs, name);
	if (ret == -1)
	{
		cout << "���޴���" << endl;
	}
	else
	{
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		cout << "�������Ա�1���У�2��Ů����" << endl;
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
				cout << "���������������" << endl;
			}
		}

		cout << "���������䣺" << endl;
		int age;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		cout << "������绰��" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		cout << "�������ַ��" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Address = address;
	}
	system("pause");//�밴���������
	system("cls");//��������
}

void cleanPerson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "�����ͨѶ¼" << endl;
	system("pause");//�밴���������
	system("cls");//��������
}

void menu()
{
	cout << "************************" << endl;
	cout << "***** 1.�����ϵ�� *****" << endl;
	cout << "***** 2.��ʾ��ϵ�� *****" << endl;
	cout << "***** 3.ɾ����ϵ�� *****" << endl;
	cout << "***** 4.������ϵ�� *****" << endl;
	cout << "***** 5.�޸���ϵ�� *****" << endl;
	cout << "***** 6.�����ϵ�� *****" << endl;
	cout << "***** 0.�˳�ͨѶ¼ *****" << endl;
	cout << "************************" << endl;
}
int main()
{
	Addressbooks abs;//����ͨѶ¼�ṹ�����
	abs.m_Size = 0;
	int input = 0;
	do 
	{
		menu();
		cout << "��ѡ�������" << endl;
		cin >>  input;
		switch (input)
		{
		case 0:
			cout << "�˳�ͨѶ¼����ӭ�´�ʹ��" << endl;
			system("pause");
			break;
		case 1:
			cout << "�����ϵ��" << endl;
			addPerson(&abs);
			break; 
		case 2:
			cout << "��ʾ��ϵ��" << endl;
			showPerson(&abs);
			break;
		case 3:
			cout << "ɾ����ϵ��" << endl;
			deletePerson(&abs);
			break;
		case 4:
			cout << "������ϵ��" << endl;
			findPerson(&abs);
			break;
		case 5:
			cout << "�޸���ϵ��" << endl;
			modifyPerson(&abs);
			break;
		case 6:
			cout << "�����ϵ��" << endl;
			cleanPerson(&abs);
			break;
		default:
			cout << "�������" << endl;
			break;
		}
	} while (input);
	
	system("pause");
	return 0;
}