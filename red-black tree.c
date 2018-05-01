//
//  red-black tree.c
//  red-black trees
//
//  Created by Khaled Mohab on 5/1/18.
//  Copyright © 2018 Khaled Mohab. All rights reserved.
//

#include "red-black tree.h"
#include <stdio.h>
#include <stdlib.h>


node * create_node(int value)
{
    node * new_node= (node*)malloc(sizeof(node));
    new_node->value=value;
    new_node->color=red;
    new_node->leftchild=NULL;
    new_node->rightchild=NULL;
    return new_node;
};

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
void calibrateorder(rbtree *tree)
{
    node * temp=tree->head;
    rbtree * tempright = NULL;
    rbtree * templeft = NULL;
    tempright->head=tree->head->rightchild;
    templeft->head=tree->head->leftchild;
    if (temp->value<temp->leftchild->value)
        swap(temp, temp->leftchild);
    if (temp->value>temp->rightchild->value)
        swap(temp, temp->rightchild);
    if (tempright->head->rightchild!=NULL)
        calibrateorder(tempright);
    if (tempright->head->leftchild!=NULL)
        calibrateorder(templeft);
};

void insert_node(rbtree* tree,node* Node)
{
    if (tree->head==NULL)
        tree->head=Node;
    else
    {
        node *temp=tree->head;
        while (temp->leftchild!=NULL && temp->rightchild!=NULL)
        {
            if (Node->value>temp->value && temp->rightchild==NULL)
            {
                temp->rightchild=Node;
                break;
            }
            else if (Node->value>temp->value)
                temp=temp->rightchild;
            
            if (Node->value<temp->value && temp->leftchild==NULL)
            {
                temp->leftchild=Node;
                Node->parent=temp;
                break;
            }
            else if (Node->value<temp->value)
                temp=temp->leftchild;
            
            if (Node->value==temp->value)
                break;
        }
    }
};
