#include"headPro.h"

void find(MGraph &G){
    system("cls");                                              //������˵�ҳ��
    char choice_1;                                              //�����Ƿ������ѯ�ı���
    int num = 0;                                                //����洢��ŵı���
    string *strName = new string[MAZX];                         //��������Ҫ�洢��sting����

    do{                                                         //do-while���Ȳ���һ��
    //system("cls");
    cout << "������Ҫ��ѯ�ı��/���� : ";

    bool sele = false;                                          //���岢��ʼ���Ƿ��ظ��������seleΪfalse
    cin >> strName[num ++];
    for(int i = 0;i < num - 1;i ++)                             //ѭ��һ���ж��Ƿ��ظ�����
        if(strName[i] == strName[num - 1]) {
            cout << "�ظ�����,����������,����������" << endl;
            num --;                                             //����ظ����룬�ͷ�һ�������±�
            sele = true;                                        //���жϱ�����Ϊtrue
        }
    if(sele) continue;                                          //�ظ����룬����
    string s;                                                   //����洢���������
    //cin >> s;
    system("cls");                                              //�����һ�β�ѯ��ֵ��ʾ��ˢ�±�
    cout << "���" << "\t" << "����" << "     \t" << "���"<<endl;
    for(int i = 0;i < num;i ++){
        s = strName[i];                                         //��ÿһ�β�ѯ�����븳ֵ�� s
        if(s[0] == '-') cout << endl <<"�����ʽ����,�������0��" << G.vexnum << "�ĵ�" << endl; //�ж�s��Ϊ���ʱ�Ƿ����
        else if(s[0] >= '0' && s[0] <= '9') {
                int num = 0;
                for(int i = 0;i < s.size();i ++){               //�����ֵתΪ������ʽ
                    num += num * 10 + s[i] - '0';
                }
                if(num >= 10) num --;                           //���Ӿ��ȣ����ڵ���10��ʱ����1��Ҫ--

                if(num > G.vexnum) {cout << endl <<"�����ʽ����,�������0��" << G.vexnum << "�ĵ�" << endl;} //�ж�����ı���Ƿ����
                else {
                    int i;
                    for(i = 0;i < G.vexnum;i ++){              //��ѯ��Ϣ���Ա�vexs�����е�numbner���ҵ��� iΪ������Ϣ��vexs�����е�λ��
                        if(G.vexs[i].number == num) break;
                    }
                    cout << G.vexs[i].number << "\t" << G.vexs[i].name << "     \t"<< G.vexs[i].intro <<endl;   //�����Ϣ
                }
        }
        else {
            int i;
            for(i = 0;i < G.vexnum;i ++) {                      //�Ա�vexs�����е�name���ҵ��� iΪ������Ϣ��vexs�����е�λ��
                if(G.vexs[i].name == s) break;
            }
            if(i == G.vexnum) cout << endl << "û�и�λ�õ�ֵ" << endl;    //���û���ҵ������ھ�����Ϣ��
            else {
                    cout << G.vexs[i].number << "\t" << G.vexs[i].name << "     \t"<< G.vexs[i].intro <<endl; //�����Ϣ
            }
        }
    }
    cout << "�Ƿ������ѯ������(Y/N) : ";
    cin >> choice_1;                                        //�����Ƿ������ѯ
    }while(choice_1 != 'n' && choice_1 != 'N');             //�����벻Ϊ'n'\'N'ʱ��������ѯ
    cout << endl <<"���»س�������" << endl;
    delete[] strName;                                       //��ѯ�������ͷ�string����Ŀռ�
    getchar();
    getchar();
}
