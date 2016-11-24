//
//  main.cpp
//  ASMParser
//
//  Created by Li, Yan on 11/22/16.
//  Copyright © 2016 Li, Yan. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "headers/asm_text.h"
#include "headers/string_utils.h"
#include "headers/cpu.h"
#include "headers/operator.h"
using namespace std;

typedef void (*Operation)(const Place& source, const Place& target);
extern unordered_map<string, Operation> assemblyToFunction;

ASMText text;
string gFileName = "/Users/amznyl/Desktop/ASMParser/ASMParser/asm.s";


int main(int argc, const char * argv[]) {
    // insert code here...
    CPU64* cpu = CPU64::getInstance();
    
    assemblyToFunction["movq"](Place(0, REGISTER, "rax"), Place(0, REGISTER, "rbx"));
    cout << *cpu->getRegLong("ebx") << endl;
    
    /*
    ifstream infile(gFileName);
    string line;
    string currentLabel = "global";
    while (getline(infile, line))
    {
        if (text.empty()) {
            text.addGlobal();
        } else if (line.find(":") != string::npos) {
            currentLabel = line.substr(0, line.find(":"));
            text.addLabel(currentLabel);
            continue;
        }
        text.addInstruction(currentLabel, line);
    }
    text.dumpText();*/
    return 0;
}
