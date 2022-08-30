#include<iostream>
#include<string.h>
#define MAX 30
using namespace std;
int n;
class students
{
	protected:
		char name[MAX];
		int enrolyr;
		int rollno;
};
class arts:protected students
{
	protected:
		float english;
		float history;
		float total;
	public:	
		void getdata()
		{
		cout<<"Enter name of the student:";
		cin>>name;
		cout<<"Enter the year of enrollment:";
		cin>>enrolyr;
		cout<<"Enter the roll number:";
		cin>>rollno;
		cout<<"Enter marks scored in English:";
		cin>>english;
		cout<<"Enter the marks scored in History:";
		cin>>history;
		total=english+history;	
		}
		void showdata()
		{
		cout<<"Name: "<<name<<endl;
		cout<<"Year of Enrollment: "<<enrolyr<<endl;
		cout<<"Stream: Arts"<<endl;
		cout<<"Roll Number: "<<rollno<<endl;
		cout<<"English Marks: "<<english<<endl;
		cout<<"History Marks: "<<history<<endl;
		cout<<"Total Marks: "<<total<<"/200"<<endl;	
		}
		int studentsearch(int inputrollno)
		{
			if(inputrollno==rollno)
			{
			showdata();	
			return 1;
			}
			else
			return 0;
		}	
};

class engineering:protected students
{
	protected:
		float maths;
		float workshop;
		float total;
};

class mech: protected engineering
{
	protected:
		float msol;
		float eg;
	public:	
		void getdata()
		{
		cout<<"Enter name of the student:";
		cin>>name;
		cout<<"Enter the year of enrollment:";
		cin>>enrolyr;
		cout<<"Enter roll number:";
		cin>>rollno;
		cout<<"Enter the marks scored in Maths:";
		cin>>maths;
		cout<<"Enter the marks scored in Workshop:";
		cin>>workshop;
		cout<<"Enter the marks scored in MSOL:";
		cin>>msol;
		cout<<"Enter the marks scored in Engineering Graphics:";
		cin>>eg;
		total=maths+workshop+msol+eg;
		}
		
		void showdata()
		{
		cout<<"Name: "<<name<<endl;
		cout<<"Year of Enrollment: "<<enrolyr<<endl;
		cout<<"Stream: Mechanical Engineering"<<endl;
		cout<<"Roll Number: "<<rollno<<endl;
		cout<<"Maths Marks: "<<maths<<endl;
		cout<<"Workshop Marks: "<<workshop<<endl;
		cout<<"MSOL Marks: "<<msol<<endl;
		cout<<"Engineering Graphics Marks: "<<eg<<endl;
		cout<<"Total Marks: "<<total<<"/400"<<endl;
		}
		
		int studentsearch(int inputrollno)
		{
			if(inputrollno==rollno)
			{
			showdata();	
			return 1;
			}
			else
			return 0;
		}

};

class comp: protected engineering
{
	protected:
		float oops;
		float ds;
	public:
		void getdata()
		{
		cout<<"Enter name of the student:";
		cin>>name;
		cout<<"Enter the year of enrollment:";
		cin>>enrolyr;
		cout<<"Enter the roll number:";
		cin>>rollno;
		cout<<"Enter the marks scored in Maths:";
		cin>>maths;
		cout<<"Enter the marks scored in Workshop:";
		cin>>workshop;
		cout<<"Enter the marks scored in OOPS:";
		cin>>oops;
		cout<<"Enter the marks scored in DS:";
		cin>>ds;
		total=maths+workshop+oops+ds;		
		}
		
		void showdata()
		{
		cout<<"Name: "<<name<<endl;
		cout<<"Year of Enrollment: "<<enrolyr<<endl;
		cout<<"Stream: Computer Engineering"<<endl;
		cout<<"Roll Number: "<<rollno<<endl;
		cout<<"Maths Marks: "<<maths<<endl;
		cout<<"Workshop Marks: "<<workshop<<endl;
		cout<<"OOPS Marks: "<<oops<<endl;
		cout<<"DS Marks: "<<ds<<endl;
		cout<<"Total Marks: "<<total<<"/400"<<endl;	
		}
		
		int studentsearch(int inputrollno)
		{
			if(inputrollno==rollno)
			{
			showdata();	
			return 1;
			}
			else
			return 0;
		}
};

class etc: protected engineering
{
	protected:
		float cd;
		float network;
	public:
		void getdata()
		{
		cout<<"Enter name of the student:";
		cin>>name;
		cout<<"Enter the year of enrollment:";
		cin>>enrolyr;
		cout<<"Enter the roll number:";
		cin>>rollno;
		cout<<"Enter the marks scored in Maths:";
		cin>>maths;
		cout<<"Enter the marks scored in Workshop:";
		cin>>workshop;
		cout<<"Enter the marks scored in Circuit Design:";
		cin>>cd;
		cout<<"Enter the marks scored in Networking:";
		cin>>network;
		total=maths+workshop+cd+network;		
		}
		void showdata()
		{
		cout<<"Name: "<<name<<endl;
		cout<<"Year of Enrollment: "<<enrolyr<<endl;
		cout<<"Stream: ETC Engineering"<<endl;
		cout<<"Roll Number: "<<rollno<<endl;
		cout<<"Maths Marks: "<<maths<<endl;
		cout<<"Workshop Marks: "<<workshop<<endl;
		cout<<"Circuit Design Marks: "<<cd<<endl;
		cout<<"Networking Marks: "<<network<<endl;
		cout<<"Total Marks: "<<total<<"/400"<<endl;	
		}
		int studentsearch(int inputrollno)
		{
			if(inputrollno==rollno)
			{
			showdata();	
			return 1;
			}
			else
			return 0;
		}	
};

class it: protected engineering
{
	protected:
		float python;
		float ca;
	public:
		void getdata()
		{
		cout<<"Enter name of the student:";
		cin>>name;
		cout<<"Enter the year of enrollment:";
		cin>>enrolyr;
		cout<<"Enter the roll number:";
		cin>>rollno;
		cout<<"Enter the marks scored in Maths:";
		cin>>maths;
		cout<<"Enter the marks scored in Workshop:";
		cin>>workshop;
		cout<<"Enter the marks scored in Python:";
		cin>>python;
		cout<<"Enter the marks scored in Computer Architecture:";
		cin>>ca;
		total=maths+workshop+python+ca;		
		}
		void showdata()
		{
		cout<<"Name: "<<name<<endl;
		cout<<"Year of Enrollment: "<<enrolyr<<endl;
		cout<<"Stream: IT Engineering"<<endl;
		cout<<"Roll Number: "<<rollno<<endl;
		cout<<"Maths Marks: "<<maths<<endl;
		cout<<"Workshop Marks: "<<workshop<<endl;
		cout<<"Python Marks: "<<python<<endl;
		cout<<"Computer Architecture Marks: "<<ca<<endl;
		cout<<"Total Marks: "<<total<<"/400"<<endl;	
		}
		int studentsearch(int inputrollno)
		{
			if(inputrollno==rollno)
			{
			showdata();	
			return 1;
			}
			else
			return 0;
		}
};

class medical: protected students
{
	protected:
		float physiology;
		float pathology;
		float total;
	public: 
	void getdata()
		{
		cout<<"Enter name of the student:";
		cin>>name;
		cout<<"Enter the year of enrollment:";
		cin>>enrolyr;
		cout<<"Enter the roll number:";
		cin>>rollno;
		cout<<"Enter the marks scored in Physiology:";
		cin>>physiology;
		cout<<"Enter the marks scored in Pathology:";
		cin>>pathology;
		total=physiology+pathology;		
		}
	void showdata()
		{
		cout<<"Name: "<<name<<endl;
		cout<<"Year of Enrollment: "<<enrolyr<<endl;
		cout<<"Stream: Medical"<<endl;
		cout<<"Roll Number: "<<rollno<<endl;
		cout<<"Physiology Marks: "<<physiology<<endl;
		cout<<"Pathology Marks: "<<pathology<<endl;
		cout<<"Total Marks: "<<total<<"/200"<<endl;	
		}
		int studentsearch(int inputrollno)
		{
			if(inputrollno==rollno)
			{
			showdata();	
			return 1;
			}
			else
			return 0;
		}
};
arts *a;
mech *m;
comp *c;
etc *e;
it *i;
medical *md;
int main()
{
int count=0;
int n=0;
int k;
int artsn=0,mechn=0,compn=0,etcn=0,itn=0,medn=0;
int choice;
int searchflag=0;
int inputrollno;
int streamchoice,engchoice;
int outputstreamchoice,outputengchoice;
//creation of dynamic array of objects.
	do{
	cout<<"\n\t|MENU|\n";
	cout<<"1.Enter student details"<<endl;
	cout<<"2.Display student details"<<endl;	
	cout<<"3.Search a student by roll number"<<endl;
	cout<<"4.Display total number of students"<<endl;
	cout<<"5.Exit"<<endl;
	cout<<"Enter your choice:";
	cin>>choice;
		switch(choice){
		
		case 1:
		cout<<"\n\t|INPUT DETAILS|";
		cout<<"\n1. Enter arts details"<<endl;
		cout<<"2. Enter engineering details"<<endl;
		cout<<"3. Enter medical details"<<endl;
		cout<<"Enter your choice:";
		cin>>streamchoice;
			switch(streamchoice){
			case 1:cout<<"Enter the number of students in the arts stream:";
		cin>>artsn;
		count=count+artsn;
		a = new arts[artsn];		
			goto inputarts;break;
			case 2:
					cout<<"\n\t|INPUT ENGINEERING DETAILS|";
					cout<<"\n1. Enter mechanical details"<<endl;
					cout<<"2. Enter computer details"<<endl;
				   cout<<"3. Enter ETC details"<<endl;
				   cout<<"4. Enter IT details"<<endl;
				   cout<<"Enter your choice:";
				   cin>>engchoice;
				   switch(engchoice){
				   case 1:cout<<"Enter the number of students in mechanical stream:";
					cin>>mechn;
					count+=mechn;
					m = new mech[mechn];
				   goto inputmechanical;break;
				   case 2:cout<<"Enter the number of students in computer stream:";
					cin>>compn;
					count+=compn;
					c = new comp[compn];
				   goto inputcomputer; break;
				   case 3:cout<<"Enter the number of students in ETC stream:";
					cin>>etcn;
					count+=etcn;
					e = new etc[etcn];
				   goto inputetc;break;
				   case 4:cout<<"Enter the number of students in IT stream:";
					cin>>itn;
					count+=itn;
					i = new it[itn];
				   goto inputit;break;	
				   }break;
			case 3:cout<<"Enter the number of students in medical stream:";
				cin>>medn;
				count+=medn;
				md = new medical[medn];
			goto inputmedical;break;
				}			
		inputarts:
		{	
		cout<<"\n\t|ARTS STUDENTS|\n";
			for(k=0;k<artsn;k++)
			{
			cout<<"\n";
			a[k].getdata();	
			}
		goto inputend;	
		}
		inputmechanical:
		{
		cout<<"\n\t|MECHANICAL STUDENTS|\n";
		for(k=0;k<mechn;k++)
			{
			cout<<"\n";
			m[k].getdata();	
			}
		goto inputend;			
		}
		inputcomputer:
		{
		cout<<"\n\t|COMPUTER STUDENTS|\n";
		for(k=0;k<compn;k++)
			{
			cout<<"\n";
			c[k].getdata();	
			}
		goto inputend;
		}
		inputetc:
		{	
		cout<<"\n\t|ETC STUDENTS|\n";	
		for(k=0;k<etcn;k++)
			{
			cout<<"\n";
			e[k].getdata();	
			}
		goto inputend;
		}
		inputit:
		{	
		cout<<"\n\t|IT STUDENTS|\n";
		for(k=0;k<itn;k++)
			{
			cout<<"\n";
			i[k].getdata();	
			}
		goto inputend;
		}
		inputmedical:
		{
		cout<<"\n\t|MEDICAL STUDENTS|\n";			
		for(k=0;k<medn;k++)
			{
			cout<<"\n";
			md[k].getdata();	
			}
		goto inputend;
		}
		inputend:
		break;
		
		case 2:cout<<"\n\t|DISPLAY DETAILS|";
			cout<<"\n1.Display arts details"<<endl;
			cout<<"2.Display engineering details"<<endl;
			cout<<"3.Display medical details"<<endl;
			cout<<"Enter your choice:";
			cin>>outputstreamchoice;
				switch(outputstreamchoice){
				case 1:goto outputarts;break;
				case 2:cout<<"\n\t|DISPLAY ENGINEERING DETAILS|"<<endl;
						cout<<"1.Display mechanical details"<<endl;
						cout<<"2.Display computer details"<<endl;
						cout<<"3.Display ETC details"<<endl;
						cout<<"4.Display IT details"<<endl;
						cout<<"Enter your choice:";
						cin>>outputengchoice;
							switch(outputengchoice)
							{
							case 1:goto outputmech;break;
							case 2:goto outputcomp;break;
							case 3:goto outputetc;break;
							case 4:goto outputit;break;						
							}break;
				case 3:goto outputmedical;break;
				}break;		
		outputarts:	
			{
			cout<<"\n|ARTS STUDENTS|\n";
			for(k=0;k<artsn;k++)
			{
			cout<<"\n";
			a[k].showdata();	
			}
			goto outputend;
			}
		outputmech:
		{	
		cout<<"\n|MECHANICAL STUDENTS|\n";
		for(k=0;k<mechn;k++)
			{
			cout<<"\n";
			m[k].showdata();	
			}
			goto outputend;
		}
		outputcomp:
		{
		cout<<"\n|COMPUTER STUDENTS|\n";
		for(k=0;k<compn;k++)
			{
			cout<<"\n";
			c[k].showdata();	
			}
		goto outputend;
		}
		outputetc:
		{
		cout<<"\n|ETC STUDENTS|\n";	
		for(k=0;k<etcn;k++)
			{
			cout<<"\n";
			e[k].showdata();	
			}
		goto outputend;
		}
		outputit:
		{
		cout<<"\n|IT STUDENTS|\n";
		for(k=0;k<itn;k++)
			{
			cout<<"\n";
			i[k].showdata();	
			}
		goto outputend;
		}
		outputmedical:
		{
		cout<<"\n|MEDICAL STUDENTS|\n";			
		for(k=0;k<medn;k++)
			{
			cout<<"\n";
			md[k].showdata();	
			}	
		goto outputend;
		}
		outputend:
		break;
		case 3:"\n|STUDENT SEARCH|";
		cout<<"Enter the roll number you want to search:";
		cin>>inputrollno;
		searchflag=0; //reset searchflag
		cout<<"\n";
			for(k=0;k<artsn;k++)
			{
			searchflag=a[k].studentsearch(inputrollno);
			if(searchflag==1)
			goto flagchecker;
			}
			for(k=0;k<mechn;k++)
			{
			searchflag=m[k].studentsearch(inputrollno);
			if(searchflag==1)
			goto flagchecker;
			}
			for(k=0;k<compn;k++)
			{
			searchflag=c[k].studentsearch(inputrollno);
			if(searchflag==1)
			goto flagchecker;	
			}
			for(k=0;k<etcn;k++)
			{
			searchflag=e[k].studentsearch(inputrollno);	
			if(searchflag==1)
			goto flagchecker;
			}	
			for(k=0;k<itn;k++)
			{
			searchflag=i[k].studentsearch(inputrollno);	
			if(searchflag==1)
			goto flagchecker;
			}
			for(k=0;k<medn;k++)
			{
			searchflag=md[k].studentsearch(inputrollno);	
			if(searchflag==1)
			goto flagchecker;
			}
			flagchecker:
			{
			if(searchflag==0)
			cout<<"Student not present in the database."<<endl;
			}
		break;
		case 4:
		cout<<"Total number of students in the database: "<<count<<endl;
		break;
		case 5:
		exit(1);
		break;	
		default:cout<<"Please enter a valid choice!";
		}
	}while(choice!=5);	
	return 0;
}
