#define _CRT_SECURE_NO_WARNINGS
#include"Game1.h"
#include "XMLDataFile.h"
#include <stdio.h>
#include <iostream>
#include <ctime>
#include <string>
#include <cctype>
#include <algorithm>

bool is_number(const std::string& s)//funkcija za provjeru da li je ucitani string br ili nije
{
	return !s.empty() && std::find_if(s.begin(), s.end(), [](char c) {return !std::isdigit(c); }) == s.end();
}

//a-veci br, b-manji br
int ucitaj_br(int a, int b)
{
	
	int n;
	std::string s;
	std::cout << "Unesite broj iz opsega (" << b << " - " << a << ")" << ":" << std::endl;
	do
	{
		std::cin >> s;
		if ((!is_number(s))||((s.length())>6))
		{
			std::cout<<"Unos nije validan, pokusajte ponovo..."<<std::endl;
			n=-1;
		}
		else
		{
			n=std::stoi(s);
		}
		/*if (is_number(s))
		{
			n = std::stoi(s);
		}
		else
		{
			std::cout << "Niste unijeli broj, unesite ponovo";
			n = -1;
		}*/
		if ((n!=-1)&&(n > a || n < b))
			std::cout << "Taj broj nije iz dozvoljenog opsega, unesite ponovo broj." << std::endl;
	} while (n > a || n < b);
	return n;
	
}

//a i b su interval od a do b
int slucajan_br(int a, int b)
{
	srand(time(NULL));
	rand();
	return rand() % (a - b) + b;
}


int ucitajBrojIgranja()
{
	int br;
	FILE* fp;
	if ((fp = fopen("assets//data//GameOneData.txt", "r")) != nullptr)
	{
		fscanf(fp, "%d", &br);
		fclose(fp);
	}
	return br;
}

void upisiBrojIgranja(int br)
{
	FILE* fp;
	if ((fp = fopen("assets//data//GameOneData.txt", "w")) != nullptr)
	{
		fprintf(fp, "%d", br);
		fclose(fp);
	}
}


int game1(int brb,int percentage)
{
	/*std::cout << "Pravila igre: " << std::endl;
	std::cout << "Aplikacija ce prvo na slucajan nacin izabrati odredjeni broj." << std::endl;
	std::cout << "Korisnik ima 5 pokusaja da ga pogodi tako sto unosi broj" << std::endl;
	std::cout << "Aplikacija nakon svakog pokusaja prikazuje poruku:" << std::endl << "\"Broj koji trazite je[veci | manji] od unesenog broja\"" << std::endl;
	std::cout << "Ako korisnik pogodi trazeni broj dobija" << std::endl << "100 / broj_pokusaja bodova za svoj profil. " << std::endl << std::endl << std::endl;
	*/

	std::cout << "*********************************" << std::endl;
	std::cout << "*          Pogodite broj        *" << std::endl;
	std::cout << "*********************************" << std::endl;
	int br_igranja;
	br_igranja = ucitajBrojIgranja();
	int n, a, b;
	a = 100;
	b = 0;
	//POSTENI DIO IGRE
	if (br_igranja >= 3)
	{
		int br_pokusaja = 0;
		if (brb > 100)
		{
			int trazeni_br = slucajan_br(100, 0);
			while (true)
			{
				n = ucitaj_br(a, b);
				br_pokusaja++;
				if (n == trazeni_br)
				{
					brb = brb + 100 / br_pokusaja;
					std::cout << std::endl << "Pogodili ste trazeni broj i dobili " << (100 / br_pokusaja) << " bodova" << std::endl;
					upisiBrojIgranja(br_igranja + 1);
					return brb;//vracam ukupan broj bodova iz funkcije
				}
				else
				{
					if (br_pokusaja == 5)
					{
						std::cout << std::endl << "Niste pogodili, trazeni broj je bio " << trazeni_br << "." << std::endl;
						upisiBrojIgranja(br_igranja + 1);
						return brb;//vracam ukupan broj bodova iz funkcije
					}
					if (n > trazeni_br)
					{
						std::cout << std::endl << "Broj koji trazite je manji od navedenog broja." << std::endl;
						a = n - 1;
					}
					if (n < trazeni_br)
					{
						std::cout << std::endl << "Broj koji trazite je veci od navedenog broja." << std::endl;
						b = n + 1;
					}
				}
			}
		}
		else if (brb <= 100 && brb > 50)
		{
			int trazeni_br = slucajan_br(100, 0);
			while (true)
			{
				n = ucitaj_br(a, b);
				br_pokusaja++;
				if (n == trazeni_br)
				{
					if (br_pokusaja < 2)
						trazeni_br = slucajan_br(a, b);
					else
					{
						brb = brb + 100 / br_pokusaja;
						std::cout << std::endl << "Pogodili ste trazeni broj i dobili " << (100 / br_pokusaja) << " bodova" << std::endl;
						upisiBrojIgranja(br_igranja + 1);
						return brb;//vracam ukupan broj bodova iz funkcije
					}
				}
				else
				{
					if (br_pokusaja == 5)
					{
						std::cout << std::endl << "Niste pogodili, trazeni broj je bio " << trazeni_br << "." << std::endl;
						upisiBrojIgranja(br_igranja + 1);
						return brb;//vracam ukupan broj bodova iz funkcije
					}
					if (n > trazeni_br)
					{
						std::cout << std::endl << "Broj koji trazite je manji od navedenog broja." << std::endl;
						a = n - 1;
					}
					if (n < trazeni_br)
					{
						std::cout << std::endl << "Broj koji trazite je veci od navedenog broja." << std::endl;
						b = n + 1;
					}
				}
			}
		}
		else if (brb <= 50 && brb > 33)
		{
			int trazeni_br = slucajan_br(100, 0);
			while (true)
			{
				n = ucitaj_br(a, b);
				br_pokusaja++;
				if (n == trazeni_br)
				{
					if (br_pokusaja < 3)
						trazeni_br = slucajan_br(a, b);
					else
					{
						brb = brb + 100 / br_pokusaja;
						std::cout << std::endl << "Pogodili ste trazeni broj i dobili " << (100 / br_pokusaja) << " bodova" << std::endl;

						upisiBrojIgranja(br_igranja + 1);
						return brb;//vracam ukupan broj bodova iz funkcije
					}
				}
				else
				{
					if (br_pokusaja == 5)
					{
						std::cout << std::endl << "Niste pogodili, trazeni broj je bio " << trazeni_br << "." << std::endl;
						upisiBrojIgranja(br_igranja + 1);
						return brb;//vracam ukupan broj bodova iz funkcije
					}
					if (n > trazeni_br)
					{
						std::cout << std::endl << "Broj koji trazite je manji od navedenog broja." << std::endl;
						a = n - 1;
					}
					if (n < trazeni_br)
					{
						std::cout << std::endl << "Broj koji trazite je veci od navedenog broja." << std::endl;
						b = n + 1;
					}
				}
			}
		}
		else if (brb <= 33 && brb > 25)
		{
			int trazeni_br = slucajan_br(100, 0);
			while (true)
			{
				n = ucitaj_br(a, b);
				br_pokusaja++;
				if (n == trazeni_br && br_pokusaja < 4)
				{
					if (br_pokusaja < 4)
						trazeni_br = slucajan_br(a, b);
					else
					{
						brb = brb + 100 / br_pokusaja;
						std::cout << std::endl << "Pogodili ste trazeni broj i dobili " << (100 / br_pokusaja) << " bodova" << std::endl;
						upisiBrojIgranja(br_igranja + 1);
						return brb;//vracam ukupan broj bodova iz funkcije
					}
				}
				else
				{
					if (br_pokusaja == 5)
					{
						std::cout << std::endl << "Niste pogodili, trazeni broj je bio " << trazeni_br << "." << std::endl;
						upisiBrojIgranja(br_igranja + 1);
						return brb;//vracam ukupan broj bodova iz funkcije
					}
					if (n > trazeni_br)
					{
						std::cout << std::endl << "Broj koji trazite je manji od navedenog broja." << std::endl;
						a = n - 1;
					}
					if (n < trazeni_br)
					{
						std::cout << std::endl << "Broj koji trazite je veci od navedenog broja." << std::endl;
						b = n + 1;
					}
				}
			}
		}
		else if (brb <= 25 && brb > 20)
		{
			int trazeni_br = slucajan_br(100, 0);
			while (true)
			{
				n = ucitaj_br(a, b);
				br_pokusaja++;
				if (n == trazeni_br && br_pokusaja < 5)
				{
					if (br_pokusaja < 5)
						trazeni_br = slucajan_br(a, b);
					else
					{
						brb = brb + 100 / br_pokusaja;
						std::cout << std::endl << "Pogodili ste trazeni broj i dobili " << (100 / br_pokusaja) << " bodova" << std::endl;
						upisiBrojIgranja(br_igranja + 1);
						return brb;//vracam ukupan broj bodova iz funkcije
					}
				}
				else
				{
					if (br_pokusaja == 5)
					{
						std::cout << std::endl << "Niste pogodili, trazeni broj je bio " << trazeni_br << "." << std::endl;
						upisiBrojIgranja(br_igranja + 1);
						return brb;//vracam ukupan broj bodova iz funkcije
					}
					if (n > trazeni_br)
					{
						std::cout << std::endl << "Broj koji trazite je manji od navedenog broja." << std::endl;
						a = n - 1;
					}
					if (n < trazeni_br)
					{
						std::cout << std::endl << "Broj koji trazite je veci od navedenog broja." << std::endl;
						b = n + 1;
					}
				}
			}
		}

		//NAMJESTENI DIO IGRE,KORISNIK GUBI
		else
		{
			while (true)
			{
				if (br_pokusaja < 5) {
					n = ucitaj_br(a, b);
					br_pokusaja++;
				}

				if (br_pokusaja == 5)
				{
					std::cout << std::endl << "Niste pogodili, trazeni broj je bio " << slucajan_br(a, b) << "." << std::endl;
					upisiBrojIgranja(br_igranja + 1);
					return brb;//vracam ukupan broj bodova iz funkcije
				}
				else
				{
					if (n >= ((a + b) / 2))
					{
						std::cout << std::endl << "Broj koji trazite je manji od navedenog broja." << std::endl;
						a = n - 1;
					}
					if (n < (a + b) / 2)
					{
						std::cout << std::endl << "Broj koji trazite je veci od navedenog broja." << std::endl;
						b = n + 1;
					}
				}
			}
		}
	}

	//NAMJESTENI DIO IGRE,KORISNIK DOBIJA PRVA 3 PUTA
	else
	{
		int br_pokusaja = 0;
		int pogodak;
		pogodak = slucajan_br(5, 1); // slucajnim izborom odredim kad korisnik treba da dobije u prva tri puta
		while (true)
		{
			n = ucitaj_br(a, b);//ucita se broj koji korisnik misli da je odgovarajuci
			br_pokusaja++;
			if (br_pokusaja == pogodak) //ako je broj pokusaja jednak onom broju koji sam slucajnim izborom izvukao
			{							//onda je "pogodio" broj
				brb = brb + 100 / br_pokusaja; //povecava se br bodova
				std::cout << std::endl << "Pogodili ste trazeni broj i dobili " << (100 / br_pokusaja) << " bodova" << std::endl;
				upisiBrojIgranja(br_igranja + 1);
				return brb; //vracam ukupan broj bodova iz funkcije
			}
			if (br_pokusaja < pogodak) //...
			{
				if (n >= ((a + b) / 2))
				{
					std::cout << std::endl << "Broj koji trazite je manji od navedenog broja." << std::endl;
					a = n - 1;
				}
				if (n < (a + b) / 2)
				{
					std::cout << std::endl << "Broj koji trazite je veci od navedenog broja." << std::endl;
					b = n + 1;
				}
			}
		}
	}
}
