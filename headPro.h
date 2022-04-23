    #include<iostream>
    #include<string.h>
    #include<stdlib.h>
    #include<fstream>       //输入输出流
    #include<windows.h>

    using namespace std;

    #define INF 32767
    #define MVNum 100

    const int MAZX = 111776;


    typedef struct VerTexType{
        int number;             //编号
        string name;            //名称
        string intro;           //简介
    }VerTexType;                //定义一个新的类型方便下面使用

    typedef struct{
        VerTexType vexs[MVNum];     //一维数组
        float arcs[MVNum][MVNum];   //邻接矩阵
        int vexnum = 0,arcnum = 0;  //当前定点数和边数
    }MGraph;                        //图的存储结构

