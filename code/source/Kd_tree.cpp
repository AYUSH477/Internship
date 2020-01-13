#include <iostream>
#include <cmath>
#include <cstring>
#include <limits>
#include <algorithm>
#include "Kd_tree.h"
/*Recursive creation of a k_d tree*/
Point* Kd_implementation::kd_tree(int start, int end, int s_axis)
{
			if(start>=end){
				return nullptr;
				
			}
			
            int x = ((end-start)/2)+start; //finds median position
	    std::nth_element(&l[start], &l[x], &l[end], C(s_axis)); //finds the median wrt to an axis and also makes sure that all the 
								   //elements before are smaller than the median wrt to tha axis and after
								  // are greater than the median wrt to that axis
            s_axis = (s_axis+1)%dim; //switches to adjacent axis
	    l[x].left = kd_tree(start, x, s_axis); // recursive call for left sub-tree
            l[x].right = kd_tree(x+1, end, s_axis); // recursive call for right sub-tree
            return &l[x];
            
}
/*operator overloading for printing the Point Clouds*/
std::ostream& operator<<(std::ostream& os, const Point& p)
{
	for(int i = 0; i<p.d; i++){
		os << p.co_ordinates[i]	<< " ";
		}
    
    return os;
}

void Kd_implementation:: Print(Point *p){ // a non-fancy method to print the tree 
	if(p==nullptr){
		return;
		
	}
	Print(p->left);
	std::cout<<*p<<std::endl;
	Print(p->right);
	
	
	}
void Kd_implementation:: Reset(){ // important to reset these values while finding nearest neighbor
	val = std::numeric_limits<double>::infinity();
	val_ptr = nullptr;
	
	
	}
double cartesian_dist(const Point* p1, const Point& p2){ // calculates cartesian distance between the two points
            double sum = 0.0;
            for(int  i = 0; i<p1->d; i++){
                sum+=pow((p1->co_ordinates[i]-p2.co_ordinates[i]),2);
            }
            return sum;
}

Kd_implementation::Kd_implementation(Point* p, size_t size, int d):tree_size(size){ // initializes the class and creates the tree
		dim = d;
		l = new Point[size];
                for(int i = 0; i<size; i++){
                  l[i] = p[i];
                }
		delete [] p;
                root = kd_tree(0, size, 0);
				
}


Point Kd_implementation::nearest_neighbor(const Point& p, int s_axis, Point* p1){ 
            
            if(p1 == nullptr){
		//throw("Tree is empty\n");
                return p;
	    }
	
            if(val>cartesian_dist(p1, p)){ //val stores the closest point to the given point so far
                val = cartesian_dist(p1, p);
                val_ptr = p1;
            }
	    double d = p.co_ordinates[s_axis]-p1->co_ordinates[s_axis]; 
            nearest_neighbor(p, (s_axis+1)%dim, d> 0 ? p1->right : p1->left); //goes to left or right sub-tree depending 
									     // upon the point's respective co-ordinate is larger
									   // or smaller
            if(val<=pow(d, 2))
                return *val_ptr;
            nearest_neighbor(p, (s_axis+1)%dim, d > 0 ? p1->left : p1->right);
            return *val_ptr;
            
            
}
/*Public method called by the user*/
Point Kd_implementation::find_nearest(const Point& p, int s_axis, Point* p1){
	Reset();
	return nearest_neighbor(p, s_axis, p1);
	}
