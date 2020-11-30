public class Auction{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-->0){
            int n = sc.nextInt();
            int a[] = new int[n];
            int c[] = new int[n+1];
            int d[] = new int[n+1];
            for(int i=0;i<n;i++){
                a[i] = sc.nextInt();
                 c[a[i]]++;
                 d[a[i]]=i+1;            }
            int idx = -1;
            
             for(int i=0;i<n+1;i++){
               if(c[i]==1){
               idx = d[i];
               break;
            }}
            System.out.println(idx);
            
            
        }
    }
}

