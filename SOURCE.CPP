#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <fstream.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

const char put = 219;   //Dosen't work... IDK why..

		/* CURRENT PROBLEMS
			  Line : 571,644
			  Landline no. of student dosen't get input
			  Line : 71
			  Ranking logic missing...
			  Line : 336
			  User's password dosen't match (is never stored)..
			  Line : 586
			  EditDetail has some logical error.. (dosen't work...)
		  */
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
	   //Complete Class declarations...                                     #
	   //********************************************************************

		class studentDetails
		{
			struct students {
				char name[30], fName[30], mName[30];
				int  grno;
				char division[4],section[2];
				struct address
				{
					int building, block, road, zip, pobox;
					char flat;
				}a;
				struct phone
				{
				long home, one, two;
				}p;

				struct marks {
					float m1, m2, m3, m4, m5, avg;
				}m;
				int rank;

		    }sn;

		public:  void search();
		            void searchN(char name[]);
					void searchG(int gno);
				 void report();
					void studentReport(int gno);
				    void classReport();
			     void newAdmission();
				 void editDetail(int gno);
				 void displayDetails(int gno);
				 void inputMarks();

		}sD;

		struct userDetails
		{
			char firstname[10], lastname[10], securityn[10];
			char username [12], password[9] ;

		}uD;
		
//Main Program...
void main()
{
	openingCredits();
	passwordMenu();
	//loadingSequence();
	//mainMenu();
}

//***************************************************************************
// All the definitions of all the helping functions...                      #
//***************************************************************************

void projectLogo()
{
	 gotoxy(13,9);
	cout << " /¯¯(\___\‘  /¯¯/\_/\¯¯\°  /¯¯(\___\‘   ";
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
		cout << "(If no , you will be required to create a new user...)";
		 gotoxy(20, 10);
		cout << "Do you have an account (y/n) : ";
		  cin >> option;

		loadingSequence();

			switch (option)
			{
				 case 'y': {userCheck(); break;}
				 case 'n': {newUser();   break;}
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
	puts(uD.username);
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
	cout << "4. Report Manager.";
	 gotoxy(25, 12);
	cout << "5. LogOut.";
	 gotoxy(25, 13);
	cout << "6. EXIT ";
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
						        break;
		  }
	case 4: {sD.report();       break;}
	case 5: {passwordMenu();    break;}
	case 6: exit(1);
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
void newUser()
{
  char repass[9];
  ofstream fout("user.dat",ios::app|ios::binary);
	gotoxy(6, 2);
  cout << "Please file in the details given below : ";
	gotoxy(15, 4);
  cout << "Your first name : ";
  gets(uD.firstname);
	gotoxy(15, 5);
  cout << "Your last name  : ";
  gets(uD.lastname);
	gotoxy(15, 6);
  cout << "Enter a username : ";
  gets(uD.username);
	gotoxy(15,7);
  cout << "Enter a new password (8 Characters) : ";
  for (int i=0;i<8;i++)
	{
	 uD.password[i] = getch();
	 cout << "*";
	}
	  gotoxy(16,8);
	 cout << "Re-enter the password : ";

	 for (i = 0;i < 8;i++)
	 {
		 repass[i] = getch();
		 cout << "*";
	 }
		gotoxy(16,12);
		cout<<uD.password<<" "<<repass;
		delay(2000);
	 if (strcmp(uD.password,repass)==0)
	{   gotoxy(16,9);
		cout << "Enter your personal secret sequrity name : ";
		gets(uD.securityn);
		 gotoxy(17,16);
		cout << "Saving... Please wait...";
		fout.write((char*)&uD, sizeof(uD));
		 delay(500);
		 gotoxy(17,17);
		cout << "Password directory has been updated ...";
		delay(250);
		loadingSequence();
		mainMenu();
	}
	else
	 { clrscr();
		cout << "There is some unexpected problem....";
		delay(500);
		clrscr();
		cout << "Restarting...";
		delay(500);
		loadingSequence();
		passwordMenu();
	}
	fout.close();
}
void userCheck()
{  char erch;
	do {
		ifstream fin("user.dat",ios::in|ios::binary);
		 int flagu = 0, flagp = 0;
		 char usn[12], pwd[9];
		  gotoxy(10, 5);
		cout << "Welcome back !!! ";
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

		while(!fin.eof())
		{
			fin.read((char*)&uD,sizeof(uD));
			if (strcmpi(uD.username, usn) == 0)
				flagu = 1;
			if (strcmp(uD.password, pwd) == 0)
				flagp = 1;
		}
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
		fin.close();
	 } while (erch=='t'||erch=='T');
}
void forgotPassword()
	 {
		ifstream fin("users.dat", ios::in | ios::binary);
		char ans[10];
		 gotoxy(29, 10);
		cout<<"Enter the security name to proceed...";
		 gotoxy(29, 11);
		gets(ans);
		 loadingSequence();


		if (strcmp(uD.securityn, ans) == 0) {
			delay(100);
			mainMenu();
		}
		else {
			delay(100);
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
			  case '2' :{
						  classReport();
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
				cout << " Class  : " << sn.division;
				 gotoxy(24,7);
				cout << " Section  : " << sn.section;
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
				 gotoxy(8,21);
				cout << "Rank : " <<sn.rank;
			}
		}thefile.close();
		gotoxy(3,23);
		cout << "Press any key to go back to the previous menu...";
		getch();
		loadingSequence();
		report();
	}
void studentDetails::classReport(){
	 gotoxy(3,3);
	cout<<"Class report :";
	 gotoxy(8,6);
	cout<<"Rank";
	 gotoxy(14,6);
	cout<<"Name";
	 gotoxy(56,6);
	cout<<"Percentage";
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
	cout << " Class  : ";
	 gets(sn.division);
	 gotoxy(24,12);
	cout << " Section  : ";
	 gets(sn.section);
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
	 cin >> sn.a.flat;
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

	ifstream toRead ("stuDet.dat",ios::binary|ios::in);
	ofstream toWrite("help.dat",ios::binary|ios::out);

	  while (!toRead.eof()) {

		  toRead.read((char *)&sn,sizeof(sn));

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
		cout << " Class  : " << sn.division;
		 gotoxy(14,13);
		 gets(sn.division);
		gotoxy(24,12);
		cout << " Section  : " << sn.section;
		 gotoxy(36,13);
		 gets(sn.section);
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

		 toWrite.write((char*)&sn,sizeof(sn));

		  }
	  else toWrite.write((char*)&sn,sizeof(sn));
	  }
			 toRead.close();
			 toWrite.close();
		remove("stuDet.dat");
		ifstream toRead2 ("help.dat",ios::binary|ios::in);
		ofstream toWrite2("stuDet.dat",ios::binary|ios::app);
		 while (!toRead2.eof()) {
			 toRead2.read((char *)&sn,sizeof(sn));
			  toWrite2.write((char *)&sn,sizeof(sn));
			  toRead2.close();
			 toWrite.close();
			}
	  loadingSequence();
	  mainMenu();
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
			cout << " Class  : " << sn.division;
			 gotoxy(24,10);
			cout << " Section  : " << sn.section;
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
