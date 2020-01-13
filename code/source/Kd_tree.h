#ifndef KDTREE
#define KDTREE

class Point{
	public:
		Point* left;
		Point*right;
		double *co_ordinates;
		int d;
		Point(const Point& p){
			this->d = p.d;
			this->left= p.left ;
			this->right = p.right;
			this->co_ordinates = new double[p.d];
			for(int i = 0; i<p.d; i++)
				this->co_ordinates[i] = p.co_ordinates[i];
			}
		Point():d(3){
			co_ordinates = new double[d];
			left = nullptr;
			right = nullptr;
		}
		Point(int dim): d(dim){
			co_ordinates = new double[dim];
			left = nullptr;
			right = nullptr;
		}
		friend double cartesian_dist(const Point* p1, const Point& p2);
		friend std::ostream& operator<<(std::ostream& os, const Point& p);
    
};



class Kd_implementation{
    private:
        int dim;
        size_t tree_size;
        Point* l;
		double val;
		Point* val_ptr;
		Point* root;
        typedef struct Comp{
            int index;
			Comp(int i):index(i){
				
				
				}
            bool operator()(const Point& p1, const Point& p2){
                return p1.co_ordinates[index]<p2.co_ordinates[index];
                
            }
    
        }C;
        
        Point *kd_tree(int start, int end, int s_axis);
		Point nearest_neighbor(const Point& p, int s_axis, Point* p1);
        void Reset();
        
    public:
       Kd_implementation(Point* p, size_t size, int dim=3);
	   Point find_nearest(const Point& p, int s_axis, Point* p1);
	   void Print(Point *p);
	   Point* getRoot() const{
		   return root;
		   }
      ~Kd_implementation(){
        for(int i = 0; i<tree_size; i++)
            delete [] l[i].co_ordinates;
        delete [] l;
        
    }
	
};


#endif
