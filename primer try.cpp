#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int genenarNum(int max){
	srand(time(NULL));
	int num = rand() % max;
	return num;
}

string generarPremio(int &bolDosmill,int &bolDosyMedmill,int &bolTresmill,int &bolCincomill,int &bolDiezmill,int &bolQuinmill,int &bolAcu){
	srand(time(NULL));
	int opcion = genenarNum(7);
	string respPrem;
	cout<<opcion<<endl;
	
	if (opcion==0 && bolDosmill!=0){
		respPrem="El premio es de 2.000.000";
		bolDosmill--;
	}
	else{
		genenarNum(7);
	}
	
	if(opcion==1 && bolDosyMedmill!=0){
		respPrem="El premio es de 2.500.000";
		bolDosyMedmill--;
	}
	else{
		genenarNum(7);
	}
	
	if(opcion==2 && bolTresmill!=0){
		respPrem="El premio es de 3.000.000";
		bolTresmill--;
	}
	else{
		genenarNum(7);
	}
	
	if(opcion==3 && bolCincomill!=0){
		respPrem="El premio es de 5.000.000";
		bolCincomill--;
	}
	else{
		genenarNum(7);
	}
	
	if(opcion==4 && bolDiezmill!=0){
		respPrem="El premio es de 10.000.000";
		bolDiezmill--;
	}
	else{
		genenarNum(7);
	}
	
	if(opcion==5 && bolQuinmill!=0){
		respPrem="El premio es de 15.000.000";
		bolQuinmill--;
	}
	else{
		genenarNum(7);
	}
	
	if(opcion==6 && bolAcu!=0){
		respPrem="El premio es el Acumulado";
		bolAcu--;
	}
	else{
		genenarNum(7);
	}
	
	return respPrem;
}


	
int main() {
	//Declaración de variables
	int opcMenu;
	int montoAcu=100;
	int numSortAcu = 1;
	int numSortLot = 1001;
	//int premFinal;
	//int incrAcu;
	//int montSigSort;
	int bolDosmill = 10;
	int bolDosyMedmill = 10;
	int bolTresmill = 16;
	int bolCincomill = 10;
	int bolDiezmill = 2;
	int bolQuinmill = 1;
	int bolAcu= 1;
	
	
	
	for(int i=1;i<=21;i++){
		int bolExt= bolDosmill+bolDosyMedmill+bolTresmill+bolCincomill+bolDiezmill+bolQuinmill;
		
		cout<<"El numero de sorteo de acumulado es "<<numSortAcu<<" y el numero de sorteo de loteria es "<<numSortLot<<endl;
		cout<<endl;
		cout<<"El monto del acumulado esta en: "<<montoAcu<<" millones"<<endl;
		cout<<"Bolitas de acumulado: "<<bolAcu<<" y bolitas de premios extra: "<<bolExt<<endl;
		cout<<endl;
		cout<<"El número ganador es "<<genenarNum(100)<<" y la serie es "<<genenarNum(1000)<<endl;
		cout<<generarPremio(bolDosmill,bolDosyMedmill,bolTresmill,bolCincomill,bolDiezmill,bolQuinmill,bolAcu);
		cout<<endl;
		numSortAcu++;
		numSortLot++;
		cout<<"Ingrese 1 para ejecutar sorteo "<<endl;
		cout<<"Ingrese 2 para salir "<<endl;
		cout<<endl;
		cout<<"Ingrese su opción:  ";
		cin>>opcMenu;
		
			
		//Aumento del monto de Acumulado por sorteo
		if (i<11){
			montoAcu=montoAcu+20;
		}
		else{
			montoAcu=montoAcu+30;
		}
		//El menú de elección para salir o ejecutar
		if(opcMenu==1){
			system("CLS()");
		}
		else{
			system("CLS()");
			cout<<"Muchas gracias por participar.";
			break;
		}
//
		
	}
	
	//Ya no quedan sorteos
	cout<<"Muchas gracias por participar, ya no quedan premios.";
	
	
	
	return 0;
}


