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

int Score(string *m, int len_pat, int num_str){
    int result=0;
    int **profile_matrix;
    profile_matrix=new int* [4];
    for(int i=0;i<4;i++){
        profile_matrix[i]=new int[len_pat];
    }
    for(int i=0;i<num_str;i++){
        for(int j=0;j<len_pat;j++){
            string tmp=m[i];
            switch(tmp[j]){
                case 'A' : profile_matrix[0][j]++; break;
                case 'C' : profile_matrix[1][j]++; break;
                case 'G' : profile_matrix[2][j]++; break;
                case 'T' : profile_matrix[3][j]++; break;
            
            }
        }
    }
    for(int i=0;i<len_pat;i++){
        int max_zn=0;
        for(int j=0;j<4; j++){
            if(max_zn<profile_matrix[j][i]) max_zn=profile_matrix[j][i];
        }
        result+=max_zn;
    }
    return result;
}


int main(int argc, char** argv) {
    ifstream input_file("Input.txt");
    ofstream output_file("Output.txt");
    string *str;
    string a1,a2;
    string *result;//результат
    string *motifs;//текущий набор мотивов
    string **all_patterns;//все наборы 
    int length_pattern;
    int number_str;
    int length_str;
    int best_score=0;//наилучшее score
    int score;//score для текущего 
    getline(input_file,a1,' ');
    getline(input_file,a2,' ');
    length_pattern=atoi(a1.c_str());
    number_str=atoi(a2.c_str());
    str=new string [number_str];
    motifs=new string [number_str];
    result=new string [number_str];
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
    int z=0;
    // создаем массив с в котором хранится номер паттерна в строке
    int len=length_str-length_pattern+1;
    int kol=number_str;
    int *mas=new int[kol];
    int *maxzn= new int [kol];
    for(int i=0;i<kol;i++){
        mas[i]=0;
        maxzn[i]=len-1;
       // cout<<maxzn[i];
    }
    for(int i=0;i<kol;i++){
        motifs[i]=all_patterns[i][0];
    }
    score=Score(motifs,length_pattern,number_str);
        if(best_score<score){
            best_score=score;
            for(int i=0;i<kol;i++){
                result[i]=motifs[i];
            }
        }
    cout<<endl;
    int pr=0;
    while(pr==0){
        if(mas[kol-1]==len-1){
            mas[kol-1]=0;
            int pr1=0;
            int k=kol-2;
            while(pr1==0){
                if(mas[k]==len-1){
                    mas[k]=0;
                    k--;
                }
                else {
                    mas[k]++;
                    pr1=1;
                }     
            }
        }
        else mas[kol-1]++;
        //проверка на совпадение 
        int ch=0;
        for(int i=0;i<kol;i++){
            if(mas[i]==maxzn[i])ch++;
            //cout<<mas[i];
        }
       // cout<<" ";
        for(int i=0;i<kol;i++){
            motifs[i]=all_patterns[i][mas[i]];
        }
        score=Score(motifs,length_pattern,number_str);
        //cout<<score<<" "; 
        
        if(best_score<score){
            best_score=score;
            for(int i=0;i<kol;i++){
                result[i]=motifs[i];
            }
        }
        //если совпадают массивы то выходим из цикла
        if(ch==kol) pr=1;
    }
    
//    cout<<endl;cout<<best_score;
   for(int i=0;i<kol;i++){
                cout<<result[i]<<" ";
            }
    
    for(int i=0;i<kol;i++){
    output_file<<result[i]<<" ";}
    output_file.close();
    input_file.close();
    return 0;
}

