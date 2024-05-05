#include <iostream>
#include <fstream>
#include <cstdio>

class Student {
    int rollNumber;
    float percentage;
    float english, physics, chemistry, maths, computer;
    char name[200], fatherName[200], motherName[200], className[200];

public:
    void inputDetails() {
        std::cout << "Enter Name of Student: ";
        std::cin.getline(name, 200);
        std::cout << "Enter Father's name: ";
        std::cin.getline(fatherName, 200);
        std::cout << "Enter Mother's Name: ";
        std::cin.getline(motherName, 200);
        std::cout << "Enter Class: ";
        std::cin.getline(className, 200);
        std::cout << "Enter Roll Number: ";
        std::cin >> rollNumber;
        std::cout << "Enter 5 Subject Marks(out of 100):\n";
        std::cout << "English: ";
        std::cin >> english;
        std::cout << "Physics: ";
        std::cin >> physics;
        std::cout << "Chemistry: ";
        std::cin >> chemistry;
        std::cout << "Maths: ";
        std::cin >> maths;
        std::cout << "Computer: ";
        std::cin >> computer;
    }

    void outputDetails() {
        std::cout << "Name of Student: " << name << "\n";
        std::cout << "Father's name: " << fatherName << "\n";
        std::cout << "Mother's Name: " << motherName << "\n";
        std::cout << "Class: " << className << "\n";
        std::cout << "Roll Number: " << rollNumber << "\n";
        std::cout << "Subject Marks(out of 100):\n";
        std::cout << "English: " << english << "\n";
        std::cout << "Physics: " << physics << "\n";
        std::cout << "Chemistry: " << chemistry << "\n";
        std::cout << "Maths: " << maths << "\n";
        std::cout << "Computer: " << computer << "\n";
    }

    int getRollNumber() {
        return rollNumber;
    }

    void modifyRecord() {
        char choice;
        std::cout << "Do you want to modify the record (Y/N): ";
        std::cin >> choice;
        if (choice == 'Y' || choice == 'y') {
            // Code for modifying the record
        }
        else {
            std::cout << "Record not modified\n";
        }
    }

    void displayResult() {
        // Code to display result
    }
};

void addRecordToFile(Student obj) {
    std::ofstream outfile("student_records.dat", std::ios::app | std::ios::binary);
    outfile.write((char*)&obj, sizeof(obj));
    outfile.close();
}

void searchRecordInFile(int rollNumber) {
    Student obj;
    std::ifstream infile("student_records.dat", std::ios::binary);
    while (infile.read((char*)&obj, sizeof(obj))) {
        if (obj.getRollNumber() == rollNumber) {
            obj.outputDetails();
            break;
        }
    }
    infile.close();
}

void editRecordInFile(int rollNumber) {
    Student obj;
    std::fstream file("student_records.dat", std::ios::in | std::ios::out | std::ios::binary);
    while (file.read((char*)&obj, sizeof(obj))) {
        if (obj.getRollNumber() == rollNumber) {
            // Code to modify the record
            file.seekp(-sizeof(obj), std::ios::cur);
            file.write((char*)&obj, sizeof(obj));
            break;
        }
    }
    file.close();
}

void deleteRecordFromFile(int rollNumber) {
    Student obj;
    std::ifstream infile("student_records.dat", std::ios::binary);
    std::ofstream outfile("temp.dat", std::ios::binary);
    while (infile.read((char*)&obj, sizeof(obj))) {
        if (obj.getRollNumber() != rollNumber) {
            outfile.write((char*)&obj, sizeof(obj));
        }
    }
    infile.close();
    outfile.close();
    std::remove("student_records.dat");
    std::rename("temp.dat", "student_records.dat");
}

int main() {
    int option;
    Student obj;

    while (option != 5) {
        std::cout << "\t\t\t*************************\n";
        std::cout << "\t\t\tSTUDENT MANAGEMENT SYSTEM\n";
        std::cout << "\t\t\t**************************\n\n\n";
        std::cout << "MENU\n\n";
        std::cout << "1. Add a New Record of Student\n";
        std::cout << "2. Search a Record of Student\n";
        std::cout << "3. Edit Record of Student\n";
        std::cout << "4. Delete the Record of Student\n";
        std::cout << "5. Exit\n\n";
        std::cout << "Enter your choice: ";
        std::cin >> option;

        switch (option) {
            case 1:
                std::cout << "Adding a New Record\n\n";
                obj.inputDetails();
                addRecordToFile(obj);
                obj.outputDetails();
                break;

            case 2:
                std::cout << "Searching the Details of Student\n\n";
                int roll;
                std::cout << "Enter Student Roll Number: ";
                std::cin >> roll;
                searchRecordInFile(roll);
                break;

            case 3:
                std::cout << "Editing the Student Record\n\n";
                int rollToEdit;
                std::cout << "Enter Roll No. of Student to edit: ";
                std::cin >> rollToEdit;
                editRecordInFile(rollToEdit);
                break;

            case 4:
                std::cout << "Deleting the Student Record\n\n";
                int rollToDelete;
                std::cout << "Enter Student Roll no. you want to delete: ";
                std::cin >> rollToDelete;
                deleteRecordFromFile(rollToDelete);
                break;

            case 5:
                std::cout << "EXIT\n";
                break;

            default:
                std::cout << "Wrong choice\n";
                break;
        }
    }

    return 0;
}

