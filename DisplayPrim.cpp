#include"headPro.h"

extern void Prim(MGraph &G,int begin);

void DisplayPrim(MGraph &G){
    system("cls");
    int start;
    cout << "��������� : "<< endl;
    cin >> start;
    if(start > G.vexnum - 1 || start < 0) cout << "����ֵ��Χ" << endl;
    else Prim(G,start);
    cout << endl << "�������������" << endl;
    getchar();
    getchar();
}
