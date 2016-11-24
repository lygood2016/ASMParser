//
//  memory.h
//  ASMParser
//
//  Created by Li, Yan on 11/23/16.
//  Copyright © 2016 Li, Yan. All rights reserved.
//

#ifndef memory_h
#define memory_h

#include <string>

#define MEMORY_SIZE 1048576 * 64 // 64 MB memory

class Memory {
public:
    
    static Memory* getInstance() {
        if (!memory) {
            memory = new Memory();
        }
        return memory;
    }
    
    long* head() { return memory; }
    
    void put(const long* source, long* destination, long size) {
        memcpy(source, destination, size);
    }

private:
    
    Memory() {
    }
    
    static Memory* memory;
    
    long memory[MEMORY_SIZE/sizeof(long)];
};
#endif /* memory_h */
