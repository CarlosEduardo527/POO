#include <iostream>

class lista {
public:
    lista();
    void insere(int v);
    virtual void remove();
    virtual void primeiro();
    void last();
    void tamanho();
    void lelista();
    int* num;
    int tam;
};

class fila : public lista {
public:
    void remove() override;
    void primeiro() override;
};

class pilha : public lista {
public:
    void pop();
    void primeiro() override;
    void push(int v);
};

lista::lista() {
    num = nullptr;
    tam = 0;
}

void lista::insere(int v) {
    int* list = new int[tam + 1];
    for (int i = 0; i < tam; i++) {
        list[i] = num[i];
    }
    list[tam] = v;
    num = list;
    tam++;
}

void lista::remove() {
    int* list = new int[tam - 1];
    for (int i = 0; i < tam - 1; i++) {
        list[i] = num[i+1];
    }
    num = list;
    tam--;
}

void lista::primeiro() {
    std::cout << "Primeiro: " << num[0] << std::endl;
}

void lista::last() {
    std::cout << "Ultimo: " << num[tam - 1] << std::endl;
}

void lista::tamanho() {
    std::cout << "Tamanho: " << tam << std::endl;
}

void lista::lelista() {
    for (int i = 0; i < tam; i++) {
        std::cout << "Numero: " << i << " Valor:" << num[i] << std::endl;
    }
}

void fila::remove() {
    lista::remove();
}

void fila::primeiro() {
    lista::primeiro();
}

void pilha::pop() {
    remove();
}

void pilha::primeiro() {
    lista::primeiro();
}

void pilha::push(int v) {
    int* list = new int[tam + 1];
    list[0] = v;
    for (int i = 0; i < tam; i++) {
        list[i + 1] = num[i];
    }
    num = list;
    tam++;
}

int main() {
    fila f;
    f.insere(1);
    f.insere(2);
    f.insere(3);
    f.remove();
    f.primeiro();
    f.lelista();
    f.tamanho();

    pilha p;
    p.push(1);
    p.push(2);
    p.push(3);
    p.pop();
    p.primeiro();
    p.lelista();
    p.tamanho();

    return 0;
}
