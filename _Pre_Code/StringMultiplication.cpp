
#include <iostream>
#include <string>
using namespace std;



class Multiplication{
  public:
    string multiplyStrings(string s1, string s2) {

       bool negFlag1 = false, negFlag2 = false;
       if(s1[0] == '-'){
           negFlag1 = true;
           s1.erase(0,1);
       }

       if(s2[0] == '-'){
           negFlag2 = true;
           s2.erase(0,1);
       }



       string temp;
       if(s1.size()<s2.size())
       {
            temp = s1;
            s1=s2;
            s2 = temp;
       }

       string curSum = "";
       string zeros = "";
       for(int j=s2.size()-1; j>=0; j--){
           string ans = getMultiPlication(s1, s2[j]);
           ans+=zeros;
           curSum = addString(ans, curSum);
           zeros+="0";
       }

       curSum.erase(0, min(curSum.find_first_not_of('0'), curSum.size()-1));

       if(negFlag1 ^ negFlag2 && curSum != "0"){
           curSum = "-" + curSum;
       }
       return curSum;
    }

    string getMultiPlication(string s, char c){

        string ans = "";
        int p = c - '0';
        int carry = 0;
        for(int i=s.size()-1; i>=0; i--){
            int digit = s[i] - '0';
            int multiplication = digit * p;
            if(carry){
                multiplication += carry;
            }
            carry = 0;
            digit = multiplication % 10;
            carry = int(multiplication / 10);
            char nextC = digit + '0';
            ans = nextC + ans;

        }

        if(carry){
            char nextC = carry + '0';
            ans = nextC + ans;

        }

        return ans;

    }
    string addString(string s1, string s2){
        string temp;
        if(s1.size() < s2.size()){
            temp = s1;
            s1 = s2;
            s2 = temp;
        }

        bool carry = false;
        string ans = "";
        int i, j;
        for(i=s1.size()-1, j = s2.size()-1; j>=0; i--, j--){

            int sum = s1[i] + s2[j] - '0' - '0';
            if(carry){
                sum++;
            }
            carry = false;

            int digit;
            if(sum>=10){
                carry = true;
            }

            digit = sum %10;
            char c = digit + '0';
            ans = c + ans;

        }

        for(i; i>=0; i--){
            int sum = s1[i] - '0';
            if(carry){
                sum++;
            }
            carry = false;

            int digit;
            if(sum>=10){
                carry = true;
            }

            digit = sum %10;
            char c = digit + '0';
            ans = c + ans ;

        }
        if(carry){
            ans = "1" + ans;
        }

        return ans;
    }

};

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    Multiplication mult;

    string s1, s2;
    int kase = 0;
    while(cin>>s1>>s2){
        cout<<"Case "<<++kase<<": ";
        cout<<mult.multiplyStrings(s1, s2)<<endl;
        cout<<"\n\n";
    }

    return 0;
}
