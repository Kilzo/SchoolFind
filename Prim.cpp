#include"headPro.h"

// prim算法构建最小生成树
//
struct{
	int v;					//最小边在U中的那个顶点
	int w;					//最小边上的权值
}point[MVNum];

int MinVex(MGraph G){                                   //返回权值最小的点
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
    k = u;           										//k为顶点u的下标
    for(int j = 0; j < G.vexnum; j ++){     							//对V-U的每一个顶点vi，初始化point[i]
		if(j != k){
			point[j].v = u;
			point[j].w = G.arcs[k][j];									//{v, w}
		}
	}
	point[k].w = 0;        												//初始，U = {u}
	for(int i = 1; i < G.vexnum; i ++){     							//选择其余n-1个顶点，生成n-1条边(n= G.vexnum)
		k = MinVex(G);
		//求出图的下一个结点：第k个最小权值的顶点，point[k]中存有当前最小边
		u0 = point[k].v;     									        //u0为最小边的一个顶点，u0∈U
		v0 = G.vexs[k].number;            							    //v0为最小边的另一个顶点，v0∈V-U
        cout << "("<< u0 << "," <<v0 << ") = "<< G.arcs[u0][v0]<<endl;  //输出边情况
		sum += G.arcs[u0][v0];                                          //最小生成树的代价和
		point[k].w = 0;   		                                        //第 k个顶点并入U集
		for(int j = 0; j < G.vexnum; j ++)
			if(G.arcs[k][j] < point[j].w){						        //将顶点并入U集合
				point[j].v = G.vexs[k].number;
				point[j].w = G.arcs[k][j];
			}
	}
	if(sum < 0x3f3f3f3f)cout << "最小生成树的代价和" << sum << endl;
	else {
        system("cls");
        cout << "无从该点到终点的最小生成树" << endl;
	}
}
