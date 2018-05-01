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
#define red 1
#define black 0

typedef struct node
{
    int value;
    int color;
    struct node *leftchild;
    struct node *rightchild;
    struct node *parent;
}node;

typedef struct leaf
{
    int color ;
    struct leaf *parent;
}leaf;

typedef struct rbtree
{
    struct node *head;
}rbtree;

node * create_node(int value)
{
    node * new_node= (node*)malloc(sizeof(node));
    new_node->value=value;
    new_node->color=red;
    new_node->leftchild=NULL;
    new_node->rightchild=NULL;
    return new_node;
};


void calibrate(rbtree *tree)
{
    node * temp=tree->head;
    if (temp->value<temp->leftchild->value)
    {
        
    }
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
