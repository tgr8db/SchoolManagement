#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <fstream.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

const char symBor = '%'; //Border Symbol ...

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
		   void forgotPassword(int curUser);

	   //********************************************************************
	   //All Tool Declarations...                                           #
	   //********************************************************************

		   void borderCreator();
		   void loadingSequence();
				void Pattern1();
				void Pattern2();
				void Pattern3();
		   void delay(int x);
		   void projectLogo();

	   //********************************************************************
	   //Other declarations...                                              #
	   //********************************************************************
        
		char securityn[][10] = {"leader",  "memone",  "memtoo",  "memthree"};
		char username [][12] = {"Aman",    "Ashley",  "Alwin",   "Arun"    };
		char password [][9]  = {"amanaman","ashash00","al_alwin","arunarun"};
		
		char curUsername[12];
		int nUsers=4;
		
		class studentDetails {
			
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
				  int getMarks(int y);

		}sD;

//Main Program...
void main() {
	openingCredits();
	passwordMenu();
}

//***************************************************************************
// All the definitions of all the helping functions...                      #
//***************************************************************************

void projectLogo() {
	
	gotoxy(13,9);
	cout << " /¯¯(\___\   /¯¯/\_/\¯¯\   /¯¯(\___\    ";
	 gotoxy(13,10);
	cout << " (¯¯¯\)___)  \__\    /__/  (¯¯¯\)___)   ";

}
void openingCredits() {
	
	loadingSequence();

	 gotoxy(2, 2);
	cout << "A Multi-User management software magic..." << endl;
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

	getch();
	loadingSequence();
}

//***************************************************************************
// Menu definitions...                                                      #
//***************************************************************************

void passwordMenu() {
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
void mainMenu() {
	 gotoxy(4, 4);
	cout << " Welcome " << curUsername << "!!!";
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
	 choice = getch();
    choice-= 48;
	cout << choice;
	getch();
	loadingSequence();
	delay(100);

	switch (choice) {
	case 1: { sD.newAdmission(); break; }
	case 2: { sD.search();       break; }
	case 3: { int gno;
			   gotoxy(15,15);
			  cout << "Enter the GR. no. of the student : ";
			   cin>>gno;
			  clrscr();
			  loadingSequence();
			  sD.editDetail(gno);
										 break;}
	case 4: { int gno;
			   gotoxy(15,15);
			  cout << "Enter the GR. no. of the student : ";
			   cin>>gno;
			  clrscr();
			  loadingSequence();
			  sD.giveTC(gno);    break; }
	case 5: { sD.report();       break; }
	case 6: { passwordMenu();    break; }
	case 7: exit(1);
	default:{ gotoxy(4,20);
				 cout << "There was some unexpected error ... ";
				 mainMenu();
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
	 choice = getch();
	cout << choice;
	getch();

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
					 break;
					}
		  default  :{mainMenu();}
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
	  }
	  thefile.close();
	if(found==0) {
	  loadingSequence();
		gotoxy(8,8);
	  cout << "No such Name was found in the directory...";
		getch();
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
		getch();
	  loadingSequence();
	  search();
	 }
 }

//***************************************************************************
// Password_Sub-menu definitions...                                         #
//***************************************************************************

void userCheck() {  
	char erch;
	do 
	{  
		 int flagu = 0, flagp = 0, i, j=0;
		 char usn[12], pwd[8];
		  gotoxy(10, 5);
		cout << "Welcome back !!!";
		  gotoxy(29,10);
		cout << "Username : ";
		  gets(usn);
		  gotoxy(29,11);
		cout << "Password : ";
			for(i=0;i < 8;i++ )
			{
			  pwd[i] = getch();
			  cout << "*";
			}
			getch();
			
        for(i=0;i<nUsers;i++){
			if (strcmp(username[i], usn) == 0) {
				flagu = 1;
				j=i;
			  if (strcmp(password[j], pwd) == 0) {
				flagp = 1;
				strcpy(curUsername,username[i]);
				break;
			  }	
			}
		  }
		  
	  if (flagu == 1 && flagp == 1) {
			 gotoxy(29,12);
			cout << "Access granted... ";
			 delay(750);
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
				forgotPassword(j);
			else if (erch=='t'||erch=='T');
			else passwordMenu();
		}
	} 
	while (erch=='t'||erch=='T');
}
void forgotPassword(int curUser) {
		
		char ans[10];
		 gotoxy(29, 10);
		cout<<"Enter the security name to proceed...";
		 gotoxy(29, 11);
		gets(ans);
		 loadingSequence();

		if (strcmp(securityn[curUser], ans) == 0) {
			loadingSequence();
			 gotoxy(4,6);
			cout << "Your password is : " << password[curUser];
            getch();
			strcpy(curUsername,username[i]);
            loadingSequence();			
			mainMenu();
		}
		else {
			cout<<"Wrong Security answer... ";
			 delay(500);
			loadingSequence();
			passwordMenu();
		}
	}

//***************************************************************************
// studentDetails_Report definitions...                                     #
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
	 gotoxy(24,6);
	cout<<"Name";
	 gotoxy(56,6);
	cout<<"Percentage";
	int i = 8;
	ifstream thefile ("stuDet.dat",ios::binary|ios::in);
		while(!thefile.eof()) {
			thefile.read((char *)&sn,sizeof(sn));
			if(strcmp(sn.theClass,aClass)==0) {
				 gotoxy(8,i);
				cout << (i-7); 
				 gotoxy(24,i);
				cout << sn.name ;
				 gotoxy(56,i);
				cout << sn.m.avg;
            i++;
			}
		}thefile.close();
	 gotoxy(4,23);
	cout<<"Enter any key to go back to previous menu..";
	 getch();
	loadingSequence();
	report();
}

//***************************************************************************
// studentDetails_Other definitions...                                      #
//***************************************************************************

void studentDetails::newAdmission() {

	ofstream thefile ("stuDet.dat",ios::binary|ios::app);
	
	gotoxy(4,4);
	cout << " Student's GR no. {int} : ";
	 cin>>sn.grno;
	gotoxy(4,6);
	cout << " Student's Name {char[30]} : ";
	 gets(sn.name);
	  gotoxy(4,8);
	cout << " Father's name  {char[30]} : ";
	 gets(sn.fName);
	  gotoxy(4,10);
	cout << " Mother's name  {char[30]} : ";
	 gets(sn.mName);
	  gotoxy(4,12);
	cout << " Division & Section {char[6]} : ";
	 gets(sn.theClass);
	 gotoxy(4,14);
	cout << " Building  {int} : ";
	 cin >> sn.a.building;
	 gotoxy(28,14);
	cout << " Block  {int} : ";
	 cin >> sn.a.block;
	 gotoxy(52,14);
	cout << " Road  {int} : ";
	 cin >> sn.a.road;
	 gotoxy(4,16);
	cout << " ZIP  {int} : ";
	 cin >> sn.a.zip;
	 gotoxy(28,16);
	cout << " P.O. Box  {int} : ";
	 cin >> sn.a.pobox;
	 gotoxy(52,16);
	cout << " Flat  {char[6]} : ";
	 gets(sn.a.flat);
	 gotoxy(4,18);
	cout << " Landline no. {long} : ";
	 cin >> sn.p.home;
	 gotoxy(4,20);
	cout << " Mobile no. (One) {long} : ";
	 cin >> sn.p.one;
	 gotoxy(4,22);
	cout << " Mobile no. (Two) {long} : ";
	 cin >> sn.p.two;

	 loadingSequence();
	 inputMarks();

	thefile.write((char *)&sn,sizeof(sn));
	loadingSequence();
	thefile.close();
	mainMenu();
}

void studentDetails::editDetail(int gno) {

  int found=0;
  ofstream toWrite("helper.dat",ios::out|ios::binary);
  ifstream toRead ("stuDet.dat",ios::in| ios::binary);

	toRead.read((char*)&sn, sizeof(sn));

  while(!toRead.eof()) {

	if(sn.grno==gno) {

		found=1;

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
		cout << " Division & Section : " << sn.theClass;
		 gotoxy(26,13);
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

		toWrite.write((char*)&sn, sizeof(sn));
	}
	toWrite.write((char*)&sn, sizeof(sn));
   toRead.read((char*)&sn, sizeof(sn));
  }
	toRead.close();
	toWrite.close();

  loadingSequence();
  if(found==0){
	 gotoxy(4,4);
	 cout<<"Such student wasn't found...";
	 getch();
  }
  remove("stuDet.dat");
  rename("helper.dat", "stuDet.dat");
  loadingSequence();
  mainMenu();
}

void studentDetails::giveTC(int gno) {
	ofstream toWrite("helper.dat",ios::out|ios::binary);
	ifstream toRead ("stuDet.dat",ios::in| ios::binary);
		toRead.read((char*)&sn, sizeof(sn));
		while(!toRead.eof()) {
			if(sn.grno!=gno)
			  toWrite.write((char*)&sn, sizeof(sn));
			toRead.read((char*)&sn, sizeof(sn));
		}
	toRead.close();
	toWrite.close();
     gotoxy(4,5);
    cout<<"The students record has been deleted...";
     gotoxy(4,10);	
 	cout<<"P.S.Maybe it wasn't present ;)";
    getch();	
	remove("stuDet.dat");
	rename("helper.dat", "stuDet.dat");
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
		gotoxy(4,6);
      cout<<"Enter '0' before entering a two-digit number... ";
		gotoxy(8,8);
	   cout << "Enter mark One   (Physics)         : ";
		sn.m.m1 = getMarks(8);
		gotoxy(8,10);
	   cout << "Enter mark Two   (Chemistry)       : ";
		sn.m.m2 = getMarks(10);
		gotoxy(8,12);
	   cout << "Enter mark Three (Mathematics)     : ";
		sn.m.m3 = getMarks(12);
		gotoxy(8,14);
	   cout << "Enter mark Four  (Computer Science): ";
		sn.m.m4 = getMarks(14);
		gotoxy(8,16);
	   cout << "Enter mark Five  (English)         : ";
		sn.m.m5 = getMarks(16);

	  sn.m.avg=(sn.m.m1+sn.m.m2+sn.m.m3+sn.m.m4+sn.m.m5)/5;
	  getch();
}

int studentDetails::getMarks(int y){
	int n100, n10, n, i;
	char c[4];
	int result=0;
  do{	i = 0;
		 gotoxy(45,y);
	  cout<<"     ";
		gotoxy(45,y);
	  do
	  {
		 c[i] = getch();
		 cout << c[i];
		 delay(50);
		 i++;
		 if(i==3)
			break;
	  }
	  while(c[i]>='0'||c[i]<='9');

	  n100 = (c[0]-'0')*100;
	  n10  = (c[1]-'0')*10;
	  n    = (c[2]-'0');

	  result = n100 + n10 + n;
	  if(result > 100){
			gotoxy(4,22);
		  cout << "Invalid marks entry...";
			gotoxy(4,23);
		  cout << "Please Enter the value again...";
	  }
	 }
	while(result > 100);
	return result;
}

//***************************************************************************
// Helper tool definitions...                                               #
//***************************************************************************

void borderCreator() {
	gotoxy(0, 0);
	for (int y = 0; y < 25; y++)
	{
		if (y == 0 || y == 24)
			for (int x = 1; x < 81; x++)
			{
				gotoxy(x, y);
				cout << symBor;
			}
		else
		{
			gotoxy(0, y);
			cout << symBor;
			gotoxy(80, y);
			cout << symBor;
		}
	}
	gotoxy(2, 2);

}

void loadingSequence() {
	 clrscr();
	 int x = random(3);
	 switch (x) {
		case 0: Pattern1(); break;
		case 1: Pattern2(); break;
		case 2: Pattern3(); break;
	 }

	delay(250);
	clrscr();
	delay(250);
	borderCreator();
}

	void Pattern1() {
		int reverse = 0, x1 = 0, x2 = 80;
		while (x1 != 41) {
			if (reverse == 0) {
				for (int y = 0; y < 25; y++) {
					gotoxy(x1, y);
					cout << symBor;
					gotoxy(x2, y);
					cout << symBor;
					delay(50);
					reverse = 1;
				}
			}
			else {
				for (int y = 24; y >= 0; y--) {
					gotoxy(x1, y);
					cout << symBor;
					gotoxy(x2, y);
					cout << symBor;
					delay(50);
					reverse = 0;
				}
			}
			delay(125);
			x1++;
			x2--;

		}

	}
	
	void Pattern2() {
		for (int y = 0; y < 25; y++)
			for (int x = 0; x < 81; x++)
			{
				gotoxy(x, y);
				cout << symBor;
				delay(35);
			}
	}
	
	void Pattern3() {
		int reverse = 0, y1 = 0, y2 = 24;
		while (y1 != 13) {
			if (reverse == 0) {
				for (int x = 0; x < 81; x++) {
					gotoxy(x, y1);
					cout << symBor;
					gotoxy(x, y2);
					cout << symBor;
					delay(50);
					reverse = 1;
				}
			}
			else {
				for (int x = 80; x >= 0; x--) {
					gotoxy(x, y1);
					cout << symBor;
					gotoxy(x, y2);
					cout << symBor;
					delay(50);
					reverse = 0;
				}
			}
			delay(125);
			y1++;
			y2--;
			
		}
	}

	void delay(int x) {
 for (int i = 1; i < x; i++)
	 for (int j = 0; j < x; j++)
		  for (int k = 0; k < x/4; k++);

}
