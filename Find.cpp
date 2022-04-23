#include"headPro.h"

void find(MGraph &G){
    system("cls");                                              //清楚主菜单页面
    char choice_1;                                              //定义是否继续查询的变量
    int num = 0;                                                //定义存储编号的变量
    string *strName = new string[MAZX];                         //定义输入要存储的sting数组

    do{                                                         //do-while首先查找一次
    //system("cls");
    cout << "请输入要查询的编号/名称 : ";

    bool sele = false;                                          //定义并初始化是否重复输入变量sele为false
    cin >> strName[num ++];
    for(int i = 0;i < num - 1;i ++)                             //循环一遍判断是否重复输入
        if(strName[i] == strName[num - 1]) {
            cout << "重复输入,已有输出结果,请重新输入" << endl;
            num --;                                             //如果重复输入，释放一次输入下标
            sele = true;                                        //将判断变量置为true
        }
    if(sele) continue;                                          //重复输入，跳过
    string s;                                                   //定义存储的输入变量
    //cin >> s;
    system("cls");                                              //清楚上一次查询的值显示，刷新表单
    cout << "编号" << "\t" << "名称" << "     \t" << "简介"<<endl;
    for(int i = 0;i < num;i ++){
        s = strName[i];                                         //将每一次查询的输入赋值给 s
        if(s[0] == '-') cout << endl <<"输入格式错误,请输入从0到" << G.vexnum << "的点" << endl; //判断s作为编号时是否负溢出
        else if(s[0] >= '0' && s[0] <= '9') {
                int num = 0;
                for(int i = 0;i < s.size();i ++){               //将编号值转为整数形式
                    num += num * 10 + s[i] - '0';
                }
                if(num >= 10) num --;                           //增加精度，大于等于10的时候会多1，要--

                if(num > G.vexnum) {cout << endl <<"输入格式错误,请输入从0到" << G.vexnum << "的点" << endl;} //判断输入的编号是否溢出
                else {
                    int i;
                    for(i = 0;i < G.vexnum;i ++){              //查询信息，对比vexs数组中的numbner，找到即 i为输入信息在vexs数组中的位置
                        if(G.vexs[i].number == num) break;
                    }
                    cout << G.vexs[i].number << "\t" << G.vexs[i].name << "     \t"<< G.vexs[i].intro <<endl;   //输出信息
                }
        }
        else {
            int i;
            for(i = 0;i < G.vexnum;i ++) {                      //对比vexs数组中的name，找到即 i为输入信息在vexs数组中的位置
                if(G.vexs[i].name == s) break;
            }
            if(i == G.vexnum) cout << endl << "没有该位置的值" << endl;    //如果没有找到即不在景点信息中
            else {
                    cout << G.vexs[i].number << "\t" << G.vexs[i].name << "     \t"<< G.vexs[i].intro <<endl; //输出信息
            }
        }
    }
    cout << "是否继续查询，输入(Y/N) : ";
    cin >> choice_1;                                        //输入是否继续查询
    }while(choice_1 != 'n' && choice_1 != 'N');             //当输入不为'n'\'N'时，继续查询
    cout << endl <<"按下回车键继续" << endl;
    delete[] strName;                                       //查询结束，释放string数组的空间
    getchar();
    getchar();
}
