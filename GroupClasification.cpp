//
//  GroupClasification.cpp
//  JPMorganProject
//
//  Created by Georgios Tsoumplekas on 23/1/24.
//
#include <iostream>
#include "GroupClassification.h"
#include "Group.hpp"
#include <cmath>
extern std::ostream & operator<<(std::ostream &os,  Group const & group);

void GroupClassification::classify(std::vector<Group>  & groups){
    std::sort(groups.begin(),groups.end(),[](auto const & lhs,auto const &  rhs){
        return lhs.count_ < rhs.count_;
    });
    
    //a  vector to store  all the compinations of groups where counts are 5
    std::vector<Group> groupsCount5{};
    ///NOTE:: for debug purposes
    //for(auto && el : groups){
    //    std::cout << el << std::endl;
   // }
    std::vector<std::vector<Group>>  classifiedGroupsVec{};
    std::vector<Group>  temporalVec{};
    findAllCompinationTagetSum5(groups,classifiedGroupsVec,temporalVec);
    //NOTE: for debug purposes
    /*for (auto && vec : classifiedGroupsVec){
        for (auto && el : vec){
            std::cout << el << ",";
        }
        std::cout << std::endl;
    }*/
    //store all of them in a map/
    for(auto && groupVec : classifiedGroupsVec){
        auto weight = calculateAverage(groupVec);
        classifiedGroup.insert(std::pair(weight,groupVec));
    }
    
    
}

AverageWeight GroupClassification::calculateAverage(std::vector<Group> const & groups){
    
        unsigned long sum  = 0;
        for(auto && el: groups){
            sum+= (el.count_ * el.strength_);
        }
        sum/=5;
        return sum;
}

void GroupClassification::print(){
    std::size_t count{};
    for(auto el : classifiedGroup){
        std::cout << "Group" << count++ << std::endl;
        std::cout << "Average Weight is " << el.first << std::endl;
        std::cout << "Groups included" << std::endl;
        for(auto && group : el.second){
            std::cout << group << std::endl;
        }
        std::cout << "-----------------------------------------------"<<std::endl;
    }
}

void GroupClassification::findAllCompinationTagetSum5(std::vector<Group> const & groups,std::vector<std::vector<Group>> & classifiedGroups, std::vector<Group> & temporalVec, std::size_t index , int sum  ){
    if(0 == sum){
        classifiedGroups.push_back(temporalVec);
        return;
    }
    for(std::size_t i = index; index < groups.size();++i ){
        if (groups[i].count_ > sum){
            break;
        }
        temporalVec.push_back(groups[i]);
        findAllCompinationTagetSum5(groups,classifiedGroups,temporalVec,i+1,sum-groups[i].count_);
        //remove from the stack the current weight
        temporalVec.pop_back();
        
    }
}
std::pair<GroupIterator,GroupIterator> GroupClassification::findMinDiff(){
    std::pair<GroupIterator,GroupIterator> p;
    long  min = std::numeric_limits<long>::max();
    auto begin = classifiedGroup.begin();
    auto end   = classifiedGroup.end();
    auto next_begin = std::next(begin,1);
    for(auto it = next_begin; it != end;++it){
        auto previous = std::next(it,-1);
        long diff =  (it->first - previous->first);
        diff = std::abs(diff);
        if (min > diff){
            min = diff;
            p = {previous,it};
        }
    }
    return p;
}

