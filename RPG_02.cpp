#include <string>
#include <sstream>
#include <math.h>
#include <iostream>
#include <stdlib.h>
//#include <bits\stdc++>

using namespace std;


struct Mundo{
    string nome;
    int hp; 
    int hp_tot; 
    int atk;
    int def;
    int gold;
};

struct Heroi : Mundo{
    Heroi(){
        string nome;
        hp = 15;
        hp_tot=15;
        atk = 3;
        def = 1;
        gold = 0;

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
};

struct Monstro : Mundo{


    Monstro(bool qual_monstro ){
        if(qual_monstro==true){
            this->nome="Azazel";
            this->hp=10;
            this->hp_tot=10;
            this->atk=3;
            this->def=1;
            this->gold=4;
        }

        if(qual_monstro==false){
            this->nome="Slime";
            this->hp=8;
            this->hp_tot=8;
            this->atk=2;
            this->def=1;
            this->gold=2;
        }
    }
    ~Monstro(){
        cout<<endl;
        cout<<" Monstro Derrotado"<<endl;
        cout<<endl;
    }    
};


int main() {
    Heroi * heroi = new Heroi; 
    string menu,decisao,time;
    bool rand=false;

    while (true)    {
        cin >> time;
        system("clear");
        cout<<"Bem vindo a midgard SR."<< heroi-> nome << " o que deseja fazer:"<<endl<<endl;
        cout<<"caçar"<<endl;
        cout<<"descansar"<<endl<<endl;
        cin >> menu;
        if(menu=="caçar"){
            rand = not(rand);
            Monstro * monstro = new Monstro(rand); 
            cout<<"lutar ou fugir"<<endl;            
            while (true){
                cout<<heroi->nome<< " HP: "<<heroi->hp <<"/ "<<heroi->hp_tot<<endl;
                cout<<monstro->nome<< " HP: "<<monstro->hp<<"/ "<<monstro->hp_tot<<endl;
                cin>>decisao;
                if(decisao=="lutar"){
                    heroi->hp -= fabs(monstro->atk-heroi->def);
                    monstro->hp -= fabs(heroi->atk-monstro->def);
                    if ( heroi->hp <= 0){
                        delete heroi;
                        return 0;
                    }else if(monstro->hp<=0){
                        heroi->gold+=monstro->gold;
                        delete monstro;
                        break;
                    }
                }else if(decisao == "fugir"){
                    break;
                }
            }
        }else if(menu=="descansar"){
            cout<<"Recuperando vida"<<endl;
            heroi->hp=15;

            cout<< "Nome: "<< heroi->nome<<endl;
            cout<< "HP: "<<heroi->hp <<"/ "<<heroi->hp_tot<<endl;
            cout<< "ATK: "<< heroi->atk<<endl;
            cout<< "DEF: "<< heroi->def<<endl;
            cout<< "GOLD: "<< heroi->gold<<endl;
        }else{
            cout<<"comando incorreto"<<endl;
        }
    }
    
    return 0;
}
