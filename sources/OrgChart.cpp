#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <stdlib.h>
#include <iterator>
#include "OrgChart.hpp"
#include <vector>
using namespace std;
int global =0;
namespace ariel{
    
    OrgChart OrgChart::add_root(const string& name){
        /* 
        this function add a new root to the org chart, if there is root already, it will replace it
        */
        if(this->root == NULL){
        cout<< "root added"<<endl;
        this->root = new node;
        this->root->children = vector<node*>();
        /*
        TODO:
        CHECK WHAT TO DO EITH THE PREVIOUS ORGCHART
        */
        this->root->name = name;
        this->root->parent = NULL;
        this->root->level = 0;
        this->root->number_of_children = 0;
        return *this;
        }
        else{
            node *old_root = this->root;
            node *new_root = new node;
            new_root->children = old_root->children;
            new_root->name = name;
            new_root->parent = NULL;
            new_root->level = 0;
            for(node *child : this->root->children){
                cout<<"Child's name: "<<child->name<<endl;
                child->parent = new_root;
                
            }
            this->root = new_root;
            old_root = NULL;
            return *this;

        }
    }
    OrgChart OrgChart::add_sub(const string& parent, const string& child){
       // this function add a new child to the org chart, if there is no parent, it will throw an exception
        node *parent_node = this->find_node(parent, this->root);
        if (parent_node == NULL){
            throw std::invalid_argument("parent does not exist-first");
        }
        node *child_node = new node;
        child_node->name = child;
        parent_node->children.push_back(child_node);
        child_node->parent = parent_node;
        child_node->level = parent_node->level + 1;
        parent_node->number_of_children++;
        return *this;
    }

    







    std::ostream& operator<<(ostream& os, const OrgChart& org){
       

        node *current_node = org.root;
        os <<"        ----------"<<current_node->name <<"---------- "<<endl;
        OrgChart::print_recursive(current_node);
        return os;

    }

    node* OrgChart::find_node(const string& name, node * root){
        /*
        this function find a node in the org chart, if there is no node, it will return NULL
        */
        node *current_node = root;
        if(current_node->name == name){
            return current_node;
        }
        else{
            for(node * n : current_node->children){
                current_node = find_node(name, n);
                if(current_node != NULL){
                    return current_node;
                }
         }
        }
        return NULL;


    }
 
 void OrgChart::print_recursive(node * root){
        // this function print the org chart with recursion according to his children
        global = root->level;
        for(node * n : root->children){
            
            cout <<"     "<<n->name << " <----- is child of--->  " << n->parent->name <<endl;
            OrgChart::print_recursive(n);

    }
    }
   Iterator OrgChart::begin_level_order()const{
           // this function return the begin of the level order iterator
              return Iterator();
   }

   Iterator OrgChart::end_level_order()const{
           // this function return the end of the level order iterator
              return Iterator();
   }

    Iterator OrgChart::begin_reverse_order()const{
              // this function return the begin of the reverse order iterator
                  return Iterator();
    }

    Iterator OrgChart::reverse_order()const{
              // this function return the end of the reverse order iterator
                  return Iterator();
    }

    Iterator OrgChart::begin_preorder()const{
              // this function return the begin of the preorder iterator
                  return Iterator();
    }

    Iterator OrgChart::end_preorder()const{
              // this function return the end of the preorder iterator
                  return Iterator();
    }



}




