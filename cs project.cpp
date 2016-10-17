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

		}sn;

		public:
                void search(int gno){}  // this function has to be overloaded to be able to search with name , grno and class.
				void search(int nam){}  // it normally displays the details 
                void search(int div){}	// it also gives option to edit the detail OR go back 
				void report() // this function provides option for choosing student or class report 
                                void studentReport(int gno){}  // this function displays the report of a student..
	   			void classReport(){} //this function displays the ranking of all the students (from stuDet.dat file).
			    void newAdmission() {
					
					ofstream thefile ("stuDet.dat",ios::binary|ios::app|ios::out);
					
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
					gotoxy(12,12);
					cout << " Section  : ";
					 gets(sn.section);
					gotoxy(4,14);
					cout << " Building  : ";
					 cin >> sn.a.building;
					gotoxy(12,14);
					cout << " Block  : ";
					 cin >> sn.a.block;
					gotoxy(20,14);
					cout << " Road  : ";
					 cin >> sn.a.road;
					gotoxy(4,16);
					cout << " ZIP  : ";
					 cin >> sn.a.zip;
					gotoxy(12,16);
					cout << " P.O. Box  : ";
					 cin >> sn.a.pobox;
					gotoxy(20,16);
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
					
					thefile.write((char *)&s,sizeof(s));
					thefile.close();
			}
				void editDetail(int gno) {      //this function has to be improved , it currently dosen't replace the older structure ;
				                                // it instead keeps the old one AND appends a new structure into the file.. 
				  ifstream thefile ("stuDet.dat",ios::binary|ios::in);

				  while (!thefile.eof()) {
					  
					  thefile.read((char *)&sn,sizeof(sn));
					  	  
				   if(sn.grno==gno){
					   
					gotoxy(3,6);
                    cout << "You have to re-enter the detail even if you don't want to alter it. "					
					gotoxy(4,6);
					cout << " Student's Name : " << sn.name ;
					 gotoxy(4,7);
					 gets(sn.name);
					gotoxy(4,8);
					cout << " Father's name  : " << sn.fName;
					 gotoxy(4,9);
					 gets(sn.fName);
					gotoxy(4,10);
					cout << " Mother's name  : " << sn.mName;
					 gotoxy(4,11);
					 gets(sn.mName);
					gotoxy(4,12);
					cout << " Class  : " << sn.division;
					 gotoxy(4,13);
					 gets(sn.division);
					gotoxy(12,12);
					cout << " Section  : " << sn.section;
					 gotoxy(12,13);
					 gets(sn.section);
					gotoxy(4,14);
					cout << " Building  : " << sn.a.building;
					 gotoxy(4,15);
					 cin >> sn.a.building;
					gotoxy(12,14);
					cout << " Block  : " << sn.a.block;
					 gotoxy(12,15);
					 cin >> sn.a.block;
					gotoxy(20,14);
					cout << " Road  : " << sn.a.road;
					 gotoxy(20,15);
					 cin >> sn.a.road;
					gotoxy(4,16);
					cout << " ZIP  : " << sn.a.zip;
					 gotoxy(4,17);
					 cin >> sn.a.zip;
					gotoxy(12,16);
					cout << " P.O. Box  : " << sn.a.pobox;
					 gotoxy(12,17);
					 cin >> sn.a.pobox;
					gotoxy(20,16);
					cout << " Flat  : " << sn.a.flat;
					 gotoxy(20,17);
					 cin >> sn.a.flat;
					gotoxy(4,18);
					cout << " Landline no. : " << sn.p.home;
					 gotoxy(4,19);
					 cin >> sn.p.home;
					gotoxy(4,20);
					cout << " Mobile no. (One) : " << sn.p.one;
					 gotoxy(4,21);
					 cin >> sn.p.one;
					gotoxy(4,22);
					cout << " Mobile no. (Two) : " << sn.p.two;
					 gotoxy(4,23);
					 cin >> sn.p.two;
						  
					  }
				  }
                    thefile.close();

					ofstream thefile ("user.dat",ios::binary|ios::app|ios::out);
					thefile.write((char *)&s,sizeof(s));
					thefile.close();
								
				}
				void displayDetails(int gno) {
					
				  ifstream thefile ("stuDet.dat",ios::binary|ios::in);

				  while (!thefile.eof()) {
					  
					  thefile.read((char *)&sn,sizeof(sn));
					  	  
				   if(sn.grno==gno){
					   
                     gotoxy(4,6);
					cout << " Student's Name : " << sn.name ;
					 gotoxy(4,8);
					cout << " Father's name  : " << sn.fName;
					 gotoxy(4,10);
					cout << " Mother's name  : " << sn.mName;
					 gotoxy(4,12);
					cout << " Class  : " << sn.division;
					 gotoxy(12,12);
					cout << " Section  : " << sn.section;
					 gotoxy(4,14);
					cout << " Building  : " << sn.a.building;
					 gotoxy(12,14);
					cout << " Block  : " << sn.a.block;
					 gotoxy(20,14);
					cout << " Road  : " << sn.a.road;
					 gotoxy(4,16);
					cout << " ZIP  : " << sn.a.zip;
					 gotoxy(12,16);
					cout << " P.O. Box  : " << sn.a.pobox;
					 gotoxy(20,16);
					cout << " Flat  : " << sn.a.flat;
					 gotoxy(4,18);
					cout << " Landline no. : " << sn.p.home;
					 gotoxy(4,20);
					cout << " Mobile no. (One) : " << sn.p.one;
					 gotoxy(4,22);
					cout << " Mobile no. (Two) : " << sn.p.two;
				   }
				  }
				  
				  thefile.close();
						  
				}
				void marksManager(int gno) {   // has to be integrated into the othere three functions...
                  for(int i = 0; i < 40; i++)
					  if(sn.grno==gno){
						  
						  cout << "Enter mark One   (Physics)         : ";
						  cout << "Enter mark Two   (Chemistry)       : ";
						  cout << "Enter mark Three (Mathematics)     : ";
						  cout << "Enter mark Four  (Computer Science): ";
						  cout << "Enter mark Five  (English)         : ";
					  }
				}

		}sD;
		class userDetails    // has scope for improvement...
		{
			char firstname[10], lastname[10], securityq[10];
			char username [12], password[9] ;

		public: void resetData() 
		        { 
			        ofstream fout("users.dat", ios::app | ios::binary|ios::out);
			        username = "  "; 
					password = "  "; 
					firstname = " "; 
					lastname = "  ";
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
****************************************************************************************************
// report                                                                                          #
****************************************************************************************************
void report()//using this function to choose between student and class report
{
        char ch;

	cout<<"\n\n\n\tRESULT MENU";
	cout<<"\n\n\n\t1. Class Report";
	cout<<"\n\n\t2. Student Report Card";
	cout<<"\n\n\n\tEnter Choice (1/2)? ";
	cin>>ch;
	clrscr();
	switch(ch)
	{
	case '1' : studentreport();
	           break;
	case '2' : classreport(); 
	           break;
        }
 }  
void studentreport(int gno)//using this to read from file and display it
{
          ifstream thefile ("stuDet.dat",ios::binary|ios::in);
              while(!fin.eof())
              {
                thefile.read((char *)&sn,sizeof(sn));
		gotoxy(4,5);
				    if(sn.grno==gno){
				
				        cout << " Student's Name : " << sn.name ;
					 gotoxy(4,8);
					cout << " Father's name  : " << sn.fName;
					 gotoxy(4,10);
					cout << " Mother's name  : " << sn.mName;
					 gotoxy(4,12);
					cout << " Class  : " << sn.division;
					 gotoxy(12,12);
					cout << " Section  : " << sn.section;
					 gotoxy(4,14);
					cout << " Building  : " << sn.a.building;
					 gotoxy(12,14);
					cout << " Block  : " << sn.a.block;
					 gotoxy(20,14);
					cout << " Road  : " << sn.a.road;
					 gotoxy(4,16);
					cout << " ZIP  : " << sn.a.zip;
					 gotoxy(12,16);
					cout << " P.O. Box  : " << sn.a.pobox;
					 gotoxy(20,16);
					cout << " Flat  : " << sn.a.flat;
					 gotoxy(4,18);
					cout << " Landline no. : " << sn.p.home;
					 gotoxy(4,20);
					cout << " Mobile no. (One) : " << sn.p.one;
					 gotoxy(4,22);
					cout << " Mobile no. (Two) : " << sn.p.two;
				        cout << "      Physics           : "<<sn.m.m1;
                                         gotoxy(4,24);
				        cout << "      Chemistry         : "<<sn.m.m2;
                                         gotoxy(4,26);  
			                cout << "      Mathematics       : "<<sn.m.m3;
                                         gotoxy(4,28);
			                cout << "      Computer Science  : "<<sn.m.m4;
                                         gotoxy(4,30);
			                cout << "      English           : "<<sn.m.m5;
                                         gotoxy(4,32);  	
                                  }
                   
                 fin.close();
            }
void ranking()//this function adds all the marks and ranks the in order
{
    ifstream thefile("stuDet.dat,ios::binary|ios::in);
        while(!thefile.eof())
         {
           thefile.read((char*)&sn,sizeof(sn));
           
         }
              float TotalS=0;
              int a[100],j=0,k=0;

          for(int i=0;i<40;i++)
           {
              
              TotalS=sn.m.m1+sn.m.m2+sn.m.m3+sn.m.m4+sn.m.m5/5;
               a[j]=TotalS; 
               j++;           
            }
              while(k>0)
                  {              
                    if(a[k]>a[k+1])
                      {
                       temp=a[k];
                      }
                       else if(a[k]<a[k+1])
                        {
                         temp=a[k+1];
                        }
                        a[k]=temp;
                         k++;
                  }                  
	void classreport()
{
    ifstream thefile ("stuDet.dat",ios::binary|ios::in);
    while(!thefile.eof())
    {
      if(!thefile)
	{
		cout<<"File could not be open !! Press any Key...";
		getch();
		return;
	}
     thefile.read((char *)&sn,sizeof(sn));                                   
        {
        	cout << " Student's Name : " << sn.name<<'\t' ;     
					 gotoxy(4,8);
					cout << " Father's name  : " << sn.fName<<'\t';
					 gotoxy(4,10);
					cout << " Mother's name  : " << sn.mName<<'\t';
					 gotoxy(4,12);
					cout << " Class  : " << sn.division<<'\t';
					 gotoxy(12,12);
					cout << " Section  : " << sn.section<<'\t';
					 gotoxy(4,14);
					cout << " Building  : " << sn.a.building<<'\t';
					 gotoxy(12,14);
					cout << " Block  : " << sn.a.block<<'\t';
					 gotoxy(20,14);
					cout << " Road  : " << sn.a.road<<'\t';
					 gotoxy(4,16);
					cout << " ZIP  : " << sn.a.zip<<'\t';
					 gotoxy(12,16);
					cout << " P.O. Box  : " << sn.a.pobox<<'\t';
					 gotoxy(20,16);
					cout << " Flat  : " << sn.a.flat<<'\t';
					 gotoxy(4,18);
					cout << " Landline no. : " << sn.p.home<<'\t';
					 gotoxy(4,20);
					cout << " Mobile no. (One) : " << sn.p.one<<'\t';
					 gotoxy(4,22);
					cout << " Mobile no. (Two) : " << sn.p.two<<'\t';
				        cout << "      Physics           : "<<sn.m.m1<<'\t';
                                         gotoxy(4,24);
				        cout << "      Chemistry         : "<<sn.m.m2<<'\t';
                                         gotoxy(4,26);  
			                cout << "      Mathematics       : "<<sn.m.m3<<'\t';
                                         gotoxy(4,28);
			                cout << "      Computer Science  : "<<sn.m.m4<<'\t';
                                         gotoxy(4,30);
			                cout << "      English           : "<<sn.m.m5<<'\t';
                                         gotoxy(4,32); 
	}
	getch();
	thefile.close();
     
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
