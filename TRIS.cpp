#include <iostream>
#include <ctime>
#include <cstdlib>
#define r 3
#define c 3
using namespace std;

int main (void){
	int i=0, j=0, m[r][c];
	int x1, x2, y1, y2; 

  	for (i=0; i<r; i++){
        for (j=0; j<c; j++){
            m[i][j] =0;
            cout<<m[i][j]<<"  ";
        }
    cout<<endl;
    }
//Faccio il ciclo per riempire la nostra matrice con l'1 e il 2 
	
	for(i=0; i<m[x1][y1]; i++){
		for(j=0; j<m[x2][y2]; j++){
			cout<<"Dove vuoi inserire la mossa(x) Giocatore 1: ";
			cin>>x1;
			cout<<"Dove vuoi inserire la mossa(y) Giocatore 1: ";
			cin>>y1;
			cout<<"Dove vuoi inserire la mossa(x) Giocatore 2: ";
			cin>>x2;
			cout<<"Dove vuoi inserire la mossa(y) Giocatore 2: ";
			cin>>y2;
			
			//chiedere le mosse al giocatore 1
			if((m[i][j]==0)||(m[i][j]==0)){//controllo che la casella sia vuota
		 		cout<<"Casella già occupata, inserisci di nuovo(x,y)";
		 		cin>>x1;
				cin>>y1;
			}	
			else if((x1>2)||(x1<0)||(y1>2)||(y1<0)){//controllo che le coordinate siano giuste
		 		cout<<"Coordinate non valide, inserisci di nuovo(x,y)";
				cin>>x1;
				cin>>y1;
			}
				else{
				m[y1][x1]='1';
				cout<<m[i][j]<<" ";
				cout<<endl;
			}
			
			if((m[i][j]==0)||(m[i][j]==0)){//controllo che la casella sia vuota
		 		cout<<"Casella già occupata, inserisci di nuovo(x,y)";
		 		cin>>x2;
				cin>>y2;
			}
		 	// Chiedere le mosse al giocatore 2 
			else if((x2>2)||(x2<0)||(y2>2)||(y2<0)){//controllo che le coordinate siano giuste
		 		cout<<"Coordinate non valide, inserisci di nuovo(x,y)";
				cin>>x2;
				cin>>y2;
			}
				else{
				m[y2][x2]='2';
				cout<<m[i][j]<<" ";
				cout<<endl;
			}
		}
	}
	
}
