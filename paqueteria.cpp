#include <iostream>
#include "paquete.cpp"
#include <fstream>

class paqueteria
{
private:
    paquete *pro;
    int u_id;
public:
    paqueteria(/* args */);
    ~paqueteria();

    bool insertar_inicio(int id, char origen[100], char destino[100], float peso);
    bool eliminar_inicio();
    void mostrar();
    void guardar();
    void recuperar();
    int aumento_ids();
    paquete get_pro();
};


paqueteria::paqueteria()
{
    this->u_id = -1;
    this->pro = NULL;
}

paqueteria::~paqueteria()
{
    //dtor
}

bool paqueteria::insertar_inicio(int id, char origen[100], char destino[100], float peso)
{
    paquete *n_paquete = new paquete();
    n_paquete->n_paquete(id,origen,destino,peso);

    if(this->pro == NULL)
    {
        this->pro = n_paquete;
    }
    else
    {
        paquete *aux = this->pro;
        n_paquete->sig = aux;
        this->pro = n_paquete;
    }

    return true;
}

paquete paqueteria::get_pro()
{
    return *pro;
}

bool paqueteria::eliminar_inicio()
{
    if(this->pro!=NULL)
    {
        paquete *aux = this->pro;
        this->pro = this->pro->sig;
        delete(aux);
        return true;
    }
    return false;
}

void paqueteria::mostrar()
{
    char ori[100], des[100];

    paquete *aux = this->pro;
    
    cout << " \n\n  -- -- -- --Paquetes!-- -- -- --   \n\n" << endl;
    while(aux != NULL)
    {
        cout << "   ID: " << aux->get_id() << endl;
        cout << "   Peso: " << aux->get_peso() << endl;

        aux->get_origen(ori);
        aux->get_destino(des);

        cout << "   Origen: ";
        int n = 0;
        while(ori[n] != '\0')
        {
            cout << ori[n];
            n++;
        }
        cout << endl;

        cout << "   Destino: ";
        n = 0;
        while(des[n] != '\0')
        {
            cout << des[n];
            n++;
        }
        cout << endl << "----------------------" << endl;

        aux = aux->sig;
    }
    return;
}

void paqueteria::guardar()
{
    paquete *aux = this->pro;
    char ori[100], des[100];

    ofstream fichero_g("paquetes.txt");

    while(aux != NULL)
    {
        aux->get_origen(ori);
        aux->get_destino(des);
        fichero_g << aux->get_id() << ":" << aux->get_peso() << ":" << ori << ":" << des << endl;

        aux = aux->sig;
    }
    
    fichero_g.close();
    return;
}

void paqueteria::recuperar()
{
    char ori[100], des[100];
    int id;
    float peso;

    ifstream fichero_r("paquetes.txt",ios::app);
    if(fichero_r.fail())
    {
        cout << "\n !No existe el archivo!" << endl;
    }
    else{
        while(!fichero_r.eof())
        {
            fichero_r >> id;
            fichero_r.get();
            fichero_r >> peso;
            fichero_r.get();
            fichero_r.getline(ori,100,':');
            fichero_r.getline(des,100);

            this->insertar_inicio(id,ori,des,peso);
        }
    }
    fichero_r.close();
    this->eliminar_inicio();
    return;
}

int paqueteria::aumento_ids()
{
    this->u_id = this->u_id+1;

    return this->u_id;
}
