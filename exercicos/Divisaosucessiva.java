package exercicos;

public class Divisaosucessiva {
    //Log²(n)
    public static void main(String[] args) {
        double x = 10; //O(1)
        while(x>1){ //Log(n)
            x=x/2;//O(1)
            System.out.println(x); //O(1);
        }
    }
}
