#define NA -1
int canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    int flag = 1, flag2;
    int i, j, k;
    int aux[numCourses];
    for(i = 0; i < numCourses; i++){
        aux[i] = NA;
    }
    for(i = 0; i < prerequisitesSize; i++){
        for(j = prerequisitesColSize[i] - 1; j> 0; j--){
            aux[prerequisites[i][j-1]] = prerequisites[i][j];
        }
    }
    for(i = 0; i < numCourses && flag; i++){
        if(aux[i] >= 0){
            flag2 = 1;
            j = aux[i];
            while(flag && flag2){
                if(aux[j] == -2){
                    flag = 0;
                }
                else if(aux[j] == NA){
                    flag2= 0;
                }
                else{
                    k =aux[j];
                    aux[j] = -2;
                    j = k;
                }
            }
        }
    }
    return flag;

}