import java.util.*;

class sample{

    public static void main(String args[]){

        System.out.println("Hello");
        
        Scanner s = new Scanner(System.in);

        int x = s.nextInt();

        for(int i = 0; i < x; i++)
            System.out.print(i + " ");
    }
}