#include"headPro.h"

void DispMar(MGraph &G){
    system("cls");
    cout << "\t";
    for(int i = 0;i < G.vexnum; i ++)
        cout << i << "\t";
    cout << endl << endl;
    for(int i = 0;i < G.vexnum; i++){
        cout << i << "\t";
        for(int j = 0;j < G.vexnum;j ++)
            if(G.arcs[i][j] == 0x3f3f3f3f) cout << "∞" << "\t";
            else cout << G.arcs[i][j] << "\t";
        cout <<endl;
    }
    cout << "按下回车键继续" << endl;
    getchar();
}
