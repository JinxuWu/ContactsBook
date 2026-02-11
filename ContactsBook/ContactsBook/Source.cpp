#include<iostream>
#include<string>
using namespace std;
#define max 1000//定义宏常量
//联系人结构体变量
struct person{
	string s_name;
	string s_sex;
	int s_age;
	string s_address;
	string s_number;
};
//通讯录结构体变量
struct Contactsbook{
	person s_parray[max];
	int s_size;
};
Contactsbook book;//创建通讯录变量实参
//添加联系人函数
int size = 0;
void add(Contactsbook * book){
	//判断容量情况
	if (book->s_size == max)
	{
		cout << "No more spaces for new contact!";
	}
	else
	{
		string name;
		string sex;
		int age;
		string address;
		string number;
		string s;
		cout << "Please input a name:\n";
		getline(cin, s);//接收缓冲区
		getline(cin, name);
		book->s_parray[book->s_size].s_name = name;
		cout << "Please input the sex:\n";
		getline(cin, sex);
		book->s_parray[book->s_size].s_sex = sex;
		cout << "Please input the age:\n";
		cin >> age;
		book->s_parray[book->s_size].s_age = age;
		cout << "Please input the address:\n";
		getline(cin, s);//接收缓冲区(可以用ignore但是我认为这里更简便）
		getline(cin, address);
		book->s_parray[book->s_size].s_address = address;
		cout << "Please input the number:\n";
		cin >> number;
		book->s_parray[book->s_size].s_number = number;
		cout << "New contact added successfully!\n" << endl;
		book->s_size++;
	}
}
//展示所有联系人函数
void showall(Contactsbook * book){
	if (book->s_size ==0)
	{
		cout << "Empty book!\n";
	}
	else
	{
		for (int i = 0; i < book->s_size ; i++)
		{
			cout << i + 1 << ",\n" << "name:" << book->s_parray[i].s_name << endl;
			cout << "sex:" << book->s_parray[i].s_sex << endl;
			cout << "age:" << book->s_parray[i].s_age << endl;
			cout << "address:" << book->s_parray[i].s_address << endl;
			cout << "number:" << book->s_parray[i].s_number << endl;
			cout << endl;
		}
	}
}
//搜索函数
void search(Contactsbook * book){
	string name;
	cout << "Please input the name of the contact to search:\n";
	getline(cin, name);
	getline(cin, name);
	bool found = 0;
	for (int i = 0; i < book->s_size; i++)
	{
		if (name == book->s_parray[i].s_name)
		{
			cout << "Contact found!\n";
			cout << i+1 << ",\n" << "name:" << book->s_parray[i].s_name << endl;
			cout << "sex:" << book->s_parray[i].s_sex << endl;
			cout << "age:" << book->s_parray[i].s_age << endl;
			cout << "address:" << book->s_parray[i].s_address << endl;
			cout << "number:" << book->s_parray[i].s_number << endl;
			cout << endl;
			found = 1;
		}
	}
	if (found==0)
	{
		cout << "No such name in the contactsbook! Please try again!\n";
	}
}
//检查函数(姓名）
int check_name(Contactsbook * book, string name){
	for (int i = 0; i < book->s_size; i++)
	{
		if (book->s_parray[i].s_name == name)
		{
			return i;
		}
	}
	return -1;
}
//检查函数（编号）
int check_num(Contactsbook * book, int num){
	for (int i = 0; i < book->s_size; i++)
	{
		if (num > book->s_size)
		{
			return -1;
		}
		else
		{
			return num;
		}
	}
}
//删除函数
void dlt(Contactsbook * book){
	string name;
	cin >> name;
	int ret=check_name(book, name);
	if (ret != -1)
	{
		cout << "Contact found:\n";
		cout << "name:" << book->s_parray[ret].s_name << endl;
		cout << "sex:" << book->s_parray[ret].s_sex << endl;
		cout << "age:" << book->s_parray[ret].s_age << endl;
		cout << "address:" << book->s_parray[ret].s_address << endl;
		cout << "number:" << book->s_parray[ret].s_number << endl;
		flag0://误操作保护
		cout << "Sure to delete?(1 for yes,0 for no)\n";
		int ans;
		cin >> ans;
		if (ans == 1)
		{
			for (int i = ret; i < book->s_size; i++)
			{
				book->s_parray[i] = book->s_parray[i + 1];
			}
			cout << "Contact deleted!\n";
			book->s_size--;
		}
		else if (ans==0)
		{
			cout << "Deleting cancelled!";
		}
		else
		{
			cout << "Invalid input,please try again!\n";
			goto flag0;
		}
	}
	else
	{
		cout << "No such name in the Contactsbook!\n";
	}
}
void revise(Contactsbook * book){
	string name;
	string sex;
	int age;
	string address;
	string number;
	string s;
	showall(book);
	cout << "Please input the number of the contact to revise information:\n";
	int num;
	cin >> num;
	int ret = check_num(book, num);
	if (ret != -1)
	{
		cout << "Please input a name:\n";
		getline(cin, name);//接收缓冲区
		getline(cin, name);
		book->s_parray[ret-1].s_name = name;
		cout << "Please input the sex:\n";
		getline(cin, sex);
		book->s_parray[ret-1].s_sex = sex;
		cout << "Please input the age:\n";
		cin >> age;
		book->s_parray[ret-1].s_age = age;
		cout << "Please input the address:\n";
		getline(cin, s);
		getline(cin, address);
		book->s_parray[ret-1].s_address = address;
		cout << "Please input the number:\n";
		cin >> number;
		book->s_parray[ret-1].s_number = number;
		cout << "Contacted revised successfully!\n";
	}
}
void clr(Contactsbook * book){
	if (book->s_size == 0)
	{
		cout << "No contact in the book!";
	}
	else
	{
		int ans;
	flag1:
		cout << "Sure to clear all the contacts?\nCaution,once cleared,it cannot be restored!\n(1 for yes,0 for no)\n";
		cin >> ans;
		if (ans == 1)
		{
			book->s_size = 0;
			cout << "All contacts have been cleared!\n";
		}
		else if (ans == 0)
		{
			cout << "Clearing cancelled!\n";
		}
		else
		{
			cout << "Unknown input,please try again!\n";
			goto flag1;
		}
	}
}
//选项函数
void option(int x){
	switch (x){
	case 1:
		cout << "Adding new contact:\n";
		add(&book);//调用添加函数
		break;
	case 2:
		cout << "Showing all contacts:\n" << endl;
		showall(&book);
		break;
	case 3:
		cout << "Searching contact:\n";
		search(&book);
		break;
	case 4:
		cout << "Deleting contact:\n";
		dlt(&book);
		break;
	case 5:
		cout << "Revising contact:\n";
		revise(&book);
		break;
	case 6:
		clr(&book);
		break;
	default:
		cout << "Unknown input,please try again!\n";
		break;
	}
}
//展示菜单
void showmenu(){
	cout << "ContactsBook\n"
		<< "1.Adding new contact\n"
		<< "2.Showing all contacts\n"
		<< "3.Searching contact\n"
		<< "4.Deleting contact\n"
		<< "5.Revising contact\n"
		<< "6.Clear all contacts\n"
		<< "7.Exit\n";
}
int main(){
	bool exit = 0;
	while (!exit){
		showmenu();//调用展示菜单函数
		int num = 0;
		cin >> num;
		if (num == 7)
		{
			exit = 1;
			cout << "Thanks for using,bye!\n";
			system("pause");
		}
		else
		{
			option(num);
			system("pause");//调用选项函数
		}
		system("cls");//清屏
		/*cout<<*/
	}
	return 0;
}
/*
10.2.2025
JinxuWu,CQUPT,SE2025
*/