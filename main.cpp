#include <windows.h>

#include <fstream>
#include <iostream>

using namespace std;

class Project {
    struct student {
        char name[80], id[10];
        int understanding_the_self, filipino, philippine_history, programming, physical_education,
            living_in_IT_Era, intro_to_computing, roll, sum, average;
    };

   public:
    void intro() {
        cout << "\n\n\n";
        Sleep(300);
        cout << "\t\t\t\t * * *  **** *      ****  ***   ***   ****   \n";
        Sleep(300);
        cout << "\t\t\t\t * * * *     *     *     *   * * * * *        \n";
        Sleep(300);
        cout << "\t\t\t\t * * * ***** *     *     *   * * * * *****    \n";
        Sleep(300);
        cout << "\t\t\t\t * * * *     *     *     *   * * * * *         \n";
        Sleep(300);
        cout << "\t\t\t\t  ***   **** *****  ****  ***  * * *  ****     \n";
        Sleep(300);
        cout << '\n';
        cout << "\t\t\t\t=============================================\n";
        Sleep(500);
        cout << "\t\t\t\t    STUDENT REPORT CARD MANEGEMENT SYSTEM\n";
        cout << "\t\t\t\t\t\tBY GROUP 3\n";
        Sleep(500);
        cout << "\t\t\t\t=============================================\n\n\n";
        Sleep(500);
        cout << "Press Enter to continue...";
        cin.ignore();
    }
    void main_menu() {
        system("color c");
        char choice;
        cout << "\t\t\t\t================= MAIN MENU ================\n\n\n";
        Sleep(300);
        cout << "\t\t\t\t1. CREATE STUDENT REPORT CARD\n\n\n";
        Sleep(300);
        cout << "\t\t\t\t2. VIEW ALL STUDENTS REPORT CARD\n\n\n";
        Sleep(300);
        cout << "\t\t\t\t3. VIEW A SINGLE STUDENT REPORT CARD\n\n\n";
        Sleep(300);
        cout << "\t\t\t\t4. MODIFY REPORT CARD\n\n\n";
        Sleep(300);
        cout << "\t\t\t\t5. DELETE RECORD\n\n\n";
        Sleep(300);
        cout << "\t\t\t\t=============================================\n";
        Sleep(300);
        cout << "\t\t\t\tENTER YOUR CHOICE(1-5): ";
        Sleep(300);
        cin >> choice;
        cout << '\n';
        switch (choice) {
        case '1': {
            add_record();
            break;
        }
        case '2': {
            view_all_records();
            break;
        }
        case '3': {
            system("cls");
            int number;
            cout << "ENTER YOUR ROLL NUMBER: ";
            cin >> number;
            view_specific_record(number);
            break;
        }
        case '4': {
            system("cls");
            int number;
            cout << "ENTER YOUR ROLL NUMBER: ";
            cin >> number;
            modify_record(number);
            break;
        }
        case '5': {
            system("cls");
            int number;
            cout << "ENTER YOUR ROLL NUMBER: ";
            cin >> number;
            cout << '\n';
            delete_record(number);
            break;
        }
        }
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
            cout << "ENTER YOUR FULL NAME: ";
            cin.ignore();
            cin.getline(s.name, 80);
            cout << "ENTER YOUR STUDENT ID NUMBER: ";
            cin.get(s.id, 10);
            cout << "ENTER YOUR ROLL NUMBER: ";
            cin >> s.roll;
            cout << "ENTER YOUR COMPUTER PROGRAMMING MARK: ";
            cin >> s.programming;
            cout << "ENTER YOUR UNDERSTANDING THE SELF MARK: ";
            cin >> s.understanding_the_self;
            cout << "ENTER YOUR FILIPINO MARK: ";
            cin >> s.filipino;
            cout << "ENTER YOUR PHILIPPINE HISTORY MARK: ";
            cin >> s.philippine_history;
            cout << "ENTER YOUR PHYSICAL EDUCATION MARK: ";
            cin >> s.physical_education;
            cout << "ENTER YOUR LIVING IN IT ERA MARK: ";
            cin >> s.living_in_IT_Era;
            cout << "ENTER YOUR INTRO TO COMPUTING MARK: ";
            cin >> s.intro_to_computing;
            s.sum = s.programming + s.physical_education + s.living_in_IT_Era + s.intro_to_computing
                    + s.philippine_history + s.filipino + s.understanding_the_self;
            s.average = (s.sum / 7);
            output_file.write(reinterpret_cast<char *>(&s), sizeof(student));
            output_file.close();
            cout << "\n\t\t\t\tTHE FILE IS SUCCESSFULLY SAVED\n\n";
            cout << "Press Enter to continue...";
            cin.ignore();
            cin.get();
        }
    }
    void view_specific_record(int number) {
        system("cls");
        student s;
        ifstream infile;
        infile.open("Data.txt", ios::app | ios::binary);
        if (infile.fail()) {
            cout << "THE FILE COULD NOT BE OPENED...";
            cin.ignore();
            cin.get();
        }
        bool equality = false;
        cout << "\t\t\t\t========== VIEW A SINGLE STUDENT REPORT ==========\n\n";
        while (infile.read(reinterpret_cast<char *>(&s), sizeof(student))) {
            if (s.roll == number) {
                cout << "\t\t\t\t==================================================\n";
                cout << "\t\t\t\tSTUDENT NAME: " << s.name << "\n\n";
                cout << "\t\t\t\tSTUDENT ID NUMBER: " << s.id << "\n\n";
                cout << "\t\t\t\tSTUDENT ROLL NUMBER: " << s.roll << "\n\n";
                cout << "\t\t\t\tPROGRAMMING MARK: " << s.programming << "\n\n";
                cout << "\t\t\t\tUNDERSTANDING THE SELF MARK: " << s.understanding_the_self
                     << "\n\n";
                cout << "\t\t\t\tFILIPINO MARK: " << s.filipino << "\n\n";
                cout << "\t\t\t\tPHILIPPINE HISTORY MARK: " << s.philippine_history << "\n\n";
                cout << "\t\t\t\tPHYSICAL EDUCATION MARK: " << s.physical_education << "\n\n";
                cout << "\t\t\t\tLIVING IN IT ERA MARK: " << s.living_in_IT_Era << "\n\n";
                cout << "\t\t\t\tINTRO TO COMPUTING MARK: " << s.intro_to_computing << "\n\n";
                cout << "\t\t\t\tSUM: " << s.sum << "\n\n";
                cout << "\t\t\t\tAVERAGE: " << s.average << "\n\n";
                cout << "=================================================================="
                        "================\n";

                equality = true;
            }
        }
        infile.close();
        if (equality == false)
            cout << "\t\t\t\tRECORD NOT FOUND...\n\n";
        cout << "Press Enter to continue...";
        cin.ignore();
        cin.get();
    }
    void view_all_records() {
        system("cls");
        student s;
        ifstream infile;
        bool check = false;
        infile.open("Data.txt", ios::app | ios::binary);
        if (infile.fail()) {
            cout << "THE FILE COULD NOT BE OPENED.....Press Enter...";
            cin.ignore();
            cin.get();
        } else {
            cout << "\n\n\t\t\t\tALL STUDENTS REPORT CARDS\n";
            cout << "===================================================================="
                    "==============\n";
            while (infile.read(reinterpret_cast<char *>(&s), sizeof(student))) {
                cout << "\t\t\t\tSTUDENT NAME: " << s.name << "\n\n";
                cout << "\t\t\t\tSTUDENT ID NUMBER: " << s.id << "\n\n";
                cout << "\t\t\t\tSTUDENT ROLL NUMBER: " << s.roll << "\n\n";
                cout << "\t\t\t\tPROGRAMMING MARK: " << s.programming << "\n\n";
                cout << "\t\t\t\tUNDERSTANDING THE SELF MARK: " << s.understanding_the_self
                     << "\n\n";
                cout << "\t\t\t\tFILIPINO MARK: " << s.filipino << "\n\n";
                cout << "\t\t\t\tPHILIPPINE HISTORY MARK: " << s.philippine_history << "\n\n";
                cout << "\t\t\t\tPHYSICAL EDUCATION MARK: " << s.physical_education << "\n\n";
                cout << "\t\t\t\tLIVING IN IT ERA MARK: " << s.living_in_IT_Era << "\n\n";
                cout << "\t\t\t\tINTRO TO COMPUTING MARK: " << s.intro_to_computing << "\n\n";
                cout << "\t\t\t\tSUM: " << s.sum << "\n\n";
                cout << "\t\t\t\tAVERAGE: " << s.average << "\n\n";
                cout << "=================================================================="
                        "================\n";

                check = true;
            }
            infile.close();
            if (check == false)
                cout << "\t\t\t\tNO RECORD FOUND...\n\n";
            cout << "Press Enter to continue....";
            cin.ignore();
            cin.get();
        }
    }
    void delete_record(int number) {
        system("cls");
        student s;
        ifstream input_file;
        input_file.open("Data.txt", ios::binary);
        if (!input_file) {
            cout << "THE FILE COULD NOT BE OPENED...\n";
            cin.ignore();
            cin.get();
        }
        ofstream output_file;
        output_file.open("Backup.txt", ios::binary);
        input_file.seekg(0, ios::beg);
        cout << "\t\t\t\t=========== DELETE A REPORT CARD ==========\n\n";
        while (input_file.read(reinterpret_cast<char *>(&s), sizeof(student))) {
            if (s.roll != number) {
                output_file.write(reinterpret_cast<char *>(&s), sizeof(student));
            }
        }
        input_file.close();
        output_file.close();
        remove("Data.txt");
        rename("Backup.txt", "Data.txt");
        cout << '\n';
        cout << "\t\t\t\tRECORD SUCCESSFULLY DELETED\n";
        cout << "Press Enter to continue...";
        cin.ignore();
        cin.get();
    }
    void modify_record(int n) {
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
                if (s.roll == n) {
                    cout << "\t\t\t\t================================================\n";
                    cout << "\t\t\t\tSTUDENT NAME: " << s.name << "\n\n";
                    cout << "\t\t\t\tSTUDENT ID NUMBER : " << s.id << "\n\n";
                    cout << "\t\t\t\tSTUDENT ROLL NUMBER: " << s.roll << "\n\n";
                    cout << "\t\t\t\tPROGRAMMING MARK: " << s.programming << "\n\n";
                    cout << "\t\t\t\tUNDERSTANDING THE SELF MARK: " << s.understanding_the_self
                         << "\n\n";
                    cout << "\t\t\t\tFILIPINO MARK: " << s.filipino << "\n\n";
                    cout << "\t\t\t\tPHILIPPINE HISTORY MARK: " << s.philippine_history << "\n\n";
                    cout << "\t\t\t\tPHYSICAL EDUCATION MARK: " << s.physical_education << "\n\n";
                    cout << "\t\t\t\tLIVING IN IT ERA MARK: " << s.living_in_IT_Era << "\n\n";
                    cout << "\t\t\t\tINTRO TO COMPUTING MARK: " << s.intro_to_computing << "\n\n";
                    cout << "=============================================\n";
                    cout << "\t\tENTER THE NEW INFORMATION\n";
                    cout << "=============================================\n";
                    cout << "ENTER YOUR FULL NAME: ";
                    cin.ignore();
                    cin.getline(s.name, 80);
                    cout << "ENTER YOUR STUDENT ID NUMBER: ";
                    cin.get(s.id, 10);
                    cout << "ENTER YOUR ROLL NUMBER: ";
                    cin >> s.roll;
                    cout << "ENTER YOUR COMPUTER PROGRAMMING MARK: ";
                    cin >> s.programming;
                    cout << "ENTER YOUR UNDERSTANDING THE SELF MARK: ";
                    cin >> s.understanding_the_self;
                    cout << "ENTER YOUR FILIPINO MARK: ";
                    cin >> s.filipino;
                    cout << "ENTER YOUR PHILIPPINE HISTORY MARK: ";
                    cin >> s.philippine_history;
                    cout << "ENTER YOUR PHYSICAL EDUCATION MARK: ";
                    cin >> s.physical_education;
                    cout << "ENTER YOUR LIVING IN IT ERA MARK: ";
                    cin >> s.living_in_IT_Era;
                    cout << "ENTER YOUR INTRO TO COMPUTING MARK: ";
                    cin >> s.intro_to_computing;

                    s.sum = s.programming + s.physical_education + s.living_in_IT_Era
                            + s.intro_to_computing + s.philippine_history + s.filipino
                            + s.understanding_the_self;
                    s.average = (s.sum / 7);
                    int pos = (-1) * static_cast<int>(sizeof(student));
                    input_file.seekp(pos, ios::cur);
                    input_file.write(reinterpret_cast<char *>(&s), sizeof(student));
                    cout << "\n\t\t\t\tTHE FILE IS SUCCESSFULLY UPDATED\n";
                    checker = true;
                }
            }
        }
        input_file.close();
        if (checker == false)
            cout << "\t\t\t\tRECORD NOT FOUND\n";
        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
    }
    void run() {
        system("color a");
        char choice;
        system("cls");
        intro();

        do {
            system("cls");
            system("color e");
            cout << "\n\n\t==================== STUDENT REPORT CARD MANEGEMENT "
                    "SYSTEM ====================\n\n";
            cout << "\t\t\t\t1. MAIN MENU\n\n";
            cout << "\t\t\t\t2. EXIT\n\n";
            cout << "ENTER YOUR CHOICE: ";
            cin >> choice;
            system("cls");
            switch (choice) {
            case '1': {
                main_menu();
                break;
            }
            case '2': {
                cout << "\t\t     THANK YOU FOR USING THIS SYSTEM\n";
                cout << "\n\n";
                cout << "\t   MEMBERS:\n";
                cout << "\t Arguil, Devyth\n";
                cout << "\t Ballarda, Audrey Rose\n";
                cout << "\t Caceres, Jan Darsey\n";
                cout << "\t Corporal, Alexis\n";
                cout << "\t Ducut, Rodelene\n";
                cout << "\t Lacdan, Peejay\n";
                cout << "\t Mendoza, Ronnel\n";
                cout << "\t Paliza, Janmar\n";
                cout << "\t San Luis, James Errol\n";
            }
            }
        } while (choice != '2');
    }
};

int main() {
    Project project;
    project.run();
    return 0;
}
