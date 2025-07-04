class Solution {
public:
    string countOfAtoms(string formula) {
        stack<unordered_map<string, int>> stt;
        int n = formula.size();
        stt.push({});
        int i=0;
        while(i<n) {
            if (formula[i] == '(') {
                stt.push({});
                i++;
            } else if (formula[i] == ')') {
                unordered_map<string, int> top = stt.top();
                stt.pop();
                i++;
                int start = i;
                while (i < n && isdigit(formula[i])) {
                    i++;
                }
                int multiplier = start < i ? stoi(formula.substr(start, i - start)) : 1;
                for (auto kv : top) {
                    stt.top()[kv.first] += kv.second * multiplier;
                }
            } 
            else {
                int start = i;
                i++;
                while (i < n && islower(formula[i])) {
                    i++;
                }
                string element = formula.substr(start, i - start);
                start = i;
                while (i < n && isdigit(formula[i])) {
                    i++;
                }
                int count = start < i ? stoi(formula.substr(start, i - start)) : 1;
                stt.top()[element] += count;
            }
        }
        unordered_map<string , int> result = stt.top();
        vector<string> elements;
        for (auto& kv : result) {
            elements.push_back(kv.first);
        }
        sort(elements.begin(), elements.end());
        string res;
        for (auto element : elements) {
            res += element;
            if (result[element] > 1) {
                res += to_string(result[element]);
            }
        }
        return res;

        // unordered_map<string , int> hash;
        // int n=formula.size();
        // string temp="";
        // for(int i=0 ; i<n ; i++){
        //     int index=formula[i];
        //     if(index>64 && index<91){
        //         int index2=formula[i+1];
        //         temp+=formula[i];
        //         if(i==n-1){
        //             hash[temp]=1;
        //             continue;
        //         }
        //         if(index2>96 && index2<113 ){

        //             temp+=formula[i+1];
        //             i++;
        //             continue;
        //         }
        //         if(index2>46 && index2<58){
        //         index2-=48;    //convert them into actual number 1-9
        //         if(hash.find(temp)!=hash.end()){
        //             hash[temp]=hash[temp]*index2;
        //         }
        //         else hash[temp]=index2;
        //         temp="";
        //     }
        //     }

        // }
        // for(auto it: hash){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        // return "xyz";
    }
};
