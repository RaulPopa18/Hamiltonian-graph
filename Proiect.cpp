#include<fstream>
#include<iostream>
#include<string>
using namespace std;

int vect[100], n, m, k, a[20][20], solutii;

void dis(int marcator[1][20], int distanta[20])
{
    cout << endl << "Distanta dintre comenzi " << endl;
    for (int i = 1; i <= m; i++)
    {
        cout << marcator[1][i] << " " << marcator[2][i] << " = " << distanta[i] << " Km. " << endl;
    }
}

int plata(int marcator[2][20],int distanta[20],int total)
{
    cout << endl;
    cout <<endl<< "Plata deplasarii: (2 lei/ Km) " << endl<<endl;

    for (int i = 1; i <= m; i++)
    {
        cout <<"Distanta dintre "<< marcator[1][i] << " " << marcator[2][i] << " costa: " << distanta[i]*2 << " lei. " << endl;
    
        
    }
    int aux = 1;
    for (int i = 1; i <= m; i++)
    {
        if (vect[aux] == marcator[1][i] && vect[aux + 1] == marcator[2][i])
            for (int j = 1; j <= m; j++)
            {

                if (i==j)
                {
                    total += distanta[i] * 2;
                    aux++;
                    i = 0;
                    break;
                }

            }
        if (vect[aux] == marcator[2][i] && vect[aux + 1] == marcator[1][i])
        {
            for (int j = 1; j <= m; j++)
            {

                if (i == j)
                {
                    total += distanta[i] * 2;
                    aux++;
                    i = 0;
                    break;
                }

            }
        }
       
     
    }

    for (int i = 1; i <= m; i++)
    {
        if (marcator[2][i] == vect[n] || marcator[1][i] == vect[n])
        {
            total = total + distanta[i] * 2;
            break;
        }
    }

    return total;
}

int venituri(string transport,int total)
{
  
    if (transport == "bicicleta" || transport == "moped-electric" || transport == "trotineta")
    {
        total = total + total * 1 / 10;
        cout <<endl<< "Pentru activitate cu " << transport << " venitul este " << total << " lei. " << endl;
    }else
        cout << "Plata pentru angajatul responsabil cu transportul cu " <<transport<<" = "<< total << " lei. " << endl;
    return total;
  
}

int Verificare()
{
   if (k > 1) // este nivelul din stiva
        if (!a[vect[k - 1]][vect[k]]) // se verifica daca elementele formeaza o muchie
            return 0;
        else
        for (int i = 1; i <= k - 1; i++) //parcurg nivelurile anterioare nivelului curent
           if (vect[i] == vect[k])
             return 0;
    if (k == n) // se verifica daca varfurile apartin vectorului
        if (!a[vect[1]][vect[k]])
            return 0;

    return 1;
}

void Afisare()
{
    for (int i = 1; i <= n; i++)
        cout << vect[i] << " ";
    cout << vect[1];
    k = 0; //determina iesirea la prima solutie
    solutii++;
}

void back()
{
    k = 1;
    while (k > 0) //cand k va descreste la 0 algoritmul se incheie
        if (vect[k] < n)
        {
            vect[k]++;
            if (Verificare()) //daca elementul incarcat este valid
                if (k == n) //verific daca am ajuns la solutia completa.
                    Afisare(); 
                else  //daca nu am solutia completa urc in stiva (maresc vectorul, adica pe k)
                {
                    k++;
                    vect[k] = 0;
                }
        }
        else
            k--;
}

void timpul(int marcator[2][20], int distanta[20], int timp, string transport)
{
    int aux = 1, distanta1, distanta2;
    cout << endl<<"Timpul parcurs intre "; cin >> distanta1; cin >> distanta2;
    int gasit = 0;
    for (int i = 1; i <= m; i++)
    {
        if (vect[aux] == distanta1)
        {
            gasit++;
            int aux1 = aux;
            for (int j = 1; j <= m; j++)
            {

                if (vect[aux] == marcator[1][j] && vect[aux1 + 1] == marcator[2][j] || vect[aux1+1] == marcator[1][j] && vect[aux] == marcator[2][j])
                {
                    
                    timp += distanta[j] * 3;
                    j = 0;
                    if (vect[aux1+1] == distanta2)
                    {
                        break;
                    }
                    aux1++;
                    aux++;

                }
            }
        }
        else
        {
            aux++;
        }
        if(gasit==1)
        {
            break;
        }
    }

    if (transport == "bicicleta" || transport == "moped-electric" || transport == "trotineta")
    {
        timp += timp * 0.2;
    }

    if (distanta1 == 1 && distanta2 == 1)
    {
        for (int i = 1; i <= m; i++)
        {
            if (marcator[2][i] == vect[n] || marcator[1][i] == vect[n])
            {
                timp = timp + distanta[i] * 3;
                break;
            }
        }


        cout << endl << "Distribuirea tuturor comenzilor va dura aproximativ: " << timp / 60 << " ore si " << timp % 60 << " minute." << endl;

    }
    else  cout << timp / 60 << " ore si " << timp % 60 << " minute." << endl;

   
}

int venituri(int marcator[3][20],int pret[20], int suma)
{

    cout << endl;
    for (int i = 1; i <= m; i++)
        cout <<"Restaurantul " << marcator[1][i] << " livreaza catre " << marcator[2][i] << " o camanda de " << pret[i]<<" lei."<<endl;

    int aux = 1;
    for (int i = 1; i <= m; i++)
    {
        if (vect[aux] == marcator[1][i] && vect[aux + 1] == marcator[2][i])
            for (int j = 1; j <= m; j++)
            {

                if (i == j)
                {
                    suma += pret[i];
                    aux++;
                    i = 0;
                    break;
                }

            }
        if (vect[aux] == marcator[2][i] && vect[aux + 1] == marcator[1][i])
        {
            for (int j = 1; j <= m; j++)
            {

                if (i == j)
                {
                    suma +=pret[i];
                    aux++;
                    i = 0;
                    break;
                }

            }
        }


    }
    cout <<endl<< "Suma incasata dupa parcurgerea traseului este: " << suma << " lei."<<endl;
    return suma;
}



int main()
{
    ifstream fin("proiect.txt");
    int u, v, distanta[20], marcator[3][20], pret[20], total = 0,timp=0,suma=0;
    string transport;

    if (fin)
        cout << "S-a citit cerinta";
    else
        cout << "Nu se poate citi cerinta";


    cout << endl;

    fin >> n >> m;
  
    for (int i = 1; i <= m; i++)
    {
        fin >> u >> v>> distanta[i]>>pret[i];

        a[u][v] = a[v][u] = 1;
        marcator[1][i] = u;
        marcator[2][i] = v;

    }

    cout << endl << "Matricea de adiacenta este: " << endl;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << a[i][j] << " ";
        cout << endl;

    }


    dis(marcator,distanta);

    cout << endl << "Traseul de urmat este: ";
    back();

    total=plata(marcator, distanta, total);


    cout << endl << "Introduceti mijlocul de transport: ";
    cin >> transport;
    total=venituri(transport, total);

    timpul(marcator, distanta, timp, transport);

    suma=venituri(marcator,pret,suma);

    cout << endl << "Profitul dupa onorarea comenzilor este de: " << suma - total << " lei."<<endl;

    if (solutii == 0)
    {
        cout << "Nu exista cai de acces catre adresa comenzilor";
    }

    return 0;
}