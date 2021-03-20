//**************W E L C O M E  TO  H O S P I T A L  M A N A G E M E N T   S Y S T E M*************************
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include<iostream>
#include<string.h>
#include<windows.h>
#include<dos.h>
#include<fstream>
using namespace std;
void OpenTofile();
void SaveTofile();
void AvailDr();
void SearchById();
void Appoint();
void AppointMenu();
void BookSeatEmergency();
void Appoint_info();
void EmergencySeat_info();
void Check_info();
void DeleteData();//for deleting appointment_info
void updateAppoint();
void goMenu();
void goManu();
void goMunu();
void showManu();
void goIf();
void Patient_info();
void DeleteRecords();
void AboutHos();
void listRecord();
void addDiagno_info();
const int maxrow = 100;
int choice;
//string exist;
string patientID;
//string seat;
//for add patient;
string patientId[maxrow];
string patientName[maxrow];
string patientContact[maxrow];
string patientAge[maxrow];
string patientBlood_gp[maxrow];
string patEarlierDisease[maxrow];
string patiententryDate[maxrow];
//for Diagnosis
string Symptoms[maxrow];
string Diagnosis[maxrow];
string Medicine[maxrow];
string Admission[maxrow];
string Ward[maxrow];
//for booking appointments
string patient_Id[maxrow];
string patient_Name[maxrow];
string patient_time[maxrow];
string patient_Contact[maxrow];
string patient_Age[maxrow];
string address[maxrow];
string patient_Problem[maxrow];
string patient_entryDate[maxrow];
//for emergencySeatBooking
string patientid[maxrow];
string patientname[maxrow];
string patientno[maxrow];
string patientage[maxrow];
string patientnum[maxrow];
string patientproblem[maxrow];
string patientaddress[maxrow];
string patientdate[maxrow];

//#################################################################>> A D D I N G  P A T I E N T###############################################################################################################################################
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//===========================================================================================================================================================================================================================================
void OpenTofile()
{
	string line;
	ifstream myfile("D:\\New folder\\DataBase.txt");
	if(myfile.is_open())
	{
		int x = 0;
		while (getline(myfile, line))
		{
		patientId[x] = line.substr(0, 3);
		patientName[x] = line.substr(4, 1 - 4);
		patientContact[x] = line.substr(5, 1 - 5);
		patientAge[x] = line.substr(6, 1- 6);
		patientBlood_gp[x] = line.substr(7, 1-7);
		patEarlierDisease[x] = line.substr(8, 1 - 8);
		patiententryDate[x] = line.substr(9, 1 - 9);
		x++;
	}
}
	else
	{
		cout << "\t\tEnable to open file!!\n";
	}
	}
void addPatient()//adding patient to our database
{
	i:
    char patient_name[50]; // using character type variable
    char patient_no[100];
    char patient_age[8];
    char patient_num[15];
    char patient_Blood_gp[20];
    char patient_eardisease[150];
    char patient_entrydate[10];
    char patient_entryDate[20];
    cin.ignore();
    system("cls");
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "\t\t\t\t             >>> Add New Patient <<<                \n";
    cout << "\t\t\t\t+===================================================+\n";
    cout << endl;
    cout << "\t\t\t\t->> Enter Patient ID: ";
    cin.getline(patient_no, 100);
    cout << endl;
    cout << "\t\t\t\t->> Enter Patient Name: ";
    cin.getline(patient_name, 50);
    cout << endl;
    cout << "\t\t\t\t->> Age : ";
    cin.getline(patient_age, 8);
    cout << endl;
    cout << "\t\t\t\t->> Patient Contact Number : ";
    cin.getline(patient_num, 15);
    cout << endl;
    cout << "\t\t\t\t->> Blood Group : ";
    cin.getline(patient_Blood_gp, 20);
    cout << endl;
    cout << "\t\t\t\t->> Any Earlier Disease : ";
    cin.getline(patient_eardisease, 150);
    cout << endl;
    cout << "\t\t\t\t->> Patient Entry Date (DD-MM-YY): ";
    cin.getline(patient_entryDate, 20);
    cout << "\n\t\t\t\t+====================================================+\n";

    for(int i = 0; i < maxrow; i++)
    {
        if(patientId[i] == "\0")
        {
            patientId[i] = patient_no;
            patientName[i] = patient_name;
            patientContact[i] = patient_num;
            patientAge[i] = patient_age;
            patientBlood_gp[i] = patient_Blood_gp;
            patEarlierDisease[i] = patient_eardisease;
            patiententryDate[i] = patient_entryDate;
			cout << "\n\t\t\t\t You have successfully added to our patient list!!";
			cout << "\n\n\t\t\t\t+====================================================+\n";
			system("pause");//using system("pause") is for terminating program and continuing program
			system("cls");//using system("cls") for clear console
			showManu();//calling main_menu function
			break;
		}
        else if(patientId[i] == patient_no)
        {
        	cout << "\n\t\t\t\tPatient ID is already existed in our DataBase, try anotherone!!\n";
        	cout << "\n\t\t\t\t+=======================================================+";
        	goManu();
        	goto i;// using goto statement 
    }

}
}
//#################################################################ADD DIAGNOSIS REPORT###############################################################################################################################################
//====================================================================================================================================================================================================================================
void addDiagno_info(string search)//adding patient diagnoisis information
{
    cout << endl;
    cout << "\n\t\t\t\t            >>> Current Record(s) <<<\n";
    cout << "\t\t\t\t+------------------------------------------------+\n";
    cout << "\t\t\t\t|                +Hospital Database+             |\n";
    cout << "\t\t\t\t+------------------------------------------------+\n";
    cout << endl;
    char symptoms[500];
    char diagnosis[500];
    char medicine[500];
    char admission[30];
    char ward[15];

    int count = 0;

    for(int i = 0; i < maxrow; i++)
    {
        if(patientId[i] == search)
        {
            count++;
        cout << "\t\t\t\t+============================================+\n\n";
        cout << "\n\t\t\t\t|->> Patient Unique Id : " << patientId[i] << "\n\n";
        cout << "\t\t\t\t|->> Patient Name      : " << patientName[i];
        cout << "\n\n";
        cout << "\t\t\t\t|->> Age               : " << patientAge[i];
        cout << "\n\n";
        cout << "\t\t\t\t|->> Contact Number    : " << patientContact[i];
        cout << "\n\n";
        cout << "\t\t\t\t|->> Blood Group       : " << patientBlood_gp[i];
        cout << "\n\n";
        cout << "\t\t\t\t|->> Major Disease     : " << patEarlierDisease[i];
        cout << "\n\n";
        cout << "\t\t\t\t|->> Patient Entry Date: " << patiententryDate[i] << "\n";
        cout << "\t\t\t\t+============================================+\n";
        cout << "\t\t\t\t|+> Symptoms : ";
        cin.getline(symptoms, 500);
        cout << endl;
        cout << "\t\t\t\t|+> Diagnosis : ";
        cin.getline(diagnosis, 500);
        cout << endl;
        cout << "\t\t\t\t|+> Medicine : ";
        cin.getline(medicine, 500);
        cout << endl;
        cout << "\t\t\t\t|+> Admission Required? (Yes / No) : ";
        cin.getline(admission, 30);
        cout << endl;
        cout << "\t\t\t\t|+> Enter the type of Ward : ";
        cin.getline(ward, 15);
        cout << endl;
        cout << "\t\t\t\t+===========================================+\n";
        //using array in a function
        Symptoms[i] = symptoms;// assigning character type variables to global string variables for storing data
        Diagnosis[i] = diagnosis;
        Medicine[i] = medicine;
        Admission[i] = admission;
        Ward[i] = ward;

        cout << "\t\t\t\t" << ">> " << ward << " ward is alotted Succesfully!!\n";
        cout << "\t\t\t\t=============================================\n";
        break;//using break statement for termination of loop and next statement follows the loop
        }
        if(count == 0)
        {
            cout << "\n\n\t\t\t\t --Record not found!!--\n";
            break;
        }
    }
}
/*********************************************************************
--------------------------------------------------------------------List Of Patients--------------------------------------------------------------------------------------
**********************************************************************/
void listRecord()//showing list of all patients that has been added recently
{
    system("cls");

    int count = 0;
    cout << endl << endl;
    cout << "\t\t\t\t+------------------------------------------------+\n";
    cout << "\t\t\t\t|                +Hospital Database+             |\n";
    cout << "\t\t\t\t+------------------------------------------------+\n";

    cout << "\t\t\t\t               +LIST OF ALL PATIENTS+          \n";
    for (int i = 0; i < maxrow; i++)
    {
        if(patientId[i] != "\0")
        {
            count++;
    cout << "\t\t\t\t+=================================================+\n\n";
    cout << "\t\t\t\t|->> No                :  " << count << endl << endl;
    cout << "\t\t\t\t|->> Patient Unique ID :  " << patientId[i] << endl << endl;
    cout << "\t\t\t\t|->> Patient Name      :  " << patientName[i]  << endl << endl;
    cout << "\t\t\t\t|->> Age               :  " << patientAge[i] << endl << endl;
    cout << "\t\t\t\t|->> Contact Number    : " << patientContact[i] << endl << endl;
    cout << "\t\t\t\t|->> Blood Group       :  " << patientBlood_gp[i]<< endl << endl;
    cout << "\t\t\t\t|->> Major Disease     :  " << patEarlierDisease[i]  << endl << endl;
    cout << "\t\t\t\t|->> Patient Entry Date:  " << patiententryDate[i] << endl << endl;
    cout << "\t\t\t\t+===============================================+\n\n";
        }
    }
    if(count == 0)
    {
        cout << endl;
        cout << "\t\t\t\t-No record found!!" << endl << endl;
    }
}
/*********************************************************************
---------------------------------------------------------Search by Patient ID--------------------------------------------------------------------------------------
**********************************************************************/
void SearchById(string search)// show full history of patients
{
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "\t\t\t\t          >>> Patient Current Record(s) <<<\n\n";
    cout << "\t\t\t\t+------------------------------------------------+\n";
    cout << "\t\t\t\t|                +Hospital Database+             |\n";
    cout << "\t\t\t\t+------------------------------------------------+\n";
    cout << endl;
    int counter = 0;
    for(int i = 0; i < maxrow; i++)
    {

        if(patientId[i] == search)
        {
            counter++;
    cout << "\t\t\t\t+===============================================+\n";
    cout << "\t\t\t\t|->> Patient Unique ID : " << patientId[i] << endl;
    cout<< endl;
    cout << "\t\t\t\t|->> Patient Name      : " << patientName[i]  << endl;
    cout<< endl;
    cout << "\t\t\t\t|->> Age               : " << patientAge[i] << endl;
    cout << endl;
    cout << "\t\t\t\t|->> Contact Number    : " << patientContact[i] << endl;
    cout << endl;
    cout << "\t\t\t\t|->> Blood Group       : " << patientBlood_gp[i]<< endl;
    cout << endl;
    cout << "\t\t\t\t|->> Entry Date        : " << patiententryDate[i]  << endl;
    cout << endl;
    cout << "\t\t\t\t|->> Major Disease     : " << patEarlierDisease[i] << endl;
    cout << endl;
    cout << "\t\t\t\t+================================================+\n\n";
    cout << "\t\t\t\t|+> Symptoms   : " << Symptoms[i] << endl;
    cout << endl;
    cout << "\t\t\t\t|+> Diagnosis  : " << Diagnosis[i] << endl;
    cout << endl;
    cout << "\t\t\t\t|+> Medicine   : " << Medicine[i] << endl;
    cout << endl;
    cout << "\t\t\t\t|+> Admission Required? (Y/ N) : " << Admission[i] << endl;
    cout << endl;
    cout << "\t\t\t\t|+> The type of Ward           : " << Ward[i] << endl;
    cout << "\t\t\t\t+================================================+\n\n";
        break;
        }
    }
    if(counter == 0)
    {
        cout << endl;
        cout << "\t\t\t\t----No such record found!------\n\n";
    }
}
//#################################################################>> A B O U T H O S P I T A L<<###############################################################################################################################################
//====================================================================================================================================================================================================================================
void AboutHos()// about our hospital
{
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "\t\t\t\t==================================================================\n";
    cout << "\t\t\t\t+                    WELCOME  TO  OUR HOSPITAL                   +\n";
    cout << "\t\t\t\t==================================================================\n";
    cout << "\t\t\t\t-> What is Hospital?\n\n";
    cout << "\t\t\t\t+> A hospital is a place where a person goes to be healed when he\n";
    cout << "\t\t\t\t   or she is sick or injured.\n";
    cout << "\t\t\t\t+> The difference between a hospital and other healthcare places \n";
    cout << "\t\t\t\t   like a clinic or a doctor's office is that a hospital will have\n";
    cout << "\t\t\t\t   beds where patients can stay overnight.\n\n";
    cout << "\t\t\t\t-> Facilities available in our Hospital.\n\n";
    cout << "\t\t\t\t+> 1. Ambulatory Surgical Centers\n";
    cout << "\t\t\t\t+> 2. Birth Centers\n";
    cout << "\t\t\t\t+> 3. Blood Banks Systems\n";
    cout << "\t\t\t\t+> 4. Diabetes Education Centers\n";
    cout << "\t\t\t\t+> 5. Dialysis Centers\n\n";
    cout << "\t\t\t\t-> THANKS FOR CHOOSING US!! other facilities are also available\n";
    cout << "\t\t\t\t-> Our main purpose of making hospital more like a home is, because\n";
    cout << "\t\t\t\t-> we are providing a productive atmosphere to our patients.\n";
    cout << "\t\t\t\t------------------------------------------------------------------\n\n";
}
/***************>>>>>DELETING RECORDS OF PATIENT FROM HOSPITAL>>>>>*****************************************************
--------------------------------------------------HOSPITAL MANAGEMENT SYSYTEM-------------------------------------------------------------------------------------
**********************************************************************/
void DeleteRecords(string search)// for delting records of patients
{
    int count = 0;
    for(int i = 0; i < maxrow; i++)
    {
        if(patientId[i] == search)
        {
            count++;
            patientId[i] = "";
            patientName[i] = "";
            patientAge[i] = "";
            patientBlood_gp[i]= "";
            patEarlierDisease[i] = "";
            patiententryDate[i] = "";
            system("cls");
	        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tDeleting patient data, please wait...2%";
		    Sleep(800);
		    cout << "\b\b............57%";
			Sleep(800);
		    cout << "\b\b\b................100%";
		    Sleep(800);
		    system("cls");

	        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t+********PATIENT DATA SUCCESSFULLY DELETED***********+\n";
            break;
        }
    }
    if(count == 0)
    {
        cout <<"\n\t\t\t\t ID does not exist!!\n";
    }
}
/**********************************************************************
------------------------------------------------------->>>>A B O U T U S  <<<-----------------------------------------------------------------------------------
**********************************************************************/
void Patient_info()// menu for deleting, showing and searching history of patients
{
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "\t\t\t\t****************+ H O S P I T A L  D A T A B A S E +******************\n\n";
	cout << "\t\t\t\t-> Choose the following options\n\n ";
	cout << "\t\t\t\t+> 1. Show full history of Patient by ID \n\n";
	cout << "\t\t\t\t+> 2. Display List Of All Patients\n\n";
	cout << "\t\t\t\t+> 3. Delete Records of Patients\n\n";
	cout << "\t\t\t\t+> 4. Go back to Main-menu\n\n";
	cout << "\t\t\t\t=============================================\n\n";
	cout << "\t\t\t\t->> Your Choice: ";
	cin >> choice;
	if(choice == 1)// using if else statement
	{
		cin.ignore();
		system("cls");
		cout << "\n\n\t\t\t\t->> Enter patient unique ID: ";
		getline(cin, patientID);
		system("cls");
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tLOADING DATA, please wait...2%";
        Sleep(200);// suspending execution for a period of time
    	cout << "\b\b........47%";
        Sleep(200);
        cout << "\b\b\b.......78%";
        Sleep(200);
        cout << "\b\b\b..........100%";
        Sleep(200);
        system("cls");
		SearchById(patientID);
		cout << endl;
		system("pause");
		system("cls");
		Patient_info();// calling patient info for records
	}
	else if(choice == 2)
	{
		system("cls");
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tLOADING DATA, please wait...2%";
        Sleep(200);
    	cout << "\b\b........47%";
        Sleep(200);
        cout << "\b\b\b.......78%";
        Sleep(200);
        cout << "\b\b\b..........100%";
        Sleep(200);
		listRecord();
		cout << endl;
		system("pause");
		system("cls");
		Patient_info();
	}
	else if(choice == 3)
	{
		        cin.ignore();
                system("cls");
                cout << endl;
                cout << endl;
                cout << "\t\t\t->> Delete by Patient Unique Id : ";
                getline(cin, patientID);
                DeleteRecords(patientID);
                cout << endl;
                cout << endl;
                cout << "\n\n\n\n\n";
                system("pause");
                system("cls");
                Patient_info();
	}
	else if(choice == 4)
	{
		system("cls");
		showManu();
	}
	else
	{
		cout << "\n\t\t\t\tInvalid Choice, Please Try Again!\n";
		cout << endl;
		system("pause");
		system("cls");
		Patient_info();
	}
}
//Now move on, to the appointment
void Appoint_info()// using this function for history of appointment
{
    cout << endl << endl;
    cout << endl;
    cout << "\t\t\t\t+------------------------------------------------+\n";
    cout << "\t\t\t\t|                +Hospital Database+             |\n";
    cout << "\t\t\t\t+------------------------------------------------+\n";
    cout << "\t\t\t\t          +Patient Appointment Information+       \n";
    int count = 0;
    for (int i = 0; i < maxrow; i++)
    {
        if(patient_Id[i] != "\0")
        {
            count++;
    cout << "\t\t\t\t+===============================================+\n\n";
    cout << "\t\t\t\t|->> Appointment No      :  " << patient_Id[i] << endl << endl;
    cout << "\t\t\t\t|->> Apointment Time(AM/PM) : " << patient_time[i] << endl << endl;
    cout << "\t\t\t\t|->> Patient Name        :  " << patient_Name[i]  << endl << endl;
    cout << "\t\t\t\t|->> Age                 :  " << patient_Age[i] << endl << endl;
    cout << "\t\t\t\t|->> Contact Number      :  " << patient_Contact[i] << endl << endl;
    cout << "\t\t\t\t|->> Address             :  " << address[i] << endl << endl;
    cout << "\t\t\t\t|->> Patient Problem     :  " << patient_Problem[i]  << endl << endl;
    cout << "\t\t\t\t|->> Patient Entry Date  :  " << patient_entryDate[i] << endl << endl;
    cout << "\t\t\t\t+===============================================+\n";
        }
    }
    if(count == 0)
    {
    	cout << "\n\t\t\t\t------No Record Found!!-------\n\n\n";
	}
}
//Displaying how many emergency appointment that has been added to our Database
void EmergencySeat_info()
{
    cout << endl << endl;
    cout << endl;
    cout << "\t\t\t\t+------------------------------------------------+\n";
    cout << "\t\t\t\t|                +Hospital Database+             |\n";
    cout << "\t\t\t\t+------------------------------------------------+\n";

    cout << "\t\t\t\t       +Emergency Seat Booking Information+       \n";
    int counter = 0;
    for (int i = 0; i < maxrow; i++)
    {
        if(patientname[i] != "\0")
        {
    counter++;
    cout << "\t\t\t\t+===============================================+\n\n";
    //cout << "\t\t\t\t|->> Emergency   No      :  " << patientid[i] << endl << endl;
    cout << "\t\t\t\t|->> Patient Name        :  " << patientname[i]  << endl << endl;
    cout << "\t\t\t\t|->> Age                 :  " << patientage[i] << endl << endl;
    cout << "\t\t\t\t|->> Contact Number      :  " << patientnum[i] << endl << endl;
    cout << "\t\t\t\t|->> Address             :  " << patientaddress[i]<< endl << endl;
    cout << "\t\t\t\t|->> Patient Problem     :  " << patientproblem[i]  << endl << endl;
    cout << "\t\t\t\t|->> Appointment Date    :  " << patientdate[i] << endl << endl;
    cout << "\t\t\t\t+===============================================+\n";
        }
    }
    if(counter == 0)
    {
    	cout << "\n\t\t\t\t-------No Record found!!------\n\n\n";
	}
}
//Now checking the info of patient appointment or reither than emergency appointments
void Check_info()
{
    cout << "\n\n\n\t\t\t\t+>> Checking Appointment Info <<+\n";
    cout << "\t\t\t\t===========================================\n\n";
    cout << "\t\t\t\t-> 1. Appointment Information\n\n";
    cout << "\t\t\t\t-> 2. Emergency Appointment Info\n\n";
    cout << "\t\t\t\t-> 3. Update Appointment\n\n";
    cout << "\t\t\t\t-> 4. Delete Appointment\n\n";
    cout << "\t\t\t\t-> 5. Go Back to Main-Menu\n\n";
    cout << "\t\t\t\t===========================================\n";
    cout << "\t\t\t\t Your Choice : ";
    cin >> choice;
    if(choice == 1)
    {
    	system("cls");
    	cout << "\n\n\n\n\n\n\n\n\t\t\t\tLoading Data, please wait...2%";
        Sleep(400);
        cout << "\b\b........47%";
        Sleep(400);
        cout << "\b\b\b.........78%";
        Sleep(400);
        cout << "\b\b\b............100%";
        Sleep(400);
        system("cls");
    	Appoint_info();
    	system("pause");
    	system("cls");
    	Check_info();
	}
	else if(choice == 2)
	{
		system("cls");
        cout << "\n\n\n\n\n\n\n\n\t\t\t\tLoading Data, please wait...2%";
        Sleep(400);
        cout << "\b\b........47%";
        Sleep(400);
        cout << "\b\b\b.........78%";
        Sleep(400);
        cout << "\b\b\b............100%";
        Sleep(400);
        system("cls");
		EmergencySeat_info();
		system("pause");
		system("cls");
		Check_info();
	}
	else if(choice == 3)
	{
			system("cls");
			updateAppoint();
			system("pause");
			system("cls");
			Check_info();
	}
	else if(choice == 4)
		{
			system("cls");
			DeleteData();
			system("pause");
			system("cls");
			Check_info();
	}
	else if(choice == 5)
	{
		system("cls");
		AppointMenu();
	}
	else
	{
		cout << "\n\t\t\t\tinvalid!!";
		system("pause");
		system("cls");
		showManu();
	}
	}
//This phase is also for the user to input appointment
void Appoint()
{
	char patient_name[50];
    char patient_no[100];
    char patient_age[8];
    char patient_num[15];
    char patient_problem[20];
    char appointtime[20];
    char patient_address[150];
    char patient_entrydate[20];
    k:
    cin.ignore();
    cout << "\t\t\t\t===============================\n";
    cout << "\t\t\t\t->> Appointment No : ";
    cin.getline(patient_no, 100);
    cout << endl;
    cout << "\t\t\t\t->> Enter Patient Name : ";
    cin.getline(patient_name, 50);
    cout << endl;
    cout << "\t\t\t\t->> Age : ";
    cin.getline(patient_age, 8);
    cout << endl;
    cout << "\t\t\t\t-> Appointment Time(AM / PM) : ";
    cin.getline(appointtime, 20);
    cout << endl;
    cout << "\t\t\t\t->> Patient Contact Number : ";
    cin.getline(patient_num, 15);
    cout << endl;
    cout << "\t\t\t\t->> Patient Problem : ";
    cin.getline(patient_problem, 20);
    cout << endl;
    cout << "\t\t\t\t->> Address : ";
    cin.getline(patient_address, 150);
    cout << endl;
    cout << "\t\t\t\t->> Appointment Date (DD-MM-YY): ";
    cin.getline(patient_entrydate, 20);

    for(int i = 0; i < maxrow; i++)
    {
    	if(patient_Id[i] == "\0" )
    	{
    		patient_Id[i] = patient_no;
            patient_Name[i] = patient_name;
            patient_Contact[i] = patient_num;
            patient_Age[i] = patient_age;
            patient_time[i] = appointtime;
            address[i] = patient_address;
            patient_Problem[i] = patient_problem;
            patient_entryDate[i] = patient_entrydate;
			cout << "\n\t\t\t\t Okay, Thank You. We calling you for confirmed Appoint after sometimes!";
			cout << "\n\n\t\t\t\t+====================================================+\n";
			goMenu();
			system("cls");
			break;
		}
		else if(patient_Id[i] == patient_no)
        {
        	cout << "\n\t\t\t\tAppointment No is already existed in our DataBase, try anotherone!!\n";
        	cout << "\n\t\t\t\t+=======================================================+";
        	goMenu();
        	goto k;
    }
	}
}
//Appointment Menu
void AppointMenu()
{
		cout << endl;
        cout << endl;
        cout << endl;
        cout << "\t\t\t\t\t+>> A P P O I N T M E N T  M E N U <<+\n";
        cout << "\t\t\t\t========================================================\n\n";
        cout << "\t\t\t\t=> 1. Booking Appointment & Doctor List\n\n";
        cout << "\t\t\t\t=> 2. Booking in case of Emergency\n\n";
        cout << "\t\t\t\t=> 3. Checking Appointment Info\n\n";
        cout << "\t\t\t\t=> 4. Go back to Main-Menu\n\n";
        cout << "\t\t\t\t========================================================\n\n";
        cout << "\t\t\t\t+> Your Choice: ";
        cin >> choice;
        if(choice == 1)
        {
        	system("cls");
        	AvailDr();
        	cout << endl;
        	cout << endl;
		}
		else if(choice == 2)
		{
			system("cls");
			BookSeatEmergency();
			cout << endl;
			cout << endl;
			AppointMenu();
		}
		else if(choice == 3)
		{
            system("cls");
            Check_info();
			system("pause");
			system("cls");
		}
		else if(choice == 4)
		{
			system("cls");
			showManu();
		}
		else
		{
		cout << "\n\t\t\t\tinvalid!!";
		system("pause");
		system("cls");
		showManu();
		}

}
//Adding Emergency appointments
void BookSeatEmergency()
{
	char patientNam[50];
    char patientNo[100];
    char patientAge[8];
    char patientNum[15];
    char patientProblem[20];
    char patientAddress[150];
    char patientEntrydate[20];
    cin.ignore();
    cout << "\n\n\n";
    cout << "\t\t\t\t\t-> Emergency Booking <-\n";
    cout << "\t\t\t\t===============================\n";
    //cout << "\t\t\t\t->> Appointment No : ";
    //cin.getline(patientNo, 100);
    //cout << endl;
    cout << "\t\t\t\t->> Enter Patient Name : ";
    cin.getline(patientNam, 50);
    cout << endl;
    cout << "\t\t\t\t->> Age : ";
    cin.getline(patientAge, 8);
    cout << endl;
    cout << "\t\t\t\t->> Patient Contact Number : ";
    cin.getline(patientNum, 15);
    cout << endl;
    cout << "\t\t\t\t->> Patient Problem : ";
    cin.getline(patientProblem, 20);
    cout << endl;
    cout << "\t\t\t\t->> Address : ";
    cin.getline(patientAddress, 150);
    cout << endl;
    cout << "\t\t\t\t->> Appointment Date (DD-MM-YY): ";
    cin.getline(patientEntrydate, 20);

    for(int i = 0; i < maxrow; i++)
    {
    	if(patientname[i] == "\0")
    	{
    		patientid[i] = patientNo;
            patientname[i] = patientNam;
            patientnum[i] = patientNum;
            patientage[i] = patientAge;
            patientaddress[i] = patientAddress;
            patientproblem[i] = patientProblem;
            patientdate[i] = patientEntrydate;
			cout << "\n\t\t\t\t Patient Booked Successfully!!";
			cout << "\n\n\t\t\t\t+====================================================+\n";
			system("pause");
			system("cls");
			break;
		}
	}
}
//This is for Available Doctor & appointments
void AvailDr()
{
		cout << endl;
        cout << endl;
        cout << "\t\t\t\t+>> Available Doctors & Appointments <<+\n";
        cout << "\t\t\t========================================================\n";
	    cout << "\t\t\t-> 1. Dr.Iftikhar Ahmed\t\t< Skin Specialist >\n";
	    cout << "\t\t\t------------------------------\n";
		cout << "\t\t\t Monday to Thurday			12PM to 4PM\n";
		cout << "\t\t\t Satuday & Sunday				OFF\n";
		cout << "\t\t\t--------------------------------------------------------\n";
	    cout << "\t\t\t2. Dr. Usman Tariq\t< Heart Specialist >" << endl;
	    cout << "\t\t\t------------------------------\n";
		cout << "\t\t\t Monday to Thurday			10AM to 3PM\n";
		cout << "\t\t\t Satuday & Sunday			 1PM to 2PM\n";
        cout << "\t\t\t--------------------------------------------------------\n";
	    cout << "\t\t\t3. Dr. Hashim Hussain\t< Diabetic Specialist >" << endl;
	    cout << "\t\t\t------------------------------\n";
		cout << "\t\t\t Monday to Thurday			11AM to 5PM\n";
		cout << "\t\t\t Satuday & Sunday				OFF\n";
        cout << "\t\t\t--------------------------------------------------------\n";
	    cout << "\t\t\t4. Dr. Suleman Tariq\t< Kidney Specialist >" << endl;
		cout << "\t\t\t------------------------------\n";
		cout << "\t\t\t Monday to Thurday			9AM to 6PM\n";
		cout << "\t\t\t Satuday & Sunday				OFF\n";
        cout << "\t\t\t--------------------------------------------------------\n";
	    cout << "\t\t\t5. Go Back to Main-Menu" << endl;
        cout << "\t\t\t========================================================\n";
        cout << "\t\t\tYour Choice: ";
        cin >> choice;
        if(choice == 1)
        {
        	system("cls");
        	cout << "\n\n\n\n\t\t\t\t1. Dr. Iftikhar (Skin Specialist-12PM to 4PM)\n";
        	Appoint();
        	cout << endl;
        	cout << endl;
        	system("pause");
        	system("cls");
        	AvailDr();
		}
        if(choice == 2)
        {
        	system("cls");
        	cout << "\n\n\n\n\t\t\t\t2. Dr. Usman Tariq (Heart Specialist-10AM to 3PM)\n";
        	Appoint();
        	cout << endl;
        	cout << endl;
        	system("pause");
        	system("cls");
        	AvailDr();
		}
        else if(choice == 3)
        {
        	system("cls");
        	cout << "\n\n\n\n\t\t\t\t3. Hashim Hassan (Diabetic Specialist-11AM to 5PM)\n";
        	Appoint();
        	cout << endl;
        	cout << endl;
        	system("pause");
        	system("cls");
        	AvailDr();
		}
        else if(choice == 4)
        {
        	system("cls");
        	cout << "\n\n\n\n\t\t\t\t4. Dr. Suleman Tariq (Kidney Specalist-9AM to 6PM)\n";
        	Appoint();
        	cout << endl;
        	cout << endl;
        	system("pause");
        	system("cls");
        	AvailDr();
		}
        else if(choice == 5)
        {
        	system("cls");
        	AppointMenu();
        }
        else
        {
        	cout << "\n\t\t\t\t-------invalid!!-----------";
        	goMenu();
        }
		}
/****************>>>M A I N  M E N U<<****************************************************
--------------------------------------------------H O S P I T A L M A N A G E M E N T S Y S T E M------------------------------------------------------------------------------------
**********************************************************************/
void updateAppoint()
{
	string search;
	cout << "\n\n\n\n\t\t\t-> Enter Appointment No: ";
	cin >> search;
	system("cls");
            cout << "\n\n\n\n\n\n\n\t\t\t\tLoading Data, please wait...2%";
            Sleep(400);
            cout << "\b\b........47%";
            Sleep(400);
            cout << "\b\b\b.........78%";
            Sleep(400);
            cout << "\b\b\b............100%";
            Sleep(400);
	system("cls");
	char patient_name[50];
    char patient_no[100];
    char patient_age[8];
    char patient_num[15];
    char patient_problem[20];
    char appointtime[20];
    char patient_address[150];
    cout << endl;
    cout << "\t\t\t\t+------------------------------------------------+\n";
    cout << "\t\t\t\t|                +Hospital Database+             |\n";
    cout << "\t\t\t\t+------------------------------------------------+\n";
    cout << "\t\t\t\t          +Patient Appointment Information+       \n";
    int count = 0;
    for(int i = 0; i < maxrow; i++)
    {
    	if(patient_Id[i] == search)
    	{
    	count++;
    cout << "\t\t\t\t+===============================================+\n\n";
    cout << "\t\t\t\t|->> Appointment No      :  " << patient_Id[i] << endl << endl;
    cout << "\t\t\t\t|-1. Apointment Time(AM/PM) : " << patient_time[i] << endl << endl;
    cout << "\t\t\t\t|-2. Patient Name        :  " << patient_Name[i]  << endl << endl;
    cout << "\t\t\t\t|-3. Age                 :  " << patient_Age[i] << endl << endl;
    cout << "\t\t\t\t|-4. Contact Number      :  " << patient_Contact[i] << endl << endl;
    cout << "\t\t\t\t|-5. Address             :  " << address[i] << endl << endl;
    cout << "\t\t\t\t|->> Patient Problem     :  " << patient_Problem[i]  << endl << endl;
    cout << "\t\t\t\t|->> Patient Entry Date  :  " << patient_entryDate[i] << endl << endl;
    cout << "\t\t\t\t+===============================================+\n";
    cout << "\t\t\t\t->> Choice: ";
    cin >> choice;
	if(choice == 1)
	{
		cin.ignore();
		cout << "\n\t\t\t\t-> Appointment Time(AM / PM) : ";
    	cin.getline(appointtime, 20);
    	patient_time[i] = appointtime;
                cout << "\n\t\t\t\tUpdating Data, please wait...2%";
                Sleep(400);
                cout << "\b\b........47%";
                Sleep(400);
                cout << "\b\b\b.........78%";
                Sleep(400);
                cout << "\b\b\b............100%";
                Sleep(400);
    	cout << "\n\n\t\t\t\t Update Successfully!!";
			cout << "\n\n\t\t\t\t+====================================================+\n";
			system("pause");
			system("cls");
			Check_info();
			break;
    	
	}
	else if(choice == 2)
	{
		cin.ignore();
    cout << "\n\t\t\t\t->> Enter Patient Name : ";
    cin.getline(patient_name, 50);
    patient_Name[i] = patient_name;
                cout << "\n\t\t\t\tUpdating Data, please wait...2%";
                Sleep(400);
                cout << "\b\b........47%";
                Sleep(400);
                cout << "\b\b\b.........78%";
                Sleep(400);
                cout << "\b\b\b............100%";
                Sleep(400);
    		cout << "\n\n\t\t\t\t Update Successfully!!";
			cout << "\n\n\t\t\t\t+====================================================+\n";
			system("Pause");
			system("cls");
			Check_info();
			break;
	}
    else if(choice == 3)
    {
    		cin.ignore();
    cout << "\n\t\t\t\t->> Age : ";
    cin.getline(patient_age, 8);
    patient_Age[i] = patient_age;
                cout << "\n\t\t\t\tUpdating Data, please wait...2%";
                Sleep(400);
                cout << "\b\b........47%";
                Sleep(400);
                cout << "\b\b\b.........78%";
                Sleep(400);
                cout << "\b\b\b............100%";
                Sleep(400);
    cout << "\n\n\t\t\t\t Update Successfully!!";
			cout << "\n\n\t\t\t\t+====================================================+\n";
			system("Pause");
			system("cls");
			Check_info();
			break;
	}
	else if(choice == 4)
	{
			cin.ignore();
    cout << "\n\t\t\t\t->> Patient Contact Number : ";
    cin.getline(patient_num, 15);
    patient_Contact[i] = patient_num;
                cout << "\n\t\t\t\tUpdating Data, please wait...2%";
                Sleep(400);
                cout << "\b\b........47%";
                Sleep(400);
                cout << "\b\b\b.........78%";
                Sleep(400);
                cout << "\b\b\b............100%";
                Sleep(400);
    		cout << "\n\n\t\t\t\t Update Successfully!!";
			cout << "\n\n\t\t\t\t+====================================================+\n";
			system("Pause");
			system("cls");
			Check_info();
			break;
	}
	else if(choice == 5)
	{
			cin.ignore();
    cout << "\n\t\t\t\t->> Address : ";
    cin.getline(patient_address, 150);
    address[i] = patient_address;
                cout << "\n\t\t\t\tUpdating Data, please wait...2%";
                Sleep(400);
                cout << "\b\b........47%";
                Sleep(400);
                cout << "\b\b\b.........78%";
                Sleep(400);
                cout << "\b\b\b............100%";
                Sleep(400);
    		cout << "\n\n\t\t\t\t Update Successfully!!";
			cout << "\n\n\t\t\t\t+====================================================+\n";
			system("pause");
			system("cls");
			Check_info();
			break;
	}
	else 
	{
		cout << "\n\t\t\t\t--No More Changes---\n";
	}
		}
		if(count == 0)
		{
			cout << "\n\t\t\t---No Record Found----!!\n";
			break;
		}
	}
}
void DeleteData()
{	
	cin.ignore();
	string search;
	cout << "\n\n\n\n\n\t\t\t-> Enter Appointment No: ";
	cin >> search;
		system("cls");
            cout << "\n\n\n\n\n\n\n\t\t\t\tLoading Data, please wait...2%";
            Sleep(400);
            cout << "\b\b........47%";
            Sleep(400);
            cout << "\b\b\b.........78%";
            Sleep(400);
            cout << "\b\b\b............100%";
            Sleep(400);
	system("cls");
	char patient_name[50];
    char patient_no[100];
    char patient_age[8];
    char patient_num[15];
    char patient_problem[20];
    char appointtime[20];
    char patient_address[150];
    int count = 0;
    cout << endl;
    cout << endl;
    cout << "\t\t\t\t+------------------------------------------------+\n";
    cout << "\t\t\t\t|                +Hospital Database+             |\n";
    cout << "\t\t\t\t+------------------------------------------------+\n";
    cout << "\t\t\t\t          +Patient Appointment Information+       \n";
    for(int i =0; i < maxrow; i++)
    {
		if(patient_Id[i] == search)
		{
			count++;
			patient_Id[i] = " ";
			patient_time[i] = " ";
			patient_Name[i] = " ";
			patient_Age[i] = " ";
			patient_Contact[i] = " ";
			address[i] = " " ;
			patient_entryDate[i] = " ";
			system("cls");
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tLoading Data, please wait...2%";
                Sleep(400);
                cout << "\b\b........47%";
                Sleep(400);
                cout << "\b\b\b.........78%";
                Sleep(400);
                cout << "\b\b\b............100%";
                Sleep(400);
                system("cls");
                cout << "\n\n\n\n\n\n\n\t\t\t\t Appointment Delete Successfully!!";
                system("pause");
                system("cls");
				goMenu();
			break;
		}
		if(count == 0)
		{
			cout << "\n\t\t\t---No Record Found----!!\n";
			break;
		}
	}
}
void AboutUs()
{
    cout << endl;
    cout << "\t\t\t\t\tTHANKS FOR USING THIS SOFTWARE!!\n";
    cout << "\t\t\t+=========================================================================+\n\n";
    cout << "\t\tGROUP MEMBERS (DEVELOPERS)\n";
    cout << "\t\t+--------------------------------------+\n\n";
    cout << "\t\t-> NAME " << "\t\t\tROLL NUMBER" << "\t\t\tBATCH" << endl << endl;
    cout << "\t\t-> 1. ESHA ZAMAN" << "\t\t20014119-081" << "\t\t\tBS-CS20-B" << endl << endl;
    cout << "\t\t-> 2. KAMRAN AHSAN" << "\t\t20014119-098" << "\t\t\tBS-CS20-B" << endl << endl;
    cout << "\t\t-> 3. HUSSNAIN UMAR" << "\t\t20014119-099" << "\t\t\tBS-CS20-B" << endl << endl;
    cout << "\t\t-> 4. ARSLAN" << "\t\t\t20014119-101" << "\t\t\tBS-CS20-B" << endl;
    cout << "\t\t+---------------------------------------------------------------------------+\n\n";
    cout << "\t\tSUBMITTED TO : " << "  MR. ADEEL AHMED " << endl << endl;


}
void SaveTofile()
{
	ofstream myfile;
	myfile.open("D:\\New folder\\DataBase.txt");
	for(int i = 0; i < maxrow; i++)
	{
		if(patientId[i] == "\0")
		{
			break;
		}
		else
		{
			myfile << patientId[i] << endl;
			myfile << patientName[i] << endl;
			myfile << patientContact[i]  << endl;
			myfile << patientAge[i]<< endl;
			myfile << patientBlood_gp[i] << endl;
			myfile << patEarlierDisease[i] << endl;
			myfile << patiententryDate[i] << endl;
		}
	}
}
void showManu()
{
	 	OpenTofile();
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "\t\t\t\t+========================================================+\n";
        cout << "\t\t\t\t|         M A I N  M E N U  O F  D A T A B A S E         |\n";
        cout << "\t\t\t\t+========================================================+\n";
        cout << endl;
        cout << "\t\t\t\t|>>> Please, Choose the following Options <<<+           |\n";
        cout << endl;
        cout << "\t\t\t\t| 1.>> Add New Patient                                   |\n";
        cout << "\t\t\t\t| 2.>> Add Patient Diagnosis information                 |\n";
        cout << "\t\t\t\t| 3.>> Patients Records                                  |\n";
        cout << "\t\t\t\t| 4.>> Appointment & list of Doctors                     |\n";
        cout << "\t\t\t\t| 5.>> About This Project                                |\n";
        cout << "\t\t\t\t| 6.>> About Hospital                                    |\n";
        cout << "\t\t\t\t| 7.>> Exit and save to file                             |\n";
        cout << endl;
        cout << "\t\t\t\t+========================================================+\n";
        cout << "\t\t\t\t| Brought to you by:                                     |\n";
        cout << "\t\t\t\t| -Kamran Ahsan, Hussnain Umar, Arslan, Esha Zaman       |\n";
        cout << "\t\t\t\t+========================================================+\n\n";
        cout << "\t\t\t\t+>>> Your Choice : ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                system("cls");
                addPatient();
                break;
            case 2:
                system("cls");
                l1:
                cout << endl;
                cout << endl;
                cout << "\n\n\n\n\n\n";
                cout << "\t\t\t\t   <_D I A G N O S I S  I N F O_>\n";
                cout << "\t\t\t\t======================================\n";
                cout << "\t\t\t\t-> 1. Add Diagnosis info by Patient ID\n";
                cout << "\n\t\t\t\t-> 2. Go back to Menu\n";
                cout << "\t\t\t\t======================================\n";
                cout << "\t\t\t\t+> Your Choice : ";
                cin >> choice;
                if(choice == 1)
                {
                cin.ignore();
                cout << "\n\n";
                cout << "\n\t\t\t\t+>> Enter Patient Unique ID : ";
                getline(cin, patientID);
                system("cls");
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tLoading Data, please wait...2%";
                Sleep(400);
                cout << "\b\b........47%";
                Sleep(400);
                cout << "\b\b\b.........78%";
                Sleep(400);
                cout << "\b\b\b............100%";
                Sleep(400);
                system("cls");
                addDiagno_info(patientID);
                cout << endl;
                cout << endl;
                system("pause");
                system("cls");
                goto l1;
                break;
                }
            	else if(choice == 2)
            	{
            		system("cls");
            		showManu();
				}
				else
				{
					cout << "\n\t\t\tInvalid Choice!!!---->";
					
					system("pause");
					system("cls");
					goto l1;
				}
                system("cls");
                cout << "\n\n\n\n\n\n\n\n\t\t\t\tLoading Data, please wait...2%";
                Sleep(400);
                cout << "\b\b........47%";
                Sleep(400);
                cout << "\b\b\b.........78%";
                Sleep(400);
                cout << "\b\b\b............100%";
                Sleep(400);
            case 3:
                system("cls");
                Patient_info();
                cout << endl;
                system("pause");
                system("cls");
                showManu();
                break;
            case 4:
                cin.ignore();
                system("cls");
				AppointMenu();
                break;
            case 5:
               system("cls");
               cout << "\n\n\n\n\n\n\n\n\t\t\t\tLoading Data, please wait...2%";
                Sleep(200);
                cout << "\b\b........47%";
                Sleep(200);
                cout << "\b\b\b.........78%";
                Sleep(200);
                cout << "\b\b\b............100%";
                Sleep(200);
                system("cls");
               AboutUs();
               system("pause");
               system("cls");
               showManu();
               break;
            case 6:
               system("cls");
               cout << "\n\n\n\n\n\n\n\n\t\t\t\tLoading Data, please wait...2%";
                Sleep(200);
                cout << "\b\b........47%";
                Sleep(200);
                cout << "\b\b\b.........78%";
                Sleep(200);
                cout << "\b\b\b............100%";
                Sleep(200);
                system("cls");
               AboutHos();
               system("pause");
               system("cls");
               showManu();
               break;
            case 7:
                system("cls");
                SaveTofile();
                cout << "\n\n\n\n\n\n\n\n\t\t\t\tExiting......Save to files...35%";
                Sleep(1000);
                cout << "\b\b\b..........67%";
                Sleep(1000);
                cout << "\b\b\b...................100%";
                Sleep(1000);
                system("cls");
                exit(0);
                break;
            default:
                cout << "Your option is invalid, Please choose the correct option." << endl;

}
}
void goMunu()
{
string b = "y";
    cout << "\n\t\t\t\t>>> Press y to go back to Main-Menu <<< ";
    cin >> b;
    if(b == "y")
    {
    system("cls");
    showManu();
}
	else if(b == "n")
	{
	system("cls");
	showManu();
}
}
void goMenu()
{
string b = "y";
    cout << "\t\t\t\t>>> Press y to go back to menu or n to add another appointment<<<";
    cin >> b;
    if(b == "y")
    {
    system("cls");
    AppointMenu();
}
	else if(b == "n")
	{
	system("cls");
	AvailDr();
}
}
void goManu()
{
    string b = "y";
    cout << "\n\t\t\t\t>>> Press y to go back to menu or n to try again <<< ";
    cin >> b;
    if(b == "y")
    {
    system("cls");
    showManu();
}
	else if(b == "n")
	{
	system("cls");
	addPatient();
}
}
//################################################################THANKS FOR CHOOSING US###############################################################################################################################################
//====================================================================================================================================================================================================================================
//##############################################################MAIN FUUNTION################################################################################################################################################################
int main()
{
	system("COLOR 4F");
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
	cout << "\t\t\t\t\t*  "<<"*  "<<"*    "<<"*****  "<<"*        "<<"*****   "<<" ****  "<<"    ***     "<<"****\n";
	cout << "\t\t\t\t\t*  "<<"*  "<<"*    "<<"*  "<<"    *       "<<"*        "<<"*    *   "<<"*  *  *   "<<"*\n";
	cout << "\t\t\t\t\t*  "<<"*  "<<"*    "<<"*****  "<<"*       "<<"*        "<<"*    *   "<<"*  *  *   "<<"****\n";
	cout << "\t\t\t\t\t*  "<<"*  "<<"*    "<<"*  "<<"    *       "<<"*        "<<"*    *   "<<"*  *  *   "<<"*\n";
	cout << "\t\t\t\t\t  ***      "<<"*****   "<<"*****   "<<"*****    "<<"****   " <<      " *  *  *   "<<"****\n\n";
	cout << "\t\t\t\t                           * * * * *      ****\n";
	cout << "\t\t\t\t                               *         *    *\n";
	cout << "\t\t\t\t                               *         *    *\n";
	cout << "\t\t\t\t                               *         *    *\n";
	cout << "\t\t\t\t                               *          ****\n\n";
    cout << "\t\t\t\t\t============================================================\n";
    cout << "\t\t\t\t\t+    H O S P I T A L  M A N A G E M E N T  S Y S T E M     +\n";
    cout << "\t\t\t\t\t============================================================\n ";
    system("pause");
    system("cls");
    showManu();
    // fuction calling
    return 0;
}
