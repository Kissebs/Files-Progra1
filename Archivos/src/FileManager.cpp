//
// Created by sebas on 1/2/2024.
//

//David was here

#include "FileManager.h"

void FileManager::saveGrades(College &college, const string &filename) {
 ofstream file(filename,ios::app);
 file<< "code,grade" << endl;
 file << college.toString()<<endl;
 file.close();
}


string FileManager::readbyLine(const string &filename) {
    ifstream file(filename);
    string line;
    string lineText;

    while (getline(file, lineText)) {
        line=line+lineText +"\n";
    }
    file.close();
    return line;
}

string FileManager::writeByLine(const string &filename) {

}

void FileManager::saveGradesB(College &college, const string &filename) {
    ofstream myfile(filename, ios::binary);
    for (const auto &grade: college.getGrades()) {
        myfile.write(reinterpret_cast<const char*>(&grade.first), sizeof(grade.first));
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
        string code;
        double grade;
        myReadFile.read(reinterpret_cast<char*>(&code), sizeof(code));
        myReadFile.read(reinterpret_cast<char*>(&grade), sizeof(grade));
        if (myReadFile.gcount() > 0) {
            college.addGrade(code, grade);
        }
    }
    myReadFile.close();
    return college;
}
void FileManager::saveGradesMap(College& college, const string &filename) {
    ofstream myFile(filename, ios::binary);
    string header = "code,grade\n";
    myFile.write(header.c_str(), header.size());
    for (const auto &grade: college.getGrades()) {
        myFile.write(reinterpret_cast<const char*>(&grade.first), sizeof(grade.first));
        myFile.write(reinterpret_cast<const char*>(&grade.second), sizeof(grade.second));
    }
    myFile.close();
}
map<string, double> FileManager::readDataCollegeMap(const string &filename) {
    ifstream myFile(filename, ios::binary);
    map<string, double> grades;
    string line;
    while (getline(myFile, line)) {
        stringstream ss(line);
        string code;
        double grade;
        ss >> code >> grade;
        grades[code] = grade;
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


