//
//  GroupClassification.h
//  JPMorganProject
//
//  Created by Georgios Tsoumplekas on 23/1/24.
//

#ifndef GroupClassification_h
#define GroupClassification_h
#include <vector>
#include <memory>
#include <map>
#pragma once
class Group;
using MapElements = std::vector<Group>;
using AverageWeight = unsigned long;
using GroupIterator = std::multimap<AverageWeight,MapElements>::iterator;
class GroupClassification{
    public:
        // classify groups based on their counts
        void classify(std::vector<Group> & groups);
        // print groups information
        void print();
        //return two iterators which have the minimum difference
        std::pair<GroupIterator,GroupIterator> findMinDiff();
        // return the size of the multimap
        inline auto  size() const {
            return classifiedGroup.size();
        }
    private:
    // return the average strength of elements in a group
    AverageWeight calculateAverage(std::vector<Group> const & groups);
    //create all the combinations of groups which has sum 5
    void findAllCompinationTagetSum5(std::vector<Group> const & groups,std::vector<std::vector<Group>> & classifiedGroups, std::vector<Group> & temporalVec, std::size_t index = {}, int sum = 5 );
    //store vectors of groups which counts it is 5
    //sort base on average weight
    std::multimap<AverageWeight,MapElements> classifiedGroup;
};
#endif /* GroupClassification_h */
