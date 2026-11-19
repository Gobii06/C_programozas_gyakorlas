#include <stdio.h>

int Beker(int min, int max, int sorszam);

void ido();

int main() {

	ido();

	return 0;
}

int Beker(int min, int max, int sorszam) {
	int szam = 0;

	do {

		printf("Adjon meg az %d. szamot ami %d es %d intervallumba esik!\n",sorszam, min, max);
		scanf(" %d", &szam);

		if (szam < min || szam > max) {
			printf("A szam az intervallumon kivul van!\n");
		}

	} while (szam < min || szam > max);
	return szam;
}

void ido() {
	int napi_ido[7];
	int legtobb = 0;
	int nap_sorszam = 0;
	double osszeg = 0;
	double atlag = 0;
	double konyv = 0;

	for (int i = 0; i < 7; i++) {
		napi_ido[i] = Beker(1, 24, i + 1);

		if (napi_ido[i] > legtobb) {
			legtobb = napi_ido[i];
			nap_sorszam = i + 1;
		}

		osszeg = osszeg + napi_ido[i];
	}

	atlag = osszeg / 7;
	
	konyv = osszeg / 14.5;

	printf("%d. napon volt a leghatekonyabb, %d orat nyert!\n", nap_sorszam, legtobb);
	printf("%.2f oraval gazdagodott a het atlagosan!\n", atlag);
	printf("Hermione %.2f konyvet olvasott el a heten a nyert idobol!\n", konyv);
}