#include <stdio.h>

int tanterem(int min, int max);

double zh();

void raktar();

void ceg();


int main()
{ 

	int hallgatok = tanterem(0, 50);
	printf("Sikeres adatbevitel, a teremben %d hallgato van.\n", hallgatok);

	double atlag = zh();
	printf("%.2f az osztalyatlag\n", atlag);

	raktar();

	ceg();

	return 0;
}

//1.FELADAT
int tanterem(int min, int max)
{
	int hallgatok = 0;

	do
	{
		printf("Adja meg a tanteremben levo hallgatok szamat\n");
		scanf(" %d", &hallgatok);

		if (hallgatok < min || hallgatok > max) {
			printf("haljal ki te ertetlen mocsok szerinted annyi kurva ember hogy ferne el egy kurva tanterembe idiota geci\n");
		}

	} while (hallgatok < min || hallgatok > max);

	return hallgatok;
}

//2.FELADAT
double zh()
{
	int pontszamok[5];
	int i = 0;
	double atlag = 0;
	double osszeg = 0;

for (i = 0; i < 5; i++)
	{
		do
		{

			printf("Adja meg a %d. diakpontszamat\n", i + 1);
			scanf("%d", &pontszamok[i]);

			if (pontszamok[i] < 0 || pontszamok[i] > 100) {
				printf("A pontszam 0 es 100 kozott lehet csak\n");
			}

		} while (pontszamok[i] < 0 || pontszamok[i] > 100);

		osszeg = osszeg + pontszamok[i];

	}

	atlag = osszeg / 5;

	return atlag;
}

void raktar() {

	int termek[5] = { 0,0,0,0,0 };
	int szam = 0;
	int sorszam = 0;
	int db = 0;

	while (1) {

		printf("\n\n======Raktar======\n\n");
		printf("1 -> Raktarkeszlet listazasa\n");
		printf("2 -> Aru beszallitasa (keszlet novelese)\n");
		printf("3 -> Kilepes\n");

		scanf(" %d", &szam);

		if (szam == 1) {
			printf("1.termek: %d, 2.termek: %d, 3.termek: %d, 4.termek: %d, 5.termek: %d\n", termek[0], termek[1], termek[2], termek[3], termek[4]);;
		}
		else if (szam == 2) {
			printf("Add meg a termek sorszamat\n");
			scanf(" %d", &sorszam);
			printf("Add meg hany darabot hoztak a termekbol\n");
			scanf(" %d", &db);

			termek[sorszam - 1] = termek[sorszam - 1] + db;
		}
		else if (szam == 3) {
			printf("Viszlat\n");
			break;
		}
		else {
			printf("Ilyen menupont nincs te agyalagyult semmirekello geci\n");
		}

	}
}

void ceg() {

	int dolgozok[5];
	int szam = 0;
	int sorszam = 0;
	int premium = 0;
	int bunti = 0;
	int kuldo = 0;
	int fogado = 0;
	int osszeg = 0;

		for (int i = 0; i < 5; i++) {
			dolgozok[i] = 200000;
		}

	while (1) {
		printf("\n\n=====SIGMA CEG=====\n\n");
		printf("1 -> Fizetesek listazasa\n");
		printf("2 -> Premium osztas\n");
		printf("3 -> Levonas / Buntetes\n");
		printf("4 -> Atutalas fizetesbol\n");
		printf("5 -> Kilepes\n");

		scanf(" %d", &szam);

		if (szam == 1) {

			for (int i = 0; i < 5; i++) {

				printf("%d. dolgozo: %d Ft\t", i + 1, dolgozok[i]);

			}
		}
		else if (szam == 2) {

			printf("Add meg a dolgozo sorszamat\n");
			scanf(" %d", &sorszam);
			printf("Add meg a premium osszeget\n");
			scanf(" %d", &premium);


			if (sorszam > 0 && sorszam < 6) {
				dolgozok[sorszam - 1] = dolgozok[sorszam - 1] + premium;
			}
			else {
				printf("Nincs ilyen sorszamu dolgozo\n");
			}
		}
		else if (szam == 3) {

			printf("Add meg a dolgozo sorszamat\n");
			scanf(" %d", &sorszam);
			printf("Add meg a buntetes osszeget\n");
			scanf(" %d", &bunti);


			if (sorszam > 0 && sorszam < 6) {
				if (dolgozok[sorszam - 1] - bunti < 200000) {
					printf("A buntetes nem vonhato le\n");
				}
				else {
					dolgozok[sorszam - 1] = dolgozok[sorszam - 1] - bunti;
				}
			}
			else {
				printf("Nincs ilyen sorszamu dolgozo\n");
			}
		}
		else if (szam == 4) {

			printf("Add meg a kuldo sorszamat!\n");
			scanf(" %d", &kuldo);
			printf("Add meg a fogado sorszamat!\n");
			scanf(" %d", &fogado);
			printf("Add meg a kuldeni kivant osszeget!\n");
			scanf(" %d", &osszeg);

			if (kuldo > 0 && kuldo < 6 && fogado > 0 && fogado < 6) {
				if (dolgozok[kuldo - 1] - osszeg < 200000) {
					printf("Az atutalas nem sikerult\n");
				}
				else {
					dolgozok[kuldo - 1] = dolgozok[kuldo - 1] - osszeg;
					dolgozok[fogado - 1] = dolgozok[fogado - 1] + osszeg;
				}
			}
			else {
				printf("Nincs ilyen sorszamu kuldo vagy fogado\n");
			}

		}
		else if (szam == 5) {
			printf("Viszlat te semmirekello\n");
			break;
		}
		else {
			printf("Nincs ilyen menupont\n");
		}
	}
}