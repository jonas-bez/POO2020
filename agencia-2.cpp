#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <string>
using namespace std;

class Conta{
public:
    int id;
    string client_id;
    float saldo;
    string tipo;
    
    Conta(int id=0 ,string cliente="", string tipo=""){
        this->id=id;
        this->client_id=cliente;
        this->saldo=0;
        this->tipo=tipo;
    }
    friend ostream& operator<<(ostream& os, Conta& conta){
		os << conta.id << " : " << conta.client_id << " : " << conta.saldo << " : " << conta.tipo;
		return os;
	}
    void atualizacao_mensal();
};

class ContaCorrente: public Conta{
private:
    float tarifaMensal = 20; 
public:
    ContaCorrente(int id=0, string cliente_id=""):Conta {id, cliente_id, "CC"}{   
    }

    void atualizacao_mensal(){
        saldo-=tarifaMensal;
    }

};

class ContaPoupanca: public Conta{
private:
    float rendimento = 0.05;
public:
    ContaPoupanca(int id=0, string cliente_id=""):Conta {id, cliente_id, "CP"}{
    }

    void atualizacao_mensal(){
        saldo= saldo + saldo*rendimento;
    }
};


class Cliente{
public:
    vector<Conta*> contas;
    string nome;
    
    Cliente(string nome=""){
        this->nome=nome;
    }

    void addConta(Conta * conta){
        contas.push_back(conta);
    }
};

class Agencia{
public:
    
    map<string, Cliente*> clientes;
    map<int, Conta*> contas;
    map<int, ContaCorrente*> contas_CC;
    map<int, ContaPoupanca*> contas_CP;
    int contador_id = 0;

    Agencia(){
    }

    void addCliente(string name){
        Cliente * cliente = new Cliente(name);
        ContaCorrente * cc = new ContaCorrente(contador_id++, name);
        ContaPoupanca * cp = new ContaPoupanca(contador_id++, name);
        cliente->addConta(cc);
        cliente->addConta(cp);
        clientes[name] = cliente;
        contas[cc->id] = cc;
        contas[cp->id] = cp;
        contas_CC[cc->id] = cc;
        contas_CP[cp->id] = cp;
    }

    void atualizar_mes(){
        for(auto& par : contas_CC)
            par.second->atualizacao_mensal();

        for(auto& par : contas_CP)
            par.second->atualizacao_mensal();
    }

    void depositar(int indice, float value){
        if(contas.find(indice) == contas.end()){
            cout << "conta inexistente" << endl;
            return;
        }
        if(value<=0){
            cout << "deposite um valor maior que 0" << endl;
            return;
        }
        contas[indice]->saldo += value;
    }

    void sacar(int indice, float value){
        if(contas.find(indice) == contas.end()){
            cout << "conta inexistente" << endl;
            return;
        }
        if(contas[indice]->saldo < value){
            cout << "dinheiro insufuciente" << endl;
            return;
        }
        contas[indice]->saldo -= value;
    }

    void transferir(int id1, int id2, float value){
        if(contas.find(id1) == contas.end() || contas.find(id2) == contas.end()){
            cout << "conta inexistente" << endl;
            return;
        }
        if( contas[id1]->saldo < value ){
            cout << "dinheiro insufuciente"<<endl;
            return;
        }
        contas[id1]->saldo -= value;
        contas[id2]->saldo += value;
    }

    void toString(){
        for(auto& par : contas)
            cout << *par.second << endl;
    }

};


int main(){
    Agencia agencia;
    while(true){
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;
        stringstream ss(line);
        ss >> cmd;
        if(cmd == "end"){
            break;
        }
        else if(cmd == "addcliente"){
            string name;
            ss >> name;
            agencia.addCliente(name);
        }
        else if(cmd == "saque"){
            int id;
            ss >> id;
            float value;
            ss >> value;
            agencia.sacar(id,value);
        }
        else if(cmd == "deposito"){
            int id;
            ss >> id;
            float value;
            ss >> value;
            agencia.depositar(id,value);
        }
        else if(cmd == "transferir"){
            int id1;
            int id2;
            float value;
            ss >> id1 >> id2 >> value;
            agencia.transferir(id1,id2,value);
        }      
        else if(cmd == "atualizar"){
            agencia.atualizar_mes();
        }
        else{
            cout << "fail: comando invalido" << endl;
        }

        agencia.toString();
    }
    return 0;
}
