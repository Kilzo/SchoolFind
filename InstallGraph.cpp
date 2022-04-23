#include"headPro.h"

void InstallGraph(MGraph &G){
    for(int i = 0;i < MVNum; i ++)
        for(int j = 0;j < MVNum;j ++)
            G.arcs[i][j] = 0x3f3f3f3f;
}
