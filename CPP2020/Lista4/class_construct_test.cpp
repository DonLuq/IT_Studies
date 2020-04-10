#include <iostream>
#include <string>


class Pracownik{
public:
    std::string imie;
    std::string nazwisko;
    int rok_uro;
    
    Pracownik(std::string const& a_imie, std::string const& a_nazwisko, int const& a_rok_uro)
    :imie(a_imie), nazwisko(a_nazwisko), rok_uro(a_rok_uro)
    {
        std::cout << "Przypisano nastepujace dane do obiektu:\n"<<imie<<" "<<nazwisko<< " (" <<rok_uro<< ")"<<std::endl;
    }

    Pracownik()
    :imie("Brak"),nazwisko("Brak"),rok_uro(0)
    {
        std::cout<< "Niewystarczajace dane, utworzono nieokreslonego pracownika.\n";
    }

    Pracownik(Pracownik const& obiekt)
    :imie(obiekt.imie),nazwisko(obiekt.nazwisko+"(copy)"),rok_uro(obiekt.rok_uro)
    {
        std::cout<< "Utworzona kopia dla"<<imie<<" "<<nazwisko<< " ("<<rok_uro<<")"<< std::endl;
    }
    ~Pracownik()
    {
        std::cout<< "Usunieto: "<< imie << " "<< nazwisko<< "("<<rok_uro<<")"<<std::endl;
    }
};

Pracownik pracownik("Jan","Sobieski",2011);

int main(){
    Pracownik naukowiec("Anna","Lokalna",1999);
    Pracownik *doktor = new Pracownik;
    Pracownik sobowtor(naukowiec);
    delete doktor;
    std::cout<< "KONIEC MAIN()\n";
}
