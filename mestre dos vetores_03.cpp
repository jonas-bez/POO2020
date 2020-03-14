#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

//printa o vetor
void vet_show(vector<int>& vet){
    cout << "[ ";
    for(size_t i = 0; i < vet.size(); i++)
        cout << vet[i] << " ";
    cout << "]\n";
}

//printa o vetor ao contrário
void vet_rshow(vector<int>& vet){
    int i;
    i = vet.size()-1;
    cout<<"[";
    while(i>=0){
        cout<<vet[i]<<" ";
        i--;    
    }
    cout<<"]"<<endl;;
}

//retorna o índice que contém value ou -1 se não existir
int vet_find(vector<int>& vet, int value){

    for (int i=0; i < vet.size(); i++){
        if (vet[i]==value){
            cout<<i<<" ";
            return 0;
        }
    }
    cout<<"-1 ";
    return 0;
}    

//remove uma posição por índice 
void vet_rmi(vector<int>& vet, int value){
    int i=0;
    if(vet.size()-1<value){
        cout<<"não e possível remover"<<endl;
    }else{
        vet.erase(vet.begin()+value);
    }
}    

//insere no indice um valor  
int vet_ins(vector<int>& vet, int indice, int value){
    
    if(vet.size()==indice){
        vet.push_back(value);
        return 0;
    }else if(indice > vet.size()-1 || indice < 0){
        cout<<"não pode inserir"<<endl;
        return 0;
    }else{
        vet.insert(vet.begin()+indice, value);
        return 0;
    }
}

//remove todos os elementos com aquele valor 
void vet_rma(vector<int>& vet, int value){
    int i=0;
    while(i<vet.size()){
        if (vet[i]==value){     
            vet.erase(vet.begin()+i);
            vet_rma(vet,value);
        }    
    i+=1;
    }
}

int main(){
    vector<int> vet;
    string line;
    while(true){
        getline(cin, line);
        stringstream ss(line);
        string cmd;

        //add, show, rshow, find, rmi, ins, rma

        cout << "$" << line << "\n";
        ss >> cmd; //pegando o primeiro comando 

        if(line == "end"){
            break;
        }else if(cmd == "add"){
            int value;
            while(ss >> value) //enquanto conseguir retirar valores
                vet.push_back(value);
        }else if(cmd == "show"){//mostra os valores do veotor 
            vet_show(vet);
        }else if(cmd == "rshow"){//mostra os valores invertidos do vetor
            vet_rshow(vet);
        }else if(cmd == "find"){//retorna a primeira ocorencia daquele valor no vetor 
            int value;
            cout<<"[";
            while(ss >> value) 
                vet_find(vet, value);
            cout<<"]"<<endl;
        }else if(cmd == "rmi"){ //remove o elemento por índice 
            int value;
            ss>>value;
            vet_rmi(vet, value);
        }else if(cmd == "ins"){
            int indice=0, value=0;
            ss>>indice>>value;
            vet_ins(vet,indice,value);
        }else if(cmd == "rma"){
            int value;
            ss>>value;            
            vet_rma(vet, value);
        }else{
            cout << "Comando invalido\n";
        }
    }
    return 0;
}