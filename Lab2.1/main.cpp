/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: macbookpro
 *
 * Created on 21 ноября 2017 г., 14:06
 */
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/*
 * 
 */

int number_pattern(string str, string pattern){
    int count=0;
    int i=0;
    for (i=str.find(pattern,i);i!=string::npos; i=str.find(pattern,i+1)){
        count++;
    }
    return count;
}




int main(int argc, char** argv) {
    ifstream input_file("Input.txt");
    ofstream output_file("Output.txt");
    string *str;
    string a1,a2;
    string result;
    int length_pattern;
    int number_str;
    int length_str;
    getline(input_file,a1,' ');
    getline(input_file,a2,' ');
    length_pattern=atoi(a1.c_str());
    length_str=str[0].length();
    number_str=atoi(a2.c_str());
    str=new string [number_str];
    //считывание строк с ДНК 
    for(int i=0;i<number_str;i++){
        getline(input_file,str[i],'\n');
    }
    int k=0;
    while(k<number_str){
        for(int i=0;i<length_str-length_pattern+1;i++){
            
        }
    }

    
    
    output_file<<result;
    output_file.close();
    input_file.close();
    return 0;
}

