//
//  GroupHandling.h
//  JPMorganProject
//
//  Created by Georgios Tsoumplekas on 23/1/24.
//

#ifndef GroupHandling_h
#define GroupHandling_h
#pragma once
#include <memory>
class Group;
class GroupClassification;
using GroupP = std::shared_ptr<Group>;
using GroupVec = std::vector<Group>;
class GroupHandling{
public:
    //Constructor
    GroupHandling();
    //insert lvalue grouos
    void insertGroup(Group const & group);
    //insert rvalue groups
    void insertGroup(Group && group);
    // print info about groups
    void printGroup();
    // classify Groups based on count and their strength
    void classifyGroups();
    // print all the classified Groups that have count 5
    void printClassfiedGroups();
    // print the two Groups with the minimum average strength
    void printGroupPair();
private:
    GroupVec groupVec_;
    std::unique_ptr<GroupClassification> groupClasify_;
    
};

#endif /* GroupHandling_h */
