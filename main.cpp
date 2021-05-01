#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class eczane
{
 private:
    int eczane_id;
    string eczane_ismi;
    string eczane_adresi;
 public:
    eczane();                                   // default constructor
    eczane(int id,string isim, string adres);   // constructot with arg
    eczane(const eczane &other);                //copy constructor
    eczane &operator=(const eczane &other);     //assignment operator

    void eczaneOlustur();
    void eczaneGoster();
    void eczaneIlacSayfasi();

    void setId(int id_);
    void setIsim(string name_);
    void setAdres(string adres_);

    int getId();
    string getIsim();
    string getAdres();
};

class ilac{
 private:
    int ilac_id;
    int ilac_sayisi;
    double ilac_fiyat;
    string ilac_ismi;
 public:
    ilac();
    ilac(int id,int sayi,double fiyat,string isim);
    ilac(const ilac &other);
    ilac &operator=(const ilac &other);

    void ilacOlustur();
    void ilacGoster();
    void ilacDuzenle();

    void setId(int id);
    void SetSayi(int sayi);
    void setFiyat(double fiyat);
    void setIsim(string isim);

    int getId();
    int getSayi();
    double getFiyat();
    string getisim();
};

//Function
void eczaneGirisi(int parola);
void musteriGirisi();
void karsilama();

int main()
{
    karsilama();

    return 0;
}

eczane::eczane() 
{
    eczane_id = 0;
    eczane_ismi = "Default";
    eczane_adresi = "Default";
}
eczane::eczane(int id,string isim, string adres)
{
    eczane_id = id;
    eczane_ismi = isim;
    eczane_adresi = adres;
}
eczane::eczane(const eczane &other)                 
{
    eczane_id = other.eczane_id;
    eczane_ismi = other.eczane_ismi;
    eczane_adresi = other.eczane_adresi;
    
}
eczane &eczane::operator=(const eczane &other)
{
    eczane_id = other.eczane_id;
    eczane_ismi = other.eczane_ismi;
    eczane_adresi = other.eczane_adresi;
    return (*this);
}

void eczane::eczaneOlustur()
{  
    cout<<"Eczane id: ";
    cin>>eczane_id;
    cout<<"Eczane ismi: ";
    cin>>eczane_ismi;
    cout<<"Eczane adresi: ";
    cin>>eczane_adresi;

    fstream File;
    File.open("eczane_listesi.dat",std::ios_base::app);
    File<<endl<<eczane_id<<endl<<eczane_ismi<<endl<<eczane_adresi;
    File.close();
}
void eczane::eczaneGoster()
{
    cout
    <<"Eczane ismi: "<<eczane_ismi<<endl
    <<"Eczane id: "<<eczane_id<<endl
    <<"Eczane adresi: "<<eczane_adresi;
}
void eczane::eczaneIlacSayfasi()
{
    string text;
    string dosyaismi;
    dosyaismi = eczane_ismi+".dat";
    ifstream File2(dosyaismi); //create or open eczane file
    while (getline(File2,text)){cout<<text;}
    File2.close();
}

void eczane::setId(int id_){eczane_id = id_;}
void eczane::setIsim(string name_){eczane_ismi=name_;}
void eczane::setAdres(string adres_){eczane_adresi = adres_;}

int eczane::getId(){return eczane_id;}
string eczane::getIsim(){return eczane_ismi;}
string eczane::getAdres(){return eczane_adresi;}

//ilac functions
ilac::ilac()
{
    ilac_id = 0;
    ilac_sayisi = 0;
    ilac_fiyat = 0;
    ilac_ismi = "";
    
}
ilac::ilac(int id, int sayi,double fiyat,string isim )
{
    ilac_id = id;
    ilac_sayisi = sayi;
    ilac_fiyat = fiyat;
    ilac_ismi = isim;
}
ilac::ilac(const ilac &other)
{
    ilac_id = other.ilac_id;
    ilac_sayisi = other.ilac_sayisi;
    ilac_fiyat = other.ilac_fiyat;
    ilac_ismi = other.ilac_ismi;
}
ilac &ilac::operator=(const ilac &other)
{
    ilac_id = other.ilac_id;
    ilac_sayisi = other.ilac_sayisi;
    ilac_fiyat = other.ilac_fiyat;
    ilac_ismi = other.ilac_ismi;
    return (*this);
}

void ilac::ilacOlustur()
{
    cout<<"Ilac id: ";
    cin>>ilac_id;
    cout<<"Ilac sayisi: ";
    cin>>ilac_sayisi;
    cout<<"Ilac fiyati: ";
    cin>>ilac_fiyat;
    cout<<"Ilac ismi: ";
    cin>>ilac_ismi;
}
void ilac::ilacGoster()
{
    cout<<
    "isim: "<<ilac_ismi<<endl<<
    "Id: "<<ilac_id<<endl<<
    "Sayi: "<<ilac_sayisi<<endl<<
    "Fiyat: "<<ilac_fiyat;
}
void ilac::ilacDuzenle()
{
    cout<<"Yeni ilac id: ";
    cin>>ilac_id;
    cout<<"Yeni ilac sayisi: ";
    cin>>ilac_sayisi;
    cout<<"Yeni ilac fiyati: ";
    cin>>ilac_fiyat;
    cout<<"Yeni ilac ismi: ";
    cin>>ilac_ismi;
}

void ilac::setId(int id){ilac_id = id;}
void ilac::SetSayi(int sayi){ilac_sayisi=sayi;}
void ilac::setFiyat(double fiyat){ilac_fiyat=fiyat;}
void ilac::setIsim(string isim){ilac_ismi=isim;}

int ilac::getId(){return ilac_id;}
int ilac::getSayi(){return ilac_sayisi;}
double ilac::getFiyat(){return ilac_fiyat;}
string ilac::getisim(){return ilac_ismi;}

//other function
void eczaneGirisi(int parola)
{
    if(parola==123)
        while (1)
        {
            int secim;
            cout<<"\nEczane Girisi\n"<<
            "   1. Eczane Listesi Olustur\n"<<
            "   2. Eczane Ekle\n"<<
            "   3. Ilac Ekle\n"<<
            "   4. Ilac Duzenle\n"<<
            "   5. Ust menu\n"<<
            "secim: ";
            cin>>secim;
            
            if (secim==1)
                cout<<"1. secim yapildi";
            else if(secim==2)
                cout<<"2. secim yapildi";
            else if(secim==3)
                cout<<"3. secim yapildi";
            else if(secim==4)
                cout<<"4. secim yapildi";
            else if(secim==5)
            {
                cout<<"Ust menuye cikildi\n";
                break;
            }
            else
                cout<<"Yanlis secim yaptiniz tekrar deneyiniz";
        }
    else
        cout<<"Hatali sifre: ";    
    
}
void musteriGirisi()
{
    while (1)
        {
            int secim;
            cout<<"\nMusteri Girisi\n"<<
            "   1. Ilac Ara\n"<<
            "   2. Eczane Listesi\n"<<
            "   3. Herhangi bir Eczaneyi Goster\n"<<
            "   4. Herhangi bir Eczaneye ait Ilac Listesi\n"<<
            "   5. Ust menu\n"<<
            "secim: ";
            cin>>secim;
            
            if (secim==1)
                cout<<"1. secim yapildi";
            else if(secim==2)
                cout<<"2. secim yapildi";
            else if(secim==3)
                cout<<"3. secim yapildi";
            else if(secim==4)
                cout<<"4. secim yapildi";
            else if(secim==5)
            {
                cout<<"Ust menuye cikildi\n";
                break;
            }
            else
                cout<<"Yanlis secim yaptiniz tekrar deneyiniz"; 
        } 
}
void karsilama()
{
    int parola,secim;
    while (1)
    {
        cout<<"1. Eczane Girisi\n"
            <<"2. Musteri Girisi\n"
            <<"3. Cıkıs\n"
            <<"\nSecim: ";
        cin>>secim;

        if(secim==1)
        {
            cout<<"Parola giriniz: ";
            cin>>parola;
            eczaneGirisi(parola);
        }
        else if(secim==2)
            musteriGirisi();
        else if(secim==3)
            break;
        else
            cout<<"Yanlis giris tekrar deneyin\n";    
    }
    
}