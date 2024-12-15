#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

/*Permutations are a fundamental concept in computational biology 
and RNA sequence analysis. Two RNA sequences can be considered permutations
of each other if they contain the same nucleotides with the same frequencies 
but possibly in different orders. For instance, the RNA sequence (C, U, G, A) is a 
permutation of [A, U, C, G]. Write a function to determine whether two RNA sequences are 
permutations of each other. The input vectors are guaranteed to be the same size. 
Your solution must run in O(n), where n is the size of the vectors.*/

void printUnorderedMap(unordered_map<char, int> &umap) {
    for (const auto &pair : umap) {
        cout << pair.first << ": " << pair.second << endl;
    }
}

bool arePermutations(vector<char> x, vector<char> y){
    unordered_map<char, int> map;
    unordered_map<char, int> map2;
    for (char& c : x){
        if(map.find(c) != map.end()){
            map.at(c) += 1;
        } else {
            map.insert({c, 1});
        }
    }
    printUnorderedMap(map);
    for (char& d : y) {
        if(map.find(d) == map.end()){
            return false;
        } 
        else if (map2.find(d) != map2.end()) {
            map2.at(d) += 1;
        } 
        else {
            map2.insert({d, 1});
        }
    }
    cout << endl;
    printUnorderedMap(map2);
    return true;
}


int main(){
    vector<char> v1 = {'C', 'U', 'G', 'A'};
    vector<char> v2 = {'A', 'U', 'C', 'G'};

    vector<char> v3 = {'C', 'U', 'A', 'A'};
    vector<char> v4 = {'A', 'U', 'A', 'A'};
    
    //arePermutations(v1, v2);
    arePermutations(v3, v4);

    return 0;

}