#include"headPro.h"

void DisplayDest(MGraph G){
    system("cls");
    cout << "���" << "\t" << "����" << "     \t" << "���"<<endl;
    for(int i = 0;i < G.vexnum;i ++)                               //��ʾ�洢�ĵ����Ϣ
        cout << G.vexs[i].number << "\t" << G.vexs[i].name << "     \t"<< G.vexs[i].intro <<endl;
    cout << endl;
    cout << "���»س�������" << endl;
    getchar();
}
