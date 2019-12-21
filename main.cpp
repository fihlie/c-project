/*
Student Name:
Student Number:
Project Number: 5
Compile Status: [SUCCESS/FAIL]
Running Status: [SUCCESS/FAIL]
Notes: Anything you want to say about your code that will be helpful in the grading process.
*/
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
void parseInput(ifstream& inFile,int &  N,int &  M, vector<int>& v);
vector<long long int>calculate(vector<long long int>v,int M,int N);
vector<long long int> convertVector(vector<int> v);
int main(int argc, char* argv[]){
    ifstream inFile(argv[1]);
    ofstream outFile(argv[2]);
    int N,M;
    vector<int> v(200001,0);
    parseInput(inFile,N,M,v);
    vector<long long int> newVersion;
    newVersion=convertVector(v);
    vector<long long int> finalVersion;
    finalVersion=calculate(newVersion,M,N);
    for(int i=0;i<N;i++){
        outFile<<finalVersion[i]<<" ";
    }
    return 0;
}//Reading from a file and Bucket sort
void parseInput(ifstream& inFile,int &  N,int &  M, vector<int>& v) {
    string line, tmp;
    getline(inFile, line);
    istringstream linestream(line);
    getline(linestream, tmp, ' ');
    N = stoi(tmp);
    getline(linestream, tmp, ' ');
    M = stoi(tmp);
    getline(inFile, line);
    int a;
    istringstream linestream2(line);
    for (int i = 0; i < N; i++) {
        linestream2 >> tmp;
        a = stoi(tmp);
        v[a] = v[a] + 1;
    }
    inFile.close();
}

vector<long long int> convertVector(vector<int> v){
    vector<long long int> temp;
    int count=0;
    for(int i=0;i<v.size();i++){
        if(v[i]!=0){
            count++;
            if(count==1){
                temp.push_back(i);
            }
            else{
                temp.push_back(temp[count-2]+i);
            }
            if(v[i]>1){
                v[i]--;
                i--;
            }
        }

    }
    return temp;
}
vector<long long int>calculate(vector<long long int>v,int M,int N){
    vector<long long int> temp;
    for(int i=0;i<N;i++){
        if(i<M){
            temp.push_back(v[i]);
        }
        else{
            temp.push_back(v[i]+temp[i-M]);
        }
    }
    return temp;
}
