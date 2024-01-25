//
//  GroupHandling.cpp
//  JPMorganProject
//
//  Created by Georgios Tsoumplekas on 23/1/24.
//
#include <iostream>
#include "Group.hpp"
#include "GroupHandling.h"
#include "GroupClassification.h"

std::ostream & operator<<(std::ostream &os,  Group const & group){
    
    os << "{" << group.groupId_ <<"," << group.count_ << ","<< group.strength_ << "}" << std::endl;
    return os;
}

GroupHandling::GroupHandling()
:groupClasify_(new GroupClassification()){
    
}
void GroupHandling::insertGroup(Group const &group){
    groupVec_.push_back(group);
}
void GroupHandling::insertGroup(Group && group){
    groupVec_.emplace_back(group);
}

void GroupHandling::classifyGroups(){
    groupClasify_->classify(groupVec_);
}
void GroupHandling::printGroup(){
    for(auto  && el : groupVec_ ){
        std::cout << el << std::endl;
    }
}
void GroupHandling::printClassfiedGroups(){
    groupClasify_->print();
}

void GroupHandling::printGroupPair(){
    std::cout << "Print the two most closest groups " << std::endl;
    auto  [lhs,rhs]  = groupClasify_->findMinDiff();
    if(groupClasify_->size() == 0){
        std::cout << "No Group" << std::endl;
        return;
    }
    if(groupClasify_->size() == 1){
        std::cout << "Group 1" << std::endl;
        std::cout << "Strenght " << lhs->first;
        for(auto && el : lhs->second ){
            std::cout << el << std::endl;
        }
        std::cout << "------------------------------------------" << std::endl;
        return;
    }
    std::cout << "Group 1" << std::endl;
    std::cout << "Strenght " << lhs->first<< std::endl;
    for(auto && el : lhs->second ){
        std::cout << el << std::endl;
    }
    std::cout << "------------------------------------------" << std::endl;
    
    std::cout << "Group 2" << std::endl;
    std::cout << "Strenght " << rhs->first << std::endl;
    for(auto && el : rhs->second ){
        std::cout << el << std::endl;
    }
    std::cout << "------------------------------------------" << std::endl;
    
    
    
}
