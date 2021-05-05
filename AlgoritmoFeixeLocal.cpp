#include<iostream>
#include<cmath>
#include <stdlib.h> 
#include <time.h>
#include <vector>

using namespace std;

double funcao(float x) 
{
	return (x*(sin(10*3.14*x)))+1;
}

int main()
{
	int cont= 10;
	srand ( time(NULL) );
	int var=0 ,var2=0 ,n=0 ,soma=0;
	vector<float> vetor,vetor2;
	float matriz[cont],matrizB[cont],k[cont];
	float temp=0, temp2=0, intervalo=0.001;
	
	
	for(int i=0; i<cont; i++)  
		matriz[i] = ((float)rand() / ((float)RAND_MAX + 1) * 2) - 1.0;
			
		while(var!=1){
			
			cout << "\nN Iteracoes: " << n;
			
			cout << "\nX:   ";
			for(int i=0; i<cont; i++){
				cout << matriz[i] << " ";	
			}
			
			soma = 0;
			
			cout << "\nf(x):";	
			
			for(int i=0; i<cont; i++){         // aplica função f(x)
				matrizB[i] = funcao(matriz[i]);
				
				matrizB[i] = floorf(matrizB[i] * 1000) / 1000; 
				
				cout << " " << matrizB[i];
				
				if(matrizB[i]==matrizB[i+1]){
					soma++;
				if (soma==9)
					var=1;         
				}
				
			}
			
			for(int i=0; i<cont; i++){   //pega vizinhos
				temp=matriz[i];
				vetor.push_back(temp-intervalo);  //intervalo  = 0.001
				vetor.push_back(temp+intervalo);
				vetor2.push_back(funcao(temp-intervalo));
				vetor2.push_back(funcao(temp+intervalo));
			}
			
			for(int i=0; i<vetor.size()-1;i++){     //Ordena
				temp = vetor[i];
				temp2 = vetor2[i];
				for(int j=vetor.size()-1;j>i;j--){
					if(vetor2[j]>vetor2[i])
					{	
						vetor[i]=vetor[j];
						vetor[j]=temp;
						vetor2[i]=vetor2[j];
						vetor2[j]=temp2;
					}
				}
			}	
			
			for(int i=0; i<cont;i++)     // pega os k melhores
				matriz[i] = vetor[i];
			
			cout <<"\n";
			
			vetor.clear();
			vetor2.clear();
			
			cin >> var2;
			
			n++;
			
		}
		return 0;
	
	
}
