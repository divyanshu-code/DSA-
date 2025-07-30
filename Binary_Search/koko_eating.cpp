// given an array of bananas and a monkey has to eat all those bananas within given hours 
// we have to find that how many bananas monkey should eat per hour so that after eating  the submission of hour must equal to given hours.
// for eg :- nums = [7, 15, 6, 3], h = 8

// like if monkey eats 5 bananas per hour then its submission will be  [2 , 3, 2 , 1 ]  i.e. is 8 which is equal to h 


// Bruteforce solution : normal two loops with linear search 
// T.C :- O(m*n)           where m is no. that check for per hours and n is iterating through loops
// S.C :- O(1)

class Solution {
public:
int minimumRateToEatBananas(vector<int> nums, int h) {
 
              int i = 1;
              while(i){

                int sum =0 ;

                for(int j =0 ;j< nums.size() ;j++){
                      
                      sum += ceil( (double)nums[j] / (double)i);
                }

                if(sum == h){
                      return i ;
                }

                i++;

              }

              return -1;
    }
};


// Optimised solution  :- binary search --- important thing to find a limit for binary search 
// T.C :- O(N log(m)) where m is maximum element 
// S.C :- O(1)

class Solution {
public:

    long long sumof(vector<int>& piles, int h){
          
             long long sum =0 ;

             for(int i =0 ;i<piles.size() ;i++){
                 
                  sum+= ceil((double)piles[i] / (double)h);
             }

             return sum ;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
          int maxi = *max_element( piles.begin() , piles.end());
           
            int low =1 , high = maxi ;

            while(low<= high ){

                   int mid  = (low + high)/2 ;

                   long long a = sumof(piles , mid);

                   if(a <= h){
                       high = mid -1 ;
                   }else{
                       low= mid+1 ;
                   }
            }

            return low ;

    }
};



