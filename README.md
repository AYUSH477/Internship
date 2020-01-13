# Internship Project

Kd tree implementation and Analysis of Cloud Points

## Data-Analysis questions

### How do the three Compressions rank in terms of similarity to the uncompresssed cloud point data-set?
  1. Compression-2 (Both qualitative and quantitative)
  2. Compression-1 (Both qualitative and quantitative)
  3. Compression-3 (Both qualitative and quantitative)

### How did you chose the figure of merit to do the ranking?
 The data ranking was done based on three factors:
  1. Mean
  2. Median
  3. Standard deviation of the errors in cartesian distance 
  
 Small mean and a small median along with a small standard deviation meant a good ranking of the compression
 data. Compression 2 had the smallest mean, smallest median, and also the smallest standard deviation making it most comparable 
 and similar to the original data-set Compression 3 had the largest mean, and the largest median making it the worst data-set.
 It is important to notice that standard deviation is only valid if the mean data is small as well.



## Algorithm Analysis questions
### Why did you the design the code the way you did?
#### The time complexity of the code is O(nlogn) and the space complexity is O(n) (given that we are dealing with data with not very large dimensions) 
A brute force approach would have given a O(n^2) time complexity. Thus, for large data with reasonable dimensions, 
my approach is bound to be significantly faster and more efficient that the brute-force approach.
### Why did you choose these algorithms and What choices you made to make sure the code runs efficiently, fast, with as few and possible CPU and RAM resources?
Well, the most important choice of the algorithmic design was that of the container. I designed a K-d tree, which helped me to reduce the time complexity to nlogn. Search of the closest neighbor took place in logarithmic time and design of the tree took nlogn time.

The other important choice was the selection of quick-select method to find the median. My initial idea was to first sort the array/sub-array and then find the median. However, quick select is far more efficient since it calculates the median in linear time and also divides the array into two halves: smaller and larger halve(wrt the median)s, which makes it easier to design the tree.

There was not much to be done to reduce the space complexity. However, I made sure the classes and containers that I used were intuitive and easy to understand

The code is extensible to larger dimensions of data. However, the space complexity will rise with the dimensions i.e O(n*d)

THANK YOU!!!

