/*2. Napisac w jezyku C program obliczajacy wyznacznik macierzy
o dowolnym rozmiarze. Macierz powinna byc wczytywana z pliku tekstowego
o nastepujacej strukturze:

N
a11 a12 .. a1n
a21 a22 .. a2n
....................
an1 an2 .. ann*/

#include <stdio.h>
#include <stdlib.h>

double det(double ** matrix, int n);
double** matrix_alloc(int n);
void matrix_free(double ** matrix, int n);
int read_matrix_size(char* file_name);
void write_matrix_from_file(char* file_name, double ** matrix, int n);

int main(int argc, char **argv){

	int n = read_matrix_size(argv[1]);
	double ** macierz = matrix_alloc(n);
    write_matrix_from_file(argv[1], macierz, n);

    //wyswietl macierz
	int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("%lf \t", macierz[i][j]);
        }
        printf("\n");
    };

    double wyzn=0.0;
    wyzn = det(macierz, n);

    printf("Wyznacznik to %lf.", wyzn);

    matrix_free(macierz, n);

    return 0;
}

int read_matrix_size(char* file_name){
	FILE *f;
	int n;

    f = fopen(file_name, "rb");

	if(!f){
		printf("Blad otwierania pliku.");
		return 0;
    };

    fscanf(f, "%d", &n);
    printf("Wielkosc macierzy to %d.\n", n);
	
	fclose(f);
	return n;
}

void write_matrix_from_file(char* file_name, double ** matrix, int n){
	FILE *f;

    f = fopen(file_name, "rb");

    if(!f){
		printf("Blad otwierania pliku.");
		exit(1);
    };

	fseek(f, 1, 0);

    double temp;
    int i, j;
    for(i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            fscanf(f, "%lf", &temp);
            matrix[i][j] = temp;
        };
    };

	fclose(f);
}

double** matrix_alloc(int n){
    double** matrix;
    // i wiersz, j kolumna
    int i;

    matrix=(double**)malloc(n*sizeof(double*));
    for(i = 0; i < n; i++){
        matrix[i]=(double*)malloc(n*sizeof(double));
    };
    return matrix;
}

void matrix_free(double ** matrix, int n){
    int i;
    for(i = 0; i < n; i++){
        free(matrix[i]);
        };
    free(matrix);
}

//rekurencyjnie
double det(double ** matrix, int n){
    double** minor;
    double sum=0.0;
    double sign=1.0;
    int j, k, l;

    if(n == 1){
        return matrix[0][0];
    }

    if(n == 2){
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }

    //zaalokuj minor
    minor = matrix_alloc(n-1);

    //kopiuj odpowiedni minor
    for(j = 0; j < n; j++){
        //n-1 bo masz mniejsza macierz!
        for(k = 0; k < n-1; k++){
            //do j
            for (l = 0; l < j; l++){
                minor[k][l] = matrix[k+1][l];
            };
            //pomin j; od j; < n bo jedziesz do konca duzej macierzy
            for(l = j+1; l < n; l++){
                minor[k][l-1] = matrix[k+1][l];
            };
        };
        sum += sign * matrix[0][j] * det(minor, n-1);
        //na przemian
        sign = - sign;
    };

    matrix_free(minor, n-1);
    return sum;
}
