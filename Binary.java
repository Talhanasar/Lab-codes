import java.util.Scanner;

class Binary{

    static int BinarySearch(int arr[],int low , int high,int value){

        if(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]==value){
                return mid;
            }else if(arr[mid]< value){
                low = mid+1;
                return BinarySearch(arr, low, high, value);
            }else {
                high = mid-1;
                return BinarySearch(arr, low, high, value);
            }
        }      
        return -1;
    }

    public static void main(String[] args) {
        int n, find, low = 0;
        System.out.print("Enter the number of elements:");
        Scanner input = new Scanner(System.in);
        n = input.nextInt();
        int[] arr =  new int [n];
        System.out.print("Enter the elements:");
        
        for(int i =0 ; i<n; i++){
            int x;
            x = input.nextInt();
            arr[i] = x;
        }
        System.out.print("Enter the value you want to Search: ");
        find = input.nextInt();
        int ans = BinarySearch(arr,low,n-1,find);
        if(ans ==-1){
            System.out.println("Value not found in the array.");
        }else System.out.println(ans);
    }

}