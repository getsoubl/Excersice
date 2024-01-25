//
//  main.cpp
//  JPMorganProject
//
//  Created by Georgios Tsoumplekas on 23/1/24.
//

#include <iostream>
#include "Group.hpp"
#include "GroupHandling.h"
#include "GroupClassification.h"


int main(int argc, const char * argv[]) {
    /////////////////Test 1
    GroupHandling groupHandling{};
    groupHandling.insertGroup({"A",1,600});
    groupHandling.insertGroup({"B",2,310});
    groupHandling.insertGroup({"C",2,200});
    groupHandling.insertGroup({"D",2,300});
    groupHandling.insertGroup({"E",4,450});
    groupHandling.insertGroup({"F",1,220});
    groupHandling.insertGroup({"G",3,195});
   // groupHandling.printGroup();
    groupHandling.classifyGroups();
    groupHandling.printClassfiedGroups();
    groupHandling.printGroupPair();
    return 0;
}
