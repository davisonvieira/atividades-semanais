package exercicos;

public class Loopaninhado {

    //o(n²)
    public static void main(String[] args) {
        int n = 10;//O(1)
        for (int i = 0; i < n; i++) {//O(N)
            for (int j = 0; j < i; j++) { //O(n)
                System.out.println(i + " " + j);//O(1)
            }
        }
    }
}