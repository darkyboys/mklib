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
std::vector <std::string> lexer (std::string code){
    std::vector <std::string> tokens;
    bool is_function_open = false,
         is_comment_started = false;
    std::string temp_function_name,
                temp_function_data,
                cache_function_name;
                // cache_function_data;
    for (std::size_t i = 0;i < code.length();i++){
        // std::cout << "'"<<code[i]<<"'\n"; // For debugging purpose only
        // Syntax Unit
        if (code[i] == '\n' and is_comment_started) 
            is_comment_started = false,
            code = code.substr(i+1),
            i = 0;
        if (is_comment_started) continue;
        if (code[i] == '#' or (code[i] == '/' and code[i+1] == '/') and not is_comment_started) {
            if (is_function_open and temp_function_name.find("append") != std::string::npos);
            else if (is_function_open) std::cout<< "Error _> Lexer Err: Invalid Syntax detected. '#' character can't be placed inside the function arguments.\n\n Critical Syntax Exception Failed: Autofixer Can't Fix Critical Syntax Error [2]\n", std::exit ( 3 );
            else is_comment_started = true;
        }
        if (code[i] == ';'){
            if (is_function_open) std::cout<< "Error _> Lexer Err: Invalid Syntax detected. ';' character can't be placed inside the function arguments.\n\n Critical Syntax Exception Failed: Autofixer Can't Fix Critical Syntax Error [1]\n", std::exit ( 3 );
            if (not is_function_open) tokens.push_back (std::string (temp_function_name + ":" + temp_function_data)), // Process the tokens in a way the parser can de-tokenise them.
                // std::cout <<"function_name: "<<temp_function_name<<", "<<temp_function_data<<"\n", // For debugging purpose only
                temp_function_name.clear(), 
                temp_function_data.clear(), 
                cache_function_name.clear(), // Clean the configurations to prevent any wrong tokenisation
                code = code.substr (i+1), // core manipulation for exact & expected tokens
                i = 0; // reset the i now
        }
        else if (code[i] == ')' and is_function_open) is_function_open = false;
        // Argument processing unit
        else if (is_function_open) temp_function_data += code[i];
        else if (code[i] == '(' and not is_function_open) {
            for (std::size_t x = i-1;true;x--) {
                cache_function_name += code [x];
                if (x == 0) break;
            }
            for (std::size_t y = cache_function_name.length()-1;true;y--) {
                if (cache_function_name[y] == ' ') {} // do nothing
                else temp_function_name += cache_function_name [y];
                if (y == 0) break;
            }
            is_function_open = true;
            // std::cout<<"function found: "  << temp_function_name<<"\n";  // For Debiggung Purpose only      
        }

    }
    return tokens;
}