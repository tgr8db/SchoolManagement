#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <fstream.h>
#include <stdio.h>


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
			
	   //********************************************************************
	   //All Tool Declarations...                                           #
	   //********************************************************************
	   
		   void borderCreator();
		   void loadingSequence();
			
	   //********************************************************************
	   //Support Tool Declarations...                                       #
	   //********************************************************************
	   
		   void delay(int x);
		   void projectLogo();
			
	   //********************************************************************
	   //Class declarations...                                              #
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
					int m1, m2, m3, m4, m5;
				}m;

		}s[40];

		public:

			    void newAdmission(int n) {
					
					gotoxy(4,6);
					cout << " Student's Name : ";
					 gets(s[n].name);
					gotoxy(4,8);
					cout << " Father's name  : ";
					 gets(s[n].fName);
					gotoxy(4,10);
					cout << " Mother's name  : ";
					 gets(s[n].mName);
					gotoxy(4,12);
					cout << " Class  : ";
					 gets(s[n].division);
					gotoxy(12,12);
					cout << " Section  : ";
					 gets(s[n].section);
					gotoxy(4,14);
					cout << " Building  : ";
					 cin >> s[n].a.building;
					gotoxy(12,14);
					cout << " Block  : ";
					 cin >> s[n].a.block;
					gotoxy(20,14);
					cout << " Road  : ";
					 cin >> s[n].a.road;
					gotoxy(4,16);
					cout << " ZIP  : ";
					 cin >> s[n].a.zip;
					gotoxy(12,16);
					cout << " P.O. Box  : ";
					 cin >> s[n].a.pobox;
					gotoxy(20,16);
					cout << " Flat  : ";
					 cin >> s[n].a.flat;
					gotoxy(4,18);
					cout << " Landline no. : ";
					 cin >> s[n].p.home;
					gotoxy(4,20);
					cout << " Mobile no. (One) : ";
					 cin >> s[n].p.one;
					gotoxy(4,22);
					cout << " Mobile no. (Two) : ";
					 cin >> s[n].p.two;
					
			}
				void editDetail(int gno) {    
                  for(int i = 0; i < 40; i++)
					  if(s.[i].grno==gno){
					gotoxy(3,6);
                    cout << "You have to re-enter the detail even if you don't want to alter it. "					
					gotoxy(4,6);
					cout << " Student's Name : " << s[n].name ;
					 gotoxy(4,7);
					 gets(s[n].name);
					gotoxy(4,8);
					cout << " Father's name  : " << s[n].fName;
					 gotoxy(4,9);
					 gets(s[n].fName);
					gotoxy(4,10);
					cout << " Mother's name  : " << s[n].mName;
					 gotoxy(4,11);
					 gets(s[n].mName);
					gotoxy(4,12);
					cout << " Class  : " << s[n].division;
					 gotoxy(4,13);
					 gets(s[n].division);
					gotoxy(12,12);
					cout << " Section  : " << s[n].section;
					 gotoxy(12,13);
					 gets(s[n].section);
					gotoxy(4,14);
					cout << " Building  : " << s[n].a.building;
					 gotoxy(4,15);
					 cin >> s[n].a.building;
					gotoxy(12,14);
					cout << " Block  : " << s[n].a.block;
					 gotoxy(12,15);
					 cin >> s[n].a.block;
					gotoxy(20,14);
					cout << " Road  : " << s[n].a.road;
					 gotoxy(20,15);
					 cin >> s[n].a.road;
					gotoxy(4,16);
					cout << " ZIP  : " << s[n].a.zip;
					 gotoxy(4,17);
					 cin >> s[n].a.zip;
					gotoxy(12,16);
					cout << " P.O. Box  : " << s[n].a.pobox;
					 gotoxy(12,17);
					 cin >> s[n].a.pobox;
					gotoxy(20,16);
					cout << " Flat  : " << s[n].a.flat;
					 gotoxy(20,17);
					 cin >> s[n].a.flat;
					gotoxy(4,18);
					cout << " Landline no. : " << s[n].p.home;
					 gotoxy(4,19);
					 cin >> s[n].p.home;
					gotoxy(4,20);
					cout << " Mobile no. (One) : " << s[n].p.one;
					 gotoxy(4,21);
					 cin >> s[n].p.one;
					gotoxy(4,22);
					cout << " Mobile no. (Two) : " << s[n].p.two;
					 gotoxy(4,23);
					 cin >> s[n].p.two;
						  
					  }
				}
				void displayDetails(int gno) {
					
                     gotoxy(4,6);
					cout << " Student's Name : " << s[n].name ;
					 gotoxy(4,7);
					 gets(s[n].name);
					gotoxy(4,8);
					cout << " Father's name  : " << s[n].fName;
					 gotoxy(4,9);
					 gets(s[n].fName);
					gotoxy(4,10);
					cout << " Mother's name  : " << s[n].mName;
					 gotoxy(4,11);
					 gets(s[n].mName);
					gotoxy(4,12);
					cout << " Class  : " << s[n].division;
					 gotoxy(4,13);
					 gets(s[n].division);
					gotoxy(12,12);
					cout << " Section  : " << s[n].section;
					 gotoxy(12,13);
					 gets(s[n].section);
					gotoxy(4,14);
					cout << " Building  : " << s[n].a.building;
					 gotoxy(4,15);
					 cin >> s[n].a.building;
					gotoxy(12,14);
					cout << " Block  : " << s[n].a.block;
					 gotoxy(12,15);
					 cin >> s[n].a.block;
					gotoxy(20,14);
					cout << " Road  : " << s[n].a.road;
					 gotoxy(20,15);
					 cin >> s[n].a.road;
					gotoxy(4,16);
					cout << " ZIP  : " << s[n].a.zip;
					 gotoxy(4,17);
					 cin >> s[n].a.zip;
					gotoxy(12,16);
					cout << " P.O. Box  : " << s[n].a.pobox;
					 gotoxy(12,17);
					 cin >> s[n].a.pobox;
					gotoxy(20,16);
					cout << " Flat  : " << s[n].a.flat;
					 gotoxy(20,17);
					 cin >> s[n].a.flat;
					gotoxy(4,18);
					cout << " Landline no. : " << s[n].p.home;
					 gotoxy(4,19);
					 cin >> s[n].p.home;
					gotoxy(4,20);
					cout << " Mobile no. (One) : " << s[n].p.one;
					 gotoxy(4,21);
					 cin >> s[n].p.one;
					gotoxy(4,22);
					cout << " Mobile no. (Two) : " << s[n].p.two;
					 gotoxy(4,23);
					 cin >> s[n].p.two;
						  
				}
				void marksManager(int gno) {
                  for(int i = 0; i < 40; i++)
					  if(s.[i].grno==gno){
						  cout << "Enter mark One   : ";
						  cout << "Enter mark Two   : ";
						  cout << "Enter mark Three : ";
						  cout << "Enter mark Four  : ";
						  cout << "Enter mark Five  : ";
					  }
				}

		}sD;
		class userDetails
		{
			char firstname[10], lastname[10], securityq[10];
			char username[12], password[9];

		public: void resetData() 
		        { 
			        ofstream fout("users.dat", ios::app | ios::binary);
			        username = ""; 
					password = ""; 
					firstname = ""; 
					lastname = "";
                }
			    void getUsername(char &un,int i)
			          {
						  un = firstname[i];
			          }
		}uD;
//Main Program...
void main()  // Change it to void main...
{
	openingCredits();
	passwordMenu();
}

//***************************************************************************
// All the definitions of all the helping functions...                      #
//***************************************************************************

void projectLogo()
{
	cout << "     ▄████████     ▄▄▄▄███▄▄▄▄        ▄████████ " << endl;
	cout << "    ███    ███   ▄██▀▀▀███▀▀▀██▄     ███    ███ " << endl;
	cout << "    ███    █▀    ███   ███   ███     ███    █▀  " << endl;
	cout << "    ███          ███   ███   ███     ███        " << endl;
	cout << "  ▀███████████   ███   ███   ███   ▀███████████ " << endl;
	cout << "           ███   ███   ███   ███            ███ " << endl;
	cout << "     ▄█    ███   ███   ███   ███      ▄█    ███ " << endl;
	cout << "   ▄████████▀  █  ▀█   ███   █▀  █  ▄████████▀  " << endl;
}
void openingCredits()
{
	gotoxy(2, 2);
	cout << "For The World" << endl;
	projectLogo();
	gotoxy(19, 11);
	cout << "The School Managment System....";
	gotoxy(24, 16);
	cout << "Done by: 4A(s)";
	gotoxy(30, 18);
	cout << "LEADER       :  Aman Dwivedi";
	gotoxy(30, 19);
	cout << "Member One   :  Ashley Anneri";
	gotoxy(30, 20);
	cout << "Member Two   :  Arun B. Anilkumar";
	gotoxy(30, 21);
	cout << "Member Three :  Alwin Sevi";

	delay(1000000);
	loadingSequence();
}
//***************************************************************************
// Menu definitions...                                                      #
//***************************************************************************
void passwordMenu() // at the end , add a loadingSequence()...
{
		char option;
		gotoxy(12, 13);
		cout << "(If no , you will be required to create a new user...)";
		gotoxy(22, 10);
		cout << "Do you have an account (y/n) : ";
		cin >> option;
		loadingSequence();

			switch (option)
			{
			     case 'y': uD.userCheck(); break;
				 case 'n': uD.newUser();   break;
				 default : {cout << "Unexpected error..."<<endl;
						    cout << "Restarting...";
						    delay(100000);
						    loadingSequence();
						    passwordMenu();
							break;
				 }
			}


}
void mainMenu()
{
	borderCreator();
	char usern[10];
	for (int i = 0; i < 10; i++) {
		char usn;
		uD.getUsername(usn);
		usern[i] = usn;
	}
	gotoxy(4, 4);
	cout << " Welcome ";
	puts(usern);
	gotoxy(4, 5);
	cout << "This the main menu of the School Management System...";
	int choice;
	gotoxy(25, 8);
	cout << "1. New Admission.";
	gotoxy(25, 9);
	cout << "2. Search.";
	gotoxy(25, 10);
	cout << "3. Edit student Data.";
	gotoxy(25, 11);
	cout << "4. Marks Manager.";
	gotoxy(25, 12);
	cout << "5. Reportcard Manager.";
	gotoxy(25, 13);
	cout << "6. Logout.";
	gotoxy(25, 14);
	cout << "7. EXIT ";
	gotoxy(30, 20);
	cout << "Enter your choice : ";
	cin >> choice;
	
	loadingSequence();
	delay(10000);

	switch (choice) {
	case 1: sD.newAdmission();
	case 2: search();
	case 3: sD.editDetail();
	case 4: sD.marksManager();
	case 5: report();
	case 6:	passwordMenu();
	case 7: exit(1);
	default:{ cout << "There was some unexpected error ... ";
			  openingCredits();
	}
	}


}
void search()
{
}
void report()
{
}
//***************************************************************************
// Sub-menu definitions...                                                  #
//***************************************************************************
void newUser()
{
  char repass[10];

  ofstream fout("users.dat",ios::app|ios::binary);
   gotoxy(6, 1);
  cout << "Please file in the details given below : ";
   gotoxy(22, 3);
  cout << "Your first name:";
  gets(uD.firstname);
   gotoxy(23, 4);
  cout << "Your last name:";
  gets(uD.lastname);
   gotoxy(21, 5);
  cout << "Enter a username:";
  gets(uD.username);
   gotoxy(17,6)
  cout << "Enter a new password:";
  while (int i = 0 < 9)
   {
	 uD.password[i] = getch();
	 cout << "*";
	 ++i;
   }
    gotoxy(16,7)
   cout << "Re-enter the password:";
    while (int i = 0 < 9)
    {
       repass[i] = getch();
       cout << "*";
   	   ++i;
    }
    cout << "Enter your personal secret sequrity name : ";
    gets(securityq);

    if (strcmp(uD.pass,repass)==0)
    {
        cout << "Saving... Please wait...";
        	fout.write((char*)&uD, sizeof(uD));
				delay(100);
				cout << "Password directory has been updated ...";
				delay(100);
				loadingSequence();
				mainMenu();
	}
	else
    {
    	cout << "There is some unexpected problem";
		delay(100);
		clrscr();
		cout << "Restarting...";
		delay(100);
		loadingSequence();
		passwordMenu();
	}
	fout.close();
}
void userCheck()
{
		ifstream fin("users.dat",ios::in|ios::binary);
		 int flagu = 0, flagp = 0;
		 char usn[12], pwd[12];
		  gotoxy(26, 1);
		cout << "Welcome back !!! ";
		  gotoxy(29,10);
		cout << "Username : ";
		  gets(usn);
		  gotoxy(29,11);
		cout << "Password : ";
		    char pwd[9];
			while(int i=0 < 9 )
			{ 
		      pwd[i] = getch();
			  cout << "*";
			  ++i;
			}

		while(fin.read((char*)&uD,sizeof(uD)))
		{
			if (strcmpi(uD.username, usn) == 0)
				flagu = 1;
			if (strcmp(uD.password, pwd) == 0)
				flagp = 1;
		}
    	if (flagu == 1 && flagp == 1)
    	{  gotoxy(29,12);
			cout << "Access granted... "; 
			strcpy(usn, username);
			strcpy(uD.firstname, firstname);
		    fin.close();
			delay(100);
			loadingSequence();
			mainmenu(); 
		} 
		else {
			char erch;
			fin.close();
			 gotoxy(29, 18);
			cout << "The input details are wrong.....";
			 gotoxy(29, 19);
			cout << "Press any key to try again ...";
			cout << "Press F key if you forgot the password . (f/F)";
			cin >> erch;

			if (erch == 'f' || erch == 'F')
				forgotPassword();
			else
			{
				delay(100);
				loadingSequence();
				passwordMenu();
			}
		}
}	
void forgotPassword()
    {
		ifstream fin("users.dat", ios::in | ios::binary);
		char ans[10];
		 gotoxy(29, 10);
		cout<<"Enter the security answer to proceed..."
		gotoxy(29, 11);
		gets(ans);
		if (strcmp(uD.securityq, ans) == 0) {
			delay(100);
			loadingSequence();
			mainmenu();
		}
		else {
			delay(100);
			loadingSequence();
			passwordMenu();
		}
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
			for (int x = 1; x < 80; x++)
			{
				gotoxy(x, y);
				cout << "█";
			}
		else
		{
			gotoxy(1, y);
			cout << "█";
			gotoxy(79, y);
			cout << "█";
		}
	}
	gotoxy(2, 2);

}
void loadingSequence()
{
    clrscr();

    for (int y = 0; y < 26; y++)
		for (int x = 0; x < 80; x++)
		       {
			gotoxy(x,y);
			cout << "█";
			delay(2);
		}
	delay(100);
	clrscr();
	delay(250);
}
void delay(int x)
{
	float j = 0;

	for (int i = 1; i < x; i++);
	   for (int k=1;k<100;k++)
       {
           j=43*21/37;
           k=34*19;
           k=k/10;
           j=j/435;
       }
}
