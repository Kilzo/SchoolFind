#include"headPro.h"

// prim�㷨������С������
//
struct{
	int v;					//��С����U�е��Ǹ�����
	int w;					//��С���ϵ�Ȩֵ
}point[MVNum];

int MinVex(MGraph G){                                   //����Ȩֵ��С�ĵ�
	int index = -1;
	int minn = 100000000;
	for(int i = 0 ; i < G.vexnum ; i ++){
		if(minn > point[i].w && point[i].w != 0){
			minn = point[i].w;
			index = i;
		}
	}
	return index;
}
void Prim(MGraph &G,int u) {
    memset(point,0,sizeof point);
	int k , sum = 0;
	int u0 , v0;
    k = u;           										//kΪ����u���±�
    for(int j = 0; j < G.vexnum; j ++){     							//��V-U��ÿһ������vi����ʼ��point[i]
		if(j != k){
			point[j].v = u;
			point[j].w = G.arcs[k][j];									//{v, w}
		}
	}
	point[k].w = 0;        												//��ʼ��U = {u}
	for(int i = 1; i < G.vexnum; i ++){     							//ѡ������n-1�����㣬����n-1����(n= G.vexnum)
		k = MinVex(G);
		//���ͼ����һ����㣺��k����СȨֵ�Ķ��㣬point[k]�д��е�ǰ��С��
		u0 = point[k].v;     									        //u0Ϊ��С�ߵ�һ�����㣬u0��U
		v0 = G.vexs[k].number;            							    //v0Ϊ��С�ߵ���һ�����㣬v0��V-U
        cout << "("<< u0 << "," <<v0 << ") = "<< G.arcs[u0][v0]<<endl;  //��������
		sum += G.arcs[u0][v0];                                          //��С�������Ĵ��ۺ�
		point[k].w = 0;   		                                        //�� k�����㲢��U��
		for(int j = 0; j < G.vexnum; j ++)
			if(G.arcs[k][j] < point[j].w){						        //�����㲢��U����
				point[j].v = G.vexs[k].number;
				point[j].w = G.arcs[k][j];
			}
	}
	if(sum < 0x3f3f3f3f)cout << "��С�������Ĵ��ۺ�" << sum << endl;
	else {
        system("cls");
        cout << "�޴Ӹõ㵽�յ����С������" << endl;
	}
}
