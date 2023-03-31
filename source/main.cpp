#include <bits/stdc++.h>
#include <random>
#include <iomanip>
#include <iostream>

using namespace std;



constexpr int FLOAT_MIN = 0;
constexpr int FLOAT_MAX = 1;
constexpr int dimensiones = 1000;
constexpr int numPuntos = 100;

void mostrar(vector<vector<float>> setPoint){
    for(int i=0;i<setPoint.size();i++){
        for(int j=0;j<dimensiones;j++){
            cout<< setPoint[i][j]<<" - ";
        }
        cout<<endl;
    }
    cout<<setPoint.size()<<endl;
}



bool puntos(int numPuntos,vector<vector <float>> &setPoint){
    random_device rd;
    default_random_engine eng(rd());
    uniform_real_distribution<float> distr(FLOAT_MIN,FLOAT_MAX);
    //setprecision(6);
    for(int i=0;i<numPuntos;i++){
        vector<float> tmp;
        for(int j=0;j<dimensiones;j++){
            tmp.push_back( distr(eng) );
        }
        setPoint.push_back(tmp);
        
    }
    return 1;
}

bool distancia(vector< vector<float> > setPoint){
    float restTmp;
    vector<float> tmpPoint;
    
    while (setPoint.size())
    {
        vector<float> e = setPoint[setPoint.size()-1];
        setPoint.pop_back();
        for(int i=0;i<setPoint.size();i++){
            float tmp=0;
            for(int j=0;j<dimensiones;j++){
            /*distancia suma = a1-b1*/
            tmp += pow(e[j]-setPoint[i][j],2);
            }
            cout<<"distancia: "<<sqrt(tmp)<<endl;    
        }
        
    }
    

    return 1;
}


int main(){
    vector<vector <float>> setPoint;
    puntos(numPuntos,setPoint);
    //mostrar(setPoint);
    distancia(setPoint);
    

    return 1;
}
