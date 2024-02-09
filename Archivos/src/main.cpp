#include <iostream>
#include "FileManager.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    College college;
    college.addGrade("1", 2);
    college.addGrade("2", 3);
    college.addGrade("3", 4);

    FileManager fileManager;
    /* FileManager::saveGrades(college, "grades.csv");
     std::string line = FileManager::readbyLine("grades.csv");
     std::cout << line << std::endl;*/
    map<string, double> grades1 = college.getGrades();
    FileManager::saveGradesB(grades1,  "grades.dat");
    College college1 = FileManager::readDataCollegeB("grades.dat");
    cout << "[FILE BINARY READ]" << endl;
    for (const auto &grade: grades1) {
        std::cout << grade.first << " " << grade.second << std::endl;
    }
    map <string, double> grades2 = college1.getGrades();
    FileManager::saveGradesMap( grades2, "gradesMap.dat");
    cout << "[FILE BINARY READ WITH Map]" << endl;
    map<string, double> grades = FileManager::readDataCollegeMap("gradesMap.dat");
    for (const auto &grade: grades2) {
        std::cout << grade.first << " " << grade.second << std::endl;
    }


    return 0;
}
