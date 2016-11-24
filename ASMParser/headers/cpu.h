//
//  parser.h
//  ASMParser
//
//  Created by Li, Yan on 11/22/16.
//  Copyright © 2016 Li, Yan. All rights reserved.
//

#ifndef parser_h
#define parser_h

#include <unordered_map>
#include <unordered_set>
#include <exception>
using namespace std;

class CPU64 {
public:
    
    struct InvalidRegisterException: public exception
    {
        string registerName;
        
        InvalidRegisterException(string registerName):registerName(registerName) {}
        virtual const char* what() const throw() {
            string errorMsg = "CPU64: Invalid register name: " + registerName + ".";
            return errorMsg.c_str();
        }
    };
    
    static CPU64* getInstance() {
        if (!cpu) {
            cpu = new CPU64();
        }
        return cpu;
    }
    
    long* getRegLong(string regName) {
        if (!reg64.count(regName)) {
            throw new InvalidRegisterException(regName);
        }
        return (long*)regMap[regName];
    }
    
    int* getRegInt(string regName) {
        if (!reg32.count(regName)) {
            throw new InvalidRegisterException(regName);
        }
        return (int*)regMap[regName];
    }
    
private:
    
    CPU64() {
        regMap["rax"] = &rax;
        regMap["rbx"] = &rbx;
        regMap["rcx"] = &rcx;
    }
    
    static long rax;
    static long rbx;
    static long rcx;
    static long rdx;
    
    static CPU64* cpu;
    static unordered_map<string, void*> regMap;
    const unordered_set<string> reg32{ "eax", "ebx", "ecx", "edx", "esi", "edi" };
    const unordered_set<string> reg64{ "rax", "rbx", "rcx", "rdx", "rsi", "rdi" };
};

CPU64* CPU64::cpu = NULL;
long CPU64::rax = 3;
long CPU64::rbx = 4;
long CPU64::rcx = 5;
long CPU64::rdx = 6;
unordered_map<string, void*> CPU64::regMap;

#endif /* parser_h */
