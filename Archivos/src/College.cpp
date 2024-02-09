//
// Created by sebas on 1/2/2024.
//

#include <sstream>
#include "College.h"

void College::addGrade(string code, double grade) {
    grades[code] = grade;
}

void College::showAllGrades() {
    for (const auto &gra: grades) {
        cout <<  gra.first << " "<<  gra.second << endl;
    }
}

ostream &saveGrades(ostream &os, College college) {
    for (const auto &gra: college.grades) {
        os << gra.first << "" << gra.second << endl;
    }
    return os;
}

string College::toString() {
    stringstream s;
    for (const auto &gra: grades) {
        if(!gra.first.empty()){
            s << gra.first <<","<< gra.second << endl;

        }



    }
    return s.str();
}

const map<string, double> &College::getGrades() const {
    return grades;
}



