#include <iostream>
#include "FileManager.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

        College college;
        college.addGrade("1", 2);
        college.addGrade("2", 3);
        college.addGrade("3", 4);

        FileManager fileManager;
        fileManager.saveGrades(college, "grades.csv");
        std::string line = fileManager.readbyLine("grades.csv");
        std::cout << line << std::endl;

        fileManager.saveGradesB(college, "grades.dat");
        College college1 = fileManager.readDataCollegeB("grades.dat");
        cout << "[FILE BINARY READ]" << endl;
        college1.showAllGrades();

        fileManager.saveGradesMap(college, "gradesMap.dat");
        cout << "[FILE BINARY READ WITH VECTOR]" << endl;
        map<string, double> grades = fileManager.readDataCollegeMap("gradesMap.dat");
        for (const auto &grade: grades) {
            std::cout << grade.first << " " << grade.second << std::endl;
        }



    return 0;
}
