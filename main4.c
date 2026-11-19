#include <stdio.h>

int Beker(int min, int max);

void posta();

void csend();

void Kviddics();

void pont();

int main() {

	posta();

	csend();

	Kviddics();

	pont();

	return 0;
}

//0. FELADAT
int Beker(int min, int max) {

	int szam = 0;

	do {
		printf("Adjon meg egy egesz szamot %d es %d intervallumban!\n", min, max);
		scanf(" %d", &szam);

		if (szam < min || szam > max) {
			printf("A szam az intervallumon kivul van!\n");
		}
	} while (szam < min || szam > max);

	return szam;
}

//1. FELADAT
void posta() {

	int ertesito = 0;
	int tajekoztato = 0;
	int felkeszito = 0;
	int prof_csomag = 0;
	int osszeg_pergamen = 0;
	int osszeg_tinta = 0;
	int osszeg_pecset = 0;
	double csomag = 0;
	double uveg = 0;
	double doboz = 0;

	printf("Felveteli Ertesito\n");
	ertesito = Beker(1, 100);
	printf("Tanevkezdo Tajekoztato\n");
	tajekoztato = Beker(1, 100);
	printf("Vizsgafelkeszito Csomagok\n");
	felkeszito = Beker(1, 100);
	printf("Professzori Csomagok\n");
	prof_csomag = Beker(1, 100);

	osszeg_pergamen = 4 * ertesito + 2 * tajekoztato + 6 * felkeszito + 4 * prof_csomag;
	osszeg_tinta = 6 * ertesito + 3 * tajekoztato + 9 * felkeszito + 6 * prof_csomag;
	osszeg_pecset = 8 * ertesito + 4 * tajekoztato + 12 * felkeszito + 8 * prof_csomag;

	csomag = osszeg_pergamen / 100.0;
	uveg = osszeg_tinta / 50.0;
	doboz = osszeg_pecset / 100.0;

	printf("%.0f csomag pergamen szukseges, %.0f uveg tinta szukseges, %.0f doboz pecsetviasz szukseges!\n", csomag, uveg, doboz);

}

//2. FELADAT
void csend() {

	int seta[10];
	int osszes = 0;
	int figy_max = 0;
	double atlag = 0;

	for (int i = 0; i < 10; i++) {
		printf("Rendreutasitott diakok szama:\n");
		seta[i] = Beker(0, 20);

		osszes = osszes + seta[i];

		if (figy_max < seta[i]) {
			figy_max = seta[i];
		}
	}

	atlag = osszes / 10.0;

	printf("%d a figyelmeztetesek osszesitett szama!\n", osszes);
	printf("%d az egyetlen ellenorzes soran rendreutasitottak maximalis szama!\n", figy_max);
	printf("%.2f az ellenorzesenkenti atlag figyelmeztetes szam!\n", atlag);

	if (osszes > 35 || figy_max > 8) {
		printf("Nem engedelyezett a csoportos tanulas\n");
	}
	else {
		printf("Engedelyezett maradt a csoportos tanulas!\n");
	}
}

//3. FELADAT
void Kviddics() {

	int csapat1 = 0;
	int csapat2 = 0;
	int valasztas = 0;
	int valasztas2 = 0;

	while (1) {

		if (csapat1 - csapat2 > 159) {
			printf("A gyoztes csapat a Griffendel\n");
			break;
		}
		else if (csapat2 - csapat1 > 159) {
			printf("A gyoztes csapat a Mardekar\n");
			break;
		}

		printf("1 -> Griffendel csapat pontnoveles\n");
		printf("2 -> Mardekár csapat pontnoveles\n");
		scanf(" %d", &valasztas);

		if (valasztas == 1) {
			printf("1 -> Gol\n");
			printf("2 -> Fogo megfogta Mardekar cikeszt\n");
			scanf(" %d", &valasztas2);

			if (valasztas2 == 1) {
				csapat1 = csapat1 + 10;
			}
			else if (valasztas2 == 2) {
				csapat1 = csapat1 + 150;
				printf("A gyoztes csapat a Griffendel\n");
				break;
			}
			else {
				printf("Hibas bevitel\n");
			}
		}
		else if (valasztas == 2) {
			printf("1 -> Gol\n");
			printf("2 -> Fogo megfogta Griffendel cikeszt\n");
			scanf(" %d", &valasztas2);

			if (valasztas2 == 1) {
				csapat2 = csapat2 + 10;
			}
			else if (valasztas2 == 2) {
				csapat2 = csapat2 + 150;
				printf("A gyoztes csapat a Mardekar\n");
				break;
			}
			else {
				printf("Hibas bevitel\n");
			}
		}
		else {
			printf("Hibas bevitel\n");
		}

		printf("A merkozes jelenlegi allasa: Mardekar: %d pont\tGriffendel: %d pont\n", csapat1, csapat2);
	}
}

//4. FELADAT
void pont() {

	int pontok[4] = { 0, 0, 0, 0 };
	int valasztas = 0;
	int valasztas2 = 0;
	int noveles = 0;
	int csokkentes = 0;
	int legnagy = 0;

	while (1) {

		printf("1 -> Pontok kiiratasa\n");
		printf("2 -> Pontszam novelese\n");
		printf("3 -> Pontszam csokkentese\n");
		printf("4 -> Tanev vege\n");
		scanf(" %d", &valasztas);

		if (valasztas == 1) {
			for (int i = 0; i < 4; i++) {
				printf("%d haz: %d pont\n", i + 1, pontok[i]);
			}
		}
		else if (valasztas == 2) {
			printf("1 -> Griffendel\n");
			printf("2 -> Hollohat\n");
			printf("3 -> Hugrabug\n");
			printf("4 -> Mardekar\n");
			scanf(" %d", valasztas2);

			if (valasztas2 == 1) {
				printf("Mennyivel noveli a pontot?\n");
				scanf(" %d", &noveles);
				pontok[0] = pontok[0] + noveles;
			}
			else if (valasztas2 == 2) {
				printf("Mennyivel noveli a pontot?\n");
				scanf(" %d", &noveles);
				pontok[1] = pontok[1] + noveles;
			}
			else if (valasztas2 == 3) {
				printf("Mennyivel noveli a pontot?\n");
				scanf(" %d", &noveles);
				pontok[2] = pontok[2] + noveles;
			}
			else if (valasztas2 == 4) {
				printf("Mennyivel noveli a pontot?\n");
				scanf(" %d", &noveles);
				pontok[3] = pontok[3] + noveles;
			}
			else {
				printf("Hibas bevitel!\n");
			}
		}
		else if (valasztas == 3) {
			printf("1 -> Griffendel\n");
			printf("2 -> Hollohat\n");
			printf("3 -> Hugrabug\n");
			printf("4 -> Mardekar\n");
			scanf(" %d", valasztas2);

			if (valasztas2 == 1) {
				printf("Mennyivel csokkenti a pontot?\n");
				scanf(" %d", &csokkentes);
				pontok[0] = pontok[0] - csokkentes;
				pontok[3] = pontok[3] + csokkentes;
			}
			else if (valasztas2 == 2) {
				printf("Mennyivel csokkenti a pontot?\n");
				scanf(" %d", &csokkentes);
				pontok[1] = pontok[1] - csokkentes;
			}
			else if (valasztas2 == 3) {
				printf("Mennyivel csokkenti a pontot?\n");
				scanf(" %d", &csokkentes);
				pontok[2] = pontok[2] - csokkentes;
			}
			else if (valasztas2 == 4) {
				printf("Mennyivel csokkenti a pontot?\n");
				scanf(" %d", &csokkentes);
				pontok[3] = pontok[3] - csokkentes;
			}
			else {
				printf("Hibas bevitel!\n");
			}


		}
		else if (valasztas == 4) {
			printf("A tanevnek vege van!\n");
			break;
		}
		else {
			printf("Hibas bevitel!\n");
		}
	}
}