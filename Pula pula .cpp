#include <string>
#include <sstream>
#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <tuple>
#include <vector>

using namespace std;


class Kid{
    private:
        string name;
        int age;
  
    public:
        void setName(string value){
            name=value;
        }
        void setAge(int value){
            age=value;
        }

        string getName(){
            return name;
        }
        int getAge(){
            return age;
        }

    Kid(string nome, int idade){
        this->setName(nome);
        this->setAge(idade) ;
    }
    ~Kid(){
       cout<<"saiu";
    }

    void novaCrianca(vector<std::pair<string,int>> & fora){
        auto novo_cria = std::make_pair(getName(),  getAge());
        fora.push_back(novo_cria);
    }

};

class Trampoline{
    public:
    void entrar(vector<std::pair<string,int>> & fora, vector<std::pair<string,int>> & dentro){
        if(fora.size()<=0){
            cout<<"não tem ninguém para entrar"<<endl;
        }else{
            dentro.push_back(fora[0]);
            fora.erase(fora.begin());
        }
    }
    void sair(vector<std::pair<string,int>> & fora, vector<std::pair<string,int>> & dentro){
       
       if(dentro.size()<=0){
            cout<<"não tem ninguém para sair"<<endl;
       }else{
            //delete dentro.begin();
            fora.push_back(dentro[0]);
            dentro.erase(dentro.begin());
       }
    }
    void mostrar(vector<std::pair<string,int>> & fora, vector<std::pair<string,int>> & dentro){
        for (int i = fora.size()-1; i>=0; --i ){
            cout<<fora[i].first<< ":" <<fora[i].second<<" ";
        }
        cout<<"=> [ ";
        for (auto contador: dentro){
            cout<<contador.first<< ":" <<contador.second<<" ";
        }
        cout<<"]"<<endl;
    }

};
int main(){
    vector<std::pair<string,int>> fora, dentro; 
    string nome, menu;
    int idade;
    //std::pair<string , int> p = make_pair("ana",2);

    Trampoline * trampoline = new Trampoline;

    while(true){

        cin>>menu;
        if(menu == "chegou"){   //adiciona criança na fila de espera fora do pula pula 
            cin>>nome>>idade;
            Kid * crianca = new Kid(nome, idade);
            crianca->novaCrianca(fora);
        }else if(menu == "show"){       //mostra as crianças na fira e dentro do pula pula 
            trampoline->mostrar(fora, dentro);
        }else if(menu == "entrar"){     //adicona crinaças dentro do pula pula 
            trampoline->entrar(fora, dentro);
        }else if(menu == "sair"){       //retira crianças de dentro do pula pula 
            trampoline->sair(fora, dentro);
        }
        
    }   

    return 0;
}
