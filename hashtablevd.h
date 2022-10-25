template <typename K, typename T> /* K key, T value*/
class HashPair {
public:
  K key;
  T value;
  HashPair(K key, T value) {
    this->key = key;
    this->value = value;
  }
  HashPair() {}
};

template <typename K, typename T> class Hashtable {
private:
  int size;
  LinkedList<HashPair<K, T> *> *tabla;
  int fh(K key) const {
    hash<K> khash;
    return khash(key) % size;
  }

public:
  Hashtable(int size = 20) {
    this->size = size;
    tabla = new LinkedList<HashPair<K, T> *>[size];
    for (int i = 0; i < size; i++)
      tabla[i] = LinkedList<HashPair<K, T> *>();
  }

  bool put(K key, T value) {
    int posicion = fh(key);
    LinkedList<HashPair<K, T> *> lista = tabla[posicion];
    int indice = -1;
    for (int i = 0; i < lista.size(); i++) {
      if (lista.get(i)->key == key) {
        indice = i;
      }
    }
    if (indice >= 0) {
      lista.get(indice)->value = value;
    } else {
      tabla[posicion].addLast(new HashPair<K, T>(key, value));
    }
    return (indice >= 0) ? 0 : 1;
  }

  T get(K key) const {
    int posicion = fh(key);
    LinkedList<HashPair<K, T> *> lista = tabla[posicion];
    int i = 0;
    while (lista.get(i)->key != key) {
      i++;
    }
    if (i >= lista.size()) {
      throw -1;
    }
    return lista.get(i)->value;
  }

  bool contains(K key) const {
    int posicion = fh(key);
    LinkedList<HashPair<K, T> *> lista = tabla[posicion];
    int indice = -1;
    for (int i = 0; i < lista.size(); i++) {
      if (lista.get(i)->key == key) {
        indice = i;
      }
    }
    return (indice == -1) ? 0 : 1;
  }

  void print() {
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < tabla[i].size(); j++) {
        cout << "i:" << i << " k: " << tabla[i].get(j)->key << "  "
             << tabla[i].get(j)->value << endl;
      }
    }
  }
};
