class Solution {
public:
    int romanToInt(string s) {
       int n=s.length();
       unordered_map <string, int> hashmap;

        for(int i=0;i<n;i++){
            if((i<n-1) && ((s[i]== 'I' && (s[i+1]=='V' || s[i+1]=='X')) || (s[i]=='X' && (s[i+1]== 'L'||s[i+1]=='C')) || (s[i]=='C' && (s[i+1]=='D' || s[i+1]=='M')))){
                string exp="";
                exp+=s[i];
                exp+=s[i+1];
                i++;
                hashmap[exp]++;
                continue;
            }
            string exp="";
            exp+=s[i];
            hashmap[exp]++;
        }

        int sum=0;

        for(auto& pair:hashmap){
            if(pair.first=="CM"){
                sum+=900*pair.second;
            }
            else if(pair.first=="CD"){
                sum+=400*pair.second;
            }
            else if(pair.first=="XC"){
                sum+=90*pair.second;
            }
            else if(pair.first=="XL"){
                sum+=40*pair.second;
            }
            else if(pair.first=="IX"){
                sum+=9*pair.second;
            }
            else if(pair.first=="IV"){
                sum+=4*pair.second;
            }
            else if(pair.first=="M"){
                sum+=1000*pair.second;
            }
            else if(pair.first=="D"){
                sum+=500*pair.second;
            }
            else if(pair.first=="C"){
                sum+=100*pair.second;
            }
            else if(pair.first=="L"){
                sum+=50*pair.second;
            }
            else if(pair.first=="X"){
                sum+=10*pair.second;
            }
            else if(pair.first=="V"){
                sum+=5*pair.second;
            }
            else if(pair.first=="I"){
                sum+=1*pair.second;
            }
        }

        return sum;
    }
};