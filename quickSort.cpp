#include<iostream>
#include<cstdlib>
using namespace std;

//Algoritmo implementado por João Vitor de Oliveira Camara para a disciplina:
//Projeto e Análise de Algoritmos

int particionar(int vetor[],int p, int r){
	int P = vetor[r];
	int i = p - 1;
	for(int j = p;j<r;j++){
		if(vetor[j]<P){
			i++;
			int temp = vetor[j];
			vetor[j] = vetor[i];
			vetor[i] = temp;
		}
	}
	int x = vetor[i+1];
	vetor[i+1] = vetor[r];
	vetor[r] = x;
	return (i+1);
}

void quickSort(int vetor[],int p,int r){
	if(p<r){
		int q = particionar(vetor,p,r);
		quickSort(vetor,p, q-1);
		quickSort(vetor,q+1,r);
	}
}

int main(){
	int vetor[] = {9 , 10 , -1, 3, 6, 2, 1, -3, 1, 0, -2, 15, 8, -7, 0};
	quickSort(vetor,0,14);
	cout<< "Vetor ordenado: [ ";
	for(int i=0;i<=14;i++){
             if(i == 14){
            cout<<vetor[i];
        }else{
            cout<<vetor[i]<<" , ";
    }
    }cout<<" ]";
    return 0;
}
