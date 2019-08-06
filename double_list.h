#ifndef _DOUBLE_LIST_H
#define _DOUBLE_LIST_H
#include<stdio.h>
//创建节点数据结
typedef struct node
{
	void * data;
        struct node *front;
        struct node *next;
}node,*pnode;
//创建链表数据结构
typedef struct list
{
        int size;
	pnode first;
	pnode last;
}list;
void print_data (const void * const p);
node* create_node (void * const x);
list* init_list ();//初始化
int print_length (list * l);//长度
void insert_back (list * l, void * const x);//尾部插入节点
void insert_head (list * l, void * const x);//头部插入节点
void print_list (list * l,void(*pt)(const void * const));//传入链表指针和函数指针，函数的参数为void*
void delete_back (list * l);//尾部删除节点
void delete_head (list * l);//头部删除节点
void delete_val (list * l,void * const x);//删除与x相同的节点
int find_data (list * l, void * const x, int (*fd)(const void * const, const void * const) );//查找
//list* sort_list(list *l, int(*sl)(const void * const, const void * const));//排序

void Sort_List (list *l, int (*sl)(const void* const , const void* const));
void sort_list (node* first, node* last ,int (*cmp)(const void * const , const void * const));
void clean_list (list * l);//清除链表
#endif
