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
		
};*/

void griglia(char matrix[][3]){
    cout << "tris"<<endl;
    
    cout << "giocatore 1(X)  -  giocatore 2(O)" << endl << endl;
    cout << endl;

    cout << "     |     |     " << endl;
    cout << "  " << matrix[0][0] << "  |  " << matrix[0][1] << "  |  " << matrix[0][2] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

   	cout << "  " << matrix[1][0] << "  |  " << matrix[1][1] << "  |  " << matrix[1][2] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << matrix[2][0] << "  |  " << matrix[2][1] << "  |  " << matrix[2][2] << endl;

    cout << "     |     |     " << endl << endl;
}

int controllo_v(char m[3][3]){
 	for(int i=0;i<3;i++){
 			//controllo righe
 			if(m[i][0]=='X' && m[i][1]==m[i][0] &&  m[i][2]==m[i][1]){
	 			return 1;//vince il giocatore 1
	 		}
			else if (m[i][0]=='O' && m[i][1]==m[i][0] &&  m[i][2]==m[i][1]){
	 			return 2;//vince il giocatore 2
	 		}
	 		//controllo colonne
	 		else if(m[0][i]=='X' && m[0][1]==m[0][i] &&  m[0][2]==m[0][1]){
	 			return 1;//vince il giocatore 1
	 		}
			else if(m[0][i]=='O' && m[0][2-1]=='O' && m[0][2+1]=='O'){
	 			return 2;//vince il giocatore 2
	 		}
	 		//controllo diagonale 1
	 		else if (m[i][0]=='X' && m[1][1]==m[i][0] && m[2][2]==m[1][1]){
				return 1;//vince il giocatore 1
	 		}
			else if (m[i][0]=='O' && m[1][1]==m[i][0] && m[2][2]==m[1][1]){
	 			return 2;//vince il giocatore 2
	 		}			
			//controllo diagonale 2
			else if (m[i][2]=='X' && m[1][1]==m[i][2] && m[2][0]==m[i][2]){
				return 1;//vince il giocatore 1
	 		}
			else if (m[i][2]=='O' && m[1][1]==m[i][2] && m[2][0]==m[i][2]){
	 			return 2;//vince il giocatore 2
	 		}
	 		else{
	 			return 0;
			}
		}
	} 

int controllo_v(char m[3][3]);
void griglia(char m[3][3]);


int main(void){
	char m[3][3] = {{'\0'}}; //matrice vuota
	int i=0, j=0, conta=0, vitt=0, x, y;
	char giocatore1[10], giocatore2[10];
	bool exit = false;
	fstream file;
	file.open("PartitaTris.txt", ios::out);

	cout<<"giocatore 1 inserisci il nome: ";
	cin>>giocatore1;
	file<<giocatore1<<endl;
	cout<<giocatore1<<" usa la X" <<endl;
	cout<<"giocatore 2 inserisci il nome: ";
	cin>>giocatore2;
	file<<giocatore2<<endl;
	cout<<giocatore2<<" usa la O"<<endl;
	
	do{
		cout<<giocatore1<<" dove vuoi inserire la X (x,y) : ";
		cin>>x;
		cin>>y;
		if((m[x][y]=='X')||(m[x][y]=='O')||(x>2)||(x<0)||(y>2)||(y<0)){//controllo che la casella selezionata sia effettivamente vuota
			cout<<"Errore, riprova"<<endl;
			cout<<giocatore1<<" dove vuoi inserire la X (x,y) : ";
			cin>>x;
			cin>>y;
		}
		else{
			m[x][y]='X';
			conta++;//contatore delle caselle riempite
		}
		griglia(m);
		vitt=controllo_v(m);
		if (conta==9 || vitt){
			exit=true; // se diventa vero ho riempito tutte le caselle e quindi esco dal ciclo
		}
		
		cout<<giocatore2<<" dove vuoi inserire la O (x,y) : ";
		cin>>x;
		cin>>y;		
		if((m[x][y]=='X')||(m[x][y]=='O')||(x>2)||(x<0)||(y>2)||(y<0)){//controllo che la casella selezionata sia effettivamente vuota
			cout<<"Errore, riprova"<<endl;
			cout<<giocatore2<<" dove vuoi inserire la O (x,y) : ";
			cin>>x;
			cin>>y;
		}
		else{
			m[x][y]='O';
			conta++;//contatore delle caselle riempite
		}
		griglia(m);
		vitt=controllo_v(m);
		if (conta==9 || vitt){
			exit=true; // se diventa vero ho riempito tutte le caselle e quindi esco dal ciclo
		}
		
	}while(!exit);//ripeto finchè non riempio le caselle
	
	if(vitt==1){
		cout<<giocatore1<<" hai vinto";
		file<<giocatore1<<endl;
	}
	else if(vitt==2){
		cout<<giocatore2<<" hai vinto";
		file<<giocatore2<<endl;
	}
	else{
		cout<<"nessuno ha vinto";
	}
		
	file.close();
}
