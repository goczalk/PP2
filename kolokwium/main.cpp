# include "pointcloud.hpp"
# include <iostream>

using namespace std;

int main(){
	PointCloud p1(3);
	
	p1.setElement(0, Point(0.5, 0.5, 0.5));
	p1.setElement(1, Point(0.7, 0.2, 0.3));
	p1.setElement(2, Point(1.8, 0.8, 1.3));
	
	cout << p1 << endl;
	cout << p1.getSize() << endl;
	cout << p1.getMeanPoint();
	
	PointCloud p2(2);
	p2.setElement(0, Point(2.7, 3.2, 4.3));
	p2.setElement(1, Point(5.8, 2.8, 0.3));

	cout << p2 << endl;
	cout << p2.getSize() << endl;
	cout << p2.getMeanPoint();
	
	try{
		p2.setElement(2, Point(5.8, 2.8, 0.3));
	}
	catch(PointCloud_Exception& err){
		cout << err.error_message << endl;
	}
	
	PointCloud p3 = p1 + p2;
	cout << p3 << endl;
	
}

//g++ -g -Wall -pedantic -Werror main.cpp pointcloud.cpp -o pointcloud
//valgrind --leak-check=full ./pointcloud