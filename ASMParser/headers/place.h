//
//  place.h
//  ASMParser
//
//  Created by Li, Yan on 11/22/16.
//  Copyright © 2016 Li, Yan. All rights reserved.
//

#ifndef place_h
#define place_h

enum Types {
    LONG,
    DOUBLE,
    MEM,
    REGISTER
};

struct Place {
    Place (long value, Types type, string regName) :value(value), type(type), regName(regName) {}
    long value;
    Types type;
    string regName;
};

#endif /* place_h */
