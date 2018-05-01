//
//  red-black tree.h
//  red-black trees
//
//  Created by Khaled Mohab on 5/1/18.
//  Copyright © 2018 Khaled Mohab. All rights reserved.
//

#ifndef red_black_tree_h
#define red_black_tree_h
#define red 1
#define black 0
#include <stdio.h>
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
node * create_node(int value);
void swap (node* parent, node* child);
void calibrateorder(rbtree *tree);
void insert_node(rbtree* tree,node* Node);

#endif /* red_black_tree_h */
