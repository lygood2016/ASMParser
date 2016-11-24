//
//  operator.h
//  ASMParser
//
//  Created by Li, Yan on 11/22/16.
//  Copyright © 2016 Li, Yan. All rights reserved.
//

#ifndef operator_h
#define operator_h

#include "place.h"
#include "cpu.h"
#include <unordered_map>
using namespace std;
static void movq(const Place& source, const Place& target) {
    CPU64* cpu = CPU64::getInstance();
        
    if (source.type == REGISTER && target.type == REGISTER) {
        long* sg = cpu->getRegLong(source.regName);
        long* tg = cpu->getRegLong(target.regName);
        *tg = *sg;
    }
}
    
static void movl(const Place& source, const Place& target) {
    CPU64* cpu = CPU64::getInstance();
        
    if (source.type == REGISTER && target.type == REGISTER) {
        int* sg = cpu->getRegInt(source.regName);
        int* tg = cpu->getRegInt(target.regName);
        *tg = *sg;
    }
}

typedef void (*Operation)(const Place& source, const Place& target);
unordered_map<string, Operation> assemblyToFunction = {
    {"movq", movq},
    {"movl", movl}
};

#endif /* operator_h */
