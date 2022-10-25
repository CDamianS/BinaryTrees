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

template <typename T> class BST {
private:
  Nodo<T> *root;
  void insert(Nodo<T> *&nodo, T dato) {
    if (nodo == NULL) {
      nodo = new Nodo<T>(dato);
    } else {
      if (dato < nodo->data) {
        insert(nodo->left, dato);
      } else if (dato > nodo->data) {
        insert(nodo->right, dato);
      } else {
        cout << "Dato repetido" << endl;
      }
    }
  };
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
  int length(Nodo<T> *&nodo) {
    if (nodo == NULL) {
      return 0;
    } else {
      return 1 + length(nodo->left) + length(nodo->right);
    }
  }
  T min(Nodo<T> *&nodo) {
    if (nodo->left == NULL) {
      return nodo->data;
    } else {
      return min(nodo->left);
    }
  }
  T max(Nodo<T> *&nodo) {
    if (nodo->right == NULL) {
      return nodo->data;
    } else {
      return max(nodo->right);
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

      } else if (nodo->left != NULL && nodo->right == NULL) {

        /*
Obtén el left de nodo.
Asigna a temp el nodo.
Asigna a nodo el left
Borra temp y regresa true*/
        Nodo<T> *temp;
        temp = nodo;
        nodo = nodo->left;
        delete temp;
        return true;

      } else if (nodo->right != NULL && nodo->left == NULL) {
        /*
Obtén el right de nodo.
Asigna a temp el nodo.
Asigna a nodo el right
Borra temp y regresa true*/
        Nodo<T> *temp;
        temp = nodo;
        nodo = nodo->right;
        delete temp;
        return true;

      } else if (nodo->left != NULL && nodo->right != NULL) {

        /*
        Obtén el dato min con getMin del lado right.
        Asigna al nodo data el min.
        Llama a remove de lado right y buscando a min
        Regresa true*/

        nodo->data = min(nodo->right);
        remove(nodo->right, nodo->data);
        return true;

        return true;
      }
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
public:
  BST() { root = NULL; }
  void inOrden() { inOrden(root); }
  void preOrden() { preOrden(root); }
  void postOrden() { postOrden(root); }
  T getMax() { return max(root); }
  T getMin() { return min(root); }
  T getroot() { return root->data; }

  int length() { return length(root); }

  void insert(T dato) {
    if (is_empty()) {
      root = new Nodo<T>(dato);

    } else {
      insert(root, dato);
    }
  }
  bool is_empty() { return (root == NULL) ? 1 : 0; }
  bool contains(T dato) { return contains(root, dato); }

  bool remove(T dato) {
    if (contains(dato)) {
      return remove(root, dato);
    } else {
      cout << "Dato no encontrado" << endl;
      return false;
    }
  }
  int getHeight(){
    return tree_height(root)-1;
  }
  void ComparadorHeight(){
    int Izq = tree_height(root->left);
    int Der = tree_height(root->right);
    if (Izq == Der){
      cout << "Arbol balanceado  "<< Izq << " || " << Der << endl;
      return 0;
      }else{
        cout << "Arbol desbalanceado  " << Izq << " || " << Der << endl;
        return 0;
      }
  }
  
  };
