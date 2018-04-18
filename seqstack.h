#pragma once
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
typedef struct Point
{
    int x;
    int y;
}Point;
typedef Point StackType;
//typedef char StackType; 
typedef struct SeqStack
{
    StackType* data;
    size_t size;
    size_t capacity;
}SeqStack;

void SeqStackInit(SeqStack* seqstack);

void SeqStackDestroy(SeqStack* seqstack);

void SeqStackPush(SeqStack* seqstack,StackType value);

void SeqStackPop(SeqStack* seqstack);

int SeqStackTop(SeqStack* seqstack,StackType* value);


//for maze
//1打印函数
void MazeSeqStackPrint(SeqStack* seqstack,const char* msg);
//2.赋值函数：from -> to
//由于栈支持动态内存开辟
//所以必须保证to的内存必须能够容纳from中的元素。
//就采用以下策肋：
//a.释放to中的原有内存。(DESTROY)
//b.根据from中的个数，重新申请大小的内存。（按照capacity）
//3.在进行数据的拷贝(循环拷贝)，
//对每一字段都要赋值，size capacity data
void SeqStackAssign(SeqStack* short_path,SeqStack* current_path);

