#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iterator>
#include <vector>

using namespace std;
namespace ariel{
struct node{
    string name;
    vector<node*> children;
    node* parent;
    int level;
    int number_of_children; // number of children of the current node
};


    enum IteratorType{
        Level_Oreder, Reverse_Level_Order, Pre_Order
    };
    
    class Iterator{
        node *current;
        vector<node *> node_list;
        uint index;

    public:
    Iterator(){
        current = NULL;
        index = 0;
    }
    Iterator(node *current, IteratorType type){
        
    }

    Iterator &operator++(){
        if(index < node_list.size()){
            index++;
        }
        return *this;
    }    
    std::string operator*(){
        return node_list[index]->name;
    }
    string *operator->(){
        return &node_list[index]->name;
    }

    bool operator !=(const Iterator &other){
        return this->current != other.current;
    }


    };
    
    
    
    
    
    
    class OrgChart
    {
    public:
    node *root;
    
    


    static void print_recursive(node * root);
    OrgChart add_root(const string& name);
    OrgChart add_sub(const string& parent, const string& child);
    friend ostream& operator<<(ostream& os, const OrgChart& org);
    // itarate over the tree and print the tree with level order traversal
    Iterator begin_level_order()const;
    Iterator end_level_order()const;

    Iterator begin_reverse_order()const;
    Iterator reverse_order()const;

    Iterator begin_preorder()const;
    Iterator end_preorder()const;

    Iterator begin()const;
    Iterator end()const;

    node * find_node(const string& name, node * root);
    
        OrgChart(){
            this->root = NULL;
        }
        
        
        
        
        };
    
  
    

}