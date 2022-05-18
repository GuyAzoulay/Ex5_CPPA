#include "OrgChart.hpp"
#include <vector>

#include <iostream>
#include <fstream>
#include "doctest.h"
using namespace std;
using namespace ariel;

// THIS TEST IS TO CHECK IF THE ORGCHART IS CREATED CORRECTLY
TEST_CASE("IINITIALIZATION") {
    OrgChart org;
    CHECK_NOTHROW(org.add_root("CEO"));
    CHECK_NOTHROW(org.add_sub("CEO", "CTO"));
    CHECK_NOTHROW(org.add_sub("CEO", "CFO"));
    CHECK_NOTHROW(org.add_sub("CEO", "COO"));
    CHECK_NOTHROW(org.add_sub("CTO", "VP_SW"));
    CHECK_NOTHROW(org.add_sub("COO", "VP_BI"));
    CHECK_THROWS(org.add_sub("FICTIVE_VAR", "VP_BI1"));
    CHECK_THROWS(org.add_sub("FICTIVE_VAR2", "VP_BI2"));
    CHECK_NOTHROW(cout << org << endl);

}

//THIS TEST CASE WILL CHECK IF ADDING A NEW ROOT WILL REPLACE THE OLD ONE
TEST_CASE("ADDING A NEW ROOT") {
    OrgChart org;
    CHECK_NOTHROW(org.add_root("CEO"));
    CHECK_NOTHROW(org.add_root("NEW_CEO"));
    CHECK_NOTHROW(org.add_sub("NEW_CEO", "CTO"));
    CHECK_NOTHROW(org.add_sub("NEW_CEO", "CFO"));
    CHECK_NOTHROW(org.add_sub("NEW_CEO", "COO"));
    CHECK_NOTHROW(org.add_sub("CTO", "VP_SW"));
    CHECK_NOTHROW(org.add_sub("COO", "VP_BI"));
    CHECK_THROWS(org.add_sub("FICTIVE_VAR", "VP_BI"));
    CHECK_NOTHROW(org.add_root("NEWEST_CEO"));
    CHECK_NOTHROW(cout << org << endl);
}

// THIS TEST CASE WILL CHECK TH EQUALITY OF LEVEL ORDER

TEST_CASE("LEVEL ORDER") {
    OrgChart org;
    uint i = 0;
    vector<string> expected_level_order = {"CEO", "CTO", "CFO", "COO", "VP_SW", "VP_BI"};
    CHECK_NOTHROW(org.add_root("CEO"));
    CHECK_NOTHROW(org.add_sub("CEO", "CTO"));
    CHECK_NOTHROW(org.add_sub("CEO", "CFO"));
    CHECK_NOTHROW(org.add_sub("CEO", "COO"));
    CHECK_THROWS(org.add_sub("FICTIVE_VAR", "VP_BI"));
    CHECK_NOTHROW(org.add_sub("CTO", "VP_SW"));
    CHECK_NOTHROW(org.add_sub("COO", "VP_BI"));
    for(Iterator it = org.begin_level_order(); it != org.end_level_order(); ++it){
        CHECK_NOTHROW(cout << *it << endl);
        CHECK_EQ(*it==expected_level_order[i], true);
        i++;
    }

}

// THIS TEST CASE WILL CHECK TH EQUALITY OF PREORDER

TEST_CASE("PREORDER") {
    OrgChart org;
    uint i = 0;
    vector<string> expected_preorder = {"CEO", "CTO", "VP_SW", "CFO", "COO", "VP_BI"};
    CHECK_NOTHROW(org.add_root("CEO"));
    CHECK_NOTHROW(org.add_sub("CEO", "CTO"));
    CHECK_NOTHROW(org.add_sub("CEO", "CFO"));
    CHECK_THROWS(org.add_sub("FICTIVE_VAR", "VP_BI"));
    CHECK_NOTHROW(org.add_sub("CEO", "COO"));
    CHECK_NOTHROW(org.add_sub("CTO", "VP_SW"));
    CHECK_THROWS(org.add_sub("FICTIVE_VAR2", "VP_BI2"));
    CHECK_NOTHROW(org.add_sub("COO", "VP_BI"));
    for(Iterator it = org.begin_preorder(); it != org.end_preorder(); ++it){
        CHECK_NOTHROW(cout << *it<< endl);
        CHECK_EQ((*it)== expected_preorder[i], true);
        i++;
    }

}

// THIS TEST CASE WILL CHECK TH EQUALITY OF REVERSE PREORDER

TEST_CASE("REVERSE PREORDER") {
    OrgChart org;
    uint i = 0;
    vector<string> expected_reverse_order = {"VP_SW","VP_BI", "CTO", "CFO", "COO", "CEO"};
    CHECK_NOTHROW(org.add_root("CEO"));
    CHECK_NOTHROW(org.add_sub("CEO", "CTO"));
    CHECK_NOTHROW(org.add_sub("CEO", "CFO"));
    CHECK_THROWS(org.add_sub("FICTIVE_VAR", "VP_BI"));
    CHECK_NOTHROW(org.add_sub("CEO", "COO"));
    CHECK_NOTHROW(org.add_sub("CTO", "VP_SW"));
    CHECK_THROWS(org.add_sub("FICTIVE_VAR2", "VP_BI2"));
    CHECK_NOTHROW(org.add_sub("COO", "VP_BI"));
    for(Iterator it = org.begin_reverse_order(); it != org.reverse_order(); ++it){
        CHECK_NOTHROW(cout << (*it)<< endl);
        CHECK_EQ((*it)== expected_reverse_order[i], true);
        i++;
    }
}


