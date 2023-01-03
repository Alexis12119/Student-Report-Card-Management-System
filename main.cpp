/**
TODO: Add Comments and Make user interface look good.
  **/
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include <fstream>
#include <iostream>

using namespace std;

class Project {
    struct student {
        char name[80], id_number[10];
        int ge101, fil101, ge102, cc112, pe1, lite, cc111, nstp1, sum, average;
    };

    void dashboard() {
        cout << "\n\n\n";
        Sleep(300);
        cout << "\t\t\t\t _  _  _ _______        _______  _____  _______ _______\n";
        Sleep(300);
        cout << "\t\t\t\t |  |  | |______ |      |       |     | |  |  | |______\n";
        Sleep(300);
        cout << "\t\t\t\t |__|__| |______ |_____ |_____  |_____| |  |  | |______\n";
        Sleep(300);

        cout << "\n\t\t\t\t=======================================================\n";
        Sleep(500);
        cout << "\t\t\t\t\tSTUDENT REPORT CARD MANEGEMENT SYSTEM\n";
        cout << "\t\t\t\t\t\t      BY GROUP 3\n";
        Sleep(500);
        cout << "\t\t\t\t=======================================================\n\n\n";
        Sleep(500);
        cout << "Press Enter to continue...";
        cin.ignore();
    }

    void main_menu() {
        system("color 7");
        string choice;
        char id[10];
        cout << "\t\t\t\t================= MAIN MENU ================\n\n\n";
        cout << "\t\t\t\t1. CREATE STUDENT REPORT CARD\n\n\n";
        cout << "\t\t\t\t2. VIEW ALL STUDENTS REPORT CARD\n\n\n";
        cout << "\t\t\t\t3. VIEW A SINGLE STUDENT REPORT CARD\n\n\n";
        cout << "\t\t\t\t4. MODIFY REPORT CARD\n\n\n";
        cout << "\t\t\t\t5. DELETE RECORD\n\n\n";
        cout << "\t\t\t\t6. BACK\n\n\n";
        cout << "\t\t\t\t=============================================\n";
        cout << "\t\t\t\tENTER YOUR CHOICE(1-6): ";
        cin >> choice;
        cout << '\n';

        if (choice == "1") {
            add_record();
            main_menu();

        } else if (choice == "2") {
            view_all_records();
            main_menu();

        } else if (choice == "3") {
            system("cls");
            cout << "ENTER YOUR STUDENT ID NUMBER: ";
            cin >> id;
            view_specific_record(id);
            main_menu();

        } else if (choice == "4") {
            system("cls");
            cout << "ENTER YOUR STUDENT ID NUMBER: ";
            cin >> id;
            modify_record(id);
            main_menu();

        } else if (choice == "5") {
            system("cls");
            cout << "ENTER YOUR STUDENT ID NUMBER: ";
            cin >> id;
            delete_record(id);
            main_menu();

        } else if (choice == "6") {
            intro();

        } else {
            main_menu();
        }
    }

    bool has_duplicate(char *id) {
        student s;
        ifstream input_file;
        input_file.open("Data.txt", ios::app | ios::binary);
        if (input_file.fail()) {
            cout << "THE FILE COULD NOT BE OPENED...";
            cin.ignore();
            cin.get();
        }
        while (input_file.read(reinterpret_cast<char *>(&s), sizeof(student))) {
            if (strcmp(s.id_number, id) == 0) {
                return 1;
            }
        }
        input_file.close();
        return 0;
    }

    void add_record() {
        system("cls");
        student s;
        ofstream output_file;
        output_file.open("Data.txt", ios::app | ios::binary);
        if (output_file.fail()) {
            cout << "THE FILE COULD NOT BE OPEN...Press Enter";
            cin.ignore();
            cin.get();
        } else {
            cout << "\n\n";
            cout << "\t\t\t\t======= CREATE A REPORT CARD ========\n\n";
            cout << "\tNOTE: When duplicate id number detected, the system won't "
                    "accept the informations\n";
            cout << "\tDon't worry, the system will ask you again, if it detects a "
                    "duplicate\n\n";
            cout << "ENTER YOUR FULL NAME: ";
            cin.ignore();
            cin.getline(s.name, 80);
            cout << "ENTER YOUR STUDENT ID NUMBER: ";
            cin.get(s.id_number, 10);
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

            s.sum = s.cc112 + s.pe1 + s.lite + s.cc111 + s.ge102 + s.fil101 + s.ge101 + s.nstp1;
            s.average = (s.sum / 8);
            if (has_duplicate(s.id_number) == 0) {
                output_file.write(reinterpret_cast<char *>(&s), sizeof(student));
                cout << "\n\t\t\t\tSUCCESSFULLY CREATED!!!\n\n";
                cout << "Press Enter to continue...";
            } else {
                add_record();
            }
            output_file.close();
            cin.ignore();
            cin.get();
        }
    }
    void view_specific_record(char *id) {
        system("cls");
        student s;
        ifstream input_file;
        input_file.open("Data.txt", ios::app | ios::binary);
        if (input_file.fail()) {
            cout << "THE FILE COULD NOT BE OPENED...";
            cin.ignore();
            cin.get();
        }
        bool equality = false;
        cout << "\t\t\t\t========== VIEW A SINGLE STUDENT REPORT ==========\n\n";
        while (input_file.read(reinterpret_cast<char *>(&s), sizeof(student))) {
            if (strcmp(s.id_number, id) == 0) {
                cout << "\t\t\t\t================================================\n";
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

                cout << "=================================================================="
                        "================\n";

                equality = true;
            }
        }
        input_file.close();
        if (equality == false)
            cout << "\t\t\t\tRECORD NOT FOUND :(\n\n";
        cout << "Press Enter to continue...";
        cin.ignore();
        cin.get();
    }

    void view_all_records() {
        system("cls");
        student s;
        ifstream input_file;
        bool check = false;
        input_file.open("Data.txt", ios::app | ios::binary);
        if (input_file.fail()) {
            cout << "THE FILE COULD NOT BE OPENED.....Press Enter...";
            cin.ignore();
            cin.get();
        } else {
            cout << "\n\n\t\t\t\tALL STUDENTS REPORT CARDS\n";
            cout << "===================================================================="
                    "==============\n";
            while (input_file.read(reinterpret_cast<char *>(&s), sizeof(student))) {
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

                cout << "=================================================================="
                        "================\n";

                check = true;
            }
            input_file.close();
            if (check == false)
                cout << "\t\t\t\tNO RECORD FOUND :(\n\n";
            cout << "Press Enter to continue....";
            cin.ignore();
            cin.get();
        }
    }

    void delete_record(char *id) {
        system("cls");
        student s;
        bool check = 0;
        ifstream input_file;
        ofstream output_file;
        input_file.open("Data.txt", ios::binary);
        if (!input_file) {
            cout << "THE FILE COULD NOT BE OPENED...\n";
            cin.ignore();
            cin.get();
        }
        // Check if there's any record
        while (input_file.read(reinterpret_cast<char *>(&s), sizeof(student))) {
            if (strcmp(s.id_number, id) == 0) {
                check = 1;
                break;
            }
        }
        cout << "\t\t\t\t=========== DELETE A REPORT CARD ==========\n\n";
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
            input_file.close();
            output_file.close();
            cout << "\t\t\t\tNO RECORD FOUND :(\n\n";
        }
        cout << "Press Enter to continue...";
        cin.ignore();
        cin.get();
    }

    void modify_record(char *id) {
        system("cls");
        student s;
        fstream input_file;
        input_file.open("Data.txt", ios::binary | ios::in | ios::out);
        if (input_file.fail()) {
            cout << "THE FILE COULD NOT BE OPENED...\n";
            cin.ignore();
            cin.get();
        }
        bool checker = false;
        cout << "\t\t\t\t========== MODIFY A REPORT CARD ==========\n\n";
        while (!input_file.eof() && checker == false) {
            input_file.read(reinterpret_cast<char *>(&s), sizeof(student));
            {
                if (strcmp(s.id_number, id) == 0) {
                    cout << "\t\t\t\t================================================\n";
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
                    cout << "=============================================\n";
                    cout << "\t\tENTER THE NEW INFORMATION\n";
                    cout << "=============================================\n";
                    cout << "NOTE: When duplicate id number detected, the system won't "
                            "accept the informations\n";
                    cout << "Don't worry, the system will ask you again, if it detects a "
                            "duplicate\n\n";

                    cout << "ENTER YOUR FULL NAME: ";
                    cin.ignore();
                    cin.getline(s.name, 80);
                    cout << "ENTER YOUR STUDENT ID NUMBER: ";
                    cin.get(s.id_number, 10);
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

                    s.sum = s.cc112 + s.pe1 + s.lite + s.cc111 + s.ge102 + s.fil101 + s.ge101
                            + s.nstp1;
                    s.average = (s.sum / 8);
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
        }
        input_file.close();
        if (checker == false) {
            cout << "\t\t\t\tRECORD NOT FOUND :(\n";
            cout << "\nPress Enter to continue...";
        }
        cin.ignore();
        cin.get();
    }

    void intro() {
        system("cls");
        string choice;
        system("cls");
        system("color e");
        cout << "\n\n\t==================== STUDENT REPORT CARD MANEGEMENT "
                "SYSTEM ====================\n\n";
        cout << "\t\t\t\t1. MAIN MENU\n\n";
        cout << "\t\t\t\t2. EXIT\n\n";
        cout << "ENTER YOUR CHOICE: ";
        cin >> choice;
        if (choice == "2") {
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
            main_menu();
        } else {
            intro();
        }
    }

   public:
    void run() {
        system("color a");
        system("cls");
        dashboard();
        intro();
    }
};

int main() {
    Project project;
    project.run();
    return 0;
}
