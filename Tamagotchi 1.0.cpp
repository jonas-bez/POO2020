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
    //  +15 de sono
    bool brincar(){
        if (this->comida <= 10){
            cout<< "NÃO PODE BRINCAR ESTÁ COM MUITA FOME"<<endl;
            return false;
        }
        cout << "Brincando com a bola\n";
        this->felicidade>=80 ? this->felicidade = 100 : this->felicidade += 20;
        this->comida <= 10 ? this->comida = 0 : this->comida -= 10;
        this->sono += 15;
        return true;            
    }


    //  A função alimenta o animal mas ele pode morrer de gordo
    //  +10 comida
    //  pode ter -5 de saúde
    //  +5 sono
    bool seAlimentar(){
        if(this->comida >= 91){
            this->comida+=10;
            this->saude-=5;
            this->sono >= 90 ? this->sono = 100 : this->sono+=10 ;

            cout<<"GORDO DEMAIS"<<endl;
            if(this->saude <=0){
                cout<<"RIP"<<endl;
                exit(0);
            }
            return true;
        }
        
        this->comida +=10;
        this->sono >= 90 ? this->sono = 100 : this->sono+=10 ;

        return true;
    }

    // A função recupera saúde do animal
    // +40 saúde
    // -30 felicidade
    // -30 comida

    bool medico(){
        if(this->saude>=60){
            this->saude=100;
        }
        else{
            this->saude+=40;
            cout<< "ESTÁ CURADO"<<endl;
        }

        this->felicidade<30 ?  this->felicidade=0:this->felicidade-=30;
        this->comida <30 ?  this->comida=0:this->comida-=30;

        return true;
    }

    //a função diminui o nono do animal
    //-30 sono
    //+10 felicidade
    //-10 comida
    bool dormir(){
        this->sono <= 30 ? this->sono = 0 : this->sono-=30;
        this->felicidade>90 ?  this->felicidade=100:this->felicidade+=10;
        this->comida <10 ? this->comida=0:this->comida-=10;
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

        if(this->sono==100){
            this->saude-=5;
            this->felicidade-=5;
            if(this->saude<=0){
                cout<<"você e um pessimo dono matou o bicho"<<endl;
                cout<<"RIP"<<endl;
                exit(0);
            }           
        }
        return true;
    }

    void informacoes(){
        cout << "brincar : +20 felicidade, -10 comida, +15 sono "<<endl;
        cout << "alimentar : +10 comida, 100 > -5 saúde, +10 sono "<<endl;
        cout << "médico : +40 saúde, -30 felicidade, -30 comida "<<endl;
        cout << "dormir : -30 sono, -10 comida, +10 felicidade "<<endl;
        cout << "Se o tamagotchi estiver com muito sono, muito infeliz ou com muita fome, ele perde saúde e pode morrer"<<endl;

    }

    //  +10 comida
    //  pode ter -5 de saúde
    //  +5 sono


};

int main() {
    Tamagotchi * tamagotchi = new Tamagotchi();

    while(true){
        string line;

        cout <<  "+-------------------------------------+" <<endl;
        cout << "Felicidade " << tamagotchi->felicidade << "%" << "   - brincar" <<endl;
        cout << "Comida " << tamagotchi->comida << "%" << "       - alimentar" <<endl;
        cout << "Saúde " << tamagotchi->saude << "%" << "        - medico" <<endl;
        cout << "Sono " << tamagotchi->sono << "%" << "         - dormir" <<endl;
        cout <<  "                 - informacoes" <<endl;
        cout <<  "                 - exit" <<endl;
        cout <<  "+-------------------------------------+" <<endl;
       
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
        }else if(line=="dormir"){
        tamagotchi->dormir();
        }else if(line=="informacoes"){
        tamagotchi->informacoes();
        }else{
            cout<<"COMANDO INVÁLIDO"<<endl;
        }

        cout << endl;

    }
    return 0;
}
