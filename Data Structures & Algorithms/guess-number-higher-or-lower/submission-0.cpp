/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        while(1){
            int check = guess(n/2);
            if(check == 0)return n/2 ;
            else if(check == 1)n = (n/2 + n )/2;
            else if (check == 1) n = n/4;
        }
        return 0;
    }
};