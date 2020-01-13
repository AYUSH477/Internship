#include <iostream>
#include <cmath>
#include <sstream>
#include <fstream>
#include "Kd_tree.h"
using namespace std;
const int d = 3;
double dist(const Point& p1, const Point& p2){ // calculates cartesian distance ()
            double sum = 0.0;
            for(int  i = 0; i<p1.d; i++){
                sum+=pow(p1.co_ordinates[i]-p2.co_ordinates[i],2);
            }
            return sum;
}

int main()
{
	std::stringstream ss, ss1, ss2;
	std::string s, s1, s2;
	double sum[3] = {0.0};
	typedef std::aligned_storage<sizeof(Point), std::alignment_of<Point>::value>::type storage_type;
	int n;
	ifstream fa, fb, fc, f_org;
	Point point1(d);
	Point point2(d);
	Point point3(d);
	std::ofstream oa("output/output1.txt", std::ofstream::out);
	std::ofstream ob("output/output2.txt", std::ofstream::out);
	std::ofstream oc("output/output3.txt", std::ofstream::out);
	
    fa.open("input/Car_XYZI_decompressed_ASCII_A.ply");
	fb.open("input/Car_XYZI_decompressed_ASCII_B.ply");
	fc.open("input/Car_XYZI_decompressed_ASCII_C.ply");
	f_org.open("input/Car_XYZI_uncompressed_ASCII.ply");
    if (!fa.is_open() || !fb.is_open() || !fc.is_open() || !f_org.is_open()) {
        cout << "Unable to open file/s"<<std::endl;
        //exit(1); 
    }
	while(std::getline(f_org, s)){
		ss.str("");
		ss<<s;
		ss>>s1;
		ss>>s2;
		if(!s1.compare("element") && !s2.compare("vertex")){
			ss>>n;
			}
		if(s1.compare("end_header")==0){
			break;
			
		}
		ss.clear();
	}
	int offset = f_org.tellg();
		Point *p = reinterpret_cast<Point*>(new storage_type[n]);
		for(size_t i = 0; i < n; i++){
			new (p+i) Point(d);
		}
		for(int i = 0; i<n; i++){
			std::getline(f_org,s);
			ss.str("");
			ss<<s;
			for(int j = 0; j<d; j++){
				ss>>p[i].co_ordinates[j];
			}
			ss.clear();
		}
		f_org.close();
		try
		{
			Kd_implementation k_tree(p, n, d);
			fa.seekg(offset, ios::beg);
			fb.seekg(offset, ios::beg);
			fc.seekg(offset, ios::beg);
			for(int i = 0; i<n; i++){
				std::getline(fa,s);
				std::getline(fb,s1);
				std::getline(fc,s2);
				ss.str("");
				ss1.str("");
				ss2.str("");
				ss<<s;
				ss1<<s1;
				ss2<<s2;
				for(int j = 0; j<d; j++){
					ss>>point1.co_ordinates[j];
					ss1>>point2.co_ordinates[j];
					ss2>>point3.co_ordinates[j];
					
				}
				Point temp_p = k_tree.find_nearest(point1, 0, k_tree.getRoot());
				sum[0]+=dist(point1, temp_p);
				oa<<point1<<temp_p<<dist(point1, temp_p)<<std::endl;
				temp_p = k_tree.find_nearest(point2, 0, k_tree.getRoot());
				sum[1]+=dist(point2, temp_p);
				ob<<point2<<temp_p<<dist(point2, temp_p)<<std::endl;
				temp_p = k_tree.find_nearest(point2, 0, k_tree.getRoot());
				sum[2]+=dist(point3, temp_p);
				oc<<point3<<temp_p<<dist(point3, temp_p)<<std::endl;
				ss.clear();
				ss1.clear();
				ss2.clear();
			}
			for(int i = 0; i<3; i++){
				std::cout<<"Mean error for input"<<i<<" "<<sum[i]/n<<std::endl;
				
				
				}
			
		}
		catch (const std::exception& e){
			std::cerr << e.what() << std::endl;;
		}
		catch (string msg){
			std:: cerr << msg<<std::endl;
			
			}
		oa.close();
		ob.close();
		oc.close();
		delete [] point1.co_ordinates;
		delete [] point2.co_ordinates;
		delete [] point3.co_ordinates;
		return 0;
		
	
	
	}