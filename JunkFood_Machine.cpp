#include <string>
#include <sstream>
#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <tuple>
#include <vector>

using namespace std;

class Produto{
    public:
    string nome;
    int quantidade;
    float valor;

    Produto(string nome="empty", int quantidade=0, float valor=0){
            this->nome=nome;
            this->quantidade=quantidade;
            this->valor=valor;
    }
    ~Produto(){
    }
};

class Maquina{
    public:
    int max_prod, dinheiro;
    vector<Produto> produtos; 
        
    Maquina(int espirais,int prod): produtos(espirais){ //criar vetor produtos antes da máquina
        max_prod=prod;
        dinheiro=0;
    }

    ~Maquina(){
    }

    void show(){

        cout<<"dinheiro: " << dinheiro <<endl;
        for(int i = 0; i<produtos.size();i++){
            cout<< i << " [ " << produtos[i].nome << " : " <<
            produtos[i].quantidade << " U : " << 
            produtos[i].valor << " R$]"<<endl;
        }

    }

    void set(int id, string nome, int quantidade, float valor){
       
        if(quantidade <= 0 || quantidade>max_prod){
            cout<<"Não tem como adicionar essa quantidade de unidades"<<endl;
            return;
        }if(valor <= 0){
            cout<<"Não tem como adicionar um produto sem valor"<<endl;
            return;
        }if(nome == ""){
            cout<<"Não tem como adicionar um produto sem nome"<<endl; 
            return; 
        }if(id > (int)produtos.size() -1 || id<0){
            cout<<"ID inválido"<<endl; 
            return; 
        }
        if(produtos[id].nome=="empty"){
            produtos[id].nome = nome;
            produtos[id].quantidade = quantidade;
            produtos[id].valor = valor;
        }else{
            cout<<"Já existe um produto ai, retire-o primeiro"<<endl;
        }
    }

    void limpar(int id){
        if(produtos[id].nome!="empty"){
            produtos[id].nome = "empty";
            produtos[id].quantidade = 0;
            produtos[id].valor = 0;
        }else{
            cout<<"Já está limpo"<<endl;
        }
    }

    void money(int quantidade){
        this->dinheiro += quantidade;
    }

    void troco(){
       cout<<"Você recebeu: " << this->dinheiro << " de troco"<<endl;
       this->dinheiro = 0;
    }

    void comprar(int id){
        if(produtos[id].nome=="empty" || produtos[id].quantidade==0){
            cout<<"Digite um produto válido"<<endl;
            return;
        }
        if(dinheiro >= produtos[id].valor){
            cout<<"Você comprou: " << produtos[id].nome<<endl;
            dinheiro -= produtos[id].valor;
            produtos[id].quantidade-=1;
        }else{
            cout<<"Dinheiro insuficiente, deposite mais."<<endl;
        }
    }
};




int main(){
    string menu;
    int  espeirais, max_prod;

    while(true){
        cin>>menu;
        if(menu=="init"){
            cin >> espeirais >> max_prod;
            Maquina * maquina = new Maquina(espeirais, max_prod);
            
            while(true){
                cin>>menu;
                if(menu == "init"){
                    delete maquina;   
                    cin >> espeirais >> max_prod;
                    Maquina * maquina = new Maquina(espeirais, max_prod);                    
                }else if(menu == "show"){       
                    maquina->show();
                }else if(menu == "set"){
                    string nome;
                    float valor; 
                    int quantidade, id;
                    cin>>id>>nome>>quantidade>>valor;
                    maquina->set(id, nome,quantidade, valor);
                }else if(menu == "limpar"){ 
                    int id;
                    cin>>id;      
                    maquina->limpar(id);
                }else if(menu == "dinheiro"){  
                    int quantidade;
                    cin>>quantidade;     
                    maquina->money(quantidade);
                }else if(menu == "troco"){      
                    maquina->troco();
                }else if(menu == "comprar"){
                    int id;
                    cin>>id;       
                    maquina->comprar(id);
                }     
            }   
        }else{
            cout<<"É necessário iniciar a máquina primeiro"<<endl;
        }
    }
    return 0;
}


