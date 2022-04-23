#include"headPro.h"

extern void CreateGraph(MGraph &G, string str[], int rowNUM);
extern int input_str(char *filename, string str[]);
extern void DispMar(MGraph &G);
extern void InstallGraph(MGraph &G);
extern void Prim(MGraph &G,int begin);
extern void find(MGraph &G);
extern void DisplayDest(MGraph G);
extern void DisplayPrim(MGraph &G);

int main(){
    int rowNUM;
    string *str = new string[MAZX];                                 //字符串数组Str[]存放从校园景点读出的点和边的信息
    rowNUM = input_str("校园景点.txt", str);                        //调用inut_str函数，把读入的信息存入str[],返回读入文件的行数

    //for(int j = 0;j <= rowNUM;j ++)
      //  cout << str[j] <<endl;

    MGraph G;
    InstallGraph(G);
    CreateGraph(G, str, rowNUM);                                   //利用str[]数组中存放的点，边的信息创建图G的存储结构
    delete[] str;
    int choice;
    do{
        system("cls");
	    cout << ("|================================================|\n");
	    cout << ("|*                                              *|\n");
	    cout << ("|*                                              *|\n");
	    cout << ("|*----------------------------------------------*|\n");
	    cout << ("|*                                              *|\n");
	    cout << ("|*               1. 查看景点信息                *|\n");
	    cout << ("|*               2. 查询景点信息                *|\n");
	    cout << ("|*               3. 查看邻接矩阵                *|\n");
        cout << ("|*               4. 查询Prim结果                *|\n");
	    cout << ("|*               0. 退出                        *|\n");
	    cout << ("|*                                              *|\n");
	    cout << ("|*==============================================*|\n");
        cout << ("\n\n");
        do{
            cout << ("请选择您要进行的操作:");
            cin >> choice;
            if(choice < 0 || choice > 4) {
                cout << "请重新输入" << endl;
            }
        }while(choice < 0 || choice > 4);
        getchar();
        if(choice == 0) cout << "已退出" << endl;
        cout << endl;
        switch(choice){
            case 1: DisplayDest(G);break; // 查看景点信息
            case 2: find(G);break;        // 查询景点信息
            case 3: DispMar(G);break;     //查看邻接矩阵
            case 4: DisplayPrim(G);break; // 查询Prim结果
            case 0: exit(0);
        }
    }while(1);
    system("pause");
    //cout << "编号" << "\t" << "名称" << "     \t" << "简介"<<endl;
    //for(int i = 0;i < G.vexnum;i ++)                               //显示存储的点的信息
    //    cout << G.vexs[i].number << "\t" << G.vexs[i].name << "     \t"<< G.vexs[i].intro <<endl;
    //cout << endl;
    //DispMar(G);                                                  //显示图的存储结构边的信息
    //int start;
    //cout << "请输入起点 : "<< endl;
    //cin >> start;
    //Prim(G,start + 1);

    //find(G);
    return 0;
}


