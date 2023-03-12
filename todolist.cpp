#include <iostream>
#include <string>
#include <list>

using namespace std;

class todo
{
private:
	list<string> todo_list;
	list<string>::iterator a = todo_list.begin();
public:
	void add_todo();
	void del_todo();
	void change_todo();
	
	void view_todo();
};




int main()
{
	todo my_todo;
	
	int choice;
	
	cout<<"[todo리스트 프로그램]"<<endl;
	cout<<"|추가: 1|삭제: 2|수정: 3|확인: 4|종료: 5|"<<endl;
	
	while(1)
	{
		cout<<"입력: "; cin>>choice;
		
		
		switch(choice)
		{
			case 1:
				my_todo.add_todo();
				break;
			case 2:
				my_todo.del_todo();
				break;
			case 3:
				my_todo.change_todo();
				break;
			case 4:
				my_todo.view_todo();
				break;
			case 5:
				cout<<"프로그램을 종료합니다."<<endl;
				return 0;
			default:
				cout<<"잘못된 입력."<<endl;
				cout<<">"<<endl;
		}
	}
	
	return 0;
	
}

void todo::add_todo()
{
	string input;
	cout<<"추가하려는 하는 할 일 입력."<<endl;
	cout<<"입력: "; cin>>input;
	todo_list.push_back(input);
	
	cout<<"할 일 추가완료."<<endl;
	cout<<">"<<endl;
	
}

void todo::del_todo()
{
	if (todo_list.empty())
	{
		cout<<"리스트가 비어있습니다."<<endl;
		return;
	}
	
	int del_todo_num;
	a = todo_list.begin();
	
	cout<<"삭제할 할 일 번호 입력."<<endl;
	cout<<"입력: "; cin>>del_todo_num;
	
	for (int i=0; i<del_todo_num - 1; i++) 
	{
		a++;
	}
	
	todo_list.erase(a);
	
	cout<<"할 일 삭제완료."<<endl;
	cout<<">"<<endl;
}

void todo::change_todo()
{
	int chng_todo_num;
	a = todo_list.begin();
	
	cout<<"수정할 할 일 번호 입력."<<endl;
	cout<<"입력: "; cin>>chng_todo_num;
	
	string chng_todo;
	cout<<"할 일 입력."<<endl;
	cout<<"입력: "; cin>>chng_todo;
	
	for (int i=0; i<chng_todo_num - 1; i++) 
	{
		a++;
	}
	
	*a=chng_todo;
	
	cout<<"할 일 수정완료."<<endl;
	cout<<">"<<endl;
}

void todo::view_todo()
{
	int i=1;
	
	for(a=todo_list.begin();  a!=todo_list.end(); a++)
	{
		cout<<i<<". "<<*a<<endl;
		i++;
	}
	cout<<">"<<endl;
}