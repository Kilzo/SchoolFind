#include"headPro.h"

void DisplayDest(MGraph G){
    system("cls");
    cout << "编号" << "\t" << "名称" << "     \t" << "简介"<<endl;
    for(int i = 0;i < G.vexnum;i ++)                               //显示存储的点的信息
        cout << G.vexs[i].number << "\t" << G.vexs[i].name << "     \t"<< G.vexs[i].intro <<endl;
    cout << endl;
    cout << "按下回车键继续" << endl;
    getchar();
}
