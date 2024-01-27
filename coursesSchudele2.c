#include <stdlib.h>
typedef struct list{
    int num;
    struct list *next;
}*llist;

int cycle(llist g[], int i, int vis[]){
    llist x;
    int flag = 1;
    vis[i] = -1;
    for(x = g[i]; x && flag; x = x->next){
        if(vis[x->num] == -1){
            flag = 0;
        }
        else if(vis[x->num] == 0){
            flag = cycle(g,x->num,vis);
        }
    }
    vis[i] = 1;
    return flag;

}
int canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    int flag = 1;
    int i, j;
    llist aux[numCourses];
    int vis[numCourses];
    llist x;
    for(i = 0; i < numCourses; i++){
        aux[i] = NULL;
        vis[i] = 0;
    }
    for(i = 0; i < prerequisitesSize; i++){
        for(j = prerequisitesColSize[i] - 1; j >0; j-- ){
            x = malloc(sizeof(struct list));
            x->num = prerequisites[i][j];
            x->next = aux[prerequisites[i][j - 1]];
            aux[prerequisites[i][j - 1]] = x;
        }
    }
    for(i = 0; i < numCourses && flag; i++){
        if(!vis[i]){
            flag = cycle(aux, i, vis);
        }
    }
    return flag;
}