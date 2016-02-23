/*
PROBLEMA 6
Studiare la dipendenza della pressione da rho. (Nfisso - 3D)
PRODUCE GRAFICO P vs rho

*/


#include <iostream>
#include <string>
#include <sstream> //per giocare con la classe string

#include <math.h>
#include <cstdlib> 
#include <ctime> 
#include <fstream>
#include <vector>


using namespace std;

#include "funzioni_utili.h"
#include "vettori_fisici.h"
#include "tempi_collisione.h"
#include "STRUTTURONA_sfere_rigide.h"

double rho_star(double eta,int d){return(eta*d*2/M_PI);}

int main()
{

	int d= 3;
	int N=5; // numero di particellle lungo un lato
	double eta=0.68;
	sistema_rigido sistema(d, N, eta);
	sistema.CheckSovrapposizione();
	sistema.Termalizzazione(50*sistema.M);	//termalizzo: 1000 urti per ogni particella
	sistema.CheckSovrapposizione();sistema.stampa_stato("Test/prova3D.dat");

	string nomeFile ="Output/Problema6/PvsRho_3D.dat";
	grafico_start(nomeFile,"#Rho\t\t#<P/N>\t\t#sigmaP/N");

	int Nc = 100000;//sistema.M;
	double Y;

	int n_dots = 120;
	double eta_max= eta, eta_min=0.285;
	double eta_step= (eta_max - eta_min)/n_dots;

	for(int i=0;i<=n_dots;i++){
		eta = eta_max - eta_step*i;
		printf("#- %d-sima evoluzione --- reimposto impacchettamento a eta = %f \n",i,eta);
		sistema.Rinizializza(eta);
		if(sistema.CheckSovrapposizione()==false){ cout<<"\t a eta= "<<eta<<" le particelle sono sovrapposte"<<endl;break;}
		sistema.Termalizzazione(5*sistema.M);

		Y = sistema.P_Osservabile(Nc);
		grafico_add(nomeFile, 2, (double)rho_star(eta, d), (double)Y);
	}

return(0);
}
