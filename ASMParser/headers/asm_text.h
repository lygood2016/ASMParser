//
//  asm_text.h
//  ASMParser
//
//  Created by Li, Yan on 11/22/16.
//  Copyright © 2016 Li, Yan. All rights reserved.
//

#ifndef asm_text_h
#define asm_text_h

#include <unordered_map>
#include <string>
#include "string_utils.h"

using namespace std;

class ASMText {
public:
    
    ASMText() {
    }
    
    void addLabel(string str) {
        labels.push_back(str);
    }
    
    unsigned long getNumOfSections() {
        return sections.size();
    }
    
    vector<string> findTextByLabel(const string& label) {
        return sections[label];
    }
    
    bool hasLabel(const string& label) {
        return sections.find(label) != sections.end();
    }
    
    bool empty() {
        return sections.empty();
    }
    
    void addGlobal() {
        addLabel("global");
    }
    
    void addInstruction(const string& label, const string& instruction) {
        sections[label].push_back(trim(instruction));
    }

    void dumpLabel(const string& label) {
        for_each(sections[label].begin(), sections[label].end(), [](const string& instruction){
            cout << instruction << endl;
        });
    }
    
    void dumpText() {
        // Output each section in order
        for (string label : labels) {
            cout << label << ":" << endl;
            vector<string> v = sections[label];
            for_each(v.begin(), v.end(), [](const string& s) { cout << s << endl;});
        }
    }
    
private:
    vector<string> labels;
    unordered_map<string, vector<string>> sections;
};
#endif /* asm_text_h */
