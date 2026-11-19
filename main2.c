#include <stdio.h>

int Beker(int min, int max);

double homerseklet_beker(int min, int max, int sorszam);

void homerseklet(int min, int max);

void szamkitalalos(int min, int max);

void Bank();

int main() {

	homerseklet(-40, 50);

	szamkitalalos(1, 100);

	Bank();

	return 0;
}

//1.FELADAT

int Beker(int min, int max) {

	int szam = 0;

	do {

		printf("Gondoljon egy szamra %d es %d intervallumban!\n", min, max);
		scanf(" %d", &szam);

		if (szam < min || szam > max) {
			printf("A szam intervallumon kivul van!\n");
		}

	} while (szam < min || szam > max);

	return szam;
}

//2. FELADAT

double homerseklet_beker(int min, int max, int sorszam) {

	double ertekek;

	do {
			printf("Adja meg az %d. homersekletet %d es %d intervallumon!\n", sorszam, min, max);
			scanf(" %lf", &ertekek);

			if (ertekek < min || ertekek > max) {
				printf("Az homerseklet az intervallumon kivul van!\n");
			}

	} while (ertekek < min || ertekek > max);

	return ertekek;
}

void homerseklet(int min, int max) {

	double homersekletek[21];
	double napi_atlagok[7];
	const int seged[7] = { 0, 3, 6, 9, 12, 15, 18 }; 
	 
	double also = 0;
	double felso = 0;
	int hideg_nap = 1;
	int meleg_nap = 1;
	double osszeg = 0;
	double heti_atlag = 0;

	for (int i = 0; i < 21; i++) {
		homersekletek[i] = homerseklet_beker(min, max, i + 1);
	}

	for (int i = 0; i < 7; i++) {
		napi_atlagok[i] = (homersekletek[0 + seged[i]] + homersekletek[1 + seged[i]] + homersekletek[2 + seged[i]]) / 3;

		if (also > napi_atlagok[i]) {
			also = napi_atlagok[i];
			hideg_nap = i + 1;
		}
		else if (felso < napi_atlagok[i]) {
			felso = napi_atlagok[i];
			meleg_nap = i + 1;
		}
	}

	printf("A leghidegebb a %d. napon volt, a homerseklet %.2f fok volt\n", hideg_nap, napi_atlagok[hideg_nap - 1]);
	printf("A legmelegebb a %d. napon volt, a homerseklet %.2f fok volt\n", meleg_nap, napi_atlagok[meleg_nap - 1]);

	for (int i = 0; i < 7; i++) {
		osszeg = osszeg + napi_atlagok[i];
	}
	heti_atlag = osszeg / 7;

	if (heti_atlag < 0) {
		printf("A meresi adatok valoszinuleg telen keszultek!\n");
	}
	else if (heti_atlag >= 0 && heti_atlag < 11) {
		printf("A meresi adatok valoszinuleg osszel keszultek!\n");
	}
	else if (heti_atlag > 10 && heti_atlag < 21) {
		printf("A meresi adatok valoszinuleg tavasszal keszultek!\n");
	}
	else {
		printf("A meresi adatok valoszinuleg nyaron keszultek!\n");
	}

}

//3. FELADAT
void szamkitalalos(int min, int max) {

	int gondolt_szam = Beker(1, 100);
	int tipp = 0;
	int valasz = 0;
	int szamlalo = 1;
	int valasz2 = 0;

	printf("A te szamod: %d\n", gondolt_szam);
	tipp = (max + min)/ 2;

	while (1) {

		printf("Tippelt szam: %d\n", tipp);
		printf("Talalt?\n");
		printf("1 -> Igen\t");
		printf("2 -> Nem\t");

		scanf(" %d", &valasz);

		if (valasz == 1 && tipp == gondolt_szam) {
			printf("Yupieee eltalaltam!\n");
			break;
		}
		else if (valasz == 2) {

			printf("1 -> Kisebb\t");
			printf("2 -> Nagyobb\t");

			scanf(" %d", &valasz2);

			if (valasz2 == 1) {

			max = tipp - 1;
			szamlalo++;
			}
			else if (valasz2 == 2) {

			min = tipp + 1;
			szamlalo++;
			}
			else {
				printf("Hibas bevitel\n");
			}
		}
		else {
			printf("Hibas bevitel\n");
		}

		tipp = (max + min) / 2;
	}

	printf("%d lepesbol talaltam el!\n", szamlalo);

}

void Bank() {

	int egyenlegek[20];
	int valasztas = 0;
	int valasztas2 = 0;
	int valasztas3 = 0;
	int valasztas4 = 0;
	int sorszam = 0;
	int osszeg = 0;
	int sorszam2 = 0;
	double osszeg2 = 0;
	double osszeg3 = 0;
	int fogado = 0;
	int kuldo = 0;

	for (int i = 0; i < 20; i++) {
		egyenlegek[i] = 0;
	}

	while (1) {

		printf("\n\n");
		printf("1 -> Szamla nyitas\n");
		printf("2 -> Ugyfelek egyenlegei\n");
		printf("3 -> Befizetes / Penzfelveves\n");
		printf("4 -> Utalas\n");
		printf("5 -> Kilepes\n");

		scanf(" %d", &valasztas);

		if (valasztas == 1) {

			printf("1 -> Mindre\n");
			printf("2 -> Egyesevel\n");
			scanf(" %d", &valasztas2);

			if (valasztas2 == 1) {
				printf("Mekkora penzosszeggel nyiljanak a szamlak?\n");
				scanf(" %d", &osszeg);

				for (int i = 0; i < 20; i++) {
					egyenlegek[i] = egyenlegek[i] + osszeg;
				}
			}
			else if (valasztas2 == 2) {

				printf("Hanyadik sorszamu helyre akar szamlat nyitni?\n");
				scanf(" %d", &sorszam);
				printf("Mekkora penzosszeggel nyiljon a szamla?\n");
				scanf(" %d", &osszeg);

				egyenlegek[sorszam - 1] = egyenlegek[sorszam - 1] + osszeg;
			}
			else {
				printf("Hibas bevitel!\n");
			}

		}
		else if (valasztas == 2) {
			for (int i = 0; i < 20; i++) {
				printf("%d. ugyfel: %d Ft\n", i + 1, egyenlegek[i]);
			}
		}
		else if (valasztas == 3) {
			printf("1 -> Penzbefizetes\n");
			printf("2 -> Penzfelvetel\n");
			scanf(" %d", &valasztas3);

			if (valasztas3 == 1) {
				printf("Melyik szamlara akarsz penzt befizetni?\t(1 - 20)\n");
				scanf(" %d", &sorszam2);
				printf("Mekkora osszeget akarsz befizetni?\n");
				scanf(" %lf", &osszeg2);

				egyenlegek[sorszam2 - 1] = egyenlegek[sorszam2 - 1] + osszeg2;
			}
			else if (valasztas3 == 2) {
				printf("Melyik szamlarol akarsz penztfelvenni?\t(1 - 20)\n");
				scanf(" %d", &sorszam2);
				printf("Mekkora osszeget akarsz felvenni?\n");
				scanf(" %lf", &osszeg2);

				if (egyenlegek[sorszam2 - 1] - osszeg2 * 1.10 < 0) {
					printf("A penz felvetel sikertelen!\n");
				}
				else {
					egyenlegek[sorszam2 - 1] = egyenlegek[sorszam2 - 1] - osszeg2 * 1.10;
				}
			}
			else {
				printf("Hibas bevitel!\n");
			}
		}
		else if (valasztas == 4) {
			printf("1 -> Bankon beluli utalas\n");
			printf("2 -> Bankon kivuli utalas\n");
			scanf(" %d", &valasztas4);

			if (valasztas4 == 1) {
				printf("Melyik szamlarol akarsz utalni?\t(1 - 20)\n");
				scanf(" %d", &kuldo);
				printf("Melyik szamlara akarsz utalni?\n");
				scanf(" %d", &fogado);
				printf("Mekkora osszeget akarsz utalni?\n");
				scanf(" %lf", &osszeg3);

				if (egyenlegek[kuldo - 1] - osszeg3 < 0) {
					printf("Az utalas nem vegezheto el!\n");
				}
				else {
					egyenlegek[kuldo - 1] = egyenlegek[kuldo - 1] - osszeg3;
					egyenlegek[fogado - 1] = egyenlegek[fogado - 1] + osszeg3;
				}
			}
			else if (valasztas4 == 2) {
				printf("Melyik szamlarol akarsz utalni?\t(1 - 20)\n");
				scanf(" %d", &kuldo);
				printf("Mekkora osszeget akarsz utalni?\n");
				scanf(" %lf", &osszeg3);

				if (egyenlegek[kuldo - 1] - osszeg3 * 1.10 < 0) {
					printf("Az utalas nem vegezheto el!\n");
				}
				else {
					egyenlegek[kuldo - 1] = egyenlegek[kuldo - 1] - osszeg3 * 1.10;
				}

			}
			else {
				printf("Hibas bevitel!\n");
			}
		}
		else if (valasztas == 5) {
			printf("Viszlat");
			break;
		}
		else {
			printf("Hibas bevitel!\n");
		}
	}
}

