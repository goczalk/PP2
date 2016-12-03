# include <iostream>

#ifndef matrix_hpp
#define matrix_hpp

class Matrix{
	private:
		int size_row, size_col;
		struct matrix_s;
		matrix_s* array;
		class RefMatrix;
		
		void read_matrix_size(const char*);
		void write_matrix_from_file(const char* file_name);

	public:
	
		//kontruktory
		Matrix(int, int);
		Matrix(const char * file_name);
		~Matrix();
		//kopiujacy
		Matrix(const Matrix &);
		
		//funkcyjne
		void check_range(int, int) const;
		double get_value(int, int) const;
		void set_value(double, int, int);
		void check_sizes(const Matrix &);
		
		//operatory
		bool operator == (const Matrix &);
		Matrix& operator = (const Matrix &);
		
		//operatory dostepu
		double operator()(int, int) const;
		RefMatrix operator()(int, int);
		
		//operatory arytmetyczne
		
		Matrix& operator += (const Matrix &);
		Matrix& operator -= (const Matrix &);
		Matrix& operator *= (const Matrix &);
		Matrix& operator *= (const double c);
		
		Matrix operator + (const Matrix&) const; //nie musza byc friend bo nie dodajemy liczby z lewej
		Matrix operator - (const Matrix&) const;
		Matrix operator * (const Matrix&) const;
		Matrix operator * (const double) const;
		
		
		//zaprzyjaznione
		friend std::ostream & operator <<( std::ostream &, const Matrix &);
		friend Matrix operator * (const double, const Matrix&);
};

struct Matrix::matrix_s{
	
	private:
		int row_s, col_s; //size of array
		
		double** matrix_alloc();
		void matrix_free();
	
	public:
		int n; //reference counter
		double** wsk; //pointer to 2d array
		
		matrix_s(int, int);
		matrix_s(int, int, double**);
		~matrix_s();
		
		matrix_s* detach();
};

//do referencji
class Matrix::RefMatrix{
	private:
		friend class Matrix;
		Matrix& matrix_r;
		int row_r;
		int col_r;
		RefMatrix(int, int, Matrix&);
	
	public:
		operator double() const;
		RefMatrix& operator = (double value);
		RefMatrix& operator = (const RefMatrix& ref);

	
};

//do bledow
namespace MatrixException{

	class Exception{
		public:
			const char * error_message;
			Exception(const char * error) : error_message(error){}
	};

	class bad_size_of_matrixes : public Exception{
		public:
			bad_size_of_matrixes(const char * error = "err: bad size of matrixes") : Exception(error){}
	};
	
	class matrix_is_not_quadratic : public Exception{
		public:
			matrix_is_not_quadratic(const char * error = "err: matrix is not quadratic") : Exception(error){}
	};
	
	class index_out_of_range : public Exception{
		public:
			index_out_of_range(const char * error = "err: index out of range") : Exception(error){}
	};
	
	class file_open_failed : public Exception{
		public:
			file_open_failed(const char * error = "err: file open failed") : Exception(error){}
	};
	
	class matrix_size_cannot_be_negative : public Exception{
		public:
			matrix_size_cannot_be_negative(const char * error = "err: matrix size cannot be negative") : Exception(error){}
	};
	
}

#endif

//kopiujacy:
//Matrix B = A;
//przypisania:
//Matrix B; B = A;