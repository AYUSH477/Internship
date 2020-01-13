#include <iostream>
#include <cmath>
#include <cstring>
#include <limits>
#include <algorithm>
#include "Kd_tree.h"
Point* Kd_implementation::kd_tree(int start, int end, int s_axis)
{
			if(start>=end){
				return nullptr;
				
			}
			
            int x = ((end-start)/2)+start;
			std::nth_element(&l[start], &l[x], &l[end], C(s_axis));
            s_axis = (s_axis+1)%dim;
			l[x].left = kd_tree(start, x, s_axis);
            l[x].right = kd_tree(x+1, end, s_axis);
            return &l[x];
            
}
std::ostream& operator<<(std::ostream& os, const Point& p)
{
	for(int i = 0; i<p.d; i++){
		os << p.co_ordinates[i]	<< " ";
		}
    
    return os;
}

void Kd_implementation:: Print(Point *p){
	if(p==nullptr){
		return;
		
	}
	Print(p->left);
	std::cout<<*p<<std::endl;
	Print(p->right);
	
	
	}
void Kd_implementation:: Reset(){
	val = std::numeric_limits<double>::infinity();
	val_ptr = nullptr;
	
	
	}
double cartesian_dist(const Point* p1, const Point& p2){
            double sum = 0.0;
            for(int  i = 0; i<p1->d; i++){
                sum+=pow((p1->co_ordinates[i]-p2.co_ordinates[i]),2);
            }
            return sum;
}

Kd_implementation::Kd_implementation(Point* p, size_t size, int d):tree_size(size){
				dim = d;
				l = new Point[size];
				//list = v1;
                for(int i = 0; i<size; i++){
                  l[i] = p[i];
                }
				delete [] p;
				//l = v1;
                root = kd_tree(0, size, 0);
				
}


Point Kd_implementation::nearest_neighbor(const Point& p, int s_axis, Point* p1){ 
            
            if(p1 == nullptr){
                return p;
			}
            if(val>cartesian_dist(p1, p)){
                val = cartesian_dist(p1, p);
                val_ptr = p1;
            }
			double d = p.co_ordinates[s_axis]-p1->co_ordinates[s_axis];
            nearest_neighbor(p, (s_axis+1)%dim, d> 0 ? p1->right : p1->left);
            if(val<=pow(d, 2))
                return *val_ptr;
            nearest_neighbor(p, (s_axis+1)%dim, d > 0 ? p1->left : p1->right);
            return *val_ptr;
            
            
}

Point Kd_implementation::find_nearest(const Point& p, int s_axis, Point* p1){
	Reset();
	return nearest_neighbor(p, s_axis, p1);
	}
