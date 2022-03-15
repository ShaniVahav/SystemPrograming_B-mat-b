#include "mat.hpp"
#include <iostream>
#include <stdexcept>
#include <bits/stdc++.h>
#include <vector>
using namespace std;



namespace ariel
{

    string mat(int cols_size, int rows_size, char ch1, char ch2)
    {
        const int smallerLegal = 33;
        const int biggestLegal = 126;

        if (cols_size%2 == 0 || rows_size%2 ==0){
            __throw_invalid_argument("Mat size cannot be even!");
        }

        if (smallerLegal > ch1 || ch1 > biggestLegal || smallerLegal > ch2 || ch2 > biggestLegal){
            __throw_invalid_argument("is invalid char!");
        }

        if (cols_size <= 0 || rows_size <= 0){
            __throw_invalid_argument("Mat size have to be a non-negative number!");
        }
        

        // Initialize a vector in size rows, in every cell put another
        // vector in size cols which contains an emepty char
        vector<vector<char>> matrix(rows_size, vector<char> (cols_size, ch1));
        bool flag = true;
        if(rows_size == 1 || cols_size == 1){
            flag = false;
        }

        // Stop is the number of frames
        int stop = (min(rows_size, cols_size)+1)/2;

        // Drawing by frames 
        int inner = 1;
        size_t row_number = 0;
        size_t col_number = 0;
        
        while(flag)
        {
            row_number = inner;
            for (col_number = inner; col_number<cols_size-inner; col_number++)
            {
                matrix[row_number][col_number] = ch2; // ceiling
                matrix[rows_size-1-inner][col_number] = ch2; // bottom

            }

            col_number = inner;
            for (row_number = inner; row_number<rows_size-inner; row_number++){
                matrix[row_number][col_number] = ch2; // left side
                matrix[row_number][cols_size-1-inner] = ch2; // right side
            }

            stop-=2;
            if (stop <= 0){
                flag = false;
            }
            inner+=2;
        }

    string ans = string("");
    for(int i = 0 ; i<rows_size;i++ ){
        for(int j = 0 ; j < cols_size ; j ++ ){
            ans+= matrix[i][j];
        }
        ans += "\n";  
    }

    return ans;
    }
}