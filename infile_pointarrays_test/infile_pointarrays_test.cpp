#include"pch.h"
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<string>

using namespace std;

class Users
{
private:
	string name;
	int user_id;
	string password;
public:
	//Users();
	//~Users();
	void setUser(string nm, int id, string psw);
	void display();
	//void registe();
};

int randomID()
{
	int r;
	srand(int(time(0)));
	r = rand() % 1000000 + 1000000;
	return r;
};

int main()
{
	string nm;
	int id;
	string psw;
	int n = 0;

	ofstream outfile("infile_pointarrays_test", ios::app);

	Users *p_user = new Users[10];

	cout << "Please Complete Information:" << endl;
	cout << "Enter Your Name:\nEnd With 'Enter'" << endl;
	while (!getline(cin, nm))
		//while(!(cin>>nm))
		cout << "NAME ERROR" << endl;
	id = randomID();
	cout << "This is Your ID:\n" << id << "\n" << "PLEASE TAKE DOWN" << endl;
	cout << "Set Your PassWord:\n" << endl;
	//while (!getline(cin, psw))
	while (!(cin >> psw))
		cout << "PSW ERROR" << endl;
	outfile << nm << "\n" << id << "\n" << psw << "\n";
	cout << "Write Correct" << endl;


	outfile.close();

	ifstream infile("infile_pointarrays_test", ios::in);

	if (!infile)
		cout << "OPEN ERROR" << endl;

	//long filelen = infile.tellg();//获取文件长度
	//infile.seekg(0,ios::beg);

	long filelen;
	infile.seekg(0,ios::end);
	filelen = infile.tellg();
	infile.seekg(0, ios::beg);


	//while (!infile.eof())
	while(filelen!=infile.tellg()&&n<10)
	{
		getline(infile, nm);//?
		//getline(infile, id);
		infile >> id;//?
		//getline(infile, psw);
		infile >> psw;//?
		cout << "infile succeed" << endl;
		p_user[n++].setUser(nm, id, psw);
		cout << "setuser succeed" << endl;
		nm = "blank";
		id = 111;
		psw = "blank";
	};
	infile.seekg(0, ios::end);

	for (int i = 0; i <= 5; i++)
		p_user[i].display();

	cout << "READ SUCCESS" << endl;

	delete[]p_user;

	infile.close();

	return 0;

};

void Users::setUser(string nm, int id, string psw)
{
	name = nm;
	user_id = id;
	password = psw;

};
void Users::display()
{
	cout << name << "\n" << user_id << "\n" << password << "\n";
};