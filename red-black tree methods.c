//
//  red-black tree methods.c
//  red-black trees
//
//  Created by Khaled Mohab on 5/4/18.
//  Copyright © 2018 Khaled Mohab. All rights reserved.
//

#include "red-black tree methods.h"
void swap (node* parent, node* child)
{
    node * temp = NULL;
    temp->value=parent->value;
    temp->color=parent->color;
    parent->value=child->value;
    parent->color=child->color;
    child->value=temp->value;
    child->color=temp->color;
}

void swap_col(node* node1,node* node2)
{
    int temp;
    temp = node1->color;
    node1->color=node2->color;
    node2->color=temp;
}
void compl_color(node * Node)
{
    if(Node->color==red)
        Node->color=black;
    else
        Node->color=red;
}
int detrmine_child(node *child)
{
    if (child->parent->leftchild==child)
        return 1;
    else
        return 0;
}
void rotateLeft(node *root, node *pt)
{
    node *pt_right = pt->rightchild;
    
    pt->rightchild = pt_right->leftchild;
    
    if (pt->rightchild != NULL)
        pt->rightchild->parent = pt;
    
    pt_right->parent = pt->parent;
    
    if (pt->parent == NULL)
        root = pt_right;
    
    else if (pt == pt->parent->leftchild)
        pt->parent->leftchild = pt_right;
    
    else
        pt->parent->rightchild = pt_right;
    
    pt_right->leftchild = pt;
    pt->parent = pt_right;
}

void rotateRight(node *root, node *pt)
{
    node *pt_left = pt->leftchild;
    
    pt->leftchild = pt_left->rightchild;
    
    if (pt->leftchild != NULL)
        pt->leftchild->parent = pt;
    
    pt_left->parent = pt->parent;
    
    if (pt->parent == NULL)
        root = pt_left;
    
    else if (pt == pt->parent->leftchild)
        pt->parent->leftchild = pt_left;
    
    else
        pt->parent->rightchild = pt_left;
    
    pt_left->rightchild = pt;
    pt->parent = pt_left;
}
