class Hashtable{
    private:
        int size;
        LinkedList<int> * tabla;
        int fh(int key){
            return key * 3 % 11;
        }
    public:
      Hashtable(int size){
        this->size  = size;
        tabla = new LinkedList<int>[size];
      }

      void insert(int key){
        int posicion = fh(key);
        tabla[posicion].addLast(key);
      }

      void print(){
        for(int i = 0; i < size; i++){
          cout << i << " : "<< tabla[i] << endl;
        }
      }

};
