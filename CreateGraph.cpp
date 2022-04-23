#include"headPro.h"

void CreateGraph(MGraph &G, string str[], int rowNUM){
    int i = 0;                              //sting数组开始下标
    for(i = 0;i < rowNUM;i ++){             //遍历string数组
        if(str[i] == "") break;             //如果遇到了景点信息和景点距离信息的分界线则跳出
        int sum = 0;                        //数组编号的存储变量
        string s = str[i];                  //将当string数组存储的字符串复制到string中方便查找
        int j = 0;                          //j为遍历的编号下标
        for(;j < s.size();j ++){
            if(s[j] == '>')break;           //当遇到第一个“>”跳出，即遇到了编号和名称的边界
            sum = sum * 10  + s[j] - '0';   //第一个字符是最高位，这种方式能够保证编号完整的存储。又由于是字符，所以需要 - '0'转换为数字
        }
        G.vexs[i].number = sum;             //存编号到图中
        G.vexnum++;                         //图中点的个数 +1
        //cout << G.vexs[i].number << " ";
        int k = j + 1;                      //别忘了下标 +1，使得下一次遍历不是 “>”从而导致存储空
        string st;                          //存景点名称和简介的中间变量，中文字符需要另外开一个string存储，具体原因应该是中文占位问题。
        for(;k < s.size();k ++){
            if(s[k] == '>') break;          //当遇到第二个“>”跳出，即遇到了名称和简介的边界
            st+=s[k];                       //c++string的用法，可以直接链接中文字符
        }
        G.vexs[i].name = st;                //存名称到图中
        //cout << G.vexs[i].name << " ";     //debug
        int p = k + 1;                      //别忘了 +1
        st.clear();                        //清空中文数组
        for(;p < s.size();p ++){
            st += s[p];                     //剩下的就是简介部分，直接读入到结尾存储即可
        }
        G.vexs[i].intro = st;               //简介存储到图中
        //cout << G.vexs[i].intro <<endl;
    }
    i ++;                                   //string数组将景点详细信息和景点和景点之间的路径长度用一个空数组隔开。
    for(;i < rowNUM;i ++){
        if(str[i] == "") break;
        int sum1 = 0,sum2 = 0,sum3 = 0,j = 0;   //定义起点，终点，距离的存储变量
        string s = str[i];                      //与上面一样的去除当前string数组的值
        for(;j < s.size();j ++){
            if(s[j] == '>')break;               //遇到第一个边界就跳出，说明起点数字已经遍历完了
            sum1 = sum1 * 10  + s[j] - '0';     //读数字，与上面相同
        }
        j ++;                                   //别忘了 +1
        for(;j < s.size();j ++){
            if(s[j] == '>')break;               //遇到第二个边界就跳出，说明终点数字遍历完了
            sum2 = sum2 * 10  + s[j] - '0';     //读数字，与上面相同
        }
        j ++;                                   //别忘了 +1
        for(;j < s.size();j ++){
            sum3 = sum3 * 10 + s[j] - '0';      //直接读取到结尾即可
        }
        G.arcs[sum2][sum1] = G.arcs[sum1][sum2] = min(int(G.arcs[sum1][sum2]),sum3);    //将起点和终点的边界路径长度信息存到邻接矩阵中
        G.arcnum+=2;                            //由于是无向图，所以边数 +2
    }
}
