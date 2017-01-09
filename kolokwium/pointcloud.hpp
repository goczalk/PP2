# include <iostream>

# ifndef pointcloud_hpp
# define pointcloud_hpp

class Point{
	private:
		double x;
		double y;
		double z;
		
	public:
			Point(): x(0), y(0), z(0){};
			Point(double x1, double y1, double z1): x(x1), y(y1), z(z1){};
		
		friend class PointCloud;
		friend std::ostream& operator << (std::ostream& s, Point const &P);
};

class PointCloud{
	private:
		int size;
		Point* wsk; //wskaznik na poczatek tablicy Pointow
	
	public:
		PointCloud(int size);
		~PointCloud();
		int getSize();
		Point getMeanPoint();
		void setElement(int, Point);
		
		friend std::ostream& operator << (std::ostream& s, PointCloud const &P);
		friend PointCloud operator + (PointCloud const &A, PointCloud const &B); 
};

class PointCloud_Exception{
		public:
			const char * error_message;
			PointCloud_Exception(const char * err) : error_message(err){};
};

#endif