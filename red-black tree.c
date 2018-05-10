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
void delete_node(rbtree* tree,int val)
{   node* leaf=tree->head;
    while(leaf->leftchild!=NULL && leaf->rightchild!=NULL)
    {
        if (leaf==NULL)
        {
            printf("value not found!!\n");
            return;
        }
        else if (val==leaf->value)
            break;
        else if(val>leaf->value)
            leaf=leaf->rightchild;
        else if (val<leaf->value)
            leaf=leaf->leftchild;
    }
    if (leaf->color==red)
    {
        node *temp=NULL;
        temp=leaf->rightchild;
        while (temp->leftchild!=NULL) {
            temp=temp->leftchild;
        }
        temp->parent->leftchild=temp->rightchild;
        swap(temp, leaf)
        free(temp);
    }
    else
    {
        if (leaf->leftchild==NULL&&leaf->rightchild==NULL)
        {
            free(leaf);
        }
        else if (leaf->leftchild!=NULL)
        {
            node *temp=NULL;
            temp=leaf->leftchild;
            while (temp->rightchild!=NULL) {
                temp=temp->rightchild;
            }
            swap(temp, leaf);
            free(temp);
        }
    }
        
}


/*
                        b
                    r        r
                b      b   b    b
              r   b   r b r  r r  r
                                   r
 */
