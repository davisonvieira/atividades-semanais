package exercicos;

public class Loopduplo {

    //O(n²)
    public static void main(String [] args){
        int n = 10;//O(1)
        for (int i = 0; i < n; i++){//O(n)
            for(int j =0; j < n ;j++){//O(N)
                System.out.println(i + "  " + j);//O(1)

            }
        }
    }

}
