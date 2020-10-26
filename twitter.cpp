#include <iostream>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

struct Msg{
    string idSender;
    string text;
    Msg(string sender, string text):
        idSender(sender), text{text}{
    }
    friend ostream& operator<<(ostream& os, Msg msg){
        os << "[" << msg.idSender << ":" << msg.text << "]";
        return os;
    }
};

struct Pessoa{
    string id;
    vector<Msg> inbox;
    int contadorNaoLidas;

    Pessoa(string id = ""): contadorNaoLidas{0}{
        this->id = id;
    }
    
    void send(Pessoa& destinatario, string text){
        Msg msg(this->id, text);
        destinatario.inbox.push_back(msg);
        destinatario.contadorNaoLidas += 1;
    }

    void readMsgs(){
        for(size_t i = inbox.size() - contadorNaoLidas; i < inbox.size(); i++){
            cout << inbox[i] << endl;
        }
        contadorNaoLidas = 0;
    }
    
    void timeline(){
        for(size_t i = 0; i < inbox.size(); i++){
            cout << inbox[i] << endl;
        }
    }
};

struct Sistema{

    map<string, Pessoa> pessoas;
    map<string, vector<string> > seguidos,seguidores;



    void create(string name){
        pessoas[name] = Pessoa(name);
        seguidos[name].push_back("");
        seguidores[name].push_back("");
    }

    void tweet(string sender, string text){
        for(int i = 1; i < (int) seguidores[sender].size(); i++){
            pessoas[sender].send(pessoas[seguidores[sender][i]], text);
        }
    }

    void readMsgs(string name){
        cout << "readMsgs of " << name << ": " << endl;
        pessoas.at(name).readMsgs();
        //return pessoas.at(name).readMsgs();
    }

    void timeline(string name){
        cout << "timeline of " << name << ": " << endl;
        pessoas.at(name).timeline();
        //return pessoas.at(name).readMsgs();
    }


    void seguir(string pessoa ,string seguidor){
        if( seguidos.find(pessoa) != seguidos.end() ){

            for(size_t i = 0; i < seguidores[pessoa].size() ; i++){//seguidores[pessoa]
                
                if( seguidos[pessoa][i] == seguidor ){
                    cout<< "seguidor ja cadastrado" << endl;
                    return;
                }         
            }
            seguidos[pessoa].push_back(seguidor);
            seguidores[seguidor].push_back(pessoa);
            return;
        }
        cout << "pessoa nao existente" <<endl;



    }

    void show(){
        for(auto par : pessoas){


        cout << par.first << ": " << endl;
        cout << "   seguindo [ ";
        for(int i = 1; i < (int) seguidos[par.first].size(); i++ ){
            cout << seguidos[par.first][i] << " ";
        }
        cout << "] ";
        cout << endl;

        cout << "   seguidores [ ";
        for(int i = 1; i < (int) seguidores[par.first].size(); i++ ){// i talvez seja 1 ou 0 depende do "seguidos[name].push_back("");"
            cout << seguidores[par.first][i] << " ";
        }
        cout << "] ";
        cout << endl;

        }

    }
};

int main(){
    Sistema sis;

    sis.create("joao");
    sis.create("daniel");
    sis.create("jonas");
    sis.seguir("daniel","jonas");
    sis.show();
    while(true){
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;
        stringstream ss(line);
        ss >> cmd;
        if(cmd == "end"){
            break;
        }
        else if(cmd == "addUser"){
            string name;
            ss >> name;
            sis.create(name);
        }
        else if(cmd == "tweet"){
            string name, mensage, teste;
            ss >> name;
            while( ss >> teste )
                mensage = mensage + " " + teste;
            sis.tweet(name,mensage);
        }
        else if(cmd == "readMensage"){
            string name;
            ss >> name;
            sis.readMsgs(name);
        }
        else if(cmd == "timeline"){
            string name;
            ss >> name;
            sis.timeline(name);
        }
        else if(cmd == "seguir"){
            string name, seguidor;
            ss >> name >> seguidor;
            sis.seguir(name,seguidor);
        }      
        else if(cmd == "show"){
            sis.show();
        }
        else{
            cout << "fail: comando invalido" << endl;
        }
    }
    return 0;
}