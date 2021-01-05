#include <iostream>
#include <ctime>
#include <cstdlib>
#include<cmath>
#include<fstream>
using namespace std;
/*
class Tris{
	private:
		char m[3][3];
		
	public:
		Tris(void); //inizializzo una matrice a 0
		void giocatore1(string);
		void giocatore2(string);
		void setX(int x);
		void setY(int y);
		int getX(void);
		int getY(void);
		int controllo_v();
		
};
*/
int controllo_v(int m[0][0]){
	int k;
 	for(k=0;k<3;k++){//controllo righe
 		if(m[k][0] + m[k][1] - 2 * (m[k][2]) ==0){//se c'è tris la somma delle prime 2 celle meno il doppio dell'ultima mi deve dare0
	 		if(m[k][0]=='X'){
	 			return 1;//vince il giocatore 1
	 		}
			 if(m[k][0]=='O'){
	 			return 2;//vince il giocatore 2
	 		}
 		}
 	}
	for(k=0;k<3;k++){// controllo se ci sono tris sulle colonne
		if(m[0][k]+m[1][k]-2*(m[2][k])==0){
			if(m[0][k]=='X'){//se questo if è vero vuol dire che il giocatore 1 ha vinto
				return 1;
			}
			if(m[0][k]=='O'){
				return 2;
			}
		}
 	}

	if(m[0][0]+m[1][1]-2*(m[2][2])==0){//controllo diagonale 1
		if(m[1][1]=='X'){
			return 1;
		}
		if(m[1][1]=='O'){
			return 2;
		}
	}
	if(m[0][2]+m[1][1]-2*(m[2][0])==0){//controllo diagonale 2
		if(m[0][2]=='X'){//se questo if è vero vuol dire che il giocatore 1 ha vinto
 			return 1;
 		}
		if(m[0][2]=='O'){
			return 2;
		}
	}
	return 0; //se arrivo qui vuol dire che non ci sono stati tris e ritorno 0
}

int stringa_vuota(char m[0][0]){  //mi sembrava più carino farlo con un funzione --> però non funziona 
    //cout<<"griglia vuota"<<endl;
	for(i=0; i<3; i++){
		for (j=0; j<3; j++){
			m[i][j]='-';
			cout<<m[i][j]<<"  ";
		}
		cout<<endl;
	}
}

int main(void)
    int stringa_vuota(char m[][]);
	char m[3][3];
	int i=0, j=0, conta=0, vitt=0, x, y;
	char giocatore1[10], giocatore2[10];
	
	ofstream file;
	file.open("PartitaTris.txt");
	
	cout<<"griglia vuota"<<endl;
	
	cout<<"giocatore 1 inserisci il nome: ";
	cin>>giocatore1;
	cout<<giocatore1<<" usa la X"<<endl;
	cout<<"giocatore 2 inserisci il nome: ";
	cin>>giocatore2;
	cout<<giocatore2<<" usa la O"<<endl;
	
	do{
		cout<<giocatore1<<" dove vuoi inserire la X (x,y) : ";
		cin>>x;
		cin>>y;
		if((m[i][j]=='X')||(m[i][j]=='O')||(x>2)||(x<0)||(y>2)||(y<0)){//controllo che la casella selezionata sia effettivamente vuota
			cout<<"errore, riprova";
			cin>>x;
			cin>>y;
		}
		else{
			m[i][j]='X';
			cout<<m[i][j]<<"  ";
			conta++;//contatore delle caselle riempite
		}
		
		if(conta==9){//se c arriva a 9 vuol dire che sono state riempite tutte le celle
	 		return 0;
		}	
		
		cout<<giocatore2<<" dove vuoi inserire la X (x,y) : ";
		cin>>x;
		cin>>y;
		if((m[i][j]=='X')||(m[i][j]=='O')||(x>2)||(x<0)||(y>2)||(y<0)){//controllo che la casella selezionata sia effettivamente vuota
			cout<<"errore, riprova";
			cin>>x;
			cin>>y;
		}
		else{
		m[i][j]='O';
		cout<<m[i][j]<<"  ";
		conta++;//contatore delle caselle riempite
		}			
	}while(conta<9);
	
	vitt=Tris.controllo_v(m[3][3]);
	
	if (vitt==1){
		cout<<giocatore1<<" hai vinto!"<<endl;
	}
	else if(vitt==2){
		cout<<giocatore2<<" hai vinto!"<<endl;
	}
	else{
		cout<<"nessuno ha vinto!"<<endl;
	}
	
}
