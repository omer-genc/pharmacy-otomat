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

int main()
{
    eczane gencEczane;
    gencEczane.eczaneOlustur();
    gencEczane.eczaneIlacSayfasi();

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
    ifstream File(dosyaismi); //create or open eczane file
    while (getline(File,text)){cout<<text;}
    File.close();
}

void eczane::setId(int id_){eczane_id = id_;}
void eczane::setIsim(string name_){eczane_ismi=name_;}
void eczane::setAdres(string adres_){eczane_adresi = adres_;}

int eczane::getId(){return eczane_id;}
string eczane::getIsim(){return eczane_ismi;}
string eczane::getAdres(){return eczane_adresi;}