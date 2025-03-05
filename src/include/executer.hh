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
void executer (){
    std::stringstream irstream(IR);
    std::string temp;
    std::string signal, libxinc;
    std::vector <std::string> files_captured = {};
    while (std::getline(irstream, temp)){
        // std::cout<<temp<<"\n";
        if (show_logs) std::cout <<"Executer -> De-Tokenising the IR "<<temp<<"\n";
        std::string temp_name, temp_arguments;
        temp_name = temp.substr(0, temp.find(" "));
        temp_arguments = temp.substr(temp.find(" ")+1);
        
        if (show_logs) std::cout <<"Executer -> Executing the temps ["<<temp_name<<","<<temp_arguments<<"]\n";
        if (temp_name == "SIGNAL"){
            if (show_logs) std::cout <<"Executer -> Making the SIGNAL "<<temp_arguments<<"\n";
            signal = temp_arguments;
        }
        
        else if (temp_name == "LIBXINC"){
            if (show_logs) std::cout <<"Executer -> Checking the includes for "<<temp_arguments<<"\n";
            bool is_file_captured = false;
            for (std::size_t i = 0;i < files_captured.size();i++){
                if (files_captured[i] == temp_arguments) is_file_captured = true;
            }
            if (is_file_captured) std::cout <<"Warning _> Executer IO: File "<<temp_arguments<<" was already processed!, Ignoring it now.\n";
            else {
                std::ifstream i_include (temp_arguments); // input includes
                if (not i_include.is_open()) std::cout <<"Error _> Executer Err: included file <"<<temp_arguments<<"> was not found.\n\nCritical IO Error found: Can-not ignore this error.\n", std::exit ( 3 );

                std::string temp_file_data = "";
                while (std::getline (i_include, temp_file_data)) libxinc += temp_file_data + "\n";
                files_captured.push_back (temp_arguments);
            }
        }

        else if (temp_name == "STRXAPD") {
            libxinc += temp_arguments + "\n";
        }

        else if (temp_name == "SIGN-SIGNAL") {
            if (show_logs) std::cout << "Signing the signal "<<signal<<"\n...";
            std::ofstream sign_signal_out_file (OUT_DIR+"/"+signal);
            sign_signal_out_file<<libxinc;
            if (show_logs) std::cout <<"Done!\nClosing the signal "<<signal<<"!";
            signal =  "";
            libxinc = "";
            files_captured.clear();
            if (show_logs) std::cout <<"The signal was closed successfully\n\nThe Library was successully created!\n";
        }

    }
}