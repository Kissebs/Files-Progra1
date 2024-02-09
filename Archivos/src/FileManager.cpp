//
// Created by sebas on 1/2/2024.
//

//David was here

#include "FileManager.h"

void FileManager::saveGradesB(map<string,double>&grades,  const string &filename) {
    ofstream myfile(filename, ios::binary);
    for (const auto &grade: grades) {
        size_t len = grade.first.size();
        myfile.write(reinterpret_cast<const char*>(&len), sizeof(len));
        myfile.write(grade.first.c_str(), len);
        myfile.write(reinterpret_cast<const char*>(&grade.second), sizeof(grade.second));
    }
    myfile.close();
}

College FileManager::readDataCollegeB(const string &filename) {
    College college;
    ifstream myReadFile(filename, ios::binary);
    if(!myReadFile.is_open()){
        throw invalid_argument("No se pudo abrir el archivo");
    }
    while (!myReadFile.eof()) {
        size_t len;
        myReadFile.read(reinterpret_cast<char*>(&len), sizeof(len));
        if (myReadFile.gcount() > 0) {
            string code;
            code.resize(len);
            myReadFile.read(&code[0], len);
            double grade;
            myReadFile.read(reinterpret_cast<char*>(&grade), sizeof(grade));
            college.addGrade(code, grade);
        }
    }
    myReadFile.close();
    return college;
}

void FileManager::saveGradesMap(map<string,double>&grades, const string &filename) {
    ofstream myFile(filename, ios::binary);
    string header = "code,grade\n";
    myFile.write(header.c_str(), header.size());
    for (const auto &grade: grades) {
        size_t len = grade.first.size();
        myFile.write(reinterpret_cast<const char*>(&len), sizeof(len));
        myFile.write(grade.first.c_str(), len);
        myFile.write(reinterpret_cast<const char*>(&grade.second), sizeof(grade.second));
    }
    myFile.close();
}

map<string, double> FileManager::readDataCollegeMap(const string &filename) {
    ifstream myFile(filename, ios::binary);
    map<string, double> grades;
    string line;
    getline(myFile, line); // Skip header
    while (!myFile.eof()) {
        size_t len;
        myFile.read(reinterpret_cast<char*>(&len), sizeof(len));
        if (myFile.gcount() > 0) {
            string code;
            code.resize(len);
            myFile.read(&code[0], len);
            double grade;
            myFile.read(reinterpret_cast<char*>(&grade), sizeof(grade));
            grades[code] = grade;
        }
    }
    myFile.close();
    return grades;
}

ostream &FileManager::write(ostream &out, College& college) {
   out<<"code grade"<<"\n";
    for (const auto &grade: college.getGrades()) {
        out << grade.first << " " << grade.second << "\n";
    }
    return out;
}

istream &FileManager::read(istream &in, College &college) {
    string line;
    while (getline(in, line)) {
        stringstream ss(line);
        string code;
        double grade;
        ss >> code >> grade;
        college.addGrade(code, grade);
    }
    return in;
}


