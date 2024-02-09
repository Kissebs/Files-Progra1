//
// Created by sebas on 1/2/2024.
//

#ifndef ARCHIVOS_COLLEGE_H
#define ARCHIVOS_COLLEGE_H

#include <map>
#include <iostream>
using namespace std;
class College {
private:
    map<string, double> grades;
public:
    //gets and sets
    const map<string, double> &getGrades() const;

    //Methods

    void addGrade(string code, double grade);
    void showAllGrades();
    friend ostream &saveGrades(ostream &os, College college);
    string toString();


};



#endif //ARCHIVOS_COLLEGE_H
