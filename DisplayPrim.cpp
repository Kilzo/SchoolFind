#include"headPro.h"

extern void Prim(MGraph &G,int begin);

void DisplayPrim(MGraph &G){
    system("cls");
    int start;
    cout << "请输入起点 : "<< endl;
    cin >> start;
    if(start > G.vexnum - 1 || start < 0) cout << "超出值范围" << endl;
    else Prim(G,start);
    cout << endl << "按下任意键继续" << endl;
    getchar();
    getchar();
}
