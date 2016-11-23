//
//  string_utils.cpp
//  ASMParser
//
//  Created by Li, Yan on 11/22/16.
//  Copyright © 2016 Li, Yan. All rights reserved.
//

#include "string_utils.h"

// trim from start
string ltrim(const string &str) {
    string s = str;
    s.erase(s.begin(), find_if(s.begin(), s.end(),
                                    not1(ptr_fun<int, int>(isspace))));
    return s;
}

// trim from end
string rtrim(const string &str) {
    string s = str;
    s.erase(find_if(s.rbegin(), s.rend(),
                         not1(ptr_fun<int, int>(isspace))).base(), s.end());
    return s;
}

// trim from both ends
string trim(const string &str) {
    string s = str;
    return ltrim(rtrim(s));
}