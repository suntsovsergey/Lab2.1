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
    string *motifs;
    string **all_patterns;
    int length_pattern;
    int number_str;
    int length_str;
    getline(input_file,a1,' ');
    getline(input_file,a2,' ');
    length_pattern=atoi(a1.c_str());
    number_str=atoi(a2.c_str());
    str=new string [number_str];
    motifs=new string [number_str];
    all_patterns=new string* [number_str];
    //считывание строк с ДНК 
    for(int i=0;i<number_str+1;i++){
        string tmp;
        getline(input_file,tmp,'\n');
        if(i>0) str[i-1]=tmp;
    }
    length_str=str[0].length();
    for(int i=0;i<number_str;i++){
        all_patterns[i]=new string [length_str-length_pattern+1];
    }
    //заполнение всеми возможными наборами шаблонов 
    for(int i=0;i<number_str;i++){
        string tmp_str=str[i];
        for(int j=0;j<length_str-length_pattern+1;j++){
            for(int k=j;k<j+length_pattern;k++){
                all_patterns[i][j]+=tmp_str[k];
            }
        }
    }
    
    for(int i=0;i<number_str;i++){
     for(int j=0;j<length_str-length_pattern+1;j++){
        cout<<all_patterns[i][j]<<" ";
     }
     cout<<endl;
    }

    
    
    output_file<<result;
    output_file.close();
    input_file.close();
    return 0;
}

