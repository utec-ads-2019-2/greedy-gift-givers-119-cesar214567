#include <iostream>
#include <vector> 
#include <string>

using namespace std;

class persona{
    public:
    string nombre;
    int dinero_obtenido=0;
    persona(string nombre1):nombre(nombre1){};
};

int main(){
    int numero_de_personas,dinero,personas_a_repartir,dinero_para_cada_uno;
    string nombre;
    bool flag=false;

    while (cin>>numero_de_personas){
        if (flag){
            cout<<endl;
        }
        flag=true;
        vector<persona> vector_de_personas;
    for (int i=0;i<numero_de_personas;i++){
        cin>>nombre;
        vector_de_personas.emplace_back( persona(nombre)); 
    }
    for (int i=0;i<numero_de_personas;i++){
        
        cin>>nombre;
        cin>>dinero;
        cin>>personas_a_repartir;
        for (int j=0;j<numero_de_personas;j++){
            if (vector_de_personas[j].nombre==nombre){
                vector_de_personas[j].dinero_obtenido-=dinero;
                if (dinero==0){
                    break;
                }else{
                    if (personas_a_repartir!=0){
                        vector_de_personas[j].dinero_obtenido+=dinero%personas_a_repartir;  
                    }
                break;
                }
                
            }
        }
        if (dinero==0){
            dinero_para_cada_uno=0;
            for (int i=0;i<personas_a_repartir;i++){
                cin>>nombre;
            }
        }else{
            if (personas_a_repartir!=0){
                dinero_para_cada_uno=dinero/personas_a_repartir;
                for (int j=0;j<personas_a_repartir;j++){
                    cin>>nombre;
                    for (int k=0;k<numero_de_personas;k++){
                        if (vector_de_personas[k].nombre==nombre){
                            vector_de_personas[k].dinero_obtenido+=dinero_para_cada_uno;
                            break;
                        }

                    }
                }
            }else{
                for (int j=0;j<numero_de_personas;j++){
                    if (vector_de_personas[j].nombre==nombre){
                        vector_de_personas[j].dinero_obtenido+=dinero;
                        break;
                    }
                }
            }
            
        }
        
    }
    for (int i=0;i<numero_de_personas;i++){
            cout<<vector_de_personas[i].nombre<<" "<<vector_de_personas[i].dinero_obtenido<<endl;
        
    }
    

}

}