#include<stdio.h>

void troca(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void maxHeapify(int arr[], int n, int i){
    int maior = i;
    int esq = 2*i+1;
    int dir = 2*i+2;

    if( esq < n && arr[esq]>arr[maior]){
        maior = esq;
    }

    if( dir < n && arr[dir] > arr[maior]){
        maior = dir;
    }

    if(maior != i){
        troca(&arr[i], &arr[maior]);
        maxHeapify(arr, n, maior);
    }
}


void heapSort(int arr[], int n){
    //constroi o heap
    for(int i = n/2-1 ; i>=0 ; i--){
        maxHeapify(arr, n, i);
    }
    //Ajusta os elementos do HEAP 1 a 1
    for(int i = n-1 ; i>=0 ; i--){
        troca(&arr[0],&arr[i]);
        maxHeapify(arr, i, 0);
    }
}

void imprimeVetor(int arr[], int n){
    for(int i=0;i<n;i++){
        printf("%d", arr[i]);
        if(i<n-1) printf(" - ");
    }
    printf("\n");
}

int main(){
    int arr[]= {3, 4, 6, 0, 8, 11, 15, 1, 20};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Vetor original: \n");
    imprimeVetor(arr,n);

    heapSort(arr, n);

    printf("Vetor ordenado com HeapSORT: \n");
    imprimeVetor(arr,n);
}
