# include "pointcloud.hpp"
# include <iostream>

PointCloud::PointCloud(int a){
	size = a;
	wsk = new Point[a]();
}

PointCloud::~PointCloud(){
	delete[] wsk;
}

int PointCloud::getSize(){
	return size;
}

void PointCloud::setElement(int i, Point p){
	if (i >= size)
		throw PointCloud_Exception("out of range");
	wsk[i] = p;
}

Point PointCloud::getMeanPoint(){
	int i;
	double x_av=0, y_av=0, z_av=0;
	
	for(i=0; i < size; i++){
		x_av += wsk[i].x;
		y_av += wsk[i].y;
		z_av += wsk[i].z;
	}
	
	x_av /= size;
	y_av /= size;
	z_av /= size;

	return Point(x_av, y_av, z_av);
}

std::ostream& operator << (std::ostream& s, PointCloud const &P){
	int i;

	for(i=0; i < P.size; i++){ 
		s << "Dane Punktu o indeksie " << i << ":" << std::endl;
		s << P.wsk[i] << std::endl;
	}
	
	return s;
}

std::ostream& operator << (std::ostream& s, Point const &P){
	s << "x: " << P.x << ", y: " << P.y << ", z: " << P.z << std::endl;
	return s;
}

PointCloud operator + (PointCloud const &A, PointCloud const &B){
	PointCloud P(A.size + B.size);
	
	int i=0, j;
	
	for(j = 0; j < A.size; j++){
		P.setElement(i, A.wsk[j]);
		i++;
	}
	
	for(j = 0; j < B.size; j++){
		P.setElement(i, B.wsk[j]);
		i++;
	}
	
	return P;
}
