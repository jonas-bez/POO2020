#include <string>
#include <sstream>
#include <math.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

class Pet{
    private:
        int energyMax, hungryMax, cleanMax;
        int energy, hungry, clean;
        int diamonds;
        int age;
        bool alive;


    public:
        void setEnergy(int value){
            energy=value;
        }
        void setHungry(int value){
            hungry=value;
        }
        void setClean(int value){
            clean=value;
        }
        void setEnergyMax(int value){
            energyMax=value;
        }
        void setHungryMax(int value){
            hungryMax=value;
        }
        void setCleanMax(int value){
            cleanMax=value;
        }
        void setAge(int value){
            age=value;
        }
        void setDiamonds(int value){
            diamonds=value;
        }
        void setAlive(bool value){
            alive=value;
        }

        int getEnergy(){
            return energy;
        }
        int getHungry(){
            return hungry;
        }
        int getClean(){
            return clean;
        }
        int getEnergyMax(){
            return energyMax;
        }
        int getHungryMax(){
            return hungryMax;
        }
        int getCleanMax(){
            return cleanMax;
        }
        int getAge(){
            return age;
        }
        int getDiamonds(){
            return diamonds;
        }
        bool getAlive(){
            return alive;
        }

    Pet(int valEnergy, int valHungry, int valClean){

        cout<<endl;
        cout<<"Nasceu"<<endl;
        this->setEnergy(valEnergy);
        this->setHungry(valHungry);
        this->setClean(valClean);
        this->setEnergyMax(valEnergy);
        this->setHungryMax(valHungry);
        this->setCleanMax(valClean);

        this->setAge(0);
        this->setDiamonds(0);
        this->setAlive(true);

        show();
    }

    ~Pet(){
        cout<<"Morreu"<<endl;
    }


//O comando "$show" mostra os parâmetros do Pet na seguinte ordem
//Energia/Max, Saciedade/Max, Limpeza/Max, Diamantes, Idade

    void show(){
        cout<<endl;
        cout << "E:" << this->getEnergy() << " / " << this->getEnergyMax()<<endl;
        cout << "H:" << this->getHungry() << " / " << this->getHungryMax()<<endl;
        cout << "C:" << this->getClean() << " / " << this->getCleanMax()<<endl;
        cout << "D:" << this->getDiamonds() <<", A: " << this->getAge()<<endl;
        cout<<endl;
    }

//O comando "$play" altera em -2 energia, -1 saciedade, -3 limpeza, +1 diamante, +1 idade.

    void play(){
        setEnergy(getEnergy()-2);
        setHungry(getHungry()-1);
        setClean(getClean()-3);
        setDiamonds(getDiamonds()+1);
        setAge(getAge()+1);

        estaVivo();
    }

//O Comando "$eat" altera em -1 a energia, +4 a saciedade, -2 a limpeza, +0 diamantes,  +1 a idade

    void eat(){
        setEnergy(getEnergy()-1);
        if(getHungry()+4>getHungryMax()){
            setHungry(getHungryMax());
        }else{
            setHungry(getHungry()+4);
        }
        setClean(getClean()-2);
        setAge(getAge()+1);

        estaVivo();
    }

//O Comando "$sleep" aumenta energia até o máximo e idade aumenta do número de turnos que o pet dormiu.
//Os outros atributos permanecem inalterados.
//case dormir sem sono
//Para dormir, precisa ter perdido pelo menos 5 unidades de energia

    void sleep(){
        if(getEnergyMax()-5 < getEnergy()){
            cout<<"ele ainda não está com sono"<<endl;
        }else{
            setEnergy(getEnergyMax());
            setAge(getAge()+1);
        }
    }

//O comando "$clean" alteram em -3 energia, -1 na saciedade, MAX na limpeza, +0 diamantes, +2 na idade.

    void shower(){
        setEnergy(getEnergy()-3);
        setHungry(getHungry()-1);
        setClean(getCleanMax());
        setAge(getAge()+2);

        estaVivo();
    }

//case morrer Se algum atributo atingir 0, o pet morre e não poderá executar nenhuma ação
  
    void estaVivo(){
        if (getEnergy()<=0 || getHungry()<=0 || getClean()<=0){
            cout<<endl;
            cout<<"GAME OVER -|-"<<endl;
            setAlive(false);
        }
    }

};


int main(){
    string menu;
    int e, h, c;
    
    cout<<"LINK START"<<endl;
    cout<<"Bem vindo ao tamagotchi"<<endl;
    cout<<"inicie os status de energy, hungry, clean"<<endl;

    cin>>e>>h>>c;
    Pet * pet = new Pet(e,h,c);
    
    while (true){


        if(not(pet->getAlive())){
            delete pet;
            cout<<endl;
            return 0;
        }

        cout<<"Bem vindo ao Tamagotchi oq deseja fazer?"<<endl;
        cout<<"init, play, eat, sleep, show, shower"<<endl;
        cout<<endl;

        cin>>menu;    
        
        if(menu=="init"){
            delete pet;
            cin>>e>>h>>c;
            Pet * pet = new Pet(e,h,c);
            cout<<endl;
        }else if(menu=="play"){
            pet->play();
            cout<<endl;
         }else if(menu=="show"){
            pet->show(); 
            cout<<endl;          
        }else if(menu=="eat"){
            pet->eat();
            cout<<endl;
        }else if(menu=="sleep"){
            pet->sleep();
            cout<<endl;
        }else if(menu=="shower"){
            pet->shower();
            cout<<endl;
        }else{
            cout<<"comando inválido"<<endl;
            cout<<endl;
        }
    }

    return 0;
}
