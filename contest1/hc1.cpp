#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll ceil(int a, int b){
	if (!b) return 1000000;
	return (a+b-1)/b;
}

int main(){
	int hsa, asa, dsa; cin >> hsa >> asa >> dsa;
	int hse, ase, dse; cin >> hse >> ase >> dse;
	int h, a, d; cin >> h >> a >> d; // health, attack, defense
	int minF=1000000;
	for(int i=0; i<1000; i++){
		for(int j=0; j<max(1, hse+dse-asa+1); j++){
			for(int k=0; k<max(1, ase-dsa+1); k++){
				ll turnos_jugador = ceil(hsa+i, max(0, ase-(dsa+k)));
				ll turnos_monstruo = ceil(hse, max(0, (asa+j)-dse));
				if(turnos_jugador>turnos_monstruo) minF=min(minF, i*h+j*a+k*d);
			}
		}
	}
	cout<<minF<<endl;
	return 0;
}