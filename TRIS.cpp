#include <iostream>
#include <ctime>
#include <cstdlib>
#define r 3
#define c 3
using namespace std;

int main (void){
	int i=0, j=0, m[r][c], x,y;

  	for (i=0; i<r; i++){
        for (j=0; j<c; j++){
            m[i][j] =0;
            cout<<m[i][j]<<"  ";
        }
    cout<<endl;
    }

	cout<<"dove vuoi inserire la mossa(x): ";
	cin>>x;
	cout<<"dove vuoi inserire la mossa(y): ";
	cin>>y;
	
	if((m[i][j]==0)||(m[i][j]==0)){//controllo che la casella sia vuota
 		cout<<"Casella già occupata, inserisci di nuovo(x,y)";
 		cin>>x;
		cin>>y;
	}
 		
	else if((x>2)||(x<0)||(y>2)||(y<0)){//controllo che le coordinate siano giuste
 		cout<<"Coordinate non valide, inserisci di nuovo(x,y)";
		cin>>x;
		cin>>y;
	}
	else{
		m[y][x]='1';
		cout<<m[i][j]<<" ";
		cout<<endl;
	}
}
