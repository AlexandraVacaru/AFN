#include <iostream>
#include<fstream>
#include<cstring>
using namespace std;

int nr_tr,st_i,nr_sf,st_f[100]; ///numarul de tranzitii, starea initiala, numarul de stari finale si starile finale
int ok=0;

struct triplet ///retinem tranzitiile, formate din 2 stari(una din care pleaca, cealalta in care ajunge) si litera de tranzitie
{
    int x,y;
    char c;

} q[100];

bool stare_finala(int y) ///verificare stare finala
{
    for(int k=0;k<nr_sf;k++)
        if(y==st_f[k])
           return 1;
    return 0;
}
void parcurgere(int a,int j,char cuvant[])/// a= starea curenta si j= litera la care am ajuns
{
    int p;
    for(p=0;p<nr_tr;p++) ///cautam in tranzitii
    {
       if(q[p].x==a && q[p].c==cuvant[j] && j<strlen(cuvant)) ///verificam daca gasim tranzitie de la starea curenta catre alta stare, cu litera corespunzatoare
     {
           if(j==strlen(cuvant)-1 && ok==0) ///verificam daca am ajuns la finalul cuvantului
            {
                 if(stare_finala(q[p].y)==1) /// verificam daca starea in care am ajuns este stare finala
              {
                  cout<<"Cuvant acceptat!";
                  ok=1;
                  return;
              }
            }

        else if(ok==0) parcurgere(q[p].y,j+1,cuvant); ///in cazul in care nu am ajuns la finalul cuvantului, vom parcurge in continuare pentru a verifica si celelalte litere

     }

    }
}
int main()
{
   int i;
   char cuvant[100]; ///cuvantul care trebuie verificat

   ifstream f("date.in");
   f>>cuvant;
   f>>nr_tr>>st_i;
   f>>nr_sf;

    for(i=0;i<nr_sf;i++)
        f>>st_f[i];
    for(i=0;i<nr_tr;i++)
        f>>q[i].x>>q[i].y>>q[i].c; ///citirea tranzitiilor
    int j=0;

    parcurgere(st_i,j++,cuvant); ///verificare incepand de la starea initiala

    if(ok==0 && strcmp(cuvant,"lambda")!=0) cout<<"Cuvant neacceptat!";
     else if(strcmp(cuvant,"lambda")==0 && stare_finala(st_i)==1) cout<<"Cuvant acceptat!";///in cazul in care cuvantul nu exista, ok va avea valoarea 0

    return 0;
}
