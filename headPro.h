    #include<iostream>
    #include<string.h>
    #include<stdlib.h>
    #include<fstream>       //���������
    #include<windows.h>

    using namespace std;

    #define INF 32767
    #define MVNum 100

    const int MAZX = 111776;


    typedef struct VerTexType{
        int number;             //���
        string name;            //����
        string intro;           //���
    }VerTexType;                //����һ���µ����ͷ�������ʹ��

    typedef struct{
        VerTexType vexs[MVNum];     //һά����
        float arcs[MVNum][MVNum];   //�ڽӾ���
        int vexnum = 0,arcnum = 0;  //��ǰ�������ͱ���
    }MGraph;                        //ͼ�Ĵ洢�ṹ

