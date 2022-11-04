template <typename T> class Nodo {
private:
  T data;
  Nodo<T> *left;
  Nodo<T> *right;
  template <typename U> friend class BST;

public:
  Nodo(T data) {
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }
};

template <typename T> class BST;

template <typename T> 
ostream &operator<< (ostream &,  BST<T> &);

template <typename T> class BST {
private:
   Nodo<T> *root;
  void insert(Nodo<T> *&nodo, T dato) {
    if (nodo == NULL) {
      nodo = new Nodo<T>(dato);
    } else {
      if (dato < nodo->data) {
        insert(nodo->left, dato);
        balanceo(nodo);
      } else if (dato > nodo->data) {
        
        insert(nodo->right, dato);
        balanceo(nodo);
      } else {
        cout<< endl;
        cout << dato << " repetido" << endl;
      }
    }
  }

  void inOrden(Nodo<T> *&nodo) {
    if (nodo != NULL) {
      inOrden(nodo->left);
      cout << nodo->data << " : ";
      inOrden(nodo->right);
    }
  }
  void preOrden(Nodo<T> *&nodo) {
    if (nodo != NULL) {
      cout << nodo->data << " : ";
      preOrden(nodo->left);
      preOrden(nodo->right);
    }
  }
  void postOrden(Nodo<T> *&nodo) {
    if (nodo != NULL) {
      postOrden(nodo->left);
      postOrden(nodo->right);
      cout << nodo->data << " : ";
    }
  }
  bool contains(Nodo<T> *&nodo, T dato) {
    if (nodo == NULL) {
      return false;
    } else if (dato < nodo->data) {
      return contains(nodo->left, dato);
    } else if (dato > nodo->data) {
    
      return contains(nodo->right, dato);
    } else {
      return true;
    }
  }

  bool remove(Nodo<T> *&nodo, T dato) {
    if (nodo == NULL) {
      return false;
    } else if (dato < nodo->data) {
      return remove(nodo->left, dato);
    } else if (dato > nodo->data) {
      return remove(nodo->right, dato);
    } else {
      if (nodo->left == NULL && nodo->right == NULL) {

        /*Borra nodo y regresa true*/
        delete nodo;
        nodo = NULL;
        return true;

      } else if (nodo->left && nodo->right == NULL) {

        Nodo<T> *left = nodo->left;
        Nodo<T> *temp = nodo;
        nodo = left;
        delete temp;
        return true;
        /*
Asigna a left el apuntador izquierdo del nodo.
Asigna a temp el nodo.
Asigna a nodo el left
Borra temp y regresa true*/

      } else if (nodo->right && nodo->left == NULL) {
        Nodo<T> *right = nodo->right;
        Nodo<T> *temp = nodo;
        nodo = right;
        delete temp;
        return true;
        /*
Asigna a right el apuntador derecho del nodo.
Asigna a temp el nodo.
Asigna a nodo el right
Borra temp y regresa true*/
      } else { // if (nodo->left &&  nodo->right) {

        /*
        Obtén el dato min con getMin del lado right.
        Asigna al nodo data el min.
        Llama a remove de lado right y buscando a min
        Regresa true*/
        T min = getMin(nodo->right);
        nodo->data = min;
        remove(nodo->right, min);
        return true;
        balanceo(nodo);
      }
    }
  }

  T getMin(Nodo<T> *nodo) {
    if (nodo->left == NULL) {
      return nodo->data;
    } else {
      return getMin(nodo->left);
    }
  }
  int tree_height(Nodo<T>* nodo) {
    if (nodo==NULL){
        return 0;
      }else {
        int AltIzq = tree_height(nodo->left);
        int AltDer = tree_height(nodo->right);
        if (AltIzq >= AltDer){
            return AltIzq + 1 ;
          }else{
            return AltDer + 1;
          }
    }
}
int lenght(Nodo<T >* & nodo){
    int count = 0;
    count++;
    if(nodo->left == NULL && nodo->right == NULL){
      return count;
    }else if(nodo->left != NULL && nodo->right == NULL){
      return count += lenght(nodo->left);
    }else if(nodo->left == NULL && nodo->right != NULL){ 
      return count += lenght(nodo->right);
    }else{
      return count += lenght(nodo->left) + lenght(nodo->right); 
    }
  }
public:
  BST() { root = NULL; }

  friend ostream & operator<< <T>(ostream &,  BST<T> &);

  void inOrden() { inOrden(root); }
  void preOrden() { preOrden(root); }
  void postOrden() { postOrden(root); }
  void insert(T dato) {
    if (is_empty()) {
      root = new Nodo<T>(dato);
    } else {
      insert(root, dato);
    }
  }
  bool is_empty() { return (root == NULL) ? 1 : 0; }

  bool contains(T dato) { return contains(root, dato); }
  T getMin() { return getMin(root); }

  bool remove(T dato) { return remove(root, dato); }

  T getroot() const { return root->data; }

  ostream & imprime(ostream &salida, Nodo<T> * &nodo)  {
    if (nodo != NULL) {
      imprime(salida, nodo->left);
      salida << nodo->data << " : ";
      cout << nodo->data << " : ";
      imprime(salida, nodo->right);
    }else{
      salida <<  " : ";
      return salida;
    }
    return salida;
  }
int height(Nodo<T> *temp)
{
    int h = 0;
    if (temp != NULL)
    {
        int l_height = height(temp->left);
        int r_height = height(temp->right);
        int max_height = max(l_height, r_height);
        h = max_height + 1;
    }
    return h;
}
int max(int a, int b) { return (a > b) ? a : b; }
int calcula_fe(Nodo<T> *temp)
{
    int left_height = height(temp->left);
    int right_height = height(temp->right);
    int b_factor =  right_height - left_height;
    return b_factor;
}
void balanceo(Nodo< T> * & temp)
{
    int factor_balanceo = calcula_fe(temp);
    if (factor_balanceo > 1)
    {
      if(calcula_fe(temp->right) < 0){
        double_left_rotation(temp);
      }else{
        left_rotation(temp);
      }
    }
    if (factor_balanceo < -1) 
    {
      if(calcula_fe(temp->left) > 0){
        double_right_rotation(temp);
      }else{
        right_rotation(temp);
      }
    }
}

void left_rotation(Nodo<T> * & nodo) {
  Nodo<T> * right = nodo->right;
  Nodo<T> * left = right->left;
  right->left=nodo;
  nodo->right=left;
  nodo = right;
}

void right_rotation(Nodo<T> * & nodo) {
  Nodo<T> * left = nodo->left;
  Nodo<T> * right = left->right;
  left->right=nodo;
  nodo->left=right;
  nodo = left;
}
void double_left_rotation(Nodo<T> * & nodo){
  Nodo<T> * right = nodo->right;
  Nodo<T> * hoja= nodo->right->left;
  Nodo<T> * aux = hoja->right;
  nodo->right=hoja;
  hoja->right=right;
  right->left =aux;
  left_rotation(nodo);
}
void double_right_rotation(Nodo<T> * & nodo){
  Nodo<T> * left= nodo->left;
  Nodo<T> * hoja= nodo->left->right;
  Nodo<T> * aux = hoja->left;
  nodo->left=hoja;
  hoja->left=left;
  left->right =aux;
  right_rotation(nodo);
}
void ComparadorHeight(){
    int Izq = tree_height(root->left);
    int Der = tree_height(root->right);
    if (Izq == Der || Der-Izq <=1 || Der-Izq >=-1){
      cout << "Arbol balanceado  "<< Izq << " || " << Der << endl;
      }else{
        cout << "Arbol desbalanceado  " << Izq << " || " << Der << endl;
      }
  }
int lenght(){
    int count = 0;
    if(is_empty()){
      return 0;
    }else{
      return lenght(root);
    }
  }
};

template <typename T>
ostream &operator<<(ostream &salida,  BST<T> &lista) {
  return lista.imprime(salida, lista.root);
}
