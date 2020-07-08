#include <iostream>
#include <string>
using namespace std;
int main(){
    string in;
    cin >> in;

    int max_score = 1; 
    int current_score = 0;
    for (unsigned long i=0;i<in.length()-1;i++){
        if(in[i]==in[i+1]){
            current_score++;
            if (current_score>max_score){
                max_score = current_score;
            }
        }else{
            current_score = 1;
        }
    }
    cout << max_score;
}
