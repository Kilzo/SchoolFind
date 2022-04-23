#include"headPro.h"

int input_str(char *filename, string str[]){            //文件的输入
    ifstream in(filename,ios::in);
    if(!in.is_open()){
        cout << "文件打开出错！"<<endl;
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
