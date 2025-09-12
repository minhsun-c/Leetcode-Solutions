/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */
#define MID(a, b) (((a ^ b) >> 1) + (a & b))
int guess(int num);

int guessNumber(int n){
	uint left = 1, right = n;
    uint mid;
    while (left <= right) {
        mid = MID(left, right);
        switch (guess(mid)) {
            case 1:
                left = mid + 1;
                break;
            case -1:
                right = mid - 1;
                break;
            default:
                return mid;
        }
    }
    return 1;
}