//
//  red-black tree methods.h
//  red-black trees
//
//  Created by Khaled Mohab on 5/4/18.
//  Copyright © 2018 Khaled Mohab. All rights reserved.
//

#ifndef red_black_tree_methods_h
#define red_black_tree_methods_h

#include <stdio.h>
#include "red-black tree.h"
#include "reb-black tree calibration.h"
void swap (node* parent, node* child);
void swap_col(node* node1,node* node2);
void compl_color(node * Node);
int detrmine_child(node *child);
void rotateLeft(node *root, node *pt);
void rotateRight(node *root, node *pt);

#endif /* red_black_tree_methods_h */
