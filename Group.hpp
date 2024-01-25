//
//  Group.hpp
//  JPMorganProject
//
//  Created by Georgios Tsoumplekas on 23/1/24.
//

#ifndef Group_h
#define Group_h
#pragma once
#include <string>
using GroupId = std::string;
using Strength  = int;
using Counts    = int;
class Group{
    public:
        GroupId  groupId_;
        Counts   count_;
        Strength strength_;
};

#endif /* Group_h */
