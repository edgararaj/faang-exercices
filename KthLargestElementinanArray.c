void swap(int aux[], int x, int y){
    int a;
    a = aux[x];
    aux[x] = aux[y];
    aux[y] = a;
}
void insert(int aux[], int *n, int x){
    int i, z;
     i = *n;
    aux[(*n)++] = x;
    z = (i - 1)/2;
    while(i > 0 && aux[i] > aux[z]){
        swap(aux,i,z);
        i = z;
        z = (i - 1)/2;
    }
}
int extract(int aux[],int  *n){
    int r = aux[0];
    int i = 0, e, max, flag = 1;
    aux[i] = aux[--(*n)];
    e = 2*i + 1;
    while(e < *n && flag){
        max = (aux[i] > aux[e])? i : e;
        if(e + 1 < *n){
            max = (aux[max] > aux[e +1])? max: e+1;
        }
        if(i != max){
            swap(aux,i,max);
            i = max;
            e = 2*i + 1;
        }
        else{
            flag = 0;
        }
    }

    return r;
}
int findKthLargest(int* nums, int numsSize, int k) {
  int aux[numsSize];
  int i,r, n = 0;
  for(i = 0; i < numsSize; i++){
      insert(aux, &n, nums[i]);
      
  }
    while(k){
        r = extract(aux, &n);
        k--;
    }
  
  return r;
}