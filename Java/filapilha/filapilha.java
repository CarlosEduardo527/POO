class list{
  int[] num;
  int tam;
    list(){
      this.num= new int[0];
      this.tam=0;
    }
  void insere(int v){
    int[] lista=new int[tam+1];
    for(int i=0;i<tam;i++){
      lista[i]=num[i];
    }
    lista[tam]=v;
    num=lista;
    tam++;  
  }
  void remove(){
    int[] lista=new int[tam-1];
    for(int i=0;i<tam-1;i++){
      lista[i]=num[i+1];
    }
    num=lista;
    tam--;
  }
  void primeiro(){
    System.out.println("Primeiro:" + num[0]);
  }
  void last(){
    System.out.println("Ultimo:" + num[tam-1]);
  }
  void lelista(){
    for(int i=0;i<tam;i++){
      System.out.println("Numero"+ i +": Valor:" + num[i]);
   }  
  }
  void tamanho(){
    System.out.println("Tamanho:" + tam);
  }
}
class fila extends list{
  fila(){
    super();
  }
}
class pilha extends list{
  pilha(){
    super();
  }
  void pop() {
    super.remove();
  }
  void primeiro() {
    System.out.println("Primeiro:" + num[0]);
  }
  void push(int v) {
    int[] pil=new int[tam+1];
    pil[0]=v;
    for(int i=0;i<tam;i++){
        pil[i+1]=num[i];
    }
    num=pil;
    tam++;  
  }
}

public class filapilha{
  public static void main(String[] args){
    fila f = new fila();
    f.insere(1);
    f.insere(2);
    f.insere(3);
    f.remove();
    f.primeiro();
    f.lelista();
    f.tamanho();

    pilha p = new pilha();
    p.push(1);
    p.push(2);
    p.push(3);
    p.pop();
    p.primeiro();
    p.lelista();
    p.tamanho();
  }
}