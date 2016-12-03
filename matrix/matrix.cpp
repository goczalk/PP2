# include <stdio.h>
# include <stdlib.h>
# include <iostream>

# include "matrix.hpp"

// konstruktory
Matrix::Matrix(int row, int col){
	if ( row < 0 || col < 0){
		throw MatrixException::matrix_size_cannot_be_negative();
	}
	
	size_row = row;
	size_col = col;
	array = new matrix_s(size_row, size_col);
}

Matrix::Matrix(const char * file_name){
	read_matrix_size(file_name);
	array = new matrix_s(size_row, size_col);
	write_matrix_from_file(file_name);
}

void Matrix::read_matrix_size(const char* file_name){
	FILE *f;
	int row, col;

    f = fopen(file_name, "rb");

	if(!f)
		throw MatrixException::file_open_failed();

    fscanf(f, "%d", &row);
	fscanf(f, "%d", &col);
	size_row = row;
	size_col = col;

	std::cout << "Wielkosc macierzy z pliku to " << row << " na " << col << std::endl;
	fclose(f);
}

void Matrix::write_matrix_from_file(const char* file_name){
	FILE *f;

    f = fopen(file_name, "rb");
	
	//wyjatek
    if(!f)
		throw MatrixException::file_open_failed();

	fseek(f, 3, 0);

    double temp;
    int i, j;
    for(i = 0; i < size_row; i++){
        for (j = 0; j < size_col; j++){
            fscanf(f, "%lf", &temp);
            array->wsk[i][j] = temp;
        };
    };

	fclose(f);
}

Matrix::~Matrix(){
	//std::cout << "Obiekt Matrix niszczony.";
	if(--array -> n == 0){
		delete array;
	}
}

//kopiujacy
//referencja zeby uniknac narzutu kopiowania
Matrix::Matrix(const Matrix& m){
	m.array -> n++;
	size_row = m.size_row;
	size_col = m.size_col;
	array = m.array;
}


//operatory
bool Matrix::operator == (const Matrix & m){
	if (this == &m){
		return true;
	}
	if ( (size_row != m.size_row) || (size_col != m.size_col)){
		return false;
	}
	//porownanie kazdego elementu	
	else{
		int i, j;
		for(i = 0; i < size_row; i++){
		    for(j = 0; j < size_col; j++){
		        if ( array->wsk[i][j] != m.array->wsk[i][j] ){
				return false;
				}
		    }
		};
	}
	return true;
}

Matrix& Matrix::operator = (const Matrix &m){
	m.array -> n++;
	if ( --array->n == 0)
		delete array;
	size_row = m.size_row;
	size_col = m.size_col;
	array = m.array;
	return *this;
}


//operatory dostepu
double Matrix::operator()(int row, int col) const{
	check_range(row, col);
	return get_value(row, col);
}

Matrix::RefMatrix Matrix::operator()(int row, int col){
	check_range(row, col);
	return RefMatrix(row, col, *this);
}

//operatory arytmetyczne
Matrix& Matrix::operator += (const Matrix & m){
	check_sizes(m);
	matrix_s* newarray = array->detach();
	
	array = newarray;
	int i, j;
    for(i = 0; i < size_row; i++){
        for (j = 0; j < size_col; j++){
            array->wsk[i][j] += m.array->wsk[i][j];
        };
    };
	return *this;
}

Matrix Matrix::operator + (const Matrix& m) const{
	Matrix M (*this);
	return M += m;
}


Matrix& Matrix::operator -= (const Matrix & m){
	check_sizes(m);
	matrix_s* newarray = array->detach();
	
	array = newarray;
	int i, j;
    for(i = 0; i < size_row; i++){
        for (j = 0; j < size_col; j++){
            array->wsk[i][j] -= m.array->wsk[i][j];
        };
    };
	return *this;
}

Matrix Matrix::operator - (const Matrix& m) const{
	Matrix M (*this);
	return M -= m;
}


Matrix Matrix::operator * (const Matrix& m) const{
	if (size_row != m.size_col || size_col != m.size_row){
		throw MatrixException::bad_size_of_matrixes();
	}
	Matrix M (size_row, m.size_col);
	
	int i, j, k;
    for(i = 0; i < M.size_row; i++){
        for (j = 0; j < M.size_col; j++){
			for (k = 0; k < m.size_row; k++){
				M.array->wsk[i][j] += array->wsk[i][k] * m.array->wsk[k][j];
			}
		}
    }
	return M;
}

Matrix& Matrix::operator *= (const Matrix & m){ 
	if (size_row != size_col || m.size_row != size_row || m.size_col != size_col ){
		throw MatrixException::matrix_is_not_quadratic();
	}

	matrix_s* newarray = array->detach();
	array = newarray;
	
	matrix_s* temp = new matrix_s(size_row, size_col, array->wsk);
	
	int i, j, k;
    for(i = 0; i < size_row; i++){
        for (j = 0; j < size_col; j++){
			for (k = 0; k < m.size_row; k++){
				array->wsk[i][j] += temp->wsk[i][k] * m.array->wsk[k][j];
			}
		}
    }
	
	delete temp;
	return *this;
}

//przez stala
Matrix Matrix::operator * (const double c) const{
	Matrix M(*this);
	int i, j;
    for(i = 0; i < M.size_row; i++){
        for (j = 0; j < M.size_col; j++){
            M.array->wsk[i][j] *= c;
        };
    };
	return M;
}

Matrix operator * (const double c, const Matrix& m){
	return (m * c);
}

Matrix& Matrix::operator *= (const double c){ 
	matrix_s* newarray = array->detach();
	array = newarray;

	int i, j;
    for(i = 0; i < size_row; i++){
        for (j = 0; j < size_col; j++){
            array->wsk[i][j] *= c;
        };
    };
	
	return *this;
}

// funkcyjne
void Matrix::check_range(int row, int col) const{
	if (row >= size_row || col >= size_col)
		throw MatrixException::index_out_of_range();
}

double Matrix::get_value(int row, int col) const{
	return array->wsk[row][col];
}

void Matrix::set_value(double value, int row, int col){
	matrix_s* newarray = array->detach();
	array = newarray;
	array->wsk[row][col] = value;
}

void Matrix::check_sizes(const Matrix & m){
	if (size_row != m.size_row || size_col != m.size_col)
		throw MatrixException::bad_size_of_matrixes();
}

// std::cout
std::ostream & operator <<( std::ostream & s, const Matrix & m){
	int i, j;
    for(i = 0; i < m.size_row; i++){
        for(j = 0; j < m.size_col; j++){
            //s << m.array->wsk[i][j] << "\t";
			s << m(i, j) << "\t";
        }
        s << std::endl;
    };
	return s;
}

//*********************************************************
// matrix_s

double** Matrix::matrix_s::matrix_alloc(){
    double** matrix;
    int i;
	
	matrix = new double*[row_s];
    for(i = 0; i < row_s; i++){
		matrix[i] = new double[col_s](); //new int() <- initialization to 0
	};
    return matrix;
}

void Matrix::matrix_s::matrix_free(){
    int i;
    for(i = 0; i < row_s; i++){
        delete [] wsk[i];
    };
    delete [] wsk;
}

Matrix::matrix_s::matrix_s(int row, int col){
	n = 1;
	row_s = row;
	col_s = col;
	wsk = matrix_alloc();
}

Matrix::matrix_s::matrix_s(int row, int col, double** source){
	n = 1;
	row_s = row;
	col_s = col;
	wsk = matrix_alloc();
	
	//przepisuje dane
	int i, j;
    for(i = 0; i < row_s; i++){
        for (j = 0; j < col_s; j++){
            wsk[i][j] += source[i][j];
        };
    };
	
}

Matrix::matrix_s::~matrix_s(){
	matrix_free();
}

Matrix::matrix_s* Matrix::matrix_s::detach(){
	if(n == 1){
		return this;
	}
	matrix_s* copy = new matrix_s(row_s, col_s, wsk);
	n--;
	return copy;
}



//*********************************************************
// RefMatrix


Matrix::RefMatrix::RefMatrix(int row, int col, Matrix& m) :
	matrix_r(m) //not initialization
{
	row_r = row;
	col_r = col;
}

Matrix::RefMatrix::operator double() const{
	return matrix_r.get_value(row_r, col_r);
}

Matrix::RefMatrix& Matrix::RefMatrix::operator = (double value){
	matrix_r.set_value(value, row_r, col_r);
	return *this;
}
		
Matrix::RefMatrix& Matrix::RefMatrix::operator = (const RefMatrix& ref){
	return operator = ((double)ref);
}
		
		
