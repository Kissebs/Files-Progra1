//
// Created by sebas on 1/2/2024.
//

#ifndef ARCHIVOS_FILEMANAGER_H
#define ARCHIVOS_FILEMANAGER_H

#include <iostream>
#include <fstream>
#include <string>
#include "College.h"
#include <map>
#include <sstream>



class FileManager {
public:
   static void saveGrades(College &college, const string &filename);

    static string readbyLine(const string &filename);

    static void readByContent(const string &filename);

    static string writeByLine(const string &filename);

    static void saveGradesB(College &college, const string &filename);

    static College readDataCollegeB(const string &filename);

    static void saveGradesMap(College& college, const string &filename);

    static map<string, double> readDataCollegeMap(const string &filename);

    static ostream &write(ostream &out, College& college);

    static istream &read(istream &in, College &college);
};


#endif //ARCHIVOS_FILEMANAGER_H
