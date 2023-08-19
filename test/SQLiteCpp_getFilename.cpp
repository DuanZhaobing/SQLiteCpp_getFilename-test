// SQLiteCpp_getFilename.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define SQLITECPP_COMPILE_DLL

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

#include <SQLiteCpp/SQLiteCpp.h>
#include <SQLiteCpp/VariadicBind.h>

#ifdef SQLITECPP_ENABLE_ASSERT_HANDLER
namespace SQLite
{
    /// definition of the assertion handler enabled when SQLITECPP_ENABLE_ASSERT_HANDLER is defined in the project (CMakeList.txt)
    void assertion_failed(const char* apFile, const long apLine, const char* apFunc, const char* apExpr, const char* apMsg)
    {
        // Print a message to the standard error output stream, and abort the program.
        std::cerr << apFile << ":" << apLine << ":" << " error: assertion failed (" << apExpr << ") in " << apFunc << "() with message \"" << apMsg << "\"\n";
        std::abort();
    }
}
#endif

/// Get path to this example's directory (including the final separator '/' or '\')
static inline std::string getExamplePath()
{
    std::string filePath(__FILE__);
    return filePath.substr(0, filePath.length() - std::string("SQLiteCpp_getFilename.cpp").length());
}

static const std::string db_name = "sample.db3";


int main()
{
    try{
        /*
        * SQLite exception : unable to open database file
        */ 
         SQLite::Database    database(db_name, SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);  

        /*
        Error reading characters of string.
        */ 
        //SQLite::Database    database(db_name.c_str(), SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);  
        std::cout << "SQLite database file '" << database.getFilename().c_str() << "' opened successfully\n";

    }
    catch (std::exception& e){
        std::cout << "SQLite exception: " << e.what() << std::endl;
        return EXIT_FAILURE; // unexpected error : exit the example program
    }
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
