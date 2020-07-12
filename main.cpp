#include <iostream>
#include <cstring>
#include <conio.h>
#include <fstream>
#include <cstdlib>
#include <windows.h>
#include <time.h>
#include <algorithm>

using namespace std;

string tresc[1000],odpa[1000],odpb[1000],odpc[1000],odpd[1000],odp[1000],odpowiedz;
int nr_z[1000],kat[1000],id[1000],key,index,wybor,los,score,zad=0,il_linii=0,log[200][2],ilkat=13,wyb,nrlog=0;

int zaladuj();
bool szukaj(int key);
void czysc();
string kategoria(int x);
void wyswietl(int x, int licznik);
void sprawdz(string x, string y);
void test();
void logger(int id, int x, int y);
void podsumowanie();

int main()
{
    /*if(test(1)==false||test(2)==false)
    {
        cout << "Bˆ¥d aplikacji!" << endl;
        cout << "Unikalno˜† ID: " << test(0) << endl;
        cout << "Unikalno˜† linii: " << test(1) << endl;
    	system("pause");
    	if(test(2)==false)
    	{
            czysc();
            for(int i=0; i<zad; i++)
            {
                cout << id[i] << endl;
            }
            system("pause");
    	}
    }*/
    zaladuj();
    for(;;)
    {
        czysc();
        score=0;
        cout << "1. Nauka (po jednym z ka¾dej kategorii)" << endl;
        cout << "2. Wszystkie z jednej kategorii" << endl;
        cout << "3. Wyszukaj po ID" << endl;
        cout << "4. Wczytaj ponownie baz©!" << endl;
        cout << "5. Oznaczenia" << endl;
        cout << "6. Wa¾ne wzory" << endl;
        cout << "0. Wyj˜cie" << endl;
        cout << "Wyb¢r: ";
        wybor=getch();

        switch(wybor)
        {
        case '1':
        {
            czysc();
            srand(time(NULL));
            for(int i=1; i<=ilkat;)
            {
                los = rand()%1000;
                if(kat[los] == i)
                {
                    wyswietl(los,nrlog);
                    nrlog++;
                    i++;
                }
            }
            system("cls");
            podsumowanie();
        }
        break;
        case '2':
        {
            system("cls");
            cout << "========================================"<<endl;
            cout << "|    Wszystkie z jednej kategorii      |"<<endl;
            cout << "========================================"<<endl;
            nrlog = 0;
            for(int i=1; i<=ilkat; i++)
            {
                cout << i << ". " << kategoria(i) <<endl;
            }///if
            cout << "Wyb¢r: ";
            cin >> wyb;
            while(wybor!='n' && wybor != 'N')
            {
                wybor=' ';
                czysc();
                los = rand()%1000;
                if(kat[los] == wyb)
                {
                    wyswietl(los, nrlog);
                    nrlog++;
                    while(wybor!='n' && wybor != 'N' && wybor != 'T' && wybor != 't')
                    {
                        cout << endl << "[T] Dalej" << endl << "[N] Powr¢t" << endl << "Wyb¢r: ";
                        wybor = getch();
                        if(wybor=='n' || wybor == 'N')
                        {
                            podsumowanie();
                        }
                        else if (wybor!='t' && wybor != 'T')cout << "Nie ma takiej opcji!";
                    }///while
                }///if
            }///for
        }///case
        break;
        case '3':
        {
            czysc();
            cout << "ID: ";
            cin >> key;
            if(szukaj(key))wyswietl(index, nrlog);
            else
            {
                czysc();
                cout << "Niestety nie znaleziono zadania o podanym ID!" << endl;
                system("pause");
            }///else
        }///case
        break;
        case '4':
        {
            zaladuj();
            czysc();
            cout << "Baza zaˆadowana pomy˜lnie! ";
            Sleep(500);
        }///case
        break;
        case '5':
        {
            cout << endl << endl;
            cout << "|==================================================================================|" << endl;
            cout << "|          Znak         |            Oznaczenie                                    |" << endl;
            cout << "|==================================================================================|" << endl;
            cout << "|^                      |Pot©gowanie                                               |" << endl;
            cout << "|< > <= >=              |Mniejsze, wi©ksze, mniejsze rowne, wieksze rowne          |" << endl;
            cout << "|[8] [-8]               |Nieskoäczono˜†, minus nieskoäczono˜†                      |" << endl;
            cout << "|[#IMG]                 |Do tego zadania doˆ¥czno obrazek o nazwie #id_zadanie     |" << endl;
            cout << "|[ALFA] [BETA] [GAMMA]  |alpha  beta  gamma                                        |" << endl;
            cout << "|[.] [K¤T]              |Stopieä, k¥t                                              |" << endl;
            cout << "|[DELTA] (an)           |Delta, ci¥g an                                            |" << endl;
            cout << "|log(a;b) log(c)        |log stopnia a z b, log stopnia 10 z c                     |" << endl;
            cout << "|==================================================================================|" << endl;

            system("pause");

        }///case
        break;
        case '6':
        {
            cout << endl << endl;
            cout << "|==================================================================================|" << endl;
            cout << "|                                   WA½NE WZORY                                    |" << endl;
            cout << "|==================================================================================|" << endl;
            cout << "|                              DZIAANIA NA LICZBACH                               |" << endl;
            cout << "|a^n*a^m = a^(n+m) | a^n/a^m = a^(n-m) | (a^n)^m = a^(n*m)                         |" << endl;
            cout << "|a^n*b^n = (ab)^n  | a^n/b^n = (a/b)^n                                             |" << endl;
            cout << "|Pierwiastek stopnia n, z a to a^(1/n)                                             |" << endl;
            cout << "|a^n = (1/a)^(-n)                                                                  |" << endl;
            cout << "|a^0 = 1 | a^1 = a | 1^n = 1                                                       |" << endl;
            cout << "|2^1/2 ~ 1,4 | 3^1/2 ~ 1,7 | 5^1/2 ~2,2                                            |" << endl;
            cout << "|(kn) = k (1+(p/100))^n | Kwota, Procent, n - ilo˜† kapitalizacji                  |" << endl;
            cout << "|==================================================================================|" << endl;
            cout << "|                                    LOGARYTMY                                     |" << endl;
            cout << "|log(a;b) = x ==> a^x = b                                                          |" << endl;
            cout << "|log(a;b) + log (a;c) = log (a;b*c) | log(a;b) - log (a;c) = log (a;b/c)           |" << endl;
            cout << "|log(a) = log(10;a) | n*log(a;b) = log(a;b^n)                                      |" << endl;
            cout << "|==================================================================================|" << endl;
            cout << "|                               NIERàWNO—CI I FUNKCJE                              |" << endl;
            cout << "|[DELTA] = b^2-4ac | x1=(-b-[DELTA]^1/2)/2a | x1=(-b-[DELTA]^1/2)/2a               |" << endl;
            cout << "|W=(p;q) | p = -b/2a | q=-[DELTA]/4a = f(p)                                        |" << endl;
            cout << "|f(x)=ax^2+bx+c <==Wz¢r o¢lny funkcji kwadratowej                                  |" << endl;
            cout << "|f(x)=a(x-x1)(x-x2) <== Wz¢r iloczynowy funkcji kwadratowej                        |" << endl;
            cout << "|f(x)=a(x-p)^2+q <== Wz¢r kanoniczny funkcji kwadratowej                           |" << endl;
            cout << "|f(x)=ax+b <== Wz¢r og¢lny funkcji liniowej                                        |" << endl;
            cout << "|==================================================================================|" << endl;
            cout << "|                             FUNKCJE TRYGONOMETRYCZNE                             |" << endl;
            cout << "|[@1] => sin[ALFA] = a/c | cos[ALFA] = a/b | tg[ALFA]= b/c                         |" << endl;
            cout << "|sin[ALFA]^2+sin[BETA]^2=1 | tg[ALFA] = sin[ALFA]/cos[ALFA]                        |" << endl;
            cout << "|tg[ALFA]=1/ctg[ALFA]                                                              |" << endl;
            cout << "|==================================================================================|" << endl;
            cout << "|                                 GEOMETRIA PASKA                                 |" << endl;
            /*cout << "|W tr¢jk¥cie r¢wnobocznym wysoko˜ci przecinaj¥ si© w stosunku 1:3                  |" << endl;
            cout << "|Pole prostok¥d = ab                      | Obw prostok¥d = 2a +2b                 |" << endl;
            cout << "|Pole kwadratu = a^2                      | Obw kwadratu = 4a                      |" << endl;
            cout << "|Pole okr¥g = [pi]r^2                     | Obw okr¥g = 2[pi]r                     |" << endl;
            cout << "|Pole tr¢jk¥t = (ah)/2                    | Obw tr¢jk¥t = a+b+c                    |" << endl;
            cout << "|Pole trapez = ((a+b)h)/2                 | Obw trapez = a+b+c+d                   |" << endl;
            cout << "|Pole r¢wnolegˆobok = ah                  | Obw r¢wnolegˆobok = 2ab                |" << endl;
            cout << "|Pole romb = ah                           | Obw romb = 4a                          |" << endl;
            cout << "|Pole walec = 2[pi]r(r+h)                 | V walec = [pi]r^2*h                    |" << endl;
            cout << "|Pole czworo˜cian foremny = a^2*3^1/2     | V czworo˜cian foremny = (a*2^1/2)/12   |" << endl;
            cout << "|Pole ostrosˆup = pp+3pb                  | V ostrosˆup =  pp*h/3                  |" << endl;
            cout << "|Pole sto¾©k = [pi]r(r+l)                 | V sto¾©k = [pi]r^2h/3                  |" << endl;
            cout << "|Pole kula = 4[pi]r^2                     | V kula = (4/3)*[pi]r^3                 |" << endl;
            cout << "|Pole sze˜cian = 4a^2                     | d sze˜cian = a*3^1/2                   |" << endl;
            cout << "|Pole prostopadˆo˜cian = 2ab+2bc+2ac      | V prostopadˆo˜cian = abc               |" << endl;
            cout << "|==================================================================================|" << endl;
            */
            cout << "|==================================================================================|" << endl;
            cout << "|TRàJK¤T RàWNOBOCZNY: h=(a*3^1/2)/2; P=(a^2*3^1/2)/4; [ALFA][BETA] [GAMMA]=60[.]   |" << endl;
            cout << "|Punkt przeci©cia wysoko˜ci przecina j¥ w stosunku 2:1                             |" << endl;
            cout << "|P(kwadratu) = a^2 = (d^2)/2 | P(trapezu) = (a+b)*h*1/2 p(rombu) = 1/2*d1*d2 = ah  |" << endl;
            cout << "|P(koˆa) = [pi]r^2 | Obw(koˆa) = 2[pi]r                                            |" << endl;
            cout << "|                                                                                  |" << endl;
            cout << "|                                                                                  |" << endl;
            cout << "|==================================================================================|" << endl;



            system("pause");
        }///case
        break;
        case '`':
        {
            system("cls");
            cout << "==================================="<<endl;
            cout << "           For develop!            "<<endl;
            cout << "==================================="<<endl;
            cout << "1. Lista ID (ci¥gˆa)"<<endl;
            cout << "2. Lista ID (przerywana)"<<endl;
            cout << "3. Testy aplikacji"<<endl;
            cout << "4. Statystyka odpowiedzi"<<endl;
            wybor = getch();
            switch(wybor)
            {
            case'1':
            {
                for(int i=0; i<zad; i++)
                {
                    cout << id[i] << endl;
                }///for
                system("pause");
            }///case
            break;
            case '2':
            {

                HANDLE  hConsole;
                hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				int test_id=0;
				cout << "Kieruj klawiszami 'a' oraz 'd' kliknij 'p' aby wyj˜†!" << endl;
				while(wybor!='p')
				{
				    wybor = getch();
					system("cls");
					if(wybor=='a')
					{
						test_id--;
						if(test_id>=0)
						{
							cout << nr_z[test_id] << "." << kat[test_id] << ": ";
							SetConsoleTextAttribute(hConsole, 10);
							cout << id[test_id];
							SetConsoleTextAttribute(hConsole, 15);
							cout << "." ;
							SetConsoleTextAttribute(hConsole, 12);
							cout << odp[test_id];
							SetConsoleTextAttribute(hConsole, 15);
							cout << " " << tresc[test_id] << endl;
						}///if
					}///if
					else if(wybor=='d')
					{
						test_id++;
						if(test_id>=0)
						{
							cout << nr_z[test_id] << "." << kat[test_id] << ": ";
							SetConsoleTextAttribute(hConsole, 10);
							cout << id[test_id];
							SetConsoleTextAttribute(hConsole, 15);
							cout << "." ;
							SetConsoleTextAttribute(hConsole, 12);
							cout << odp[test_id];
							SetConsoleTextAttribute(hConsole, 15);
							cout << " " << tresc[test_id] << endl;
						}///if
					}///else
				}///while
            }///case
            break;
            case'3':
            {
                test();
            }///case
            break;
            case '4':
            {
                int s_odpa = 0, s_odpb = 0, s_odpc = 0, s_odpd = 0, s_odp_other = 0;
                for(int i=0; i<zad; i++)
                {
                    if(odp[i]=="a") s_odpa++;
                    else if(odp[i]=="b") s_odpb++;
                    else if(odp[i]=="c") s_odpc++;
                    else if(odp[i]=="d") s_odpd++;
                    else if(odp[i]!="a"&&odp[i]!="b"&&odp[i]!="c"&&odp[i]!="d") s_odp_other++;
                }///for

                system("cls");
                cout << "=========================" << endl;
                cout << "  Statystyka odpowiedzi  "<< endl;
                cout << "=========================" << endl;
                cout << "Odpowiedz a: "<< s_odpa << endl;
                cout << "Odpowiedz b: "<< s_odpb << endl;
                cout << "Odpowiedz c: "<< s_odpc << endl;
                cout << "Odpowiedz d: "<< s_odpd << endl;
                cout << "Zadania otwarte: "<< s_odp_other << endl;
                system("pause");

            }///case
            break;
            }///switch
        }///case
        break;
        case '0':
        {
            //plik.close();
            //plik.clear();
            return 31415926535;
        }///case
        break;
        default:
        {
            cout << "Wybrano bˆ©dn¥ opcj©! Spr¢buj ponownie!" << endl;
            system("pause");
        }///case
        break;
        }///switch
    }
}///fun main

int zaladuj()
{
    fstream plik;

    plik.open("baza.txt",ios::in);
    if(plik.good()==false)
    {
        cout << "Bˆ¥d odczytu pliku. Sprawd« czy plik bazowy znaduje si© w folderze programu i ma nazw© 'baza.txt'";
        system("pause");
        exit(0);
    }///if
    else
    {
        string linia;
        int nr=1,i=0;

        while(getline(plik,linia))
        {
            switch(nr)
            {
            case 1:
            {
                zad++;
                id[i] = atoi(linia.c_str());
            }///case
            break;
            case 2:
                odp[i] = linia;
                break;
            case 3:
                nr_z[i] = atoi(linia.c_str());
                break;
            case 4:
                kat[i] = atoi(linia.c_str());
                break;
            case 5:
                tresc[i] = linia;
                break;
            case 6:
                odpa[i] = linia;
                break;
            case 7:
                odpb[i] = linia;
                break;
            case 8:
                odpc[i] = linia;
                break;
            case 9:
            {
                odpd[i] = linia;
                nr=0;
                i++;
            }///case
            break;
            }///switch

            nr++;
            il_linii++;


        }///while
    }///else

}///fun

bool szukaj(int key)
{
    for(int i=0; i<1000; i++)
    {
        if(id[i]==key)
        {
            index = i;
            return 1;
        }///if
    }///for
}///fun

void czysc()
{
    system("cls");
    cout << "***********************************" << endl;
    cout << "*             MAT+                *" << endl;
    cout << "***********************************" << endl;
}///void

string kategoria(int x)
{
    if(x==1)return "Dziaˆania na liczbach!";
    else if(x==2)return "Logarytmy!";
    else if(x==3)return "Rownania!";
    else if(x==4)return "Nier¢wno˜ci!";
    else if(x==5)return "Funkcje!";
    else if(x==6)return "Funkcja liniowe!";
    else if(x==7)return "Funkcja kwadratowe!";
    else if(x==8)return "Ci¥gi!";
    else if(x==9)return "trygonometria!";
    else if(x==10)return "Geometria pˆaska!";
    else if(x==11)return "Geometria analityczna!";
    else if(x==12)return "Geometria przestrzenna!";
    else if(x==13)return "Kombinatoryka i rachunek prawdopodobieästwa!";
    else if(x==14)return "Statystyka!";
}///fun

void wyswietl(int x, int licznik)
{
    czysc();

    cout << "ID=" << id[x] << " | Zadanie " << nr_z[x] << " | Kategoria " << kategoria(kat[x]) << endl;
    cout << tresc[x] << endl <<endl;
    if(odpa[x]=="-")
    {
        cout << "Zadanie otwarte!"<<endl << "Twoja odpowied«: ";
        Sleep(1000);
        cin >> odpowiedz;
        if(odpowiedz==odp[x])
        {
            cout << endl << "Prawidˆowa odpowied«, +1 punkt!" << endl;
            logger(x, licznik, 2);
            system("pause");
        }///if
        else
        {

            cout << endl << "To byˆo pytanie otwarte!"<<endl<<"Odpowied« z klucza: " << odp[x] << endl << "Dobrze odpowiedziaˆe˜/a˜ ?\n1. Tak\n2. Nie\nWyb¢r: ";
            for(;;)
            {
                wybor=getch();
                if(wybor=='1'||wybor=='t'||wybor=='T'||wybor=='y'||wybor=='Y')
                {
                    cout << "To fajnie, +1 punkt!\n";
                    logger(x, licznik, 2);
                    break;
                }///if
                else if(wybor=='2'||wybor=='n'||wybor=='N')
                {
                    cout << "Szkoda, punktu nie b©dzie!\n";
                    logger(x, licznik, 1);
                    break;
                }///else if
                else
                {
                    cout << "nie ma takiej opcji spr¢buj jeszcze raz!\nWyb¢r: ";
                }///else
            }///for
            system("pause");
        }
    }///if
    else
    {
        cout << "A. " << odpa[x] << endl << "B. " << odpb[x] << endl << "C. " << odpc[x] << endl << "D. " << odpd[x] << endl << "Podaj odpowied«!";

        for(;;)
        {
            odpowiedz = getch();
            transform(odpowiedz.begin(),odpowiedz.end(),odpowiedz.begin(), ::tolower);

            if(odpowiedz=="A" || odpowiedz=="B" || odpowiedz=="C" || odpowiedz=="D" || odpowiedz=="a" || odpowiedz=="b" || odpowiedz=="c" || odpowiedz=="d")
            {
                if(odpowiedz==odp[x])
                {
                    cout << endl << "Prawidˆowa odpowied«, +1 punkt!" << endl;
                    logger(x, licznik, 2);
                    system("pause");
                    break;
                }///if
                else
                {
                    cout << endl << "Bˆ©dna odpowied«, prawidˆowa odpowied« to: " << odp[x] << endl;
                    logger(x, licznik, 1);
                    system("pause");
                    break;
                }///else
            }///if
            else
            {
                cout << "Nie ma takiej odpowiedzi ;/" << endl << "Twoja odpowied«: ";
            }///else
        }///for

    }///else

}///void

void test()
{

    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int error1=0;

    czysc();
    cout << "Testy aplikacji!" << endl;

    for(int i=0; i<zad; i++)
    {
        for(int j=0; j<zad; j++)
        {
            if(id[i]==id[j]&&i!=j&&id[i]!=0&&id[i]!=779&&id[i]!=735&&id[i]!=310&&id[i]!=383&&id[i]!=119&&id[i]!=397)
            {
                error1++;
                cout << id[i] << ", ";
            }///if
        }///for
    }///for
    cout << endl;
    SetConsoleTextAttribute(hConsole, 15);
    cout << "Unikalno˜† ID: ";
    if(error1>0)
    {
        SetConsoleTextAttribute(hConsole, 12);
        cout << "FALSE(" << error1 << ")\n";
    }///if
    else
    {
        SetConsoleTextAttribute(hConsole, 10);
        cout << "TRUE(" << error1 << ")\n";
    }///else
    SetConsoleTextAttribute(hConsole, 15);
    if(il_linii%9==0)
    {
        SetConsoleTextAttribute(hConsole, 15);
        cout << "Zgodno˜† linii w pliku 'baza.txt': ";
        SetConsoleTextAttribute(hConsole, 10);
        cout << "TRUE(0)\n";
    }///if
    else if(il_linii%9!=0)
    {
        SetConsoleTextAttribute(hConsole, 15);
        cout << "Zgodno˜† linii w pliku 'baza.txt': ";
        SetConsoleTextAttribute(hConsole, 12);
        cout << "TRUE()\n";
    }///else
    else
    {

        SetConsoleTextAttribute(hConsole, 12);
        cout << "Bˆ¥d wykonania!\n  ";
    }///else
    SetConsoleTextAttribute(hConsole, 15);
    system("pause");
}///void

void logger(int id, int x, int y)
{
    log[x][0] = id;
    log[x][1] = y;
}///void

void podsumowanie()
{
    system("cls");
    cout << "========================================"<<endl;
    cout << "|             PODSUMOWANIE             |"<<endl;
    cout << "========================================"<<endl;
    int s=0;
    for(s=0; s>=0; s++)
    {
        HANDLE  hConsole;
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        if(log[s][1]==2)
        {
            SetConsoleTextAttribute(hConsole, 10);
            cout << "ID=" << id[log[s][0]] << " | Zadanie " << nr_z[log[s][0]] << " | Kategoria " << kategoria(kat[log[s][0]]) << endl;
            score++;
        }///if
        else if(log[s][1]==1)
        {
            SetConsoleTextAttribute(hConsole, 12);
            cout << "ID=" << id[log[s][0]] << " | Zadanie " << nr_z[log[s][0]] << " | Kategoria " << kategoria(kat[log[s][0]]) << endl;
        }///else
        else break;
        SetConsoleTextAttribute(hConsole, 15);
    }///for
    cout << endl << endl << score << "/" << s << " punkt¢w!"<<endl;
    system("pause");
}///void