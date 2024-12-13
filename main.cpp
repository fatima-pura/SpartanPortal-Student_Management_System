#include <iostream>
#include <string>
#include <cstdlib> 

using namespace std;

// ----------------------------------------------------GLOBAL SCOPE / GLOBAL VARIABLES --------------------------------------------------------------
char r7 = 220;

struct Student {
    string name, srCode, college, program, yearLevel, semester; 
};

Student students[5000];      
int studentCount = 0; 
  
// ---------------------------------------------------------FUNCTION PROTOTYPES -----------------------------------------------------------------
void upperDesign();
void displayMenu();
void collegeChoice();
void createAccount();
void viewAccount();
void updateAccount();
void deleteAccount();

// --------------------------------------------------------------MAIN MENU----------------------------------------------------------------------

int main() {
    char choice;
    
    do {
        system("CLS");
        upperDesign();
        
        displayMenu();
        cin >> choice;
    
        switch(choice) {
            case '1':
                system("CLS");
                createAccount();
                break;
            case '2':
                system("CLS");
                viewAccount();
                break;
            case '3':
                system("CLS");
                updateAccount();
                break;
            case '4':
                system("CLS");
                deleteAccount();
                break;
            case '5':
                cout << "\nExiting the program. Goodbye... Thank You :)\n";
                break;
            default:
                cout << "\nInvalid choice. Please select a valid option (1-5).\n";
                break;
        }
        
    } while(choice != '5');

    return 0;
}

//-----------------------------------------------------------------UPPER DESIGN----------------------------------------------------------------------

void upperDesign() {
    cout << endl;
    for (int i = 0; i < 120; i++) {
        cout << r7;
    }
    
    cout << endl;
    cout << "\n\t\t\t\t\t       Batangas State University" << endl;
    cout << "\t\t\t\t          The National Engineering University" << endl;
    
    cout << endl;
    cout << "\t\t\t\t\t\t    Spartan Portal" << endl;
    cout << endl;
    cout << "\t\t\t\t\t      by Fatima Pura | CS - 1104";
    cout << endl;
    
    for (int i = 0; i < 120; i++) {
        cout << r7;
    }
    cout << endl;    
}

void displayMenu() {
    cout << "\n\n\t\t\t\t\t\t   -- MAIN MENU --";
    cout << endl;
    cout << "\n\t\t\t\t        Press 1:   CREATE | Create an Account";
    cout << "\n\t\t\t\t        Press 2:   READ   | View Account";
    cout << "\n\t\t\t\t        Press 3:   UPDATE | Update Account Information";
    cout << "\n\t\t\t\t        Press 4:   DELETE | Delete Account";
    cout << "\n\t\t\t\t        Press 5:   EXIT   | Exit the Program";
    cout << endl;
    cout << "\n\t\t\t\t        Select Your Option (1-5): ";
}

//--------------------------------------------------------------------CREATE-----------------------------------------------------------------------------------

void collegeChoice(Student &student) {
    int choice;
    
    while (true) {
        cout << "\nEnter your new college: ";
        cout << "\nPress 1: College of Engineering, Architecture and Fine Arts [CEAFA]";
        cout << "\nPress 2: College of Industrial Technology [CIT]";
        cout << "\nPress 3: College of Informatics and Computing Sciences [CICS]";
        cout << "\nSelect Your Option (1-3): ";
        cin >> choice;
        cin.ignore();  

        if (choice == 1) {
            student.college = "College of Engineering, Architecture and Fine Arts [CEAFA]";
            break;
        } else if (choice == 2) {
            student.college = "College of Industrial Technology [CIT]";
            break;
        } else if (choice == 3) {
            student.college = "College of Informatics and Computing Sciences [CICS]";
            break;
        } else {
            cout << "Invalid input! Please select a valid college (1-3).\n";
        }
    }
}



void createAccount() {
    if (studentCount >= 5000) {
        upperDesign();
        cout << "\n\n\t\t\t\t\t\t  --CREATE ACCOUNT--" << endl;
        cout << "\nCannot create more accounts. Student limit reached.\n";
        cout << "\nPress Enter to return to the main menu.";
        cin.ignore();
        cin.get();
        return;
    }

    upperDesign();
    cout << "\n\n\t\t\t\t\t\t  --CREATE ACCOUNT--" << endl;
    cout << endl;

    cin.ignore();
    
    cout << "Enter your name (Ex. Fatima A. Pura): ";
    getline(cin, students[studentCount].name);

    cout << "\nEnter your SR-CODE: ";
    getline(cin, students[studentCount].srCode);
    
    collegeChoice(students[studentCount]); 
    
    cout << "\nEnter your program (Ex. BS Computer Science): ";
    getline(cin, students[studentCount].program);

    cout << "\nEnter your year level (Ex. 1st Year): ";
    getline(cin, students[studentCount].yearLevel);
    
    cout << "\nEnter your semester (Ex. 1st Semester): ";
    getline(cin, students[studentCount].semester);
    
    cout << "\nAccount created successfully...\n";
    studentCount++;  

    cout << "\nPress Enter to return to the main menu.";
    cin.ignore();
    cin.get();
}

// ------------------------------------------------------------------READ-----------------------------------------------------------------------------------

void viewAccount() {
    int viewChoice;
    string searchSRCODE;
    bool found = false;

    if (studentCount == 0) {
        upperDesign();
        cout << "\n\n\t\t\t\t\t         --VIEW ACCOUNTS--" << endl;
        cout << "\nNo accounts registered yet. Please proceed to the main menu and select option 1." << endl;
        cout << "\nPress Enter to return to the main menu.";
        cin.ignore();
        cin.get();
        return;
    }

    upperDesign();
     cout << "\n\n\t\t\t\t\t         --VIEW ACCOUNTS--" << endl;
    cout << endl;

	cout << "\n\t\t\t\t\t    Enter your viewing preference: ";
	cout << "\n\t\t\t\t\t    Press 1: View Specific Account";
	cout << "\n\t\t\t\t\t    Press 2: View List of Accounts";
	cout << "\n\t\t\t\t\t    Select an option (1-2): ";
	cin >> viewChoice;

    if (viewChoice == 1) {
        system("CLS");
        upperDesign();
	    cout << "\n\n\t\t\t\t\t         --VIEW ACCOUNTS--" << endl;
	    cout << endl;
	    
        cout << "\nEnter your SR-CODE: ";
        cin >> searchSRCODE;
		
        for (int i = 0; i < studentCount; i++) {
            if (students[i].srCode == searchSRCODE) {
                found = true;

                cout << "\nName: " << students[i].name;
                cout << "\nSR-CODE: " << students[i].srCode;
                cout << "\nCollege: " << students[i].college;
                cout << "\nProgram: " << students[i].program;
                cout << "\nYear Level: " << students[i].yearLevel;
                cout << "\nSemester: " << students[i].semester;
                break;  
            }
        }
    } else if (viewChoice == 2) {
        system("CLS");
        upperDesign();
 		cout << "\n\n\t\t\t\t\t         --VIEW ACCOUNTS--" << endl;
	    cout << endl;
	    
        for (int i = 0; i < studentCount; i++) {
            cout << "\nName: " << students[i].name;
            cout << "\nSR-CODE: " << students[i].srCode;
            cout << "\nCollege: " << students[i].college;
            cout << "\nProgram: " << students[i].program;
            cout << "\nYear Level: " << students[i].yearLevel;
            cout << "\nSemester: " << students[i].semester;
            cout << endl;
            cout << "\n---------------------------------------------------------------------------------------------------------------------" << endl;
        }
    } else {
        cout << "\nInvalid selection. Please select option 1 or 2.\n";
    }

    if (!found && viewChoice == 1) {
        cout << "\nStudent not found.\n";
    }

	cout << endl;
    cout << "\nPress Enter to return to the main menu.";
    cin.ignore();
    cin.get();
}

//-----------------------------------------------------------------UPDATE-----------------------------------------------------------------------------------

void updateAccount() {
    string searchSRCODE;
    int updatedINFO;
    bool found = false;

    upperDesign();
    cout << "\n\n\t\t\t\t\t         --UPDATE ACCOUNT--" << endl;
    
    cout << "\n\nEnter your SR-CODE: ";
    cin >> searchSRCODE;

    for (int i = 0; i < studentCount; i++) {
        if (students[i].srCode == searchSRCODE) {
            found = true; 
            
            cout << "\nSelect what you want to update: " << endl;
            cout << "Press 1: Name" << endl;
            cout << "Press 2: SR-CODE" << endl;
            cout << "Press 3: College" << endl;
            cout << "Press 4: Program" << endl;
            cout << "Press 5: Year Level" << endl;
            cout << "Press 6: Semester" << endl;
            cout << "Select Your Option (1-6): ";
            cin >> updatedINFO;
        
            switch (updatedINFO) {
                case 1:
                    cout << "\nEnter new name: ";
                    cin.ignore();
                    getline(cin, students[i].name);
                    break;
                case 2:
                    cout << "\nEnter new SR-CODE: ";
                    cin.ignore();
                    getline(cin, students[i].srCode);
                    break;
                case 3:
                    collegeChoice(students[i]); 
                    break;
                case 4:
                    cout << "\nEnter new program (Ex. BS Computer Science): ";
                    cin.ignore();
                    getline(cin, students[i].program);
                    break;
                case 5:
                    cout << "\nEnter new year level (Ex. 1st Year): ";
                    cin.ignore();
                    getline(cin, students[i].yearLevel);
                    break;
                case 6:
                    cout << "\nEnter new semester (Ex. 1st Semester): ";
                    cin.ignore();
                    getline(cin, students[i].semester);
                    break;
                default:
                    cout << "\nInvalid input. Cannot proceed to update." << endl;
                    break;
            }

            cout << "\nAccount updated successfully..." << endl;
            break;
        }
    }

    if (!found) {
        cout << "\nStudent not found.\n";
    }

    cout << "\nPress Enter to return to the main menu.";
    cin.ignore();
    cin.get();
}

//--------------------------------------------------------------DELETE----------------------------------------------------------------------------------------

void deleteAccount() {
    string searchSRCODE;
    char confirmation;
    bool found = false;

    upperDesign();
    cout << "\n\n\t\t\t\t\t         --DELETE ACCOUNT--" << endl;

    cout << "\nEnter your SR-CODE to delete your account: ";
    cin.ignore();  
    getline(cin, searchSRCODE); 

    for (int i = 0; i < studentCount; i++) {
        if (students[i].srCode == searchSRCODE) {
            found = true;
            cout << "\nAre you sure you want to delete your account? (y/n): ";
            cin >> confirmation;

            if (confirmation == 'y' || confirmation == 'Y') {
                for (int j = i; j < studentCount - 1; j++) {
                    students[j] = students[j + 1];
                }
                studentCount--;  
                cout << "\nAccount successfully deleted...\n";
            } else {
                cout << "\nAccount deletion canceled...\n";
            }
            break; 
        }
    }
    
    if (!found) {
        cout << "\nStudent not found. Please check the SR-CODE.\n"; 
    }

    cout << "\nPress Enter to return to the main menu.";
    cin.ignore(); 
    cin.get();  
}

