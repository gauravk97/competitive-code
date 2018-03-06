#include <iostream>
#include <bits/stdc++.h>

using namespace std;



int main(){
    int size = 12;

    string maze[size] = { 
                "############",
                "#...#......#",
                "..#.#.####.#",
                "###.#....#.#",
                "#....###.#.X",
                "####.#.#.#.#",
                "#..#.#.#.#.#",
                "##.#.#.#.#.#",
                "#........#.#",
                "######.###.#",
                "#......#...#",
                "############",

     };

    vector<int, int> valid_spaces;
    for(int i=0; i<12; ++i){
        for(int j=0; j<12; ++j){
            if (maze[i][j]==".")
            {
                valid_spaces.push_back((i,j)
            }
        }
    }
    cout<<maze[0][1]<<endl; 
}