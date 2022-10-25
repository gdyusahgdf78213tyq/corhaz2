#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
ifstream fin("ma.txt");

int afisare_meniu()
{
    cout<<endl<<"-----MENIU-----"<<endl;
    cout<<"1. Afisare matrice incidenta"<<endl;
    cout<<"2. Afisare lista succesori"<<endl;

    cout<<"0. Terminare"<<endl;
    cout<<"Introduceti optiunea: ";
    int o;
    cin>>o;
    return o;
}
int citire_ma(int ma[][51])
{
    int nn;
    fin>>nn;
    for(int i=1; i<=nn; i++)
        for(int j=1; j<=nn; j++)
            fin>>ma[i][j];
    return nn;
}
int nr_arce(int noduri, int ma[][51])
{
    int s=0;
    for(int i=1; i<=noduri; i++)
        for(int j=1; j<=noduri; j++)
            s+=ma[i][j];
    return s;
}
void afisare_matrice(int lin, int col, int mat[][200])
{
    for(int i=1; i<=lin; i++)
    {
        for(int j=1; j<=col; j++)
            cout<<setw(4)<<mat[i][j];
        cout<<endl;
    }
}
void afisare_vector(int dim, int vect[])
{
    for(int i=1;i<=dim;i++)
        cout<<vect[i]<<" ";
    cout<<endl;
}
void A_to_B(int noduri, int ma[][51], int arce, int mi[][200])
{
    int col=0;
    for(int i=1; i<=noduri; i++)
        for(int j=1; j<=noduri; j++)
            if(ma[i][j]==1)
            {
                col++;
                for(int lin=1; lin<=noduri; lin++)
                    mi[lin][col]=0;
                mi[i][col]=1;
                mi[j][col]=-1;
            }
}
void afis_B(int &noduri, int ma[][51], int &arce, int mi[][200])
{
    noduri = citire_ma(ma);
    arce = nr_arce(noduri,ma);
    A_to_B(noduri,ma,arce,mi);
    afisare_matrice(noduri, arce, mi);
}
void A_to_Ls(int noduri, int ma[][51], int arce, int poz[52], int succ[200])
{
    int pozlb=1;
    for(int i=1; i<=noduri; i++)
    {
        poz[i]=pozlb;
        for(int j=1; j<=noduri; j++)
        {
            if(ma[i][j])
            {
                succ[pozlb]=ma[i][j];
                pozlb++;
            }
            poz[noduri+1]=pozlb;
        }
    }
}
void afis_Ls(int &noduri, int ma[][51], int &arce, int poz[52], int succ[200])
{
    noduri = citire_ma(ma);
    arce = nr_arce(noduri,ma);
    A_to_Ls(noduri,ma,arce,poz,succ);
    afisare_vector(noduri+1, poz);
    afisare_vector(arce, succ);
}
int main()
{
    int n, a[51][51],m,opt,B[51][200],poz[52],succ[200];
    opt=-1;
    while(opt)
    {
        opt=afisare_meniu();
        switch(opt)
        {
        case 1:
            afis_B(n,a,m,B);
            break;
        case 2:
            afis_Ls(n,a,m,poz,succ);
            break;


        }
    }
    return 0;
}
