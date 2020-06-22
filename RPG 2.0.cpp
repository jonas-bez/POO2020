#include <string>
#include <sstream>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;


struct Mundo{
    string nome;
    int hp; 
    int hp_tot; 
    int atk;
    int def;
    int gold;
};

struct Monstro : Mundo{


    Monstro(){
        this->nome="Azazel";
        this->hp=10;
        this->hp_tot=10;
        this->atk=3;
        this->def=1;
        this->gold=4;

    }
    
    ~Monstro(){
        cout<<endl;
        cout<<" Monstro Derrotado"<<endl;
        cout<<endl;
    }    
};

struct Heroi : Mundo{
    Heroi(){
        string nome;
        hp = 15;
        hp_tot=15;
        atk = 3;
        def = 1;
        gold = 100;

        cout<< "Un novo heroí está nascendo seu nome é:";
        cin >> this->nome;
        cout<<endl;
        cout<< "Nome: "<< this->nome<<endl;
        cout<< "HP: "<< this->hp <<"/ "<< this->hp_tot <<endl;
        cout<< "ATK: "<< this->atk<<endl;
        cout<< "DEF: "<< this->def<<endl;
        cout<< "GOLD: "<< this->gold<<endl;
        
    }
    ~Heroi(){
        cout<<endl;
        cout<<" Você Morreu"<<endl;
        cout<<endl;
    }

    void descansando(vector<int>& itens){

        cout<<"Recuperando vida"<<endl;
        this->hp=15;

        cout<< "Nome: "<< this->nome<<endl;
        cout<< "HP: "<<this->hp <<"/ "<<this->hp_tot<<endl;
        cout<< "ATK: "<< this->atk<<endl;
        cout<< "DEF: "<< this->def<<endl;
        cout<< "GOLD: "<< this->gold<<endl<<endl;
       
        cout<< "Poção "<< itens[0] <<endl;
        cout<< "Bomba "<< itens[1] <<endl;
        cout<< "Adaga "<< itens[2] <<endl;

    }

    int batalha(vector<int>& itens){  
        string decisao, escolha_item;
        Monstro * monstro = new Monstro(); 

        while (true){
            cout<<endl;
            cout<<"1 lutar"<<endl; 
            cout<<"2 item"<<endl; 
            cout<<"3 fugir"<<endl<<endl;            
            cout<<this->nome<< " HP: "<<this->hp <<"/ "<<this->hp_tot<<endl;
            cout<<monstro->nome<< " HP: "<<monstro->hp<<"/ "<<monstro->hp_tot<<endl<<endl;
            cin>>decisao;
            if(decisao=="1"){
                this->hp -= fabs(monstro->atk-this->def);
                monstro->hp -= fabs(this->atk-monstro->def);
                if ( this->hp <= 0){
                    return 0;
                }else if(monstro->hp<=0){
                    this->gold+=monstro->gold;
                    delete monstro;
                    return 0;
                }

            }else if(decisao == "2"){
                cout<<"1 Poção "<< itens[0]<<endl;
                cout<<"2 Bomba "<< itens[1]<<endl;
                cout<<"3 Adaga "<< itens[2]<<endl;
                cin>>escolha_item;

                if(escolha_item=="1"){
                    if(itens[0]>0){
                        itens[0]-=1;
                        this->hp=this->hp_tot;
                    }else{
                        cout<<"não possue"<<endl;
                    }   
                }else if(escolha_item=="2"){
                    if(itens[1]>0){
                        itens[1]-=1;
                        if(monstro->hp>=7){
                            monstro->hp-=7;
                        }else{
                            monstro->hp=0;
                        }
                    }else{
                        cout<<"não possue"<<endl;
                    }
                }else if(escolha_item=="3"){
                    if(itens[2]>0){
                        this->atk+=1;
                        itens[2]-=1;
                    }else{
                        cout<<"não pode utilizar"<<endl;
                    }
                }

            }else if(decisao == "3"){
                return 0;
            }
        }
    }

    int comprar(vector<int>& itens){
        string decisao;
        while(1){
            cout<<endl;
            cout<<"Bem vindo a loja o que deseja comprar"<<endl; 
            cout<<"1  Poção - 3G  (restaura hp)"<<endl; 
            cout<<"2  Bomba - 10G (7 dano)"<<endl;
            cout<<"3  Adaga - 50G (+1 dano)"<<endl;
            cout<<"4  Sair"<<endl;

            cin>>decisao;
            cout<<endl;
            if(decisao=="1"){
                if(this->gold>=3){               
                    itens[0]=(itens[0]+1);
                    this->gold-=3;
                }else{
                    cout<<"gold inufisciente"<<endl;
                }
            }else if(decisao=="2"){
                if(this->gold>=10){
                itens[1]=(itens[1]+1);
                this->gold-=10;
                }else{
                    cout<<"gold inufisciente"<<endl;
                }
            }else if(decisao=="3"){
                if(this->gold>=50){
                itens[2]=(itens[2]+1);
                this->gold-=50;
                }else{
                    cout<<"gold inufisciente"<<endl;
                }
            }else if(decisao=="4"){
                return 0;
            }else{
                cout<<"compra inválida"<<endl;
            }
        }

    }


};



int main() {
    Heroi * heroi = new Heroi; 
    string menu,time;
    vector<int> itens;
    bool rand=false;

    for (int i = 0; i < 3; i++){
        itens.push_back(0);
    }

    while (true){
        //cin >> time;
        //system("pause");
        cin.ignore();
        cin.get();
        system("clear");
        cout<<"Bem vindo a midgard SR."<< heroi-> nome << " o que deseja fazer:"<<endl<<endl;
        cout<<"1 caçar"<<endl;
        cout<<"2 loja"<<endl;
        cout<<"3 descansar"<<endl<<endl;
        cin >> menu;
        
        if(menu=="1"){
            heroi->batalha(itens);
            if(heroi->hp<=0){
                delete heroi;
            }
        }else if(menu=="2"){
            heroi->comprar(itens);
        }else if(menu=="3"){
            heroi->descansando(itens);
        }else{
            cout<<"comando incorreto"<<endl;
        }
    }
   
    return 0;
}
