import java.util.Scanner;


public class Quicksort {

    static int partition(int arr[],int low,int high){
        int pivot = arr[low];
        int i = low+1;
        int j = high;
        int swap;
        do{
    
            while(pivot>=arr[i]){
                i++;
            }
            while (pivot<arr[j]){
                j--;
            }
            if(i<j){
                swap = arr[i];
                arr[i] = arr[j];
                arr[j] = swap;
            }
        } while(i<j);
        swap = arr[low];
        arr[low] = arr[j];
        arr[j] = swap;
        return j;
    }
    
    static void Sort(int arr[],int low, int high){
        if(low<high){
            int n  = partition(arr,low,high);
            Sort(arr,low,n-1);
            Sort(arr,n+1,high);
        }
    }
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the number of elements: ");
        int n = input.nextInt();
        int[] arr =  new int [n];
        System.out.print("Enter the elements: ");
        
        for(int i =0 ; i<n; i++){
            int x;
            x = input.nextInt();
            arr[i] = x;
        }

        Sort(arr,0,n-1);
        System.out.print("Array after sorting: ");
        for(int i=0; i<n; i++){
            System.out.print(arr[i]+" ");
        }
    }
}
