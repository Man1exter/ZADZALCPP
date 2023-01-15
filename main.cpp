#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>
#include <sstream>

using namespace std;

class Uzytkownik {

private:

    string imie;
    string nazwisko;
    int rok_urodzenia;
    string miejscowosc;

public:
    void setImie(string im) { imie = im; }
    void setNazwisko(string nazw) { nazwisko = nazw; }
    void setRokUrodzenia(int rok) { rok_urodzenia = rok; }
    void setMiejscowosc(string miejsc) { miejscowosc = miejsc; }

    string getImie() { return imie; }
    string getNazwisko() { return nazwisko; }
    int getRokUrodzenia() { return rok_urodzenia; }
    string getMiejscowosc() { return miejscowosc; }
};

int main() {
    int wybor;

    cout << "[1] DODAJ UZYTKOWNIKA " << endl;
    cout << "[2] WYSZUKAJ UZYTKOWNIKA " << endl;
    cout << "[3] WYSZUKAJ PO URODZENIU " << endl;
    cin >> wybor;

    if(wybor == 1){

      Uzytkownik nowyUzytkownik;

      cout << "Podaj imie: ";
      string imie;
      cin >> imie;
      nowyUzytkownik.setImie(imie);

      cout << "Podaj nazwisko: ";
      string nazwisko;
      cin >> nazwisko;
      nowyUzytkownik.setNazwisko(nazwisko);

      cout << "Podaj rok urodzenia: ";
      int rok;
      cin >> rok;
      nowyUzytkownik.setRokUrodzenia(rok);

      cout << "Podaj miejscowosc: ";
      string miejscowosc;
      cin >> miejscowosc;
      nowyUzytkownik.setMiejscowosc(miejscowosc);

      ofstream plik("uzytkownicy.txt", ios::app);
      plik << nowyUzytkownik.getImie() << " " << nowyUzytkownik.getNazwisko() << " " << nowyUzytkownik.getRokUrodzenia() << " " << nowyUzytkownik.getMiejscowosc() << endl;
      plik.close();

      cout << "" << endl;

      cout << "Dane uzytkownika: " << endl;
      cout << "Imie: " << nowyUzytkownik.getImie() << endl;
      cout << "Nazwisko: " << nowyUzytkownik.getNazwisko() << endl;
      cout << "Rok urodzenia: " << nowyUzytkownik.getRokUrodzenia() << endl;
      cout << "Miejscowosc: " << nowyUzytkownik.getMiejscowosc() << endl;

      cout << "" << endl;

    }
    else if(wybor == 2){

      string imie_szukaj, nazwisko_szukaj;
      cout << "Podaj imie uzytkownika, ktorego chcesz wyszukac: ";
      cin >> imie_szukaj;
      cout << "Podaj nazwisko uzytkownika, ktorego chcesz wyszukac: ";
      cin >> nazwisko_szukaj;

      transform(imie_szukaj.begin(), imie_szukaj.end(), imie_szukaj.begin(), ::tolower);
      transform(nazwisko_szukaj.begin(), nazwisko_szukaj.end(), nazwisko_szukaj.begin(), ::tolower);

      bool znaleziono = false;

      string linijska;

      ifstream plik_odczyt("uzytkownicy.txt");
      while (getline(plik_odczyt, linijska)) {

        transform(linijska.begin(), linijska.end(), linijska.begin(), ::tolower);

        if (linijska.find(imie_szukaj) != string::npos && linijska.find(nazwisko_szukaj) != string::npos) {

          cout << "Uzytkownik znaleziony: " << linijska << endl;
          znaleziono = true;
          break;
         }
      }
      plik_odczyt.close();
      if (!znaleziono) {
        cout << "Nie znaleziono uzytkownika o podanym imieniu i nazwisku." << endl;
      }
      return 0;
    }
    else if(wybor == 3){

      cout << " " << endl;

      int kryterium;
      cout << "[1] Urodzony przed rokiem" << endl;
      cout << "[2] Urodzony po roku" << endl;
      cout << "[3] Urodzony dokładnie w roku" << endl;
      cout << "[4] Powrot " << endl;
      cin >> kryterium;


      if(kryterium == 1) {
      int rok;
      cout << "Podaj rok: ";
      cin >> rok;

      ifstream plik("uzytkownicy.txt");
      string linia;
      bool znaleziono = false;
      while (getline(plik, linia)) {
      string imie, nazwisko, miejscowosc;
      int rok_urodzenia;
      istringstream iss(linia);
      iss >> imie >> nazwisko >> rok_urodzenia >> miejscowosc;
      if (rok_urodzenia < rok) {
      cout << "Imie: " << imie << " Nazwisko: " << nazwisko << " Rok urodzenia: " << rok_urodzenia << " Miejscowosc: " << miejscowosc << endl;
      znaleziono = true;
      }
      }
      if (!znaleziono) {
      cout << "Nie znaleziono uzytkownika urodzonego przed " << rok << " rokiem" << endl;
      }
      plik.close();
   
      }
      else if(kryterium == 2) {
      int rok;
      cout << "Podaj rok: ";
      cin >> rok;

      ifstream plik("uzytkownicy.txt");
      string linia;
      bool znaleziono = false;
      while (getline(plik, linia)) {
      string imie, nazwisko, miejscowosc;
      int rok_urodzenia;
      istringstream iss(linia);
      iss >> imie >> nazwisko >> rok_urodzenia >> miejscowosc;
      if (rok_urodzenia > rok) {
      cout << "Imie: " << imie << " Nazwisko: " << nazwisko << " Rok urodzenia: " << rok_urodzenia << " Miejscowosc: " << miejscowosc << endl;
      znaleziono = true;
      }
      }
      if (!znaleziono) {
      cout << "Nie znaleziono uzytkownika urodzonego po " << rok << " roku" << endl;
      }
      plik.close();
      }

      else if(kryterium == 3) {
      int rok;
      cout << "Podaj rok: ";
      cin >> rok;

      ifstream plik("uzytkownicy.txt");
      string linia;
      bool znaleziono = false;
      while (getline(plik, linia)) {
      string imie, nazwisko, miejscowosc;
      int rok_urodzenia;
      istringstream iss(linia);
      iss >> imie >> nazwisko >> rok_urodzenia >> miejscowosc;
      if (rok_urodzenia == rok) {
      cout << "Imie: " << imie << " Nazwisko: " << nazwisko << " Rok urodzenia: " << rok_urodzenia << " Miejscowosc: " << miejscowosc << endl;
      znaleziono = true;
      }
      }
      if (!znaleziono) {
      cout << "Nie znaleziono uzytkownika urodzonego w " << rok << " roku" << endl;
      }
      plik.close();
      }
      else if(kryterium == 4) {
      cout << "Powrot do menu glownego" << endl;
      main(); 
      }
      else {
      cout << "Niepoprawny wybor" << endl;
      }

    }

    else{
      cout << "NIE WIEM CO CHCESZ ZROBIC" << endl;
    }
}



