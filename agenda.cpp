#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

class Fone{
public:
    int index;
    string id;
    string fone;

    Fone(int index, string id = "", string fone = ""){
        this->index = index;
        this->id = id;
        this->fone = fone;
    }

    static bool validar(string number){
        string valid = "0123456789()-.";
        for(char c : number)
            if(valid.find(c) == string::npos)
                return false;
        return true;
    }

    void toString(){
        cout << " " << id << " :"  << fone;
    }
};
/*
ostream& operator<<(ostream& ost, const Fone& fone){
    ost << "[" << fone.index << ":" << fone.id << ":" << fone.fone << "]";
    return ost;
}*/

class Contato{
public:
    bool favorito = false;
    string name;
    vector<Fone> fones;
    Contato(string name = "", vector<Fone> fones = vector<Fone>()):
        name(name), fones(fones){
    }

    ~Contato(){

    }

    string getName(){
        return name;
    }
    void addFone(string id, string fone){
        if(Fone::validar(fone))
            fones.push_back(Fone(this->fones.size(), id, fone));
        else
            cout << "fail: fone invalido" << endl;
    }
    void rmFone(int index){
        if(index < 0 || index >= (int) fones.size())
            return;
        fones.erase(fones.begin() + index);
        for(int i = 0; i < (int) fones.size(); i++)
            fones[i].index = i;
    }
    vector<Fone> getFones(){
        return fones;
    }

    void tostring(){
        cout << "- " << getName();
        if(getFones().empty())
            cout << " ";
        for(size_t i = 0; i < fones.size();i++)
            fones[i].toString(); 
    }
};

class Agenda{
    public:
    Agenda(){

    }

    vector<Contato*> agenda_lista;
    vector<Contato*> agenda_fav;

     bool add_fav(string name){
        for(int i = 0; i < (int) agenda_lista.size(); i++){
            auto x = agenda_lista[i]->getName();

            if( name == agenda_lista[i]->getName()){
                for(int k = 0; k < (int) agenda_fav.size(); k++){
                    if(name == agenda_fav[i]->name){
                        cout << "contato ja existente em favoritos" << endl;
                        return false;
                    }
                }
                agenda_lista[i]->favorito = true;
                agenda_fav.push_back(agenda_lista[i]);
                return true; 
            }

        }
            cout << "ERRO: contato nao existente" << endl;
        return false;
    }

    void print_fav(){
        for(size_t i = 0 ; i < agenda_fav.size() ; i++){
            agenda_fav[i]->tostring();
            cout << endl;
            }

    }

    bool rm_fav(string name){
        for(int i = 0; i < (int) agenda_fav.size(); i++){
            if( name == agenda_fav[i]->getName()){
                agenda_fav[i]->favorito = false;
                agenda_fav.erase(agenda_fav.begin()+i);
                return true;
            }
        }
        cout << "ERRO: contato nao encontrado" << endl;
        return false;
    }

    void inserir(Contato * contato){
        for(int i = 0; i < (int) agenda_lista.size(); i++){
            if(agenda_lista[i]->getName() == contato->getName()){
            cout << "ERRO: contato ja existente" << endl;
            delete contato;
            return;
            }
        }
        agenda_lista.push_back(contato);
    }
    void addFone(string name, string id, string fone){

        for(int i = 0; i < (int) agenda_lista.size(); i++){
            if( name == agenda_lista[i]->getName()){
                agenda_lista[i]->addFone(id, fone);
                return;
            }
        }
        cout << "ERRO: Contato nao encontrado" << endl;
        /*contato = agenda_lista[agenda_lista.size()-1];
        contato->addFone(id, fone);*/
    }

    void rmFone(string name, int index){

        for(int i = 0; i < (int) agenda_lista.size(); i++){
            if( name == agenda_lista[i]->getName()){
                agenda_lista[i]->rmFone(index);
                return;
            }
        }

    }
    void rmcontato(string name){
        for(int i = 0; i < (int) agenda_lista.size(); i++){
            if( name == agenda_lista[i]->getName()){
                delete agenda_lista[i];
                agenda_lista.erase(agenda_lista.begin()+i);
                return;
            }
        }
        cout << "ERRO: contato nao encontrado" << endl;
    }

    void buscar(string name){
        bool cont = false;
        for(int i = 0; i < (int) agenda_lista.size(); i++){
            auto x = agenda_lista[i]->getName().find(name);

            if( name == agenda_lista[i]->getName()){
                agenda_lista[i]->tostring();
                cout << endl;
                return; 
            }
                for(int j = 0; j < (int) agenda_lista[i]->fones.size(); j++){
                    if(agenda_lista[i]->fones[j].fone == name){
                        agenda_lista[i]->tostring();
                        cout << endl;
                        return; 
                    }
                    else if(agenda_lista[i]->fones[j].id == name){
                        agenda_lista[i]->tostring();
                        cout << endl;
                        return;                       
                    }
                }
            if(!x){
                cont = true;
                agenda_lista[i]->tostring();
                cout << endl;
            }

        } 
        if(!cont)
            cout << "ERRO: contato nao encontrado" << endl;
    }


    void printString(){
        for(size_t i = 0 ; i < agenda_lista.size() ; i++){
            agenda_lista[i]->tostring();
            cout << endl;
        }
    }

};


/*ostream& operator<<(ostream& ost, Contato& contato){
    ost << "- " << contato.getName();
    if(!contato.getFones().empty())
        cout << " ";
    for(Fone fone : contato.getFones())
        ost << fone;
    return ost;
}*/

template <class T>
T get(stringstream& ss){
    T t;
    ss >> t;
    return t;
}

int main(){
    //Contato * contato;
    Agenda agenda;
    while(true){
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;
        stringstream ss(line);
        ss >> cmd;
        if(cmd == "end"){
            break;
        }
        else if(cmd == "init"){//name
            Contato * contato = new Contato(get<string>(ss));
            agenda.inserir(contato);
        }
        else if(cmd == "add"){//id fone
            string name = get<string>(ss);
            string id = get<string>(ss);
            string fone = get<string>(ss);
            agenda.addFone(name, id, fone); //composição
        }
        else if(cmd == "rm"){
            string name = get<string>(ss);
            int index = get<int>(ss);
            agenda.rmFone(name, index);
        }

        else if(cmd == "rmcontato"){
            string name = get<string>(ss);
            agenda.rmcontato(name);
        }

        else if(cmd == "buscar"){
            string name = get<string>(ss);
            agenda.buscar(name);
        }


        else if(cmd == "print_fav"){
            string name = get<string>(ss);
            agenda.buscar(name);
        }
  
        else if(cmd == "rm_fav"){
            string name = get<string>(ss);
            agenda.buscar(name);
        }

        else if(cmd == "add_fav"){
            string name = get<string>(ss);
            agenda.buscar(name);
        }

        else if(cmd == "show"){
            //sort(agenda.agenda_lista.begin(), agenda.agenda_lista.end(), agenda.agenda_lista[0]);
            agenda.printString();
            //contato.tostring();
            //cout << "\n";
        }
        else{
            cout << "fail: comando invalido" << endl;
        }
    }
    return 0;
}
