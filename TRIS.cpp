#include <iostream>
#include <ctime>
#include <cstdlib>
#define r 3
#define c 3
using namespace std;

int main (void){
	int m[r][c];
	char giocatore1[10], giocatore2[10];
	int i=0, j=0, x, y;
	
	for (i=0; i<r; i++){
        for (j=0; j<c; j++){
            m[i][j] =0;
            cout<<m[i][j]<<"  ";
        }
    cout<<endl;
    }
    
	cout<<"giocatore 1 inserisci il nome: ";
	cin>>giocatore1;
	cout<<giocatore1<<" usa la X"<<endl;
	cout<<"giocatore 2 inserisci il nome: ";
	cin>>giocatore2;
	cout<<giocatore2<<" usa la O"<<endl;

//giocatore 1
	cout<<giocatore1<<" dove vuoi inserire la mossa(x,y): ";
	cin>>x;
	cin>>y;
	if ((m[i][j] == 'X') || (m[i][j] == 'O')||(x>2)||(x<0)||(y>2)||(y<0)){
        for (i=0; i<r; i++) {
            for (j=0; j<c; j++) {
                cout<<m[i][j]<<" ";
            }
            cout<<endl;
        }
    } else{
        m[i][j] = 'X'; //non stampa la X
        for (i=0; i<r; i++) {
            for (j=0; j<c; j++) {
                cout<<m[i][j]<<" ";
            }
        cout<<endl;
    	}
    }

//giocatore 2
	cout<<giocatore2<<" dove vuoi inserire la mossa(x,y): ";
	cin>>x;
	cin>>y;
	if ((m[i][j] == 'X') || (m[i][j] == 'O')||(x>2)||(x<0)||(y>2)||(y<0)){
        for (i=0; i<r; i++) {
            for (j=0; j<c; j++) {
                cout<<m[i][j]<<" ";
            }
            cout<<endl;
        }
    } else{
        m[i][j] = 'O'; //non stampa la O
        for (i=0; i<r; i++) {
            for (j=0; j<c; j++) {
                cout<<m[i][j]<<" ";
            }
        cout<<endl;
        }
    }
}


/* CONTROLLO VITTORIE giocatore 1

	if (((tris[0][0] == 'X') && (tris[0][1] == 'X') && (tris[0][2] == 'X')) || ((tris[1][0] == 'X') && (tris[1][1] == 'X') && (tris[1][2] == 'X')) || ((tris[2][0] == 'X') && (tris[2][1] == 'X') && (tris[2][2] == 'X'))) {
            vit = giocatore1;
   
    }

    if (((tris[0][0] == 'X') && (tris[1][0] == 'X') && (tris[2][0] == 'X')) || ((tris[0][1] == 'X') && (tris[1][1] == 'X') && (tris[2][1] == 'X')) || ((tris[0][2] == 'X') && (tris[1][2] == 'X') && (tris[2][2] == 'X'))) {
            vit = giocatore1;

    }

    if (((tris[0][0] == 'X') && (tris[1][1] == 'X') && (tris[2][2] == 'X')) || ((tris[2][0] == 'X') && (tris[1][1] == 'X') && (tris[0][2] == 'X'))) {
            vit = giocatore1;
  
    }

*/
