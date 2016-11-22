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
    Place (long* address, Types type) :address(address), isMem(isMem) {}
    long* address;
    Types isMem;
};

#endif /* place_h */
