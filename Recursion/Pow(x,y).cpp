// Implement the power function pow(x, n) , which calculates the x raised to n i.e. x^n.

// Input : x = 2.0000 , n = 10
// Output : 1024.0000

// shortcut 

// some languages like c++ , java , python have built in function for calculating this 

// bruteforce method : - normal loops 
// T.C :- O(n) 
// S.C :- O(1);

class Solution {
public:
    double myPow(double x, int n) {
        //your code goes here

        if( n == 0 || x == 1.0)  return 1 ;

        if(n <0){
              
              double a = 1/pow(x , abs(n)) ;
              return a ;
        }

        double ans =1 ;
        for(int i =0 ;i< n ;i++){
              ans *= x;
        }

        return ans ;
    }
};

// optimal solution  :- using recursion 
// T.C :- O(logn)
// S.C :- O(logn)


class Solution {
public:
    
    double power(double x  , int n){
          
          if(n == 0)  return 1 ;

          if(n % 2 == 1){
               return x * power(x , n-1) ;
          }

          return power(x *x , n/2);

    }
    double myPow(double x, int n) {
        //your code goes here

        if( n == 0 || x == 1.0)  return 1 ;

        if(n <0){
              
              double a = 1/pow(x , abs(n)) ;
              return a ;
        }

        return power(x  , n );
    }
};