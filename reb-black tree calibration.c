//
//  reb-black tree calibration.c
//  red-black trees
//
//  Created by Khaled Mohab on 5/4/18.
//  Copyright © 2018 Khaled Mohab. All rights reserved.
//

#include "reb-black tree calibration.h"

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
void calibrate_col(rbtree * tree,node * leaf)
{
    int child_pos,parent_pos;
    child_pos=detrmine_child(leaf);
    parent_pos=detrmine_child(leaf->parent);
    if (leaf->parent->color!= red)
        return;
    else if(parent_pos==0 && leaf->parent->parent->leftchild->color==red)
    {
        compl_color(leaf->parent);
        compl_color(leaf->parent->parent);
        compl_color(leaf->parent->parent->leftchild);
        if (leaf->parent->parent!=tree->head)
            calibrate_col(tree,leaf->parent->parent);
    }
    else if (parent_pos==1 && leaf->parent->parent->rightchild->color==red)
    {
        compl_color(leaf->parent);
        compl_color(leaf->parent->parent);
        compl_color(leaf->parent->parent->rightchild);
        if (leaf->parent->parent!=tree->head)
            calibrate_col(tree,leaf->parent->parent);
    }
};
