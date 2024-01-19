//bankada sıra alırken ki sistem
#include <iostream>
#include <stdlib.h>
#include <windows.h>    
#include <cstdlib>
#include <string>  
#include <fstream>    

using namespace std;

//prototype
string sıraAL();
bool check(string);
void tckayit();
int menu();
           
int main()
{
    menu();
   return 0;
}

int menu()
{
    string secim;
    while(true)
    {    
        cout << "                                        <<< BankIstanbul >>> " << endl;
        cout << R"(
Islemler;                                                             
Sira Almak icin 1'e,                                                                                 [*PROGRAMI SONLANDIRMAK ICIN Z'YE TIKLAYINIZ*]
Kayit olmak icin 2'ye tiklayiniz: )";
        cin >> secim;
        if(secim=="1")
        {
            system("cls");    //sayfayı yeniliyor
            sıraAL();
        }
        else if(secim=="2")
        {
            system("cls");
            tckayit();
        }
        else if(secim=="z" || secim=="Z")
        {
            exit(0);
        }
        else
        {   
            system("cls");
            cout << "HATALI TUSLAMA YAPTINIZ!!!\a\n" << endl;
        }
    }
   return 0;
}

void tckayit()
{
    string definetc;
    ofstream kayit("tckayit.txt", ios::app);          //dosyayı açıyor ve ekelmeleri hep sondan devam ettiriyor
    
    cout << "\n               ****************-| TC NU. KAYIT |-****************\n" << endl;
    cout << "Lutfen TC'nizi tuslayiniz: ";
    cin >> definetc;
    if(definetc.length() != 11)                                            //girilen tc uzunluğu 11 hane değilse olmaz
    {
        system("cls");
        cout << "TC kimlik numarasinin uzunlugu 11 haneden olusmali!\a";
        tckayit();
    }

    //kayit.open("tckayit.txt"); //54. satırda açıyor zaten
    kayit << definetc << endl;
    kayit.close();
    cout << "                         Kayit islemi basarili!\n\n";
    Sleep(400);
    cout << "Ana menuye yonlendiriliyorsunuz..."<< endl;
    
    Sleep(2500);
    system("cls");
    menu();
}

string sıraAL()
{
    string tc;
    int sira=1;
    int hak=3;
    while(hak>0)
    {
        cout << "\nSira almaka icin lutfen TC kimlik numaranizi giriniz(Kalan Hakkiniz: "<< hak << "): " ;
        cin >> tc;

        ifstream check0("tckayit.txt");
        string satir;

        bool kayitli = check(tc); /*bool tipinde değişken oluşturup fonksiyondan gelen
                                değere göre kayit durumu kontrol edilecek*/
        
        if(kayitli) //yani true ise içerisi
        {
            cout << "Hos geldiniz sira numaraniz: " << sira;
            sira++;
            Sleep(2000);
            system("cls");
            menu();
        }
        else
        {
            cout << "Girilen TC Kimlik nu. bulunamadi!\a\n" << endl;
            int kayitac;
            if(hak>1)
            {
                cout << R"(Eger kayit acmak isterseniz 0'i tuslayiniz,
Tekrar denemek icin 9'u tuslayiniz:)";
            cin >> kayitac;
            }
            else
            {
                system("cls");
                cout << R"(SISTEMDEN ATILDINIZ!!!
                COK SAYIDA HATALI GIRIS YAPTINIZ!)";
                cout << "\a";
                return 0;    
            }

            if(kayitac==0)
            {
                hak=3;
                system("cls");
                tckayit();
                break;
            }
            else if(kayitac==9)
            {
                hak--;
                system("cls");
                continue;
            }
            else
            {
                system("cls");
                cout << "Hatali tuslama yaptiniz!\a\n";
                return 0;
            }
        }
    }
}

bool check(string x)
{
    ifstream check0("tckayit.txt");
    string satir;
    int kayitac;
    //check0.open("tckayit.txt"); //133. satırda açıyor zaten
    while(getline(check0,satir))
    {   
        //eğer girilen tc sistemde kayıtlı ise true döndürü değilse false
        if(x == satir)        
        {
            return true;
        }
    }
    return false;
}
