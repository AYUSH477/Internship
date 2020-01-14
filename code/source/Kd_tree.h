#ifndef KDTREE
#define KDTREE

/*Point class to describe and operate on Cloud Points*/
class Point{
	public:
		Point* left; // left child of the cloud point (necessary for kd tree implementation)
		Point*right; // right child of the cloud point (necessary for kd tree implementation)
		double *co_ordinates;
		int d;
		Point(const Point& p){ //copy constructor
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
		friend double cartesian_dist(const Point* p1, const Point& p2); // calculates cartesian distance
		friend std::ostream& operator<<(std::ostream& os, const Point& p); // overloading <<
    
};


/*Implementation of kd_tree*/
class Kd_implementation{
    private:
        int dim; // dimension of the tree
        size_t tree_size; // size of the tree
        Point* l; // list of all the points in the tree
		double val; // stores the distance of the nearest neighbor of the last neighbor call point by the user
		Point* val_ptr; // stores the nearest neighbor of the last neighbor call point
		Point* root;  // root of the tree
        typedef struct Comp{
            int index;
			Comp(int i):index(i){ // struct Comparator to compare the x, y, or z co-ordinates depending upon which axis it is
				
				
				}
            bool operator()(const Point& p1, const Point& p2){
                return p1.co_ordinates[index]<p2.co_ordinates[index];
                
            }
    
        }C;
        
        Point *kd_tree(int start, int end, int s_axis); // creates the tree
		Point nearest_neighbor(const Point& p, int s_axis, Point* p1); // finds the nearest neighbor
        void Reset(); // resets val and val_ptr
        
    public:
       Kd_implementation(Point* p, size_t size, int dim=3); // initializes the class
	   Point find_nearest(const Point& p, int s_axis, Point* p1); // resets val and calls the nearest neighbor method
	   void Print(Point *p); //prints the tree
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
