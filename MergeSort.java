import java.util.Scanner;

public class MergeSort {
    
    static void Merge(int []arr,int low,int mid,int high){
        int i = low, j= mid+1 ,k= low; 
        int []b = new int[high+2];
        while(k<=mid && j<=high){
            if(arr[k]<= arr[j]){
                b[i] = arr[k];
                k++;
            }else {
                b[i] = arr[j];
                j++;
            }
            i++;
        }
        if(k>mid){
            while(j<=high){
                b[i] = arr[j];
                j++;
                i++;
            }
        }else{
            while(k<=mid){
                b[i] = arr[k];
                k++;
                i++;
            }
        }
        
        for (int l=low; l <high; l++) {
            arr[l] = b[l];
        }
    }
    static void Sort(int []arr,int low,int high){
        if(low<high){
            int mid = (low+high);
            Sort(arr,low,mid);
            Sort(arr,mid+1,high);
            Merge(arr,low,mid,high);
        }
    }
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the number of elements: ");
        int n = input.nextInt();
        int[] arr =  new int [n+1];
        System.out.print("Enter the elements: ");
        
        for(int i =0 ; i<n; i++){
            int x;
            x = input.nextInt();
            arr[i] = x;
        }

        Sort(arr,0,n);
        System.out.print("Array after sorting: ");
        for(int i=0; i<n; i++){
            System.out.print(arr[i]+" ");
        }
    }
}
