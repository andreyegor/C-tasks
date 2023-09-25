#include <stdio.h> 
#include <malloc.h>
#include <stdlib.h>

int of_check(void* ptr){
    if (ptr==NULL){
        printf("out of memory");
        exit(0);
    }
}
int create_triangle(size_t len, int*** out_arr){
    int** arr = (int**) malloc(len*sizeof(int*));
    of_check(arr);
    for (size_t i=0;i<len;i++){
        arr[i] = (int*) malloc(i*sizeof(int));
        of_check(arr);
    }
    *out_arr = arr;
    return len;
}

void fill_triangle(size_t len, int** arr){
    arr[0][0] = 1;
    for (size_t i=1;i<len;i++){
        arr[i][0] = 1;
        arr[i][i] = 1;
        for (size_t j=1; j<i;j++){
            arr[i][j] = arr[i-1][j-1]+arr[i-1][j];
        }
    }
}

void print_triangle(size_t len, int** arr){
    for (size_t i=1;i<len;i++){
        for (size_t j=0; j<=i;j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main(){
    size_t len;
    scanf("%lld", &len);
    int** arr;
    create_triangle(len, &arr);
    fill_triangle(len, arr);
    print_triangle(len, arr);

    return 0;
}