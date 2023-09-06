import java.util.Scanner;

class Fibonacci {

    static int find(int n){
        if(n<=1){
            return n;
        }
        return find(n-2)+ find(n-1);
    }
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the nth position to find the value: ");
        int n = input.nextInt();
        System.out.println("Answer: "+ find(n));
    }
}