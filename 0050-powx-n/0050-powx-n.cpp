class Solution {
public:

    double calc( double x, int n) {
        if( n == 0 ) {
            return 1;
        }
        if( n == 1 ) {
            return x;
        }
        if( n%2 == 0 ) {
            return calc( x*x , n/2 );
        }
        else{
            return x*calc( x*x, n/2);
        }
    }

    double myPow(double x, int n) {
      if( n < 0 ) 
          return 1.00/calc( x, n );

        return calc( x, n );
      
    }
};
