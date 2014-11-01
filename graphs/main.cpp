//#ifndef GRAFOS_H
//#define GRAFOS_H
#include<stdio.h>
//#include<windows.h>
using namespace std;

class Grafos {

private:
    int rows;
    int columns;
    int** data;
	
public:
    Grafos(int rows , int columns){
        
		this->rows = rows;
        this->columns = columns;

        buildMatrix(rows,columns);
    }

    void buildMatrix(int rows , int columns){
		
		this->data = new int*[this->rows];

        for(int i = 0; i < this->rows; i++){
            data[i] = new int[this->columns];
        }
    }

    bool set_value(int r, int c, int val){
		
		if(data[r][c] != 0){
			printf("O campo já possui valor!\nInforme outra posicao:");
			scanf("%d %d",&r,&c);
			if(data[r][c] != 0){
				set_value(r,c,val);
				return false;
			}
		}
			this->data[r][c] = val;
			return true;
    }

    void set_zero()const{
        for(int i = 0; i < this->rows; i++){
            for(int j = 0; j < this->columns; j++){
                this->data[i][j] = 0;
            }
        }
    }

    void show()const{
	//	system("cls");
		printf("\n");
        for(int i = 0; i < this->rows; i++){
            for(int j = 0; j < this->columns; j++){
                printf("%d",this->data[i][j]);
            }
            printf("\n");
        }
		printf("\n");
    }

    ~Grafos(){
        for (int i = 0; i < this->rows; i++) {
            delete [] data[i];
        }
        delete [] data;
     }

};

//#endif // GRAFOS_

//#include"Grafos.h"

int main(){
	int value = 1;
	int r;
	int c;

	//printf("Insira as linhas e colunas:");
	//scanf("%d%d",&r,&c);
	Grafos grafo(9,9);
	
	grafo.set_zero();

	grafo.set_value(1,2,value);
	grafo.set_value(1,4,value);
	grafo.set_value(1,5,value);
	
	grafo.set_value(2,3,value);
	grafo.set_value(2,1,value);
	grafo.set_value(2,6,value);
	
	grafo.set_value(3,2,value);
	grafo.set_value(3,4,value);
	grafo.set_value(3,7,value);
	
	grafo.set_value(4,1,value);
	grafo.set_value(4,2,value);
	grafo.set_value(4,8,value);
	
	grafo.set_value(5,1,value);
	grafo.set_value(5,6,value);
	grafo.set_value(5,8,value);
	
	grafo.set_value(6,2,value);
	grafo.set_value(6,5,value);
	grafo.set_value(6,7,value);
	
	grafo.set_value(7,3,value);
	grafo.set_value(7,6,value);
	grafo.set_value(7,8,value);
	
	grafo.set_value(8,4,value);
	grafo.set_value(8,3,value);
	grafo.set_value(8,7,value);
	
	grafo.show();
	
}