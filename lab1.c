#include<stdio.h>
#include<math.h>

	double formula(double lamda_1, double lamda_2, double a_0, double a_1, int n) {
		
		double diskriminanta = lamda_1 * lamda_1 + 4 * lamda_2;
		double a, b;
		
		if(diskriminanta == 0) {
			double x = lamda_1 / 2;
			a = a_0;
			b = a_1 / x - a;
			return pow(x, n) * (a + n * b);
		}
		
		double x_1 = (lamda_1 + sqrt(diskriminanta)) / 2;
		double x_2 = (lamda_1 - sqrt(diskriminanta)) / 2;
		
		b = (a_1 - a_0 * x_1) / (x_2 - x_1);
		a = a_0 - b;
		
		return a * pow(x_1, n) + b * pow(x_2, n);
	}

	double rekurzija(double lamda_1, double lamda_2, double a_0, double a_1, int n) {
		if (n == 0)
			return a_0;
		if (n == 1)
			return a_1;
		
		return lamda_1 * rekurzija(lamda_1, lamda_2, a_0, a_1, n - 1) + lamda_2 * rekurzija(lamda_1, lamda_2, a_0, a_1, n - 2);
	}

	int main(void) {
		
		double lamda_1, lamda_2, a_0, a_1;
		int n;
		
		//UPIS
		printf("Unesite prvi koeficijent λ_1 rekurzivne relacije: ");
		scanf("%lf", &lamda_1);
		
		printf("Unesite prvi koeficijent λ_2 rekurzivne relacije: ");
		scanf("%lf", &lamda_2);
		
		printf("Unesite vrijednost nultog clana niza a_0: ");
		scanf("%lf", &a_0);
		
		printf("Unesite vrijednost prvog clana niza a_1: ");
		scanf("%lf", &a_1);
		
		do {
			printf("Unesite redni broj n trazenog clana niza: ");
			scanf("%d", &n);
		}while(n < 0);
		
		//ISPIS
		printf("Vrijednost n-tog clana niza pomocu formule: %.1lf", formula(lamda_1, lamda_2, a_0, a_1, n));
		printf("\n");
		printf("Vrijednost n-tog clana niza iz rekurzije: %.1lf", rekurzija(lamda_1, lamda_2, a_0, a_1, n));
		
		return 0;
	}