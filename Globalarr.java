import java.util.Scanner;

public class Globalarr {

    static int fib(int[] arr,int n){
        arr[0] = 0;
        arr[1] = 1;
        for(int i= 2; i<=n; i++){
            arr[i] = arr[i-2] + arr[i-1];
        }
        return arr[n];
    }
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n;
        System.out.print("Enter the nth position to find the value: ");
        n = input.nextInt();
        int[] arr = new int [n+1];
        fib(arr,n);
        System.out.println("Answer: "+ arr[n]);
    }
}
