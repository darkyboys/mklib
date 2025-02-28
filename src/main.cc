/*
 * Copyright (c) ghgltggamers 2024
 * MKLIB - A Library Building System which allows you to define rules for building the let MKLIB Create your library of all the project files in one.
 * Cross Platform and Cross Language.
 * Licensed under the MIT License
 * Compile with magma build system
 * Checkout the README.md for exact compilation information
*/

// Source

// Headers
// Std Cxx17 STL
#include <iostream>
#include  <fstream>
#include  <sstream>
#include   <vector>
#include   <string>

// Local
#include "lexer.hh"
#include "ir.hh"
#include "functions.hh"
#include "executer.hh"
#include "parser.hh"


int main (int argc, char * argv[]){
    if (argc == 2 and (std::string(argv[1]) == "--version" or std::string (argv[1]) == "-v")) std::cout <<"MKLIB 1.0 (Community Edition)\n\n", std::exit ( 3 );
    if (argc == 2 and (std::string(argv[1]) == "--help" or std::string (argv[1]) == "-h")) std::cout <<"MKLIB 1.0 (Community Edition) - Help\n\n"
                                                                                                     <<"Standard Usage-> mklib in the directory with build.mklib file or mklib path/to/build.mklib/file or mklib --version , -v for version and mklib --help, -h for help\n", std::exit ( 3 );
    // std::cout <<"Exec...\n";
    // std::string temp = "", code = "";
    // std::ifstream file ("example/build.mklib");
    // while (std::getline(file, temp)) code += temp + "\n";
    // std::vector <std::string> a = lexer (code);
    // parser (a);
    if (argc == 2 and not (std::string(argv[1]) == "--version" or std::string (argv[1]) == "-v") and not (std::string(argv[1]) == "--help" or std::string (argv[1]) == "-h")) {
        std::string temp = "", code = "";
        std::ifstream file (std::string(argv[1]) + "/build.mklib");
        if (not file.is_open()) std::cout <<"Error _> File IO Err: No build file was found at the specified path\n.", std::exit ( 3 );
        while (std::getline(file, temp)) code += temp + "\n";
        parser (lexer (code));
        std::exit ( 3 );
    }

    std::string temp = "", code = "";
    std::ifstream file ("build.mklib");
    if (not file.is_open()) std::cout <<"Error _> File IO Err: No build file was found at the specified path\n.", std::exit ( 3 );
    while (std::getline(file, temp)) code += temp + "\n";
    parser (lexer (code));

    
}

// Entier project finished at 5:45pm friday, 28th feb 2025