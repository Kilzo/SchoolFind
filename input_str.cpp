#include"headPro.h"

int input_str(char *filename, string str[]){            //�ļ�������
    ifstream in(filename,ios::in);
    if(!in.is_open()){
        cout << "�ļ��򿪳���"<<endl;
        exit(1);
    }
    int i = 0;
    while(!in.eof()){
        getline(in, str[i]);
        i ++;
    }
    in.close();
    return i - 1;
}
