//Employee Salary Management Database System

#include<fstream.h>
#include<dos.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<iomanip.h>
#include<graphics.h>

	 class group
	 {
	 private:
		struct person
		{
		 char flag;
		 char empcode[5];
		 char name[60];
		 int age;
		 float sal;
		 int day;
		 int month;
		 int year;
		 }p;
		 fstream file;
		 public:
	group();

	void addrec();
	void listrec();
	void modirec();
	void delrec();
	void exit();
	};
  void main()
  {
	 char choice,v;
	 group g;
	 do
	 {
	 clrscr();
	 struct dosdate_t d;
	_dos_getdate(&d);

	 gotoxy(12,5);
	 textcolor(6);
		cprintf("Today's date:");
		printf("%d",d.day);
		cout<<"/";
		printf("%d",d.month);
		cout<<"/";
		cout<<d.year;
		gotoxy(12,7);
	 cout<<"Shri Sadashiv Sampus Puri";
	 gotoxy(12,10);
	 cout<<"1.Add record";
	 gotoxy(12,12);
	 cout<<"2.List Record";
	 gotoxy(12,14);
	 cout<<"3.Modify record";
	 gotoxy(12,16);
	 cout<<"4.Delete record";
	 gotoxy(12,18);
	 cout<<"0.Exit"<<endl;
	 gotoxy(12,20);
	 cout<<"Your choice"<<"  ";
	 cin>>choice;
		clrscr();

	 switch(choice)
	 {
	 case '1':
	 g.addrec();
	 break;
	 case'2':
	 g.listrec();
	 break;

	 case'3':
	 g.modirec();
	 break;

	 case'4':
	 g.delrec();
	 break;

	 case'0':
	 g.exit();
	 exit(1);

	 }
		 }
		 while(choice!=0);
	 }

void group::group()
	 {
file.open("Emp.dat",ios::binary|ios::in|ios::out);
		p.flag=' ';
		if(!file)
		{
		cout<<endl<<"File cannot be open";
		exit();
		}
      }
void group::addrec()
	 {
		char ch;
		file.seekp(0,ios::end);
	struct dosdate_t d;
	 _dos_getdate(&d);
		p.day=d.day;
		p.month=d.month;
		p.year=d.year;
cout<<"Make sure that no employee has the same code \n "<<endl;
	do
{cout<<endl<<"Enter employee  code, name, age & salary:"<<endl<<endl;
cout<<"OR"<<endl<<endl;
cout<<"To return to the Main menu press'm' key else press'a':\n";

	 cin>>ch;
	 if(ch=='m'||ch=='M')
	  main();
	 cout<<"\nemployee code:";
	 cin>>p.empcode;
	 cout<<"\nemployee name:";
	 cin>>p.name;
	 cout<<"\nage:";
	 cin>>p.age;
	 cout<<"\nsalary:";
	 cin>>p.sal;
	 p.flag=' ';
	 file.write((char*)&p,sizeof(p));
	 cout<<"Add another record ?(y/n) :";
	 cin>>ch;
	 }
	 while(ch=='y'||ch=='Y');
		 }

void group::listrec()
	 {
		int j=0,a;
		file.seekg(0,ios::beg);
cout<<"List of records present are as under"<<endl<<endl;
cout<<"          "<<"|CODE|"<<"            "<<"|NAME|"<<"       "<<"  |AGE|"<<"        "<<"|SALARY|"<<"       "<<"|DATED|"<<"  "<<endl;
		 
		while(file.read((char*)&p,sizeof(p)))
	   {
		if(p.flag!='*')

		cout<<endl<<"Record "<<j++<<""<<setw(6)<<p.empcode<<setw(20)<<p.name<<setw(12)<<p.age<<setw(16)<<p.sal<<setw(7)<<" "<<p.day<<"/"<<p.month<<"/"<<p.year<<endl;
	   }
file.clear();

if(j==0)
{
 gotoxy(10,10);
 cout<<"No record exit";
 gotoxy(10,11);
 cout<<"Press any key...";
 getch();
}
else
{
 cout<<endl<<"Press any key...";
 getch();
}
}
void group::modirec()
{
char code[5];
int count=0;
long int pos;
cout<<"Enter employee code whose record is to be modified :";
cin>>code;
file.seekg(0,ios::beg);
while(file.read((char*)&p,sizeof(p)))
{
 if(strcmp(p.empcode,code)==0)
 {
 cout<<endl<<"Enter new record:"<<endl;
 cout<<endl<<"Enter employee name:";
 cin>>p.name;
 cout<<"\nEnter employee age & salary:";
 cin>>p.age>>p.sal;
 struct dosdate_t d;
 _dos_getdate(&d);
 p.day=d.day;
 p.month=d.month;
 p.year=d.year;
 p.flag=' ';
 pos=count*sizeof(p);
 file.seekp(pos,ios::beg);
 file.write((char*)&p,sizeof(p));
 return;
 }
 count++;
}
cout<<endl<<"No employee in file with code= "<<code;
getch();
file.clear();
}
void group::delrec()
	{
	char code[5];
	long int pos;
	int count=0;
	cout<<"Enter employee code to be deleted :";
	cin>>code;
	file.seekg(0,ios::beg);
	while(file.read((char*)&p,sizeof(p)))
	{
	 if (strcmp(p.empcode,code)==0)
	 {
	 p.flag='*';
	 pos=count*sizeof(p);
	 file.seekp(pos,ios::beg);
	 file.write((char*)&p,sizeof(p));
	 return;
	 }
	 count++;
	 }
	 cout<<endl<<"No employee in file with code="<<code;
	 cout<<endl<<"Press any key...";
	 getch();
	 file.clear();
	 }
void group::exit()
 {
 file.close();
}