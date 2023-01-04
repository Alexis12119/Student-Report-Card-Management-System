// String library
#include <string.h>
// For windows operation
#include <windows.h>

// For file handling
#include <fstream>
// Input and output
#include <iostream>

using namespace std;

class Project {
    // Declare a struct
    // To unify the student informations
    struct student {
        // name and id number
        char name[1000], id_number[1000];
        // Subjects
        int ge101, fil101, ge102, cc112, pe1, lite, cc111, nstp1, sum, average;
    };

    // Welcome screen
    void dashboard() {
        // Add spaces
        cout << "\n\n\n";
        // For animation
        Sleep(300);
        cout << "\t\t\t_  _  _ _______        _______  _____  _______ _______\n";
        // For animation
        Sleep(300);
        cout << "\t\t\t|  |  | |______ |      |       |     | |  |  | |______\n";
        // For animation
        Sleep(300);
        cout << "\t\t\t|__|__| |______ |_____ |_____  |_____| |  |  | |______\n";
        // For animation
        Sleep(300);

        cout << "\n\t\t\t=======================================================\n";
        // For animation
        Sleep(500);
        cout << "\t\t\t\tSTUDENT REPORT CARD MANEGEMENT SYSTEM\n";
        cout << "\t\t\t\t\t      BY GROUP 3\n";
        // For animation
        Sleep(500);
        cout << "\t\t\t=======================================================\n\n\n";
        // For animation
        Sleep(500);
    }

    void main_menu() {
        // For animation purposes
        system("cls");
        // Color white
        system("color 7");
        string choice;
        char id[1000];
        // Print
        cout << "\t\t\t\t================= MAIN MENU ================\n\n\n";
        cout << "\t\t\t\t1. CREATE STUDENT REPORT CARD\n\n\n";
        cout << "\t\t\t\t2. VIEW ALL STUDENTS REPORT CARD\n\n\n";
        cout << "\t\t\t\t3. VIEW A SINGLE STUDENT REPORT CARD\n\n\n";
        cout << "\t\t\t\t4. MODIFY REPORT CARD\n\n\n";
        cout << "\t\t\t\t5. DELETE RECORD\n\n\n";
        cout << "\t\t\t\t6. BACK\n\n\n";
        cout << "\t\t\t\t=============================================\n";
        cout << "\t\t\t\tENTER YOUR CHOICE(1-6): ";
        // Ask user for input
        cin >> choice;
        cout << '\n';

        if (choice == "1") {
            // Create new report card
            add_record();
            // Back to main menu when the function is finished
            main_menu();

        } else if (choice == "2") {
            // View all Report cards
            view_all_records();
            // Back to main menu when the function is finished
            main_menu();

        } else if (choice == "3") {
            // For animation purposes
            system("cls");
            cout << "ENTER YOUR STUDENT ID NUMBER: ";
            cin >> id;
            // View a specific report card
            view_specific_record(id);
            // Back to main menu when the function is finished
            main_menu();

        } else if (choice == "4") {
            // For animation purposes
            system("cls");
            cout << "ENTER YOUR STUDENT ID NUMBER: ";
            cin >> id;
            // Modify a report card
            // In case when there's a correction
            modify_record(id);
            // Back to main menu when the function is finished
            main_menu();

        } else if (choice == "5") {
            // For animation purposes
            system("cls");
            cout << "ENTER YOUR STUDENT ID NUMBER: ";
            cin >> id;
            // Delete a specific report card
            delete_record(id);
            // Back to main menu when the function is finished
            main_menu();

        } else if (choice == "6") {
            // Back to intro screen
            intro();

        } else {
            system("cls");
            // In case when the input is less than 1 or more than 6
            main_menu();
        }
    }

    // Check for duplicate
    bool has_duplicate(char *id) {
        // Don't check if the file is successfull opened
        // Since the operation is already done
        // When this functions is called
        // Initialize variables
        student s;
        ifstream input_file;
        // Open the file
        input_file.open("Data.txt", ios::app | ios::binary);
        // Search for same id number
        while (input_file.read(reinterpret_cast<char *>(&s), sizeof(student))) {
            if (strcmp(s.id_number, id) == 0) {
                return 1;
            }
        }
        // Close the file
        input_file.close();
        return 0;
    }

    // To shorten the code
    // Pass the struct
    void ask_input(struct student &s) {
        cout << "\tNOTE: When duplicate id number detected or no id number, the system won't "
                "accept the datas\n";
        cout << "\tDon't worry, the system will ask you again, if it detects a "
                "duplicate\n\n";
        cout << "ENTER YOUR FULL NAME(80 characters only): ";
        cin.ignore();
        cin.getline(s.name, 1000);
        cout << "ENTER YOUR STUDENT ID NUMBER(10 characters only): ";
        cin.getline(s.id_number, 1000);
        cout << "ENTER YOUR CC112 GRADE: ";
        cin >> s.cc112;
        cout << "ENTER YOUR GE101 GRADE: ";
        cin >> s.ge101;
        cout << "ENTER YOUR FIL101 GRADE: ";
        cin >> s.fil101;
        cout << "ENTER YOUR GE102 GRADE: ";
        cin >> s.ge102;
        cout << "ENTER YOUR PE1 GRADE: ";
        cin >> s.pe1;
        cout << "ENTER YOUR LITE GRADE: ";
        cin >> s.lite;
        cout << "ENTER YOUR CC111 GRADE: ";
        cin >> s.cc111;
        cout << "ENTER YOUR NSTP1 GRADE: ";
        cin >> s.nstp1;
    }

    // To shorten the code
    // Pass the struct
    void show_info(struct student &s) {
        cout << "\t\t\t\tSTUDENT NAME: " << s.name << "\n\n";
        cout << "\t\t\t\tSTUDENT ID NUMBER: " << s.id_number << "\n\n";
        cout << "\t\t\t\tCC112 GRADE: " << s.cc112 << "\n\n";
        cout << "\t\t\t\tGE101 GRADE: " << s.ge101 << "\n\n";
        cout << "\t\t\t\tFIL101 GRADE: " << s.fil101 << "\n\n";
        cout << "\t\t\t\tGE102 GRADE: " << s.ge102 << "\n\n";
        cout << "\t\t\t\tPE1 GRADE: " << s.pe1 << "\n\n";
        cout << "\t\t\t\tLITE GRADE: " << s.lite << "\n\n";
        cout << "\t\t\t\tCC111 GRADE: " << s.cc111 << "\n\n";
        cout << "\t\t\t\tNSTP1 GRADE: " << s.nstp1 << "\n\n";
        cout << "\t\t\t\tSUM: " << s.sum << "\n\n";
        cout << "\t\t\t\tAVERAGE: " << s.average << "\n\n";
    }

    void add_record() {
        // For animation purposes
        system("cls");
        // Initialize variables
        student s;
        ofstream output_file;
        // Open the file
        output_file.open("Data.txt", ios::app | ios::binary);
        // If failed then don't run
        if (output_file.fail()) {
            cout << "THE FILE COULD NOT BE OPEN...Press Enter";
        } else {
            cout << "\n\n";
            cout << "\t\t\t\t======= CREATE A REPORT CARD ========\n\n";
            ask_input(s);
            s.sum = s.cc112 + s.pe1 + s.lite + s.cc111 + s.ge102 + s.fil101 + s.ge101 + s.nstp1;
            s.average = (s.sum / 8);
            // Check if there's a duplicate
            if (has_duplicate(s.id_number) == 0) {
                // If no duplicate then add the informations
                output_file.write(reinterpret_cast<char *>(&s), sizeof(student));
                cout << "\n\t\t\t\tSUCCESSFULLY CREATED!!!\n\n";
                cout << "Press Enter to continue...";
            } else {
                // If yes then restart
                add_record();
            }
            // Close the file
            output_file.close();
        }
        cin.ignore();
        cin.get();
    }

    void view_all_records() {
        // For animation purposes
        system("cls");
        // Initialize variables
        student s;
        ifstream input_file;
        bool check = false;
        // Open the file
        input_file.open("Data.txt", ios::app | ios::binary);
        // If failed then don't run
        if (input_file.fail()) {
            cout << "THE FILE COULD NOT BE OPENED.....Press Enter...";
            cin.ignore();
            cin.get();
        } else {
            cout << "\n\n\t\t\t\tALL STUDENTS REPORT CARDS\n";
            cout << "===================================================================="
                    "==============\n";
            // Show all records through while loop
            while (input_file.read(reinterpret_cast<char *>(&s), sizeof(student))) {
                show_info(s);
                cout << "=================================================================="
                        "================\n";
                // To check if there's informations
                check = true;
            }
            // Close the file
            input_file.close();
            // Check if there's any informations
            if (check == false)
                cout << "\t\t\t\tNO RECORD FOUND :(\n\n";
            cout << "Press Enter to continue....";
        }
        cin.ignore();
        cin.get();
    }

    void view_specific_record(char *id) {
        // For animation purposes
        system("cls");
        // Initialize variables
        student s;
        ifstream input_file;
        bool equality = false;
        // Open the file
        input_file.open("Data.txt", ios::app | ios::binary);
        // If failed then don't run
        if (input_file.fail()) {
            cout << "THE FILE COULD NOT BE OPENED...";
            cin.ignore();
            cin.get();
        } else {
            cout << "\t\t\t\t========== VIEW A SINGLE STUDENT REPORT ==========\n\n";
            // Search for the specific report card
            while (input_file.read(reinterpret_cast<char *>(&s), sizeof(student))) {
                if (strcmp(s.id_number, id) == 0) {
                    cout << "\t\t\t\t================================================\n";
                    show_info(s);
                    cout << "=================================================================="
                            "================\n";

                    equality = true;
                }
            }
            // Close the file
            input_file.close();
            // Check if there's any informations
            if (equality == false)
                cout << "\t\t\t\tRECORD NOT FOUND :(\n\n";
            cout << "Press Enter to continue...";
        }
        cin.ignore();
        cin.get();
    }

    void modify_record(char *id) {
        // For animation purposes
        system("cls");
        // Initialize variables
        student s;
        fstream input_file;
        bool checker = false;
        // Open the file
        input_file.open("Data.txt", ios::binary | ios::in | ios::out);
        // If failed then don't run
        if (input_file.fail()) {
            cout << "THE FILE COULD NOT BE OPENED...\n";
            cin.ignore();
            cin.get();
        } else {
            cout << "\t\t\t\t========== MODIFY A REPORT CARD ==========\n\n";
            // Check until the last part of the file
            while (!input_file.eof() && checker == false) {
                // Search for the specific report card
                input_file.read(reinterpret_cast<char *>(&s), sizeof(student));
                {
                    if (strcmp(s.id_number, id) == 0) {
                        // Modify the informations when it found the same id number
                        cout << "\t\t\t\t================================================\n";
                        show_info(s);
                        cout << "=============================================\n";
                        cout << "\t\tENTER THE NEW INFORMATION\n";
                        cout << "=============================================\n";
                        ask_input(s);

                        s.sum = s.cc112 + s.pe1 + s.lite + s.cc111 + s.ge102 + s.fil101 + s.ge101
                                + s.nstp1;
                        s.average = (s.sum / 8);
                        // Check for duplicate of id number
                        if (has_duplicate(s.id_number) == 0) {
                            int pos = (-1) * static_cast<int>(sizeof(student));
                            input_file.seekp(pos, ios::cur);
                            input_file.write(reinterpret_cast<char *>(&s), sizeof(student));
                            cout << "\n\t\t\t\tSUCCESSFULLY UPDATED!!!\n";
                            cout << "\nPress Enter to continue...";
                        } else {
                            modify_record(s.id_number);
                        }
                        checker = true;
                    }
                }
                if (checker == false) {
                    cout << "\t\t\t\tRECORD NOT FOUND :(\n";
                    cout << "\nPress Enter to continue...";
                }
            }
            // Close the file
            input_file.close();
            cin.ignore();
            cin.get();
        }
    }

    void delete_record(char *id) {
        // For animation purposes
        system("cls");
        // Initialize variables
        student s;
        bool check = 0;
        ifstream input_file;
        ofstream output_file;
        // Open the file
        input_file.open("Data.txt", ios::binary);
        // If failed then don't run
        if (!input_file) {
            cout << "THE FILE COULD NOT BE OPENED...\n";
            cin.ignore();
            cin.get();
        } else {
            // Check if there's any record
            while (input_file.read(reinterpret_cast<char *>(&s), sizeof(student))) {
                if (strcmp(s.id_number, id) == 0) {
                    check = 1;
                    break;
                }
            }
            cout << "\t\t\t\t=========== DELETE A REPORT CARD ==========\n\n";
            // If yes, then delete that specific report card
            if (check) {
                while (input_file.read(reinterpret_cast<char *>(&s), sizeof(student))) {
                    if (strcmp(s.id_number, id) != 0) {
                        output_file.write(reinterpret_cast<char *>(&s), sizeof(student));
                    }
                }
                output_file.open("Backup.txt", ios::binary);
                input_file.seekg(0, ios::beg);
                input_file.close();
                output_file.close();
                remove("Data.txt");
                rename("Backup.txt", "Data.txt");
                cout << "\n\t\t\t\tSUCCESSFULLY DELETED!!!\n";
            } else {
                // Close the files
                input_file.close();
                output_file.close();
                cout << "\t\t\t\tNO RECORD FOUND :(\n\n";
            }
            cout << "Press Enter to continue...";
            cin.ignore();
            cin.get();
        }
    }

    void intro() {
        // Initialize variables
        string choice;
        // For animation purposes
        system("cls");
        // Color Yellow
        system("color e");
        // Print
        cout << "\n\n\t==================== STUDENT REPORT CARD MANEGEMENT "
                "SYSTEM ====================\n\n";
        cout << "\t\t\t\t1. MAIN MENU\n\n";
        cout << "\t\t\t\t2. EXIT\n\n";
        cout << "ENTER YOUR CHOICE: ";
        // Ask for input
        cin >> choice;
        // If two go to the outro and exit the program
        if (choice == "2") {
            // For animation purposes
            system("cls");
            // Outro
            cout << "\t\t     THANK YOU FOR USING THIS SYSTEM\n";
            cout << "\n\n";
            cout << "\t______________________\n";
            cout << "\t|   MEMBERS          |\n";
            cout << "\t===================================================\n";
            cout << "\t| Arguil, Devyth               |        BSIT-1E   |\n";
            Sleep(300);
            cout << "\t|-------------------------------------------------|\n";
            cout << "\t| Ballarda, Audrey Rose        |        BSIT-1E   |\n";
            Sleep(300);
            cout << "\t|-------------------------------------------------|\n";
            cout << "\t| Caceres, Jan Darsey          |        BSIT-1E   |\n";
            Sleep(300);
            cout << "\t|-------------------------------------------------|\n";
            cout << "\t| Corporal, Alexis             |        BSIT-1E   |\n";
            Sleep(300);
            cout << "\t|-------------------------------------------------|\n";
            cout << "\t| Ducut, Rodelene              |        BSIT-1E   |\n";
            Sleep(300);
            cout << "\t|-------------------------------------------------|\n";
            cout << "\t| Lacdan, Peejay               |        BSIT-1E   |\n";
            Sleep(300);
            cout << "\t|-------------------------------------------------|\n";
            cout << "\t| Mendoza, Ronnel              |        BSIT-1E   |\n";
            Sleep(300);
            cout << "\t|-------------------------------------------------|\n";
            cout << "\t| Paliza, Janmar               |        BSIT-1E   |\n";
            Sleep(300);
            cout << "\t|-------------------------------------------------|\n";
            cout << "\t| San Luis, James Errol        |        BSIT-1E   |\n";
            Sleep(300);
            cout << "\t===================================================\n";
            cout << "\n\nPress Enter to exit...";
            cin.ignore();
            cin.get();
        } else if (choice == "1") {
            // Go to main menu
            main_menu();
        } else {
            // If invalid input then restart
            intro();
        }
    }

   public:
    // Make this function only public for security purposes
    void run() {
        // Color Green
        system("color a");
        // For animation purposes
        system("cls");
        // Welcome Screen
        dashboard();
        // Initialize variables
        string input;
        int limit = 5;
        cout << "Please Enter the password to access the system\n";
        // While Loop
        while (limit--) {
            cout << "Password: ";
            // Ask for input
            getline(cin, input);
            if (input == "1234") {
                // If the input is equal to the correction password
                // go to intro
                intro();
                break;
            } else {
                if (limit == 0) {
                    // If the user reached the limit, exit the program
                    cout << "Sorry, You've reached the limit!!!\n";
                    cout << "You can't access the system!!!\n";
                    break;
                } else {
                    // For user, to know there available chance/s left.
                    cout << "Wrong, You have " << limit << " chance/s left\n";
                }
            }
        }
    }
};

int main() {
    // Initialize Class
    Project project;
    // Run the project
    project.run();
    // Exit the Program
    return 0;
}
