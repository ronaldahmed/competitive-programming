/* Codigo del Trie, no lo compile ni lo testie asi que no se ni si compila
pero de tener errores son minimos y esta es la base de un codigo que funciona 
y es eficiente */

struct Trie{
	map<char,int> hijos;
	bool fin;
};

int n; // tamanio del trie, empieza inicializado en cero
Trie t[MAXN] // MAXN lo definimos con #define

/* El trie tiene una raiz que es t[0] */

/*Llamamos a insertar con pos = 0, p = 0
pos representa la posicion en el string y
p representa el puntero al nodo donde vamos
a insertar el siguiente caracter */
void insertar(string &st, int pos, int p)
{
	if(pos==st.size())
	{
		t[p].fin = true; // indica que es el fin de una palabra
		return;
	}
	if(t[p].hijos.find(st[pos])==t[p].hijos.end())
	{
		t[p].hijos[st[pos]] = n;
		t[n].hijos.clear();
		t[n].fin = false;
		n++;
	}
	insertar(st,pos+1,t[p].hijos[st[pos]];
}

/*Funcion que busca si una palabra esta en el trie */

bool buscar(string &st)
{
	int p = 0;
	forn(i,st.size())
	{
		if(t[p].hijos.find(st[i])==t[p].hijos.end())
			return false;
		p = t[p].hijos[st[i]];
	}
	return t[p].fin; // si t[p].fin es true quiere decir que ahi termina una palabra
}
