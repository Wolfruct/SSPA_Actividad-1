#include <iostream>

using namespace std;

class paquete
{
private:
    int id;
    float peso;
    char destino[100];
    

public:
    char origen[100];
    paquete();
    ~paquete();
    paquete *sig;
    
    bool n_paquete(int id,char origen[100],char destino[100],float peso);
    int get_id();
    float get_peso();
    void get_origen(char origen[100]);
    void get_destino(char destino[100]);
    paquete* get_sig();
};

paquete::paquete()
{
    this->sig = NULL;
}

bool paquete::n_paquete(int id,char origen[100],char destino[100],float peso)
{
    this->id = id;
    for(int i = 0; i < 100; i++)
    {
        this->origen[i] = origen[i];
    }
    for(int i = 0; i < 100; i++)
    {
        this->destino[i] = destino[i];
    }
    this->peso = peso;

    return true;
}

paquete::~paquete()
{
    //dtor
}

int paquete::get_id()
{
    return this->id;
}

void paquete::get_origen(char origen[100])
{
    int n;

    n = 0;

    while(this->origen[n] != '\0')
    {
        origen[n] = this->origen[n];
        n++;
    }
    origen[n] = '\0';

    return;
}

void paquete::get_destino(char destino[100])
{
    int n;

    n = 0;

    while(this->destino[n] != '\0')
    {
        destino[n] = this->destino[n];
        n++;
    }
    destino[n] = '\0';

    return;
}

float paquete::get_peso()
{
    return this->peso;
}

paquete* paquete::get_sig()
{
    return this->sig;
}