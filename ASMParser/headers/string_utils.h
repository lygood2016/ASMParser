//
//  string_utils.h
//  ASMParser
//
//  Created by Li, Yan on 11/22/16.
//  Copyright © 2016 Li, Yan. All rights reserved.
//

#ifndef string_utils_h
#define string_utils_h

#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>
#include <string>

using namespace std;
// trim from start
string ltrim(const string &s);
// trim from end
string rtrim(const string &s);
// trim from both ends
string trim(const string &s);

#endif /* string_utils_h */
