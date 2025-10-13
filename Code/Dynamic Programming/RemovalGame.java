import java.util.*;


public class RemovalGame {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        sc.nextLine();
        int[] numbers = new int[n+1];
        long[][] dp = new long[n+1][n+1];
        long[] prefixSum = new long[n+1];

        prefixSum[0] = 0;
        for(int i=1; i<=n; i++)
        {
            numbers[i] = sc.nextInt();
            prefixSum[i] = prefixSum[i-1] + numbers[i];
            dp[i][i] = numbers[i];
        }
        
        
        


        int i=1,j, t=1;
        while(t<=n)
        {
            j=i+t;
            if(j>n)
            {
                t++;
                i=1;
                continue;
            }
                else if(j-i==1)  dp[i][j] = Math.max(numbers[i], numbers[j]);
                else{
                    dp[i][j] = Math.max(

                        numbers[i] + (prefixSum[j] - prefixSum[i] - dp[i+1][j]), 
                        numbers[j] + (prefixSum[j-1] - prefixSum[i-1] - dp[i][j-1]) );
                }
            i++;
        }

        System.out.println(dp[1][n]);
        sc.close();
    }
    
}