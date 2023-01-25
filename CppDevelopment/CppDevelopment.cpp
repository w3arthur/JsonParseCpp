// CppDevelopment.cpp : This file contains the 'main' function. Program execution 
// begins and ends there.
//

//https://github.com/nlohmann/json

#define DEBUG_MODE 1
#include <iostream>
#include <vector>
#include <string> 
#include <fstream>
#include <exception>
#include <nlohmann/json.hpp>
#include <Person.h>
using std::ifstream;
using std::exception;
using std::vector;
using std::ws;
using std::cout;
using std::endl;
using std::cin;
using std::hash;
using std::map;
using std::pair;
using std::function;
using json = nlohmann::json;



int main()
{

    vector<Person> persons;
    string buffer;
    int personCounter{ 0 };

    string fileName = "mock-data.json";
    ifstream inFile;
    inFile.open(fileName);
    if (!inFile.is_open()) throw exception("cant read the file");
    inFile.seekg(0, std::ios::end);//
    buffer.resize(inFile.tellg());//
    inFile.seekg(0, std::ios::beg);//
    inFile.read(&buffer[0], buffer.size());//
    //while (inFile) { string line; getline(inFile >> ws, line); buffer += line; }
    inFile.close();

    auto jsonItems = json::parse(buffer);

    for (auto& el : jsonItems.items()) {   /*array list*/
        auto key = el.key();
        ++personCounter;
        auto poupleValue = el.value();
        Person p;
        for (auto& [subkey, subval] : poupleValue.items()) 
            p.setValue(subkey, subval);
        persons.push_back(p);
    }



#if DEBUG_MODE == 1
    std::cout << "\nDebugging mode\n";
    for (auto p : persons)
        cout << p << '\n';
    cin.get();  //debug  
#endif // DEBUG
}
