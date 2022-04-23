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
    string *str = new string[MAZX];                                 //�ַ�������Str[]��Ŵ�У԰��������ĵ�ͱߵ���Ϣ
    rowNUM = input_str("У԰����.txt", str);                        //����inut_str�������Ѷ������Ϣ����str[],���ض����ļ�������

    //for(int j = 0;j <= rowNUM;j ++)
      //  cout << str[j] <<endl;

    MGraph G;
    InstallGraph(G);
    CreateGraph(G, str, rowNUM);                                   //����str[]�����д�ŵĵ㣬�ߵ���Ϣ����ͼG�Ĵ洢�ṹ
    delete[] str;
    int choice;
    do{
        system("cls");
	    cout << ("|================================================|\n");
	    cout << ("|*                                              *|\n");
	    cout << ("|*                                              *|\n");
	    cout << ("|*----------------------------------------------*|\n");
	    cout << ("|*                                              *|\n");
	    cout << ("|*               1. �鿴������Ϣ                *|\n");
	    cout << ("|*               2. ��ѯ������Ϣ                *|\n");
	    cout << ("|*               3. �鿴�ڽӾ���                *|\n");
        cout << ("|*               4. ��ѯPrim���                *|\n");
	    cout << ("|*               0. �˳�                        *|\n");
	    cout << ("|*                                              *|\n");
	    cout << ("|*==============================================*|\n");
        cout << ("\n\n");
        do{
            cout << ("��ѡ����Ҫ���еĲ���:");
            cin >> choice;
            if(choice < 0 || choice > 4) {
                cout << "����������" << endl;
            }
        }while(choice < 0 || choice > 4);
        getchar();
        if(choice == 0) cout << "���˳�" << endl;
        cout << endl;
        switch(choice){
            case 1: DisplayDest(G);break; // �鿴������Ϣ
            case 2: find(G);break;        // ��ѯ������Ϣ
            case 3: DispMar(G);break;     //�鿴�ڽӾ���
            case 4: DisplayPrim(G);break; // ��ѯPrim���
            case 0: exit(0);
        }
    }while(1);
    system("pause");
    //cout << "���" << "\t" << "����" << "     \t" << "���"<<endl;
    //for(int i = 0;i < G.vexnum;i ++)                               //��ʾ�洢�ĵ����Ϣ
    //    cout << G.vexs[i].number << "\t" << G.vexs[i].name << "     \t"<< G.vexs[i].intro <<endl;
    //cout << endl;
    //DispMar(G);                                                  //��ʾͼ�Ĵ洢�ṹ�ߵ���Ϣ
    //int start;
    //cout << "��������� : "<< endl;
    //cin >> start;
    //Prim(G,start + 1);

    //find(G);
    return 0;
}


