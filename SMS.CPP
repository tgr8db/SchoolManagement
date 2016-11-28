#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <fstream.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

const char put = 219;

//***************************************************************************
//Menu Function Declarations...                                             #
//***************************************************************************

	void openingCredits();
	void passwordMenu();
	void mainMenu();
	void search();
	void report();

	    //*******************************************************************
	    // Sub-menu declarations...                                         #
	    //*******************************************************************

		   void newUser();
		   void userCheck();
		   void forgotPassword();

	   //********************************************************************
	   //All Tool Declarations...                                           #
	   //********************************************************************

		   void borderCreator();
		   void loadingSequence();
		   void delay(int x);
		   void projectLogo();

	   //********************************************************************
	   //Other declarations...                                              #
	   //********************************************************************
        char securityn[10] = "underdog";
		char username [12] = "projeKt";
		char password [9]  = "random21";
		class studentDetails
		{
			struct students {
				char name[30], fName[30], mName[30];
				int  grno;
				char theClass[6];
				struct address
				{
					int building, block, road, zip, pobox;
					char flat[6];
				}a;
				struct phone
				{
				long home, one, two;
				}p;

				struct marks {
					float m1, m2, m3, m4, m5, avg;
				}m;
			 }sn;

		public: void search();
				  void searchN(char name[]);
				  void searchG(int gno);
				void report();
				  void studentReport(int gno);
				  void classReport(char aClass[]);
				void newAdmission();
				void editDetail(int gno);
				void giveTC(int gno);
				void displayDetails(int gno);
				void inputMarks();

		}sD;


//Main Program...
void main()
{
	openingCredits();
	passwordMenu();
}

//***************************************************************************
// All the definitions of all the helping functions...                      #
//***************************************************************************

void projectLogo()
{
	 gotoxy(13,9);
	cout << " /¯¯(\___\   /¯¯/\_/\¯¯\   /¯¯(\___\    ";
	 gotoxy(13,10);
	cout << " (¯¯¯\)___)  \__\    /__/  (¯¯¯\)___)   ";

}

void openingCredits()
{
	loadingSequence();

	 gotoxy(2, 2);
	cout << "For The World" << endl;
	 gotoxy(0,0);
	projectLogo();
	borderCreator();
	 gotoxy(19, 11);
	cout << "The School Managment System....";
	 gotoxy(24, 16);
	cout << "Done by: ";
	 gotoxy(30, 18);
	cout << "LEADER       :  Aman Dwivedi";
	 gotoxy(30, 19);
	cout << "Member One   :  Ashley Anneri";
	 gotoxy(30, 20);
	cout << "Member Two   :  Arun B. Anilkumar";
	 gotoxy(30, 21);
	cout << "Member Three :  Alwin Sevi";

	delay(1000);
	delay(1000);
	loadingSequence();
}
//***************************************************************************
// Menu definitions...                                                      #
//***************************************************************************
void passwordMenu()
{
		char option;
		 gotoxy(18, 15);
		cout << "(If no , you will be required to contact the programmer...)";
		 gotoxy(20, 10);
		cout << "Do you have the account (y/n) : ";
		  cin >> option;

		loadingSequence();

			switch (option)
			{
				 case 'y': {userCheck(); break;}
				 case 'n': {exit(1);}
				 default : { gotoxy(10,15);
							cout << "Unexpected error...";
							 gotoxy(10,16);
							cout << "Restarting...";
							 delay(1000);
							loadingSequence();
							passwordMenu();
							break;
						  }
			}
}
void mainMenu()
{
	 gotoxy(4, 4);
	cout << " Welcome ";
	puts(username);
	 gotoxy(4, 5);
	cout << "This the main menu of the School Management System...";
	int choice;
	 gotoxy(25, 8);
	cout << "1. New Admission.";
	 gotoxy(25, 9);
	cout << "2. Search and Display.";
	 gotoxy(25, 10);
	cout << "3. Edit Student Data.";
	 gotoxy(25, 11);
	cout << "4. Give TC.";
	 gotoxy(25, 12);
	cout << "5. Report Manager.";
	 gotoxy(25, 13);
	cout << "6. LogOut ";
	 gotoxy(25, 14);
	cout << "7. EXIT ";
	 gotoxy(30, 18);
	cout << "Enter your choice : ";
	cin >> choice;
	loadingSequence();
	delay(100);

	switch (choice) {
	case 1: {sD.newAdmission(); break;}
	case 2: {sD.search();       break;}
	case 3: {int gno;
				 gotoxy(15,15);
				cout << "Enter the GR. no. of the student : ";
				 cin>>gno;
				 clrscr();
			  loadingSequence();
			  sD.editDetail(gno);
										 break;}
	case 4: {int gno;
				 gotoxy(15,15);
				cout << "Enter the GR. no. of the student : ";
				 cin>>gno;
				 clrscr();
			  loadingSequence();
			  sD.giveTC(gno);     break;}
	case 5: {sD.report();       break;}
	case 6: {passwordMenu();    break;}
	case 7: exit(1);
	default:{ cout << "There was some unexpected error ... ";
			  passwordMenu();
	}
	}


}
//***************************************************************************
// studentDetails_Search-menu definitions...                                #
//***************************************************************************
void studentDetails::search(){
	char choice;
	 gotoxy(4,4);
	cout<<"1. Search with name...";
	 gotoxy(4,5);
	cout<<"2. Search with GR no.   ";
	 gotoxy(4,6);
	cout<<"Press any other key to go back to the mainMenu...";
	 gotoxy(4,7);
	cout<<"Enter your choice : ";
	cin>>choice;

	loadingSequence();

	  switch(choice) {
		  case '1' :{char name[30];
					  gotoxy(8,8);
					 cout<<"Enter the name of the Student : ";
					 gets(name);
							loadingSequence();
					 searchN(name);
					 break;
					}
		  case '2' :{int gno;
					  gotoxy(8,8);
					 cout<<"Enter the G.R.No. of the Student : ";
					 cin>>gno;
							loadingSequence();
					 searchG(gno);
					}
		  default  :{
						loadingSequence();
						mainMenu();
					 }
			 }
 }
 void studentDetails::searchN(char name[]){
	 ifstream thefile("stuDet.dat",ios::in|ios::binary);
	 int found=1;
	  while(!thefile.eof()) {
		  thefile.read((char*)&sn,sizeof(sn));
		  if(strcmp(sn.name,name)==0) {
			displayDetails(sn.grno);
				return;
		  }
		  else found=0;
	  }thefile.close();
	if(found==0) {
	  loadingSequence();
		gotoxy(8,8);
	  cout << "No such name was found in the directory...";
		delay(750);
	  loadingSequence();
	  search();
	 }
 }
 void studentDetails::searchG(int gno){
	 ifstream thefile ("stuDet.dat",ios::binary|ios::in);
	  int found=1;
	  while (!thefile.eof()) {

		thefile.read((char *)&sn,sizeof(sn));
		  if(sn.grno==gno) {
			  displayDetails(gno);
			  return;
		  }
		  else found=0;
	  }thefile.close();
	if(found==0) {
	  loadingSequence();
		gotoxy(8,8);
	  cout << "No such GRno. was found in the directory...";
		delay(750);
	  loadingSequence();
	  search();
	 }
 }
//***************************************************************************
// Password_Sub-menu definitions...                                         #
//***************************************************************************
void userCheck()
{  char erch;
	do {
		 int flagu = 0, flagp = 0;
		 char usn[12], pwd[8];
		  gotoxy(10, 5);
		cout << "Welcome back !!!";
		  gotoxy(29,10);
		cout << "Username : ";
		  gets(usn);
		  gotoxy(29,11);
		cout << "Password : ";
			for(int i=0;i < 8;i++ )
			{
			  pwd[i] = getch();
			  cout << "*";
			}
			delay(200);

		if (strcmpi(username, usn) == 0)
			flagu = 1;
		if (strcmp(password, pwd) == 0)
			flagp = 1;

	if (flagu == 1 && flagp == 1) {
			 gotoxy(29,12);
			cout << "Access granted... ";
			 delay(100);
			loadingSequence();
			 mainMenu();
		}
	else {
			 gotoxy(10, 18);
			cout << "The input details are wrong.....";
			 gotoxy(10, 19);
			cout << "Press 't/T' to try again ...";
			 gotoxy(10, 20);
			cout << "Press 'f/F' if you forgot the password . (f/F)... ";
			 gotoxy(10, 21);
			cout << "Press any key (except t,T,f,F) to go back to previous menu...";
			 erch = getch();
			 loadingSequence();

			if (erch == 'f' || erch == 'F')
				forgotPassword();
			else if (erch=='t'||erch=='T');
			else passwordMenu();
		}
	 } while (erch=='t'||erch=='T');
}
void forgotPassword()
	 {
		char ans[10];
		 gotoxy(29, 10);
		cout<<"Enter the security name to proceed...";
		 gotoxy(29, 11);
		gets(ans);
		 loadingSequence();

		if (strcmp(securityn, ans) == 0) {
			delay(100);
			mainMenu();
		}
		else {
			cout<<"Wrong Security answer... ";
			 delay(100);
			loadingSequence();
			passwordMenu();
		}
	}

//***************************************************************************
// studentDetails_Other definitions...                                      #
//***************************************************************************

void studentDetails::report() {

		char choice;
		 gotoxy(4,4);
		cout<<"1. Student Report ";
		 gotoxy(4,5);
		cout<<"2. Class Report   ";
		 gotoxy(4,6);
		cout<<"Press any other key to go back to the mainMenu...";
		 gotoxy(4,7);
		cout<<"Enter your choice : ";
		cin>>choice;

		loadingSequence();

		  switch(choice) {
			  case '1' :{ int gno;
						   gotoxy(8,8);
						  cout<<"Enter the G.R.No. of the Student : ";
						  cin>>gno;
                          loadingSequence();
						  studentReport(gno);
						  break;
						}
			  case '2' :{ char aClass[6];
						   gotoxy(8,8);
						  cout<<"Enter the Class with Section : ";
						  gets(aClass);
                          loadingSequence();
						  classReport(aClass);
						  break;
						}
			  default  :{
						  loadingSequence();
						  mainMenu();
						}
				 }
	}
void studentDetails::studentReport(int gno){

	ifstream thefile ("stuDet.dat",ios::binary|ios::in);
		while(!thefile.eof()) {
			thefile.read((char *)&sn,sizeof(sn));

			if(sn.grno==gno) {
				 gotoxy(4,3);
				cout << " Student's Name : " << sn.name ;
				 gotoxy(4,4);
				cout << " Father's name  : " << sn.fName;
				 gotoxy(4,5);
				cout << " Mother's name  : " << sn.mName;
				 gotoxy(4,7);
				cout << " Division & Section  : " << sn.theClass;
				 gotoxy(8,9);
				cout << " Physics           : "<<sn.m.m1;
				 gotoxy(8,11);
				cout << " Chemistry         : "<<sn.m.m2;
				 gotoxy(8,13);
				cout << " Mathematics       : "<<sn.m.m3;
				 gotoxy(8,15);
				cout << " Computer Science  : "<<sn.m.m4;
				 gotoxy(8,17);
				cout << " English           : "<<sn.m.m5;
				 gotoxy(8,19);
				cout << "Average Mark : " <<sn.m.avg;
			}
		}thefile.close();
		gotoxy(3,23);
		cout << "Press any key to go back to the previous menu...";
		getch();
		loadingSequence();
		report();
	}
void studentDetails::classReport(char aClass[]){
	 gotoxy(3,3);
	cout<<"Class report of class "<<aClass<<" : ";
	 gotoxy(8,6);
	cout<<"Roll no.";
	 gotoxy(14,6);
	cout<<"Name";
	 gotoxy(56,6);
	cout<<"Percentage";
	int i = 8;
	ifstream thefile ("stuDet.dat",ios::binary|ios::in);
		while(!thefile.eof()) {
			thefile.read((char *)&sn,sizeof(sn));
			if(sn.theClass==aClass) {
				 gotoxy(8,i);
				cout << (i-7); 
				 gotoxy(14,i);
				cout << sn.name ;
				 gotoxy(56,i);
				cout << sn.m.avg;
			}
		}thefile.close();
	 gotoxy(4,23);
	cout<<"Enter any key to go back to previous menu..";
	 getch();
	loadingSequence();
	report();
}
void studentDetails::newAdmission() {

	ofstream thefile ("stuDet.dat",ios::binary|ios::app);
	gotoxy(4,4);
	cout << " Student's GR no. : ";
	 cin>>sn.grno;
	gotoxy(4,6);
	cout << " Student's Name : ";
	 gets(sn.name);
	  gotoxy(4,8);
	cout << " Father's name  : ";
	 gets(sn.fName);
	  gotoxy(4,10);
	cout << " Mother's name  : ";
	 gets(sn.mName);
	  gotoxy(4,12);
	cout << " Division & Section : ";
	 gets(sn.theClass);
	 gotoxy(4,14);
	cout << " Building  : ";
	 cin >> sn.a.building;
	 gotoxy(24,14);
	cout << " Block  : ";
	 cin >> sn.a.block;
	 gotoxy(45,14);
	cout << " Road  : ";
	 cin >> sn.a.road;
	 gotoxy(4,16);
	cout << " ZIP  : ";
	 cin >> sn.a.zip;
	 gotoxy(24,16);
	cout << " P.O. Box  : ";
	 cin >> sn.a.pobox;
	 gotoxy(45,16);
	cout << " Flat  : ";
	 gets(sn.a.flat);
	 gotoxy(4,18);
	cout << " Landline no. : ";
	 cin >> sn.p.home;
	 gotoxy(4,20);
	cout << " Mobile no. (One) : ";
	 cin >> sn.p.one;
	 gotoxy(4,22);
	cout << " Mobile no. (Two) : ";
	 cin >> sn.p.two;

	 loadingSequence();
	 inputMarks();

	thefile.write((char *)&sn,sizeof(sn));
	loadingSequence();
	thefile.close();
	mainMenu();
}
void studentDetails::editDetail(int gno) {

  fstream thefile ("stuDet.dat",ios::binary);
  thefile.read((char *)&sn,sizeof(sn));
  while (!thefile.eof())  {
	if(sn.grno==gno) {

		 gotoxy(3,3);
		cout << "You have to re-enter the detail even if you don't want to alter it. ";
		gotoxy(4,6);
		cout << " Student's Name : " << sn.name ;
		 gotoxy(22,7);
		 gets(sn.name);
		gotoxy(4,8);
		cout << " Father's name  : " << sn.fName;
		 gotoxy(22,9);
		 gets(sn.fName);
		gotoxy(4,10);
		cout << " Mother's name  : " << sn.mName;
		 gotoxy(22,11);
		 gets(sn.mName);
		gotoxy(4,12);
		cout << " Dividion & Section : " << sn.theClass;
		 gotoxy(14,13);
		 gets(sn.theClass);
		gotoxy(4,14);
		cout << " Building  : " << sn.a.building;
		 gotoxy(17,15);
		 cin >> sn.a.building;
		gotoxy(24,14);
		cout << " Block  : " << sn.a.block;
		 gotoxy(34,15);
		 cin >> sn.a.block;
		gotoxy(45,14);
		cout << " Road  : " << sn.a.road;
		 gotoxy(54,15);
		 cin >> sn.a.road;
		gotoxy(4,16);
		cout << " ZIP  : " << sn.a.zip;
		 gotoxy(12,17);
		 cin >> sn.a.zip;
		gotoxy(24,16);
		cout << " P.O. Box  : " << sn.a.pobox;
		 gotoxy(37,17);
		 cin >> sn.a.pobox;
		gotoxy(45,16);
		cout << " Flat  : " << sn.a.flat;
		 gotoxy(54,17);
		 cin >> sn.a.flat;
		gotoxy(4,18);
		cout << " Landline no. : " << sn.p.home;
		 gotoxy(20,19);
		 cin >> sn.p.home;
		gotoxy(4,20);
		cout << " Mobile no. (One) : " << sn.p.one;
		 gotoxy(24,21);
		 cin >> sn.p.one;
		gotoxy(4,22);
		cout << " Mobile no. (Two) : " << sn.p.two;
		 gotoxy(24,23);
		 cin >> sn.p.two;

		loadingSequence();
		inputMarks();

		  thefile.seekp(thefile.tellg() - sizeof(sn));
		thefile.write((char*)&sn,sizeof(sn));
	}
	thefile.close();
  loadingSequence();
  mainMenu();
  }
}
void studentDetails::giveTC(int gno) {
	ofstream toWrite("helper.dat",ios::out|ios::binary);
	ifstream toRead ("stuDet.dat",ios::in| ios::binary);
		toRead.read((char*)&sn, sizeof(sn));
		while(!toRead.eof()) {
			if(sn.grno==gno)
			  toWrite.write((char*)&sn, sizeof(sn));
			toRead.read((char*)&sn, sizeof(sn));
		}
	toRead.close();
	toWrite.close();
	remove("stuDet.dat");
	rename("helper.dat", "stuDet.dat");
}
void studentDetails::displayDetails(int gno) {

	    ifstream thefile ("stuDet.dat",ios::binary|ios::in);
		while (!thefile.eof()) {
			thefile.read((char *)&sn,sizeof(sn));
			if(sn.grno==gno) {
             gotoxy(4,4);
	        cout << " Student's GR no. : " << sn.grno ;
			 gotoxy(4,6);
			cout << " Student's Name : " << sn.name ;
			 gotoxy(4,7);
			cout << " Father's name  : " << sn.fName;
			 gotoxy(4,8);
			cout << " Mother's name  : " << sn.mName;
			 gotoxy(4,10);
			cout << " Division & Section : " << sn.theClass;
			 gotoxy(4,12);
			cout << " Building  : " << sn.a.building;
			 gotoxy(24,12);
			cout << " Block  : " << sn.a.block;
			 gotoxy(45,12);
			cout << " Road  : " << sn.a.road;
			 gotoxy(4,14);
			cout << " ZIP  : " << sn.a.zip;
			 gotoxy(24,14);
			cout << " P.O. Box  : " << sn.a.pobox;
			 gotoxy(45,14);
			cout << " Flat  : " << sn.a.flat;
			 gotoxy(4,16);
			cout << " Landline no. : " << sn.p.home;
			 gotoxy(4,18);
			cout << " Mobile no. (One) : " << sn.p.one;
			 gotoxy(4,20);
			cout << " Mobile no. (Two) : " << sn.p.two;	
            }
		}thefile.close();
		
		 gotoxy(4,23);
		cout<<"Press any key to go back to previous menu...";
		 getch();
		loadingSequence();
		search();
}
void studentDetails::inputMarks() {

		 gotoxy(8,8);
	  cout << "Enter mark One   (Physics)         : ";
		cin >> sn.m.m1;
		 gotoxy(8,10);
	  cout << "Enter mark Two   (Chemistry)       : ";
		cin >> sn.m.m2;
		gotoxy(8,12);
	  cout << "Enter mark Three (Mathematics)     : ";
		cin >> sn.m.m3;
		gotoxy(8,14);
	  cout << "Enter mark Four  (Computer Science): ";
		cin >> sn.m.m4;
		gotoxy(8,16);
	  cout << "Enter mark Five  (English)         : ";
		 cin >> sn.m.m5;

	  sn.m.avg=(sn.m.m1+sn.m.m2+sn.m.m3+sn.m.m4+sn.m.m5)/5;
}

//***************************************************************************
// Helper tool definitions...                                               #
//***************************************************************************
void borderCreator()
{
	gotoxy(0, 0);
	for (int y = 0; y < 25; y++)
	{
		if (y == 0 || y == 24)
			for (int x = 1; x < 81; x++)
			{
				gotoxy(x, y);
				cout << put;
			}
		else
		{
			gotoxy(0, y);
			cout << put;
			gotoxy(80, y);
			cout << put;
		}
	}
	gotoxy(2, 2);

}
void loadingSequence()
{
	 clrscr();

	 for (int y = 0; y < 25; y++)
		for (int x = 0; x < 81; x++)
				 {
			gotoxy(x,y);
			cout << put;
			delay(35);
		}
	delay(250);
	clrscr();
	delay(250);
	borderCreator();
}
void delay(int x)
{
 for (int i = 1; i < x; i++)
	 for (int j = 0; j < x; j++)
		  for (int k = 0; k < x/4; k++);

}
