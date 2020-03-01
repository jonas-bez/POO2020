#include <iostream>
#include <stdlib.h>
#include <sstream>
using namespace std;

struct Tamagotchi{
    int felicidade = 50;
    int comida = 50;
    int sono = 50;
    int saude = 50;

    //  A função brinca com o animal mas ele pode não brincar por estar com fome
    //  +20 felicidade
    //  -10 comida
    //  +0.1 de inteligência
    bool brincar(){
 /*       if (this->comida < 10){
            cout<< "NÃO PODE BRINCAR ESTÁ COM MUITA FOME"<<endl;
            return false;
        }*/
        cout << "Brincando com a bola\n";
        this->felicidade>=80 ? this->felicidade = 100 : this->felicidade += 20;
        this->comida <= 10 ? this->comida = 0 : this->comida -= 10;
        this->sono += 15;
        return true;            
    }


    //  A função alimenta o animal mas ele pode morrer de gordo
    //  +10 comida
    //  pode ter -5 de saúde
    bool seAlimentar(){
        if(this->comida >= 91){
            this->comida+=10;
            this->saude-=5;
            cout<<"GORDO DEMAIS"<<endl;
            if(this->saude <=0){
                cout<<"RIP"<<endl;
                exit(0);
            }
            return true;
        }
        
        this->comida +=10;
        return true;
    }

    // A função recupera saúde do animal
    // +40 saúde
    // -10 felicidade
    bool medico(){
        if(this->saude>=60){
            this->saude=100;
        }
        else{
            this->saude+=40;
            cout<< "ESTÁ SE CURANDO"<<endl;
        }

        this->felicidade<10 ?  this->felicidade=0:this->felicidade-=10;
        this->comida <20 ?  this->comida=0:this->comida-=20;

        return true;
    }

    bool parametrosDeVida(){

        if(this->felicidade==0){
            this->saude -= 5;
            this->comida -=5;
            if(this->saude<=0){
                cout<<"você e um pessimo dono matou o bicho"<<endl;
                cout<<"RIP"<<endl;
                exit(0);
            }
        }
        if(this->comida==0){
            this->saude-=10;
            this->felicidade-=5;
            if(this->saude<=0){
                cout<<"você e um pessimo dono matou o bicho"<<endl;
                cout<<"RIP"<<endl;
                exit(0);
            }           
        }
        return true;
    }

};

int main() {
    Tamagotchi * tamagotchi = new Tamagotchi();

    while(true){
        string line;

        cout << "Felicidade " << tamagotchi->felicidade << "%"  <<endl;
        cout << "Comida " << tamagotchi->comida << "%"  <<endl;
        cout << "Inteligência " << tamagotchi->inteligencia  <<endl;
        cout << "Saúde " << tamagotchi->saude << "%" <<endl;
       
        cout<<endl;
        tamagotchi->parametrosDeVida();
        cout<<endl;

        getline(cin, line);
        stringstream ss(line);



        if(line=="exit"){
            exit(0);
        }else if(line=="medico"){
            tamagotchi->medico();
        }else if(line=="alimentar"){
            tamagotchi->seAlimentar();
        }else if(line=="brincar"){
        tamagotchi->brincar();
        }else{
            cout<<"COMANDO INVÁLIDO"<<endl;
        }

        cout << endl;

    }
    return 0;
}
