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
void function (std::string name, std::string arg){
    if (name == "show_logs"){
        if (show_logs) std::cout << "Function -> Setting the show_logs to "<<arg<<"\n";
        if (arg == "true") show_logs = true;
        else if (arg == "false") show_logs = false;
        else std::cout<<"Error _> Function Err: show_logs can only understand boolean values (true/false)\n", std::exit (3);
    }
    else if (name == "source_path"){
        if (show_logs) std::cout << "Function -> Setting the source_path to "<<arg<<"\n";
        SRC_PATH=arg;
    }
    else if (name == "src"){
        if (show_logs) std::cout << "Function -> Setting the source_path to "<<arg<<"\n";
        SRC_PATH=arg;
    }
    else if (name == "import"){
        if (show_logs) std::cout << "Function -> Setting the import to "<<arg<<"\n";
        INCLUDE+="LIBXINC "+arg+"\n";
    }
    else if (name == "append"){
        if (show_logs) std::cout << "Function -> Setting the append to "<<arg<<"\n";
        INCLUDE+="STRXAPD " + arg + "\n";
    }
    else if (name == "clear_config"){
        if (show_logs) std::cout << "Function -> Clearing the config "<<arg<<"\n";
        INCLUDE="";
        EXTENSION="";
        OUTPUT="";
        OUT_DIR="";
        SRC_PATH="";
    }
    else if (name == "extension"){
        if (show_logs) std::cout << "Function -> Setting the extension to "<<arg<<"\n";
        EXTENSION=arg;
    }
    else if (name == "output"){
        if (show_logs) std::cout << "Function -> Setting the output to "<<arg<<"\n";
        OUTPUT = arg;
    }
    else if (name == "include"){
        if (show_logs) std::cout << "Function -> Setting the include to "<<arg<<"\n";
        INCLUDE+="LIBXINC "+SRC_PATH+"/"+arg+"."+EXTENSION+"\n";
    }
    else if (name == "output_directory"){
        if (show_logs) std::cout << "Function -> Setting the output_directory to "<<arg<<"\n";
        std::ifstream directory (arg+"/dirconfig.mklib");
        if (not directory.is_open()) std::system (std::string ("mkdir " + arg).c_str());
        else std::system (std::string ("rm -rf "+ arg+"/dirconfig.mklib").c_str());
        OUT_DIR=arg;
    }
    else if (name == "make"){
        if (is_IR_Made)
        {
            if (show_logs) std::cout << "Function -> Updating the IR (Intermediate Reprensentation) "<<"\n";
            IR+="SIGNAL " + OUTPUT + "." + EXTENSION + "\n"
                + INCLUDE +
                "SIGN-SIGNAL\n";
        }
        else {
            if (show_logs) std::cout << "Function -> Making the IR (Intermediate Reprensentation) "<<"\n";
            IR="SIGNAL " + OUTPUT + "." + EXTENSION + "\n"
               + INCLUDE + 
               "SIGN-SIGNAL\n";
            is_IR_Made = true;
        }
        INCLUDE="";
        OUTPUT="libxmklib";
        EXTENSION="";
        if (show_logs) std::cout<<"Generated IR _> \n"<<IR<<"\n";
    }
    else std::cout<<"Error _> Function Err: Unknown function "<<name<<"\n", std::exit (3);
}