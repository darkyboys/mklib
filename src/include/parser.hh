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
void parser (std::vector <std::string> tokens){
    for (std::size_t i = 0;i < tokens.size();i++) {
        // std::cout<<tokens[i]<<"\n";
        if (show_logs) std::cout << "Parser -> Processing the token ["<<tokens[i]<<"] token number, "<< i<<"\n"
                                 << "Parser -> Making the valid token...\n";
        // Function processing
        std::string valid_token = "";
        for (std::size_t x = 0;x < tokens[i].length();x++){
            if (tokens[i][x] == '\n') {}
            else valid_token += tokens[i][x];
        }
        if (show_logs) std::cout << "Parser -> Done processing valid token which is ["<<valid_token<<"] token number, "<< i<<"\n";
        function (valid_token.substr(0, valid_token.find(":")), valid_token.substr(valid_token.find(":")+1));
    }
    if (show_logs) std::cout <<"Parser -> Parsing the IR (Intermediate Representation) to the executer...\n";
    executer();
}