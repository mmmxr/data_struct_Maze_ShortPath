#include <stdio.h>
#include "maze.h"
/////////////////////////////////////////////
//Round4.针对一个复杂的迷宫地图找出最短路径。
//这里的复杂不光是指迷宫有多个出口，同时路径上可能带环
/////////////////////////////////////////////
//实现一个递归版本
void MarkWithCycle(Maze* m,Point cur,Point pre)
{
    //先判断是入口点的情况，不能+1，应该直接赋值为2；
    //    if(pre.x==-1&&pre.y==-1)
    //   {
    //=2
    //return
    //  }
    //取出pre_value
    //让这个点的值=pre_value+1

}
int CanStayWithCycle(Maze* m,Point cur,Point pre)
{
    //1.判断当前点是否在地图上
    //2.当前点是不是墙
    //3.如果当前点是1，这是可以直接落脚的
    //4.当前点如果已经走过了，比较cur对应的值和pre的值的大小关系
    //   a.cur_value 7,pre_value 5 应该落脚 更短
    //   b.cur_value 6,pre_value 5 不应该落脚 一样,没必要
    //   c.cur_value 5,pre_value 5 不应该落脚 更长
//    //  规则是：cur_value > pre_value+1 就应该可以落脚
//    if (条件)
//    {
//        return 1;
//    }
//    return 0;

}
void _GetShortPathWithCycle(Maze* m,Point cur,Point pre,Point entry,SeqStack* cur_path,SeqStack* short_path)
{
    //1.判定当前点是否能落脚(判定规则变了)
    //CanStayWithCycle()
    //2.标记当前点，标记规则变了，并且将当前点插入到cur_path
    //MarkWithCycle();
    //3.判定当前点是否是出口
    //  是出口，要拿cur_path和short_path进行pk（或者short空栈），把比较短的路径保存到short_path(seqstackassign)
    //  不管当前这条路径是不是比较短的都要进行回溯。
    //4.不是出口，探测四个方向。（顺时针）
    //5.如果四个方向都探测过了，就出栈回溯
}
void GetShortPathWithCycle(Maze* maze,Point entry)
{
  //  SeqStack cur_path;
  //  SeqStack short_path;
  //  SeqStackInit(&cur_path);
  //  SeqStackInit(&short_path);
  //  Point pre={-1,-1};//虚拟一个非法点
  //  _GetShortPathWithCycle(maze,entry,pre,entry,&cur_path,&short_path);//5个参数
  //  //打印

}
void MazeInitShortPathWithCycle()
{
  //  int map[ROW][COL]={
  //      {0,1,0,0,0,0},
  //      {0,1,1,1,0,0},
  //      {0,1,0,1,1,1},
  //      {1,1,1,1,0,0},
  //      {0,0,1,0,0,0},
  //      {0,0,1,0,0,0},
  //  };
  //  //循环赋值
}

/////////////////////////////////////////////
//Round3.使用递归解决多通路迷宫的最短路径问题
/////////////////////////////////////////////
///////////////////////////////////
//该函数仅作迷宫测试使用
//////////////////////////////////
void Mark(Maze* m,Point cur)
{
    //走过的地方标记为2
    m->maze[cur.x][cur.y]=2;

}
int Exit(Maze* m,Point pt,Point entry)
{
    (void)m;
    //1当前点是不是入口，若为入口，就不是出口
    if(pt.x==entry.x&&pt.y==entry.y)
    {
        return 0;
    }
    //2.如果当前点在边界上，就是出口
    if(pt.x==0||pt.y==0||pt.x== ROW-1||pt.y==COL-1)
    {
        return 1;
    }
    return 0;
}
int CanStay(Maze* m,Point pt)
{
    //判断pt该点是否能落脚
    //若该点在地图外，则不能落脚
    if(pt.x<0||pt.x>=ROW||pt.y<0||pt.y>=COL)
    {
        return 0;
    }
    //若该点在地图内，位置为1，就能落脚，为0或2都不能落脚
    int value=m->maze[pt.x][pt.y];
    if(value==1)
    {
        return 1;
    }
    return 0;
}
void MazeInitShortPath(Maze* m)
{
    int map[ROW][COL]={
        {0,1,0,0,0,0},
        {0,1,1,1,0,0},
        {0,1,0,1,1,1},
        {1,1,1,0,0,0},
        {0,0,1,0,0,0},
        {0,0,1,0,0,0},
    };
    //循环赋值
    size_t i=0;
    size_t j=0;
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COL;j++)
        {
            m->maze[i][j]=map[i][j];
        }
    }
}
//尝试找到所有的路径，然后筛选出一条最短的
//递归版本
void _GetShortPath(Maze* m,Point entry,Point cur,SeqStack* cur_path,SeqStack* short_path)
{
    printf("(%d,%d)\n",cur.x,cur.y);
    //1。判定当前点是否能落脚，
    if(!CanStay(m,cur))
    {
        return;
    }
    //2.如果能落脚就对当前点进行标记，同时把当前点插入到cur_path中，
    Mark(m,cur);
    SeqStackPush(cur_path,cur);
    //3.判定当前点是否是出口，说明当前找到了一条路径，就拿当前路径与short_path中的路径对比，
    if(Exit(m,cur,entry))
    {
        printf("找到了一条路径\n");
        if(cur_path->size<short_path->size||short_path->size==0)
        {
            //4.如果当前路径比short_path短，或者short_path是一个空栈，就拿当前路径代替short_path(在seqstack中实现一个seqstackassign功能赋值函数)
            //代替完毕，还是要进行回溯
            SeqStackAssign(cur_path,short_path);
            printf("找到了一条比较短的路径\n");
        }
        //5.如果当前路径没有比short_path短就要尝试去找其他路径。（进行回溯）
        //回溯之前，也要把cur_path栈顶元素出栈
        SeqStackPop(cur_path);
        return;
    }
        //6.如果当前点不是出口，尝试探测四个方向（顺时针），
        //如果四个方向都递归的探测过了，就可以进行出栈，(指的是函数栈帧，也要手动出栈cur_path)回溯到上一个点。
        Point up=cur;
        up.x-=1;
        _GetShortPath(m,entry,up,cur_path,short_path);

        Point right=cur;
        right.y+=1;
        _GetShortPath(m,entry,right,cur_path,short_path);

        Point down=cur;
        down.x+=1;
        _GetShortPath(m,entry,down,cur_path,short_path);

        Point left=cur;
        left.y-=1;
        _GetShortPath(m,entry,left,cur_path,short_path);
        
        SeqStackPop(cur_path);
        return;

}
void GetShortPath(Maze* m,Point entry)
{
    //定义一个栈，叫做cur_path，保存了当前路径
    //定义一个栈，叫做short_path，保存着最短路径
    //并初始化两个栈
    SeqStack cur_path;
    SeqStack short_path;
    SeqStackInit(&cur_path);
    SeqStackInit(&short_path);
    //_GetShortPath借助这个函数完成递归（5个参数）
    _GetShortPath(m,entry,entry,&cur_path,&short_path);
    //打印栈中的内容
    //打印函数写在seqstack文件内，仅用于调试该函数
    //因为，通常意义上，栈是不允许打印的，此时只是为了查看栈中的点(为了保证从入口到出口的顺序)
    MazeSeqStackPrint(&short_path,"最短路径为:\n");
}


/////////////////////////////////////////////
//Roun2.使用迭代的方式求解迷宫问题（借助循环）
/////////////////////////////////////////////

void GetPathByLoop(Maze* m,Point entry)
{
    //1.创建一个栈，并且初始化
    SeqStack stack;
    SeqStackInit(&stack);
    //2.判定入口能不能落脚，如果不能，说明参数非法
    if(!CanStay(m,entry))
    {
        return;
    }
    //3.标记入口点，将入口点入栈
    Mark(m,entry);
    SeqStackPush(&stack,entry);
    //4.进入循环，获取到当前的栈顶元素（栈顶元素一定能落脚）
    Point cur;
    while(SeqStackTop(&stack,&cur))
    {
        //5.判定这个点是不是出口，如果是出口，直接函数返回。
        //6.按照顺时针方向取相邻点，判定相邻点是否能够落脚，如果能落脚就标记入栈，立刻进入下一层循环。
        //7.如果四个相邻点都不能落脚，就出栈当前点回溯
        if(Exit(m,cur,entry))
        {
            printf("找到了一条路径\n");
            return;
        }
        Point up=cur;
        up.x-=1;
        if(CanStay(m,up))
        {
            Mark(m,up);
            SeqStackPush(&stack,up);
            continue;
        }

        Point right=cur;
        right.y+=1;
        if(CanStay(m,right))
        {
            Mark(m,right);
            SeqStackPush(&stack,right);
            continue;
        }

        Point down=cur;
        down.x+=1;
        if(CanStay(m,down))
        {
            Mark(m,down);
            SeqStackPush(&stack,down);
            continue;
        }

        Point left=cur;
        left.y-=1;
        if(CanStay(m,left))
        {
            Mark(m,left);
            SeqStackPush(&stack,left);
            continue;
        }

        SeqStackPop(&stack);
    }
}
////////////////////////////////////////////
//Round1.使用递归的方式来求解迷宫问题
////////////////////////////////////////////

void _GetPath(Maze* m,Point entry,Point cur)
{
    printf("cur:(%d,%d)\n",cur.x,cur.y);
    //每次走到下一个点，都要调用此函数
    //1.判断当前点能否能落脚
    if(!CanStay(m,cur))
    {
        return;
    }
    //2.若能落脚，给当前位置坐标记
    Mark(m,cur);
    //3.若当前点为出口，说明找到了一条出路，探测就结束
    if(Exit(m,cur,entry))
    {
        printf("找到了一条出路\n");
        return;
    }
    //4。若当前点不是出口，按顺时针顺序探测四个方向的相邻点
    
    Point up=cur;
    up.x-=1;
    _GetPath(m,entry,up);

    Point right=cur;
    right.y+=1;
    _GetPath(m,entry,right);

    Point down=cur;
    down.x+=1;
    _GetPath(m,entry,down);

    Point left=cur;
    left.y-=1;
    _GetPath(m,entry,left);
}

void GetPath(Maze* m,Point entry)
{
    if(m==NULL)
    {
        return;
    }
    _GetPath(m,entry,entry);
}
void MazeInit(Maze* m)
{
    if(m==NULL)
    {
        return;
    }
    int arr[ROW][COL]={
        {0,0,1,0,0,0},
        {0,0,1,1,1,0},
        {0,0,1,0,1,0},
        {0,1,1,0,1,0},
        {0,1,0,0,1,0},
        {0,1,0,0,0,0}
    };
    int i=0;
    int j=0;
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COL;j++)
        {
            m->maze[i][j]=arr[i][j];
        }
    }
}
void MazePrint(Maze* m)
{
    if(m==NULL)
    {
        return;
    }
    int i=0;
    int j=0;
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COL;j++)
        {
            printf("%d ",m->maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void Test1()
{
    Maze maze;
    MazeInit(&maze);
    MazePrint(&maze);
    Point entry={0,2};
    GetPath(&maze,entry);
    MazePrint(&maze);
}
void Test2()
{
    Maze maze;
    MazeInit(&maze);
    MazePrint(&maze);
    Point entry={0,2};
    GetPathByLoop(&maze,entry);
    MazePrint(&maze);
}
void Test3()
{
    Maze maze;
    MazeInitShortPath(&maze);
    MazePrint(&maze);
    Point entry={0,1};
    //GetPathByLoop(&maze,entry);
    GetShortPath(&maze,entry);
    MazePrint(&maze);
}
int main()
{
//    Test1();
//    Test2();
    Test3();
    return 0;
}
