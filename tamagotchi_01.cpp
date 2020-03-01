#include <iostream>
#include <stdlib.h>
using namespace std;

struct Tamagotchi{
    int felicidade = 0;
    int comida = 100;
    float inteligencia = 2;
    int saude = 10;
    //sono


    bool brincar(){
        if (this->comida < 30){
            cout<< "NÃO PODE BRINCAR ESTÁ COM MUITA FOME"<<endl;
            return false;
        }

        if(this->saude > 0){
            cout << "Brincando com a bola\n";
            if(this->felicidade>=80){
                this->felicidade = 100; 
            }
            this->felicidade += 20;

            if((this->comida -= 30)<0){
                this->comida = 0;
            }
            this->comida -= 30;

            this->inteligencia += 0.1;
            return true;
            }
        
        cout << "RIP\n";
        exit(0);
    }

    bool seAlimentar(){
        if(this->comida > 100){
            this->saude -= 5;
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

    bool medico(){
        if(this->saude>=60){
            this->saude=100;
        }
        else{
            this->saude+=40;
            cout<< "ESTÁ SE CURANDO"<<endl;
        }
        
        if(this->felicidade<10){
            this->felicidade=0; 
        }
        this->felicidade-=10;
    }

};

int main() {
    Tamagotchi * tamagotchi = new Tamagotchi();

    cout << "Felicidade " << tamagotchi->felicidade << "%"  <<endl;
    cout << "Comida " << tamagotchi->comida << "%"  <<endl;
    cout << "Inteligência " << tamagotchi->inteligencia  <<endl;
    cout << "Saúde " << tamagotchi->saude << "%" <<endl;

    cout << "\n\n\n";

    tamagotchi->medico();
    tamagotchi->seAlimentar();
    tamagotchi->seAlimentar();
    tamagotchi->seAlimentar();
    tamagotchi->brincar();

    return 0;
}
