#include <iostream>
#include <math.h>

using namespace std;

struct Heroi{

    string nome;
    int hp = 12;
    int atk = 3;
    int def = 1;
    int gold = 0;


    Heroi(){
        cout<< "Un novo heroí está nascendo seu nome é:";
        cin >> this->nome;
        cout<<endl;
        cout<< "Nome: "<< this->nome<<endl;
        cout<< "HP: "<< this->hp<<endl;
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

struct Monstro{

    string nome;
    int hp; 
    int atk;
    int def;
    int gold;

    Monstro(bool qual_monstro ){
        if(qual_monstro==true){
            this->nome="Azazel";
            this->hp=10;
            this->atk=2;
            this->def=1;
            this->gold=4;
        }

        if(qual_monstro==false){
            this->nome="Slime";
            this->hp=8;
            this->atk=1;
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
    string menu;
    bool rand=false;


    while (true)    {
        cout<<"Bem vindo a midgard o que deseja fazer:"<<endl<<endl;
        cout<<"caçar"<<endl;
        cout<<"descansar"<<endl<<endl;
        cin >> menu;
        if(menu=="caçar"){
            rand = not(rand);
            Monstro * monstro = new Monstro(rand); 
            
            while (true){
                cout<<"luta"<<endl;
                cout<<heroi->nome<< " hp: "<<heroi->hp<<endl;
                cout<<monstro->nome<< " hp: "<<monstro->hp<<endl;
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

            }
        }else if(menu=="descansar"){
            cout<<"Recuperando vida"<<endl;
            heroi->hp=12;
            cout<< "Nome: "<< heroi->nome<<endl;
            cout<< "HP: "<< heroi->hp<<endl;
            cout<< "ATK: "<< heroi->atk<<endl;
            cout<< "DEF: "<< heroi->def<<endl;
            cout<< "GOLD: "<< heroi->gold<<endl;
        }else{
            cout<<"comando incorreto"<<endl;
        }
    }
    

    return 0;
}
