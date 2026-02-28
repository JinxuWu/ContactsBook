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
		cout << "空间不足！\n";
	}
	else
	{
		string name;
		string sex;
		int age;
		string address;
		string number;
		string s;
		cout << "请输入名称：\n";
		getline(cin, s);//接收缓冲区
		getline(cin, name);
		book->s_parray[book->s_size].s_name = name;
		cout << "请输入性别：\n";
		getline(cin, sex);
		book->s_parray[book->s_size].s_sex = sex;
		cout << "请输入年龄：\n";
		cin >> age;
		if (cin)
			book->s_parray[book->s_size].s_age = age;
		cout << "请输入地址：\n";
		getline(cin, s);//接收缓冲区(可以用ignore但是我认为这里更简便）
		getline(cin, address);
		book->s_parray[book->s_size].s_address = address;
		cout << "请输入电话号码：\n";
		cin >> number;
		book->s_parray[book->s_size].s_number = number;
		cout << "添加成功！\n" << endl;
		book->s_size++;
	}
}
//展示所有联系人函数
void showall(Contactsbook * book){
	if (book->s_size == 0)
	{
		cout << "通讯录为空！\n";
	}
	else
	{
		for (int i = 0; i < book->s_size; i++)
		{
			cout << i + 1 << ",\n" << "姓名：" << book->s_parray[i].s_name << endl;
			cout << "性别：" << book->s_parray[i].s_sex << endl;
			cout << "年龄：" << book->s_parray[i].s_age << endl;
			cout << "地址：" << book->s_parray[i].s_address << endl;
			cout << "电话号码：" << book->s_parray[i].s_number << endl;
			cout << endl;
		}
	}
}
//搜索函数
void search(Contactsbook * book){
	string name;
	cout << "请输入要搜索的联系人姓名：\n";
	getline(cin, name);
	getline(cin, name);
	bool found = 0;
	for (int i = 0; i < book->s_size; i++)
	{
		if (name == book->s_parray[i].s_name)
		{
			cout << "找到联系人！\n";
			cout << i + 1 << ",\n" << "姓名：" << book->s_parray[i].s_name << endl;
			cout << "性别：" << book->s_parray[i].s_sex << endl;
			cout << "年龄：" << book->s_parray[i].s_age << endl;
			cout << "地址：" << book->s_parray[i].s_address << endl;
			cout << "电话号码：" << book->s_parray[i].s_number << endl;
			cout << endl;
			found = 1;
		}
	}
	if (found == 0)
	{
		cout << "没找到该联系人，请重试！\n";
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
	int ret = check_name(book, name);
	if (ret != -1)
	{
		cout << "找到联系人！\n";
		cout << "姓名：" << book->s_parray[ret].s_name << endl;
		cout << "性别：" << book->s_parray[ret].s_sex << endl;
		cout << "年龄：" << book->s_parray[ret].s_age << endl;
		cout << "地址：" << book->s_parray[ret].s_address << endl;
		cout << "电话号码：" << book->s_parray[ret].s_number << endl;
	flag0://误操作保护
		cout << "确定要删除吗？（1确认，0返回）\n";
		int ans;
		cin >> ans;
		if (ans == 1)
		{
			for (int i = ret; i < book->s_size; i++)
			{
				book->s_parray[i] = book->s_parray[i + 1];
			}
			cout << "删除成功！\n";
			book->s_size--;
		}
		else if (ans == 0)
		{
			cout << "删除取消！";
		}
		else
		{
			cout << "无效输入，请重试！\n";
			goto flag0;
		}
	}
	else
	{
		cout << "未找到该联系人，请重试！\n";
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
	cout << "请输入要修改的联系人编号：\n";
	int num;
	cin >> num;
	int ret = check_num(book, num);
	if (ret != -1)
	{
		cout << "请输入姓名：\n";
		getline(cin, name);//接收缓冲区
		getline(cin, name);
		book->s_parray[ret - 1].s_name = name;
		cout << "请输入性别：\n";
		getline(cin, sex);
		book->s_parray[ret - 1].s_sex = sex;
		cout << "请输入年龄：\n";
		cin >> age;
		book->s_parray[ret - 1].s_age = age;
		cout << "请输入地址：\n";
		getline(cin, s);
		getline(cin, address);
		book->s_parray[ret - 1].s_address = address;
		cout << "请输入电话号码：\n";
		cin >> number;
		book->s_parray[ret - 1].s_number = number;
		cout << "修改成功！\n";
	}
	else
	{
		cout << "未找到联系人，请重试！\n";
	}
}
void clr(Contactsbook * book){
	if (book->s_size == 0)
	{
		cout << "通讯录为空！";
	}
	else
	{
		int ans;
	flag1:
		cout << "是否确认清空通讯录？\n注意，一旦清空，无法恢复！\n(按1确认,按0返回)\n";
		cin >> ans;
		if (ans == 1)
		{
			book->s_size = 0;
			cout << "所有联系人已清空！\n";
		}
		else if (ans == 0)
		{
			cout << "取消清空操作！\n";
		}
		else
		{
			cout << "无效输入，请重试！\n";
			goto flag1;
		}
	}
}
//选项函数
void option(int x){
	switch (x){
	case 1:
		cout << "添加新联系人：\n";
		add(&book);//调用添加函数
		break;
	case 2:
		cout << "展示全部联系人：\n" << endl;
		showall(&book);
		break;
	case 3:
		cout << "搜索联系人：\n";
		search(&book);
		break;
	case 4:
		cout << "删除联系人：\n";
		dlt(&book);
		break;
	case 5:
		cout << "修改联系人：\n";
		revise(&book);
		break;
	case 6:
		clr(&book);
		break;
	default:
		cout << "无效输入，请重试！\n";
		break;
	}
}
//展示菜单
void showmenu(){
	cout << "通讯录\n"
		<< "1.添加联系人\n"
		<< "2.展示联系人\n"
		<< "3.搜索联系人\n"
		<< "4.删除联系人\n"
		<< "5.修改联系人\n"
		<< "6.清空联系人\n"
		<< "7.退出\n";
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
			cout << "感谢使用，再见！\n";
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
汉化：2025年2月12日
*/
