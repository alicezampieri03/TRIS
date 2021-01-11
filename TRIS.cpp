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
void griglia(){
    cout << "tris";
    cout << "giocatore 1(X)  -  giocatore 2(O)" << endl << endl;
    cout << endl;

    cout << "     |     |     " << endl;
    cout << "  " << "0" << "  |  " << "0" << "  |  " << "0" << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

   	cout << "  " << "0" << "  |  " << "0" << "  |  " << "0" << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << "0" << "  |  " << "0" << "  |  " << "0" << endl;

    cout << "     |     |     " << endl << endl;
}




int controllo_v(char m[3][3]){
	int i=0, j=0;
 	for(i=0;i<3;i++){
 		for(j=0;j<3;j++){
 			//controllo righe
 			if(i==1 && m[i][j]=='X' && m[i-1][j]=='X' && m[i+1][j]=='X'){//i=1 perchè inzio dal mezzo
	 			return 1;//vince il giocatore 1
	 		}
			else if (i==1 && m[i][j]=='O' && m[i-1][j]=='O' && m[i+1][j]=='O'){
	 			return 2;//vince il giocatore 2
	 		}
	 		else{
	 			return 0; //nessuno ha vinto
			}
	 		
	 		//controllo colonne
	 		if(j==1 && m[i][j]=='X' && m[i][j-1]=='X' && m[i][j+1]=='X'){//j=1 perchè inzio dal mezzo
	 			return 1;//vince il giocatore 1
	 		}
			else if(j==1 && m[i][j]=='O' && m[i][j-1]=='O' && m[i][j+1]=='O'){
	 			return 2;//vince il giocatore 2
	 		}
	 		else{
	 			return 0;
			}
	 		
	 		//controllo diagonale 1
	 		if (i==1 && j==1 && m[i][j]=='X' && m[i+1][j+1]=='X' && m[i-1][j-1]=='X'){
				return 1;//vince il giocatore 1
	 		}
			else if (i==1 && j==1 && m[i][j]=='O' && m[i+1][j+1]=='O' && m[i-1][j-1]=='O'){
	 			return 2;//vince il giocatore 2
	 		}
	 		else{
	 			return 0;
			 }
			
			//controllo diagonale 2
			if (i==1 && j==1 && m[i][j]=='X' && m[i-1][j+1]=='X' && m[i+1][j-1]=='X'){
				return 1;//vince il giocatore 1
	 		}
			else if (i==1 && j==1 && m[i][j]=='O' && m[i-1][j+1]=='O' && m[i+1][j-1]=='O'){
	 			return 2;//vince il giocatore 2
	 		}
	 		else{
	 			return 0;
			}
		}
	} 
}

int stringa_vuota(char m[3][3]){  
    //cout<<"griglia vuota"<<endl;
    int i=0, j=0;
	for (i=0; i<3; i++) {
		for (j=0; j<3; j++) {
			m[i][j]='-';
			cout<<m[i][j]<<"  ";
		}
		cout<<endl;
	}
}

int controllo_v(char m[3][3]);
int stringa_vuota(char m[3][3]);
void griglia();


int main(void){
	char m[3][3];
	int i=0, j=0, conta=0, vitt=0, x, y;
	char giocatore1[10], giocatore2[10];
	
	fstream file;
	file.open("PartitaTris.txt", ios::in);
	
	
	cout<<"griglia vuota"<<endl;
	griglia();

	cout<<"giocatore 1 inserisci il nome: ";
	file>>giocatore1;
	cout<<giocatore1<< "usa la X" <<endl;
	cout<<"giocatore 2 inserisci il nome: ";
	file>>giocatore2;
	cout<<giocatore2<<" usa la O"<<endl;
	
	do{
		cout<<giocatore1<<" dove vuoi inserire la X (x,y) : ";
		cin>>x;
		cin>>y;
		if((m[i][j]=='X')||(m[i][j]=='O')||(x>2)||(x<0)||(y>2)||(y<0)){//controllo che la casella selezionata sia effettivamente vuota
			cout<<"errore, riprova";
		}
		else{
			m[3][3]='X';
			cout<<m[3][3]<<"  ";
			cout<<endl;
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
		}
		else{
			m[3][3]='O';
			cout<<m[3][3]<<"  ";
			cout<<endl;
			conta++;//contatore delle caselle riempite
		}
		
	}while(conta<9);
	
	vitt=controllo_v(m);
	
	if (vitt==1){
		file<<giocatore1<<" hai vinto!"<<endl;
	}
	else if(vitt==2){
		file<<giocatore2<<" hai vinto!"<<endl;
	}
	else{
		file<<"nessuno ha vinto!"<<endl;
	}
	
	file.close();
}
