package exercicos;

public class Buscalinear {

    //O(n)
    public static void main(String[] args) {
        int[] vetor = {3, 8, 2, 5, 9};//O(1)
        int alvo = 5; //O(1)
        boolean encontrado = false; //O(1)
        for (int i = 0; i < vetor.length; i++){ //O(n)
            if (vetor[i] == alvo) { //O(1)
                encontrado = true;
                System.out.println(i); //O(1)
                break ;
            }
        }
    }
}