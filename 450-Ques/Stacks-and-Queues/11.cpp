#include<bits/stdc++.h>
using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> s;
    
    for(string x : tokens) {
        int currentCharLength = x.size();
        
        char char1 = x[0];
        
        if(currentCharLength == 1 && !isdigit(char1)) {
            int firstTop = s.top();
            s.pop();
            int secondTop = s.top();
            s.pop();
            
           if(char1 =='+') secondTop=secondTop+firstTop;
           if(char1 =='-') secondTop=secondTop-firstTop;
           if(char1 =='*') secondTop=secondTop*firstTop;
           if(char1 =='/') secondTop=secondTop/firstTop; 
            s.push(secondTop);
            
        }else{
            int newNumber = stoi(x);
            s.push(newNumber);
        }
    }
    
    return s.top();
}

int main() {
	vector<string>arr = {"2", "1", "+", "3", "*"};
	cout << evalRPN(arr) << endl;
	return 0;	
}
