#include <iostream>
#include <fstream>
#include <string>
using namespace std;
string catedras[100][3];
int cont=0, cont2=0;
void archivos(), libres();
string buscar_catedra(string code);
int busqueda(string dni, string cod);
struct alu{
	int libres;
	int regulares;
	int prom;
	string catedra;
};
struct doc{
	
	string code;
	string comision;
	string dni;
	string nya;
	string funcion;
	string cargo;
};
doc docentes[100];
alu alumnos[100];
int main(int argc, char *argv[]) {
	archivos();
	int k=0, y=0, cont_a=0;
	string dni, code;
	cout << "Ingrese DNI: "; cin >> dni; cout << endl;
	//while (dni != "0");
	//{
		cout << "Ingrese codigo de catedra: "; cin >> code; cout << endl;
		y=busqueda(dni, code);
		if (docentes[y].cargo == "JTP" || docentes[y].cargo == "AUXILIAR")
		{
			cout << "NO AUTORIZADO PARA CARGAR" << endl;
		}
		else if (docentes[y].cargo == "TITULAR" || docentes[y].cargo == "ADJUNTO")
		{
			cout << "Ingrese cantidad de alumnos libres: "; cin >> alumnos[k].libres;
			cout << "Ingrese cantidad de alumnos regulares: "; cin >> alumnos[k].regulares;
			cout << "Ingrese cantidad de alumnos promocionados: "; cin >> alumnos[k].prom;
			alumnos[k].catedra = buscar_catedra(code);
			cont_a++;
			k++;
		}
		/*cout << "Ingrese DNI: "; cin >> dni; cout << endl;
		cout << "Ingrese codigo de catedra; "; cin >> code; cout << endl;*/
	//};
	ofstream archivo3;
	archivo3.open("fin_cursada.txt");
	int auxa=0;
	if (archivo3.fail())
	{
		cout << "ERROR";
	}
	else
	{
		archivo3 << "Nombre ded catedra" << "                      " << "Libres" << "   " << "No libres" << endl;
		for (int i=0; i<cont_a; i++)
		{
			auxa = alumnos[i].prom + alumnos[i].regulares;
			archivo3 << alumnos[i].catedra << "                 " << alumnos[i].libres << "     " << auxa << endl;
		}
	}
	libres();
	return 0;
}

void archivos()
{
	int i=0;
	ifstream archivo1;
	archivo1.open("catedras.txt");
	if (archivo1.fail())
	{
		cout << "error";
	}
	else 
	{
		while (!archivo1.eof())
		{
			getline(archivo1, catedras[i][0]);
			getline(archivo1, catedras[i][1]);
			getline(archivo1, catedras[i][2]);
			i++;
			cont++;
		}
	}
	archivo1.close();
	i=0;
	ifstream archivo2;
	archivo2.open("docentes.txt");
	if (archivo2.fail())
	{
		cout << "ERROR";
	}
	else 
	{
		while (!archivo2.eof())
		{
			getline(archivo2, docentes[i].code);
			getline(archivo2, docentes[i].comision);
			getline(archivo2, docentes[i].dni);
			getline(archivo2, docentes[i].nya);
			getline(archivo2, docentes[i].funcion);
			getline(archivo2, docentes[i].cargo);
			i++;
			cont2++;
		}
	}
	archivo2.close();
}

int busqueda(string dni, string cod)
{
    bool estaEncontrado = false;
	int pos=0;
    int i = 0;
	while (i<cont2 && !estaEncontrado)
	{
		if (dni == docentes[i].dni && cod == docentes[i].code)
		{
			pos = i;
			i=cont2; // no entiendo esto.
            estaEncontrado = true;
		};
        i++;
	}
	return pos;
}
string buscar_catedra(string code)
{
	string y;
	for (int j=0; j<cont; j++)
	{
		if (code == catedras[j][0])
		{
			y=catedras[j][2];
			j=cont;
		}
	}
	return y;
}
void libres()
{
	string y= "2", x;
	cout << "NOMBRE CATEDRA" << "            " << "AÑO CURSADA" << endl;
	for (int i=0; i<cont; i++)
	{
		//y = catedras[i][0].substr(3, 1);
		x = catedras[i][0].substr(6, 1);
		if (x == "S")
		{
			cout << catedras[i][2] << "      " << y << endl;
		}
	}
}
